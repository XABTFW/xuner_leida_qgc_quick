#include "RadarBridge.h"
#include "QgcRadarTestStubs.h"

#include <QtCore/QTemporaryDir>
#include <QtCore/QtEndian>
#include <QtNetwork/QUdpSocket>
#include <QtTest/QTest>
#include <cstring>

class RadarFollowTest : public QObject
{
    Q_OBJECT

private:
    static QByteArray droneFrame(uint16_t id = 100, uint8_t classification = 0x20)
    {
        QByteArray frame(71, '\0');
        const auto header = QByteArray::fromHex("fd10000101c5cec2");
        std::memcpy(frame.data(), header.constData(), size_t(header.size()));
        qToLittleEndian<quint16>(71, frame.data() + 16);
        frame[18] = 1;
        char *target = frame.data() + 19;
        qToLittleEndian<qint32>(1088740000, target);
        qToLittleEndian<qint32>(375990000, target + 4);
        qToLittleEndian<quint16>(id, target + 12);
        target[36] = char(classification);
        target[37] = char(0x11);
        return frame;
    }

    void startBridge()
    {
        _bridge = std::make_unique<RadarBridge>();
        _bridge->init();
        QVERIFY(_bridge->receiving());
    }

    void receiveDrone()
    {
        QUdpSocket sender;
        const auto frame = droneFrame();
        QCOMPARE(sender.writeDatagram(frame, QHostAddress::LocalHost, _port), qint64(frame.size()));
        QTRY_VERIFY(_bridge->targets()->containsFreshTarget(100));
        // Ignore ordinary UAV_INFO forwarding when checking shell commands.
        _vehicle.sent.clear();
    }

    static std::vector<mavlink_serial_control_t> shellMessages(const Vehicle &vehicle)
    {
        std::vector<mavlink_serial_control_t> controls;
        for (const auto &message : vehicle.sent) {
            if (message.msgid == MAVLINK_MSG_ID_SERIAL_CONTROL) {
                mavlink_serial_control_t control{};
                mavlink_msg_serial_control_decode(&message, &control);
                controls.push_back(control);
            }
        }
        return controls;
    }

    static QByteArray command(const mavlink_serial_control_t &control)
    {
        return QByteArray(reinterpret_cast<const char *>(control.data), control.count);
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
        qputenv("QGC_RADAR_LOG", _temp->filePath("follow.txt").toUtf8());
        qunsetenv("QGC_RADAR_FORCE_ID");
        qunsetenv("QGC_RADAR_DIAG");
    }

    void cleanup()
    {
        _bridge.reset();
        MultiVehicleManager::instance()->vehicle = nullptr;
        _temp.reset();
    }

    void sendsCorrectCommandsInOrderAndReleasesShell()
    {
        startBridge();
        receiveDrone();
        QVERIFY(_bridge->followTarget(100));
        QVERIFY(_bridge->followBusy());
        QTRY_VERIFY_WITH_TIMEOUT(!_bridge->followBusy(), 2500);
        const auto messages = shellMessages(_vehicle);
        QCOMPARE(messages.size(), size_t(4));
        QCOMPARE(command(messages[0]), QByteArray("cooperative_rendezvous stop\n"));
        QCOMPARE(command(messages[1]), QByteArray("param set DYTG_TGT_ID 100\n"));
        QCOMPARE(command(messages[2]), QByteArray("cooperative_rendezvous start -r rendezvous -t 100 -T 5\n"));
        for (int index = 0; index < 3; ++index) {
            const auto &control = messages[size_t(index)];
            QCOMPARE(control.device, uint8_t(SERIAL_CONTROL_DEV_SHELL));
            QCOMPARE(control.target_system, uint8_t(2));
            QCOMPARE(control.target_component, uint8_t(1));
            QCOMPARE(control.flags, uint8_t(SERIAL_CONTROL_FLAG_EXCLUSIVE |
                                          SERIAL_CONTROL_FLAG_RESPOND | SERIAL_CONTROL_FLAG_MULTI));
            QVERIFY(control.count <= MAVLINK_MSG_SERIAL_CONTROL_FIELD_DATA_LEN);
        }
        QCOMPARE(messages[3].count, uint8_t(0));
        QCOMPARE(messages[3].flags, uint8_t(0));
        QCOMPARE(messages[3].target_system, uint8_t(2));
        QCOMPARE(messages[3].target_component, uint8_t(1));
    }

    void duplicateClickDoesNotInterleaveCommands()
    {
        startBridge();
        receiveDrone();
        QVERIFY(_bridge->followTarget(100));
        QVERIFY(!_bridge->followTarget(100));
        QCOMPARE(shellMessages(_vehicle).size(), size_t(1));
        QTRY_VERIFY_WITH_TIMEOUT(!_bridge->followBusy(), 2500);
        QCOMPARE(shellMessages(_vehicle).size(), size_t(4));
    }

    void unavailableTargetRejected()
    {
        startBridge();
        QVERIFY(!_bridge->followTarget(100));
        QVERIFY(!_bridge->followTarget(-1));
        QVERIFY(!_bridge->followTarget(65536));
        receiveDrone();
        _bridge->targets()->removeTarget(100);
        QVERIFY(!_bridge->followTarget(100));
        QVERIFY(shellMessages(_vehicle).empty());
        QVERIFY(!_bridge->followBusy());
    }

    void unavailableVehicleOrLinkRejected_data()
    {
        QTest::addColumn<int>("failure");
        QTest::newRow("no-active-vehicle") << 0;
        QTest::newRow("no-primary-link") << 1;
        QTest::newRow("disconnected-primary-link") << 2;
    }

    void unavailableVehicleOrLinkRejected()
    {
        QFETCH(int, failure);
        startBridge();
        receiveDrone();
        if (failure == 0) {
            MultiVehicleManager::instance()->vehicle = nullptr;
        } else if (failure == 1) {
            _vehicle.links.link.reset();
        } else {
            _vehicle.links.link->connected = false;
        }
        QVERIFY(!_bridge->followTarget(100));
        QVERIFY(!_bridge->followBusy());
        QVERIFY(shellMessages(_vehicle).empty());
    }

    void forceIdConflictRejected()
    {
        qputenv("QGC_RADAR_FORCE_ID", "200");
        startBridge();
        receiveDrone();
        QVERIFY(!_bridge->followTarget(100));
        QVERIFY(shellMessages(_vehicle).empty());
        QVERIFY(!_bridge->followBusy());
    }

    void changingVehicleCancelsRemainingCommands()
    {
        startBridge();
        receiveDrone();
        Vehicle otherVehicle;
        QVERIFY(_bridge->followTarget(100));
        MultiVehicleManager::instance()->vehicle = &otherVehicle;
        QTRY_VERIFY_WITH_TIMEOUT(!_bridge->followBusy(), 1500);
        const auto originalMessages = shellMessages(_vehicle);
        QCOMPARE(originalMessages.size(), size_t(2));
        QCOMPARE(command(originalMessages[0]), QByteArray("cooperative_rendezvous stop\n"));
        QCOMPARE(originalMessages[1].flags, uint8_t(0));
        QCOMPARE(originalMessages[1].count, uint8_t(0));
        QVERIFY(otherVehicle.sent.empty());
        MultiVehicleManager::instance()->vehicle = &_vehicle;
    }

    void changingPrimaryLinkCancelsRemainingCommands()
    {
        startBridge();
        receiveDrone();
        const auto originalLink = _vehicle.links.link;
        Q_UNUSED(originalLink); // Keep the original transport alive to verify shell release.
        QVERIFY(_bridge->followTarget(100));
        _vehicle.links.link = std::make_shared<LinkInterface>();
        QTRY_VERIFY_WITH_TIMEOUT(!_bridge->followBusy(), 1500);
        const auto messages = shellMessages(_vehicle);
        QCOMPARE(messages.size(), size_t(2));
        QCOMPARE(command(messages[0]), QByteArray("cooperative_rendezvous stop\n"));
        QCOMPARE(messages[1].count, uint8_t(0));
        QCOMPARE(messages[1].flags, uint8_t(0));
    }

    void lostTargetCancelsRemainingCommands()
    {
        startBridge();
        receiveDrone();
        QVERIFY(_bridge->followTarget(100));
        _bridge->targets()->removeTarget(100);
        QTRY_VERIFY_WITH_TIMEOUT(!_bridge->followBusy(), 1500);
        const auto messages = shellMessages(_vehicle);
        QCOMPARE(messages.size(), size_t(2));
        QCOMPARE(command(messages[0]), QByteArray("cooperative_rendezvous stop\n"));
        QCOMPARE(messages[1].count, uint8_t(0));
        QCOMPARE(messages[1].flags, uint8_t(0));
    }
};

QTEST_GUILESS_MAIN(RadarFollowTest)
#include "RadarFollowTest.moc"
