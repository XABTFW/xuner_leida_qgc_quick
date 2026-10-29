#include "RadarBridge.h"
#include "QgcRadarTestStubs.h"

#include <QtCore/QTemporaryDir>
#include <QtCore/QtEndian>
#include <QtNetwork/QUdpSocket>
#include <QtTest/QSignalSpy>
#include <QtTest/QTest>
#include <cstring>

class RadarBridgeTest : public QObject
{
    Q_OBJECT
private:
    static QByteArray frame(int count = 1)
    {
        QByteArray bytes(19 + count * 50 + 2, '\0');
        const QByteArray header = QByteArray::fromHex("fd10000101c5cec2");
        std::memcpy(bytes.data(), header.constData(), header.size());
        qToLittleEndian<quint16>(quint16(bytes.size()), bytes.data() + 16);
        bytes[18] = char(count);
        for (int i = 0; i < count; ++i) {
            char *target = bytes.data() + 19 + i * 50;
            qToLittleEndian<qint32>(1088740000, target);
            qToLittleEndian<qint32>(375990000, target + 4);
            qToLittleEndian<qint32>(1360000, target + 8);
            qToLittleEndian<quint16>(quint16(100 + i), target + 12);
            const auto putFloat = [target](int offset, float value) {
                quint32 bits;
                std::memcpy(&bits, &value, sizeof(bits));
                qToLittleEndian(bits, target + offset);
            };
            putFloat(16, 1.f);
            putFloat(32, 1360.f);
            putFloat(38, 1.f);
            putFloat(42, 2.f);
            putFloat(46, 3.f);
        }
        return bytes;
    }

    void start()
    {
        _bridge = std::make_unique<RadarBridge>();
        _bridge->init();
        QVERIFY(!_bridge->logFilePath().isEmpty());
    }
    void send(const QByteArray &bytes)
    {
        QUdpSocket sender;
        QCOMPARE(sender.writeDatagram(bytes, QHostAddress::LocalHost, _port), qint64(bytes.size()));
    }
    QString log() const
    {
        QFile file(_bridge->logFilePath());
        if (!file.open(QIODevice::ReadOnly)) { return {}; }
        return QString::fromUtf8(file.readAll());
    }

    std::unique_ptr<QTemporaryDir> _temp;
    std::unique_ptr<RadarBridge> _bridge;
    Vehicle _vehicle;
    quint16 _port = 0;

private slots:
    void init()
    {
        _temp = std::make_unique<QTemporaryDir>();
        QVERIFY(_temp->isValid());
        QUdpSocket probe;
        QVERIFY(probe.bind(QHostAddress::LocalHost, 0));
        _port = probe.localPort();
        _vehicle.sent.clear();
        _vehicle.links.link = std::make_shared<LinkInterface>();
        MultiVehicleManager::instance()->vehicle = &_vehicle;
        qputenv("QGC_RADAR_PORT", QByteArray::number(_port));
        qputenv("QGC_RADAR_CRC", "none");
        qputenv("QGC_RADAR_LOG", _temp->filePath(QStringLiteral("雷达.txt")).toUtf8());
        qunsetenv("QGC_RADAR_FORCE_ID");
        qunsetenv("QGC_RADAR_DIAG");
    }
    void cleanup()
    {
        _bridge.reset();
        _temp.reset();
        MultiVehicleManager::instance()->vehicle = nullptr;
    }

    void targetId_data()
    {
        QTest::addColumn<QByteArray>("setting");
        QTest::addColumn<quint32>("expected");
        QTest::newRow("unset") << QByteArray() << quint32(100);
        QTest::newRow("zero") << QByteArray("0") << quint32(100);
        QTest::newRow("package-value") << QByteArray("32123") << quint32(32123);
        QTest::newRow("wider-than-radar-id") << QByteArray("65536") << quint32(65536);
        QTest::newRow("uint32-max") << QByteArray("4294967295") << quint32(4294967295U);
        QTest::newRow("whitespace") << QByteArray(" 32123 ") << quint32(32123);
        QTest::newRow("negative") << QByteArray("-1") << quint32(100);
        QTest::newRow("overflow") << QByteArray("4294967296") << quint32(100);
        QTest::newRow("invalid") << QByteArray("radar") << quint32(100);
    }
    void targetId()
    {
        QFETCH(QByteArray, setting);
        QFETCH(quint32, expected);
        qputenv("QGC_RADAR_FORCE_ID", setting);
        start();
        send(frame());
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
        const auto &message = _vehicle.sent.front();
        QCOMPARE(message.msgid, quint32(12921));
        // MAVLink 2 trims the five trailing zero bytes (land/is_leader) on the wire.
        QCOMPARE(message.len, quint8(40));
        QCOMPARE(message.sysid, quint8(255));
        QCOMPARE(message.compid, quint8(190));
        QCOMPARE(_MAV_RETURN_uint32_t(&message, 0), expected);
        QCOMPARE(_MAV_RETURN_float(&message, 24), 1360.f);
        QCOMPARE(_MAV_RETURN_float(&message, 28), 1.f);
        QCOMPARE(_MAV_RETURN_float(&message, 32), 2.f);
        QCOMPARE(_MAV_RETURN_float(&message, 36), 3.f);
        QVERIFY(log().contains(QStringLiteral("decoded_id=100 mav_id=%1").arg(expected)));
        QVERIFY(log().contains(QStringLiteral("tx ok id=%1").arg(expected)));
        // Verify the actual MAVLink encoder's checksum including the overridden ID.
        uint8_t wire[MAVLINK_MAX_PACKET_LEN];
        const int size = mavlink_msg_to_send_buffer(wire, &message);
        uint16_t crc = crc_calculate(wire + 1, uint16_t(size - 3));
        crc_accumulate(100, &crc);
        QCOMPARE(qFromLittleEndian<quint16>(wire + size - 2), crc);
    }

    void deletedTargetsAreNotForwarded()
    {
        qputenv("QGC_RADAR_FORCE_ID", "32123");
        start();
        auto bytes = frame(2);
        qToLittleEndian<quint16>(1, bytes.data() + 19 + 14);
        send(bytes);
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
        QVERIFY(log().contains("skip delete target id=100"));
        QVERIFY(log().contains("decoded_id=101 mav_id=32123"));
    }

    void crc_data()
    {
        QTest::addColumn<QByteArray>("mode");
        QTest::addColumn<quint16>("checksum");
        // Fixed independently computed reference vectors for frame(), excluding 0xFD.
        QTest::newRow("modbus") << QByteArray("modbus") << quint16(0xc5e3);
        QTest::newRow("ccitt") << QByteArray("ccitt") << quint16(0xa77d);
        QTest::newRow("ccitt-false") << QByteArray("ccitt-false") << quint16(0xa77d);
        QTest::newRow("x25") << QByteArray("x25") << quint16(0xfe2b);
    }
    void crc()
    {
        QFETCH(QByteArray, mode);
        QFETCH(quint16, checksum);
        qputenv("QGC_RADAR_CRC", mode);
        start();
        auto bytes = frame();
        qToLittleEndian(checksum, bytes.data() + bytes.size() - 2);
        send(bytes);
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
        bytes[22] = char(bytes.at(22) ^ 1);
        send(bytes);
        QTRY_VERIFY(log().contains("reason=bad crc got=0x"));
        QCOMPARE(_vehicle.sent.size(), size_t(1));
    }

    void malformedFrames_data()
    {
        QTest::addColumn<int>("offset");
        QTest::addColumn<QByteArray>("reason");
        QTest::newRow("header") << 0 << QByteArray("bad header");
        QTest::newRow("identifier") << 5 << QByteArray("bad identifier");
        QTest::newRow("payload-field") << 1 << QByteArray("bad payload length field");
        QTest::newRow("count") << 18 << QByteArray("bad target count");
        QTest::newRow("length") << 16 << QByteArray("bad length");
        QTest::newRow("short") << -1 << QByteArray("too short");
    }
    void malformedFrames()
    {
        QFETCH(int, offset);
        QFETCH(QByteArray, reason);
        start();
        auto bytes = frame();
        if (offset < 0) { bytes.truncate(10); }
        else { bytes[offset] = 0; }
        send(bytes);
        QTRY_VERIFY(log().contains("reason=" + QString::fromLatin1(reason)));
        QVERIFY(_vehicle.sent.empty());
        QVERIFY(log().contains("from=127.0.0.1:"));
    }

    void unavailableLink_data()
    {
        QTest::addColumn<int>("state");
        QTest::addColumn<QByteArray>("reason");
        QTest::newRow("no-vehicle") << 0 << QByteArray("no active vehicle");
        QTest::newRow("no-link") << 1 << QByteArray("primary link expired");
        QTest::newRow("disconnected") << 2 << QByteArray("tx failed id=100");
    }
    void unavailableLink()
    {
        QFETCH(int, state);
        QFETCH(QByteArray, reason);
        if (state == 0) { MultiVehicleManager::instance()->vehicle = nullptr; }
        if (state == 1) { _vehicle.links.link.reset(); }
        if (state == 2) { _vehicle.links.link->connected = false; }
        start();
        send(frame());
        QTRY_VERIFY(log().contains(QString::fromLatin1(reason)));
        QVERIFY(_vehicle.sent.empty());
    }

    void diagnostics_data()
    {
        QTest::addColumn<QByteArray>("setting");
        QTest::addColumn<int>("messages");
        QTest::newRow("unset") << QByteArray() << 0;
        QTest::newRow("zero") << QByteArray("0") << 0;
        QTest::newRow("one") << QByteArray("1") << 1;
        QTest::newRow("other") << QByteArray("true") << 0;
    }
    void diagnostics()
    {
        QFETCH(QByteArray, setting);
        QFETCH(int, messages);
        qputenv("QGC_RADAR_DIAG", setting);
        _bridge = std::make_unique<RadarBridge>();
        QSignalSpy spy(_bridge.get(), &RadarBridge::diagnosticMessage);
        _bridge->init();
        QCOMPARE(spy.count(), messages);
        if (messages) { QVERIFY(spy.front().at(1).toString().contains(_bridge->logFilePath())); }
    }

    void reinitializationKeepsRunningConfiguration()
    {
        qputenv("QGC_RADAR_FORCE_ID", "32123");
        start();
        qputenv("QGC_RADAR_FORCE_ID", "999");
        qputenv("QGC_RADAR_PORT", "1");
        _bridge->init();
        send(frame());
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
        QCOMPARE(_MAV_RETURN_uint32_t(&_vehicle.sent.front(), 0), quint32(32123));
        QVERIFY(log().contains("init skipped: socket already exists"));
    }

    void bindFailureReportsAndCanRetry()
    {
        QUdpSocket occupied;
        QVERIFY(occupied.bind(QHostAddress::AnyIPv4, _port, QUdpSocket::DontShareAddress));
        qputenv("QGC_RADAR_DIAG", "1");
        qputenv("QGC_RADAR_FORCE_ID", "32123");
        _bridge = std::make_unique<RadarBridge>();
        QSignalSpy spy(_bridge.get(), &RadarBridge::diagnosticMessage);
        _bridge->init();
        QCOMPARE(spy.count(), 1);
        QVERIFY(spy.front().at(0).toString().contains("bind failed"));
        QVERIFY(log().contains("bind failed port="));

        occupied.close();
        qputenv("QGC_RADAR_FORCE_ID", "invalid");
        _bridge->init();
        QCOMPARE(spy.count(), 2);
        QVERIFY(spy.back().at(0).toString().contains("init ok"));
        send(frame());
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
        QCOMPARE(_MAV_RETURN_uint32_t(&_vehicle.sent.front(), 0), quint32(100));
    }

    void logAppendsAcrossRestart()
    {
        start();
        send(frame());
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
        _bridge.reset();
        start();
        QVERIFY(log().contains("tx ok id=100"));
        QCOMPARE(log().count("init enter app_dir="), 2);
    }

    void unwritableCustomLogFallsBack()
    {
        qputenv("QGC_RADAR_LOG", _temp->path().toUtf8()); // A directory cannot be opened as a file.
        start();
        QVERIFY(_bridge->logFilePath() != _temp->path());
        QVERIFY(_bridge->logFilePath().endsWith("qgc_radar_debug.txt"));
        send(frame());
        QTRY_COMPARE(_vehicle.sent.size(), size_t(1));
    }
};

QTEST_GUILESS_MAIN(RadarBridgeTest)
#include "RadarBridgeTest.moc"
