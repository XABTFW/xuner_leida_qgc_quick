/****************************************************************************
 *
 * RadarBridge 实现: 反无雷达协议帧(UDP) -> MAVLink UAV_INFO -> 飞控
 *
 ****************************************************************************/

#include "RadarBridge.h"

#include "MAVLinkProtocol.h"
#include "MAVLinkLib.h"
#include "MultiVehicleManager.h"
#include "Vehicle.h"
#include "VehicleLinkManager.h"
#include "LinkInterface.h"
#include "QGCLoggingCategory.h"

#include <QtCore/QByteArray>
#include <QtCore/QCoreApplication>
#include <QtCore/QDateTime>
#include <QtCore/QDir>
#include <QtCore/QStandardPaths>
#include <QtCore/QString>
#include <QtCore/qapplicationstatic.h>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>

#include <cstring>
#include <cmath>

QGC_LOGGING_CATEGORY(RadarBridgeLog, "qgc.radarbridge")

// ---- 反无雷达协议常量 (与 PX4 target_frame_codec 一致) ----
namespace {
constexpr uint8_t  FRAME_HEADER         = 0xFD;
constexpr uint8_t  PAYLOAD_LENGTH_FIELD = 0x10;
constexpr uint8_t  MESSAGE_TYPE         = 0x01;
constexpr uint8_t  RESERVED             = 0x01;
constexpr int      HEADER_SIZE          = 19; // 8-byte (u64) time field
constexpr int      TARGET_SIZE          = 50;
constexpr int      CRC_SIZE             = 2;
constexpr int      MAX_DATAGRAM_SIZE    = 1472;
constexpr int      MAX_TARGETS          = (MAX_DATAGRAM_SIZE - HEADER_SIZE - CRC_SIZE) / TARGET_SIZE;

// ---- UAV_INFO (common.xml id=12921, mavgen crc_extra=100) ----
constexpr uint32_t UAV_INFO_MSG_ID    = 12921;
constexpr uint8_t  UAV_INFO_CRC_EXTRA = 100;
constexpr uint8_t  UAV_INFO_LEN       = 45;

inline uint16_t get_u16(const uint8_t *b, int off)
{
    return static_cast<uint16_t>(b[off]) | static_cast<uint16_t>(b[off + 1] << 8);
}
inline uint32_t get_u32(const uint8_t *b, int off)
{
    return static_cast<uint32_t>(b[off]) | (static_cast<uint32_t>(b[off + 1]) << 8) |
           (static_cast<uint32_t>(b[off + 2]) << 16) | (static_cast<uint32_t>(b[off + 3]) << 24);
}
inline float get_float(const uint8_t *b, int off)
{
    uint32_t bits = get_u32(b, off);
    float v = 0.f;
    std::memcpy(&v, &bits, sizeof(v));
    return v;
}
inline int frame_size(int count) { return HEADER_SIZE + count * TARGET_SIZE + CRC_SIZE; }
} // namespace

Q_APPLICATION_STATIC(RadarBridge, _radarBridgeInstance);

RadarBridge::RadarBridge(QObject *parent)
    : QObject(parent)
{
}

RadarBridge::~RadarBridge()
{
}

RadarBridge *RadarBridge::instance()
{
    return _radarBridgeInstance();
}

void RadarBridge::init()
{
    _openLog();
    _log(QStringLiteral("init enter app_dir=%1").arg(QCoreApplication::applicationDirPath()));
    if (_socket) {
        _log(QStringLiteral("init skipped: socket already exists port=%1").arg(_listenPort));
        return;
    }

    _diagnostics = qgetenv("QGC_RADAR_DIAG") == "1";

    // 环境变量可覆盖默认监听端口与 CRC 模式
    const QByteArray portEnv = qgetenv("QGC_RADAR_PORT");
    if (!portEnv.isEmpty()) {
        bool ok = false;
        const uint p = portEnv.toUInt(&ok);
        if (ok && p > 0 && p <= 65535) {
            _listenPort = static_cast<quint16>(p);
        }
    }

    const QByteArray crcEnv = qgetenv("QGC_RADAR_CRC");
    if (!crcEnv.isEmpty()) {
        const QString c = QString::fromLatin1(crcEnv).trimmed().toLower();
        if (c == "none")        { _crcMode = CrcMode::None; }
        else if (c == "modbus") { _crcMode = CrcMode::Modbus; }
        else if (c == "ccitt" || c == "ccitt-false") { _crcMode = CrcMode::CcittFalse; }
        else if (c == "x25")    { _crcMode = CrcMode::X25; }
    }

    _forceTargetId = 0;
    const QByteArray forceIdEnv = qgetenv("QGC_RADAR_FORCE_ID").trimmed();
    if (!forceIdEnv.isEmpty()) {
        bool ok = false;
        const uint id = forceIdEnv.toUInt(&ok, 10);
        if (ok && !forceIdEnv.startsWith('-')) {
            _forceTargetId = id;
        } else {
            _log(QStringLiteral("invalid QGC_RADAR_FORCE_ID=%1; keeping original target IDs")
                     .arg(QString::fromLatin1(forceIdEnv)));
            qCWarning(RadarBridgeLog) << "Invalid QGC_RADAR_FORCE_ID; keeping original target IDs";
        }
    }

    _socket = new QUdpSocket(this);
    if (!_socket->bind(QHostAddress::AnyIPv4, _listenPort, QUdpSocket::ShareAddress)) {
        const QString error = _socket->errorString();
        _log(QStringLiteral("bind failed port=%1 error=%2").arg(_listenPort).arg(error));
        qCWarning(RadarBridgeLog) << "绑定 UDP 端口失败" << _listenPort << _socket->errorString();
        delete _socket;
        _socket = nullptr;
        if (_diagnostics) {
            emit diagnosticMessage(tr("RadarBridge bind failed"),
                                   tr("Port: %1\nError: %2\nLog: %3")
                                       .arg(_listenPort).arg(error, logFilePath()));
        }
        return;
    }

    connect(_socket, &QUdpSocket::readyRead, this, &RadarBridge::_readPendingDatagrams);
    qCInfo(RadarBridgeLog) << "RadarBridge 监听雷达协议帧 UDP 端口" << _listenPort
                           << "CRC=" << static_cast<int>(_crcMode);
    _log(QStringLiteral("bind ok port=%1 crc=%2 force_id=%3 env_port=%4 env_crc=%5")
             .arg(_listenPort).arg(static_cast<int>(_crcMode)).arg(_forceTargetId)
             .arg(QString::fromLatin1(portEnv), QString::fromLatin1(crcEnv)));
    if (_diagnostics) {
        emit diagnosticMessage(tr("RadarBridge init ok"),
                               tr("Port: %1\nCRC: %2\nForced target ID: %3\nLog: %4")
                                   .arg(_listenPort).arg(static_cast<int>(_crcMode))
                                   .arg(_forceTargetId).arg(logFilePath()));
    }
}

void RadarBridge::_openLog()
{
    if (_logFile.isOpen()) {
        return;
    }

    const QString fileName = QStringLiteral("qgc_radar_debug.txt");
    const QString appDataDir = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    QStringList candidates;
    const QString requested = qEnvironmentVariable("QGC_RADAR_LOG");
    if (!requested.isEmpty()) {
        candidates << requested;
    }
    candidates << QDir(QCoreApplication::applicationDirPath()).filePath(fileName);
    if (!appDataDir.isEmpty()) {
        candidates << QDir(appDataDir).filePath(fileName);
    }
    candidates << QDir(QStandardPaths::writableLocation(QStandardPaths::TempLocation)).filePath(fileName);
    candidates.removeDuplicates();

    for (const QString &path : candidates) {
        if (!appDataDir.isEmpty() && path == QDir(appDataDir).filePath(fileName)) {
            QDir().mkpath(appDataDir);
        }
        _logFile.setFileName(path);
        if (_logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qCInfo(RadarBridgeLog) << "RadarBridge file log:" << _logFile.fileName();
            return;
        }
    }
    qCWarning(RadarBridgeLog) << "RadarBridge file log failed, tried" << candidates;
}

void RadarBridge::_log(const QString &message)
{
    if (!_logFile.isOpen()) {
        return;
    }
    const QByteArray line = (QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd hh:mm:ss.zzz "))
                             + message + QLatin1Char('\n')).toUtf8();
    if (_logFile.write(line) != line.size() || !_logFile.flush()) {
        qCWarning(RadarBridgeLog) << "RadarBridge file log write failed:" << _logFile.errorString();
        _logFile.close();
    }
}

void RadarBridge::_readPendingDatagrams()
{
    while (_socket && _socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(static_cast<int>(_socket->pendingDatagramSize()));
        QHostAddress sender;
        quint16 senderPort = 0;
        const qint64 n = _socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        if (n <= 0) {
            _log(QStringLiteral("readDatagram failed n=%1 error=%2").arg(n).arg(_socket->errorString()));
            continue;
        }
        _log(QStringLiteral("udp rx len=%1 from=%2:%3 hex=%4")
                 .arg(n).arg(sender.toString()).arg(senderPort)
                 .arg(QString::fromLatin1(datagram.left(64).toHex(' '))));
        _processRadarFrame(reinterpret_cast<const uint8_t *>(datagram.constData()),
                           static_cast<int>(n));
    }
}

void RadarBridge::_processRadarFrame(const uint8_t *buffer, int length)
{
    RadarTarget targets[MAX_TARGETS];
    int count = 0;
    QString error;

    if (!_decodeRadarFrame(buffer, length, targets, MAX_TARGETS, count, error)) {
        ++_dropped;
        _log(QStringLiteral("decode failed dropped=%1 reason=%2 len=%3 hex=%4")
                 .arg(_dropped).arg(error).arg(length)
                 .arg(buffer && length > 0
                          ? QString::fromLatin1(QByteArray(reinterpret_cast<const char *>(buffer),
                                                          qMin(length, 64)).toHex(' '))
                          : QString()));
        if ((_dropped % 100) == 1) {
            qCWarning(RadarBridgeLog) << "丢弃无效雷达帧, 累计" << _dropped;
        }
        return;
    }

    ++_rxFrames;
    qCDebug(RadarBridgeLog) << "收到雷达帧, 目标数" << count << "rx_frames" << _rxFrames;
    _log(QStringLiteral("decode ok target_count=%1 rx_frames=%2").arg(count).arg(_rxFrames));

    for (int i = 0; i < count; ++i) {
        if (targets[i].delete_flag != 0) {
            _log(QStringLiteral("skip delete target id=%1").arg(targets[i].target_id));
            continue;
        }
        _sendUavInfo(targets[i]);
    }
}

bool RadarBridge::_decodeRadarFrame(const uint8_t *buffer, int length, RadarTarget *targets,
                                    int targetCapacity, int &targetCount, QString &error)
{
    targetCount = 0;
    error.clear();
    const auto fail = [&error](const QString &reason) { error = reason; return false; };
    if (!buffer) { return fail(QStringLiteral("null buffer")); }
    if (length < frame_size(1)) {
        return fail(QStringLiteral("too short length=%1 min=%2").arg(length).arg(frame_size(1)));
    }
    if (buffer[0] != FRAME_HEADER || buffer[3] != MESSAGE_TYPE || buffer[4] != RESERVED) {
        return fail(QStringLiteral("bad header b0=0x%1 b3=0x%2 b4=0x%3")
                        .arg(buffer[0], 2, 16, QLatin1Char('0'))
                        .arg(buffer[3], 2, 16, QLatin1Char('0')).arg(buffer[4], 2, 16, QLatin1Char('0')));
    }
    if (buffer[5] != 0xC5 || buffer[6] != 0xCE || buffer[7] != 0xC2) {
        return fail(QStringLiteral("bad identifier b5=0x%1 b6=0x%2 b7=0x%3")
                        .arg(buffer[5], 2, 16, QLatin1Char('0'))
                        .arg(buffer[6], 2, 16, QLatin1Char('0')).arg(buffer[7], 2, 16, QLatin1Char('0')));
    }
    if (buffer[1] != PAYLOAD_LENGTH_FIELD) {
        return fail(QStringLiteral("bad payload length field=0x%1").arg(buffer[1], 2, 16, QLatin1Char('0')));
    }

    const int count = buffer[18];
    if (count == 0 || count > MAX_TARGETS || count > targetCapacity) {
        return fail(QStringLiteral("bad target count=%1 max=%2 capacity=%3")
                        .arg(count).arg(MAX_TARGETS).arg(targetCapacity));
    }

    const int expected = frame_size(count);
    if (length != expected || static_cast<int>(get_u16(buffer, 16)) != expected) {
        return fail(QStringLiteral("bad length datagram=%1 field=%2 expected=%3")
                        .arg(length).arg(get_u16(buffer, 16)).arg(expected));
    }

    if (_crcMode != CrcMode::None) {
        const uint16_t got = get_u16(buffer, length - CRC_SIZE);
        // CRC covers payload length through payload data. Exclude the 0xFD frame header and CRC field itself.
        const uint16_t calc = _crc16(_crcMode, buffer + 1, length - CRC_SIZE - 1);
        if (got != calc) {
            return fail(QStringLiteral("bad crc got=0x%1 calc=0x%2 mode=%3")
                            .arg(got, 4, 16, QLatin1Char('0')).arg(calc, 4, 16, QLatin1Char('0'))
                            .arg(static_cast<int>(_crcMode)));
        }
    }

    for (int i = 0; i < count; ++i) {
        const uint8_t *t = &buffer[HEADER_SIZE + i * TARGET_SIZE];
        RadarTarget &out = targets[i];
        out.longitude_e7     = static_cast<int32_t>(get_u32(t, 0));
        out.latitude_e7      = static_cast<int32_t>(get_u32(t, 4));
        out.altitude_mm      = static_cast<int32_t>(get_u32(t, 8));
        out.target_id        = get_u16(t, 12);
        out.delete_flag      = get_u16(t, 14);
        out.speed_m_s        = get_float(t, 16);
        out.altitude_m       = get_float(t, 32);
        out.track_type       = t[36];
        out.target_attribute = t[37];
        out.vx_m_s           = get_float(t, 38);
        out.vy_m_s           = get_float(t, 42);
        out.vz_m_s           = get_float(t, 46);
    }
    targetCount = count;
    return true;
}

void RadarBridge::_sendUavInfo(const RadarTarget &target)
{
    Vehicle *vehicle = MultiVehicleManager::instance()->activeVehicle();
    if (!vehicle) {
        _log(QStringLiteral("drop target id=%1: no active vehicle").arg(target.target_id));
        qCDebug(RadarBridgeLog) << "无 active vehicle, 丢弃目标" << target.target_id;
        return;
    }

    WeakLinkInterfacePtr weakLink = vehicle->vehicleLinkManager()->primaryLink();
    if (weakLink.expired()) {
        _log(QStringLiteral("drop target id=%1: primary link expired active_vehicle=%2")
                 .arg(target.target_id).arg(vehicle->id()));
        return;
    }
    SharedLinkInterfacePtr sharedLink = weakLink.lock();
    if (!sharedLink) {
        _log(QStringLiteral("drop target id=%1: primary link lock failed active_vehicle=%2")
                 .arg(target.target_id).arg(vehicle->id()));
        return;
    }

    // 组装 UAV_INFO 45 字节载荷 (线序: mavid,group_id,lat,lon,yaw,yaw_speed,
    // rel_alt,vx,vy,vz,land 均在前 44 字节, is_leader 为最后 1 字节)
    const float lat = static_cast<float>(static_cast<double>(target.latitude_e7) * 1e-7);
    const float lon = static_cast<float>(static_cast<double>(target.longitude_e7) * 1e-7);
    const uint32_t mavId = _forceTargetId != 0 ? _forceTargetId : target.target_id;
    _log(QStringLiteral("prepare tx decoded_id=%1 mav_id=%2 force_id=%3 delete=%4 lon_e7=%5 lat_e7=%6")
             .arg(target.target_id).arg(mavId).arg(_forceTargetId).arg(target.delete_flag)
             .arg(target.longitude_e7).arg(target.latitude_e7));

    char buf[UAV_INFO_LEN];
    _mav_put_uint32_t(buf, 0,  mavId);            // 0 = 保留雷达编号; 非零强制覆盖
    _mav_put_uint32_t(buf, 4,  0);                // group_id
    _mav_put_float(buf, 8,  lat);
    _mav_put_float(buf, 12, lon);
    _mav_put_float(buf, 16, 0.f);                 // yaw
    _mav_put_float(buf, 20, 0.f);                 // yaw_speed
    _mav_put_float(buf, 24, target.altitude_m);   // rel_alt
    _mav_put_float(buf, 28, target.vx_m_s);
    _mav_put_float(buf, 32, target.vy_m_s);
    _mav_put_float(buf, 36, target.vz_m_s);
    _mav_put_uint32_t(buf, 40, 0);                // land
    _mav_put_uint8_t(buf, 44, 0);                 // is_leader=0 -> PX4 落到 follower_info.mavid=目标编号

    mavlink_message_t msg;
    std::memset(&msg, 0, sizeof(msg));
    std::memcpy(_MAV_PAYLOAD_NON_CONST(&msg), buf, UAV_INFO_LEN);
    msg.msgid = UAV_INFO_MSG_ID;

    const uint8_t sysid  = static_cast<uint8_t>(MAVLinkProtocol::instance()->getSystemId());
    const uint8_t compid = static_cast<uint8_t>(MAVLinkProtocol::getComponentId());

    mavlink_finalize_message_chan(&msg, sysid, compid, sharedLink->mavlinkChannel(),
                                  UAV_INFO_LEN, UAV_INFO_LEN, UAV_INFO_CRC_EXTRA);

    if (vehicle->sendMessageOnLinkThreadSafe(sharedLink.get(), msg)) {
        ++_txMessages;
        const double speed = std::sqrt(static_cast<double>(target.vx_m_s) * target.vx_m_s +
                                       static_cast<double>(target.vy_m_s) * target.vy_m_s +
                                       static_cast<double>(target.vz_m_s) * target.vz_m_s);
        qCDebug(RadarBridgeLog).nospace()
            << "-> UAV_INFO id=" << mavId
            << " lon=" << lon << " lat=" << lat
            << " alt=" << target.altitude_m << " speed=" << speed
            << " (tx=" << _txMessages << ")";
        _log(QStringLiteral("tx ok id=%1 vehicle=%2 chan=%3 sysid=%4 compid=%5 lon=%6 lat=%7 alt=%8 vx=%9 vy=%10 vz=%11 tx=%12")
                 .arg(mavId).arg(vehicle->id()).arg(sharedLink->mavlinkChannel()).arg(sysid).arg(compid)
                 .arg(lon, 0, 'f', 7).arg(lat, 0, 'f', 7).arg(target.altitude_m, 0, 'f', 3)
                 .arg(target.vx_m_s, 0, 'f', 3).arg(target.vy_m_s, 0, 'f', 3)
                 .arg(target.vz_m_s, 0, 'f', 3).arg(_txMessages));
    } else {
        _log(QStringLiteral("tx failed id=%1 vehicle=%2 chan=%3")
                 .arg(mavId).arg(vehicle->id()).arg(sharedLink->mavlinkChannel()));
    }
}

uint16_t RadarBridge::_crc16(CrcMode mode, const uint8_t *data, int length)
{
    switch (mode) {
    case CrcMode::None:
        return 0;

    case CrcMode::Modbus: {
        uint16_t crc = 0xFFFF;
        for (int i = 0; i < length; ++i) {
            crc ^= data[i];
            for (int bit = 0; bit < 8; ++bit) {
                crc = (crc & 1) ? static_cast<uint16_t>((crc >> 1) ^ 0xA001)
                                : static_cast<uint16_t>(crc >> 1);
            }
        }
        return crc;
    }

    case CrcMode::CcittFalse: {
        uint16_t crc = 0xFFFF;
        for (int i = 0; i < length; ++i) {
            crc ^= static_cast<uint16_t>(data[i] << 8);
            for (int bit = 0; bit < 8; ++bit) {
                crc = (crc & 0x8000) ? static_cast<uint16_t>((crc << 1) ^ 0x1021)
                                     : static_cast<uint16_t>(crc << 1);
            }
        }
        return crc;
    }

    case CrcMode::X25: {
        uint16_t crc = 0xFFFF;
        for (int i = 0; i < length; ++i) {
            crc ^= data[i];
            for (int bit = 0; bit < 8; ++bit) {
                crc = (crc & 1) ? static_cast<uint16_t>((crc >> 1) ^ 0x8408)
                                : static_cast<uint16_t>(crc >> 1);
            }
        }
        return static_cast<uint16_t>(crc ^ 0xFFFF);
    }
    }
    return 0;
}
