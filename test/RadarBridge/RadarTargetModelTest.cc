#include "RadarTargetModel.h"

#include <QtTest/QAbstractItemModelTester>
#include <QtTest/QSignalSpy>
#include <QtTest/QTest>
#include <cmath>

class RadarTargetModelTest : public QObject
{
    Q_OBJECT

private slots:
    void sameIdUpdatesInPlace()
    {
        qint64 now = 0;
        RadarTargetModel model(nullptr, [&now]() { return now; });
        QAbstractItemModelTester tester(&model, QAbstractItemModelTester::FailureReportingMode::QtTest);
        QSignalSpy inserts(&model, &QAbstractItemModel::rowsInserted);
        QSignalSpy resets(&model, &QAbstractItemModel::modelReset);
        QSignalSpy changes(&model, &QAbstractItemModel::dataChanged);
        RadarTargetModel::Target first;
        first.id = 17;
        first.latitude = 37.5;
        model.updateTarget(first);
        RadarTargetModel::Target second;
        second.id = 18;
        model.updateTarget(second);
        now = 1000;
        first.latitude = 37.6;
        first.longitude = 108.8;
        model.updateTarget(first);
        QCOMPARE(model.count(), 2);
        QCOMPARE(inserts.count(), 2);
        QCOMPARE(resets.count(), 0);
        QCOMPARE(changes.count(), 1);
        QCOMPARE(model.data(model.index(0), RadarTargetModel::TargetIdRole).toInt(), 17);
        QCOMPARE(model.data(model.index(0), RadarTargetModel::LatitudeRole).toDouble(), 37.6);
        QCOMPARE(model.data(model.index(1), RadarTargetModel::TargetIdRole).toInt(), 18);
        QCOMPARE(model.data(model.index(0), RadarTargetModel::AgeSecondsRole).toDouble(), 0.0);
    }

    void independentExpiryAndIdChanges()
    {
        qint64 now = 0;
        RadarTargetModel model(nullptr, [&now]() { return now; });
        QAbstractItemModelTester tester(&model, QAbstractItemModelTester::FailureReportingMode::QtTest);
        RadarTargetModel::Target first;
        first.id = 3;
        model.updateTarget(first);
        now = 1000;
        RadarTargetModel::Target second;
        second.id = 6;
        model.updateTarget(second);
        now = 5999;
        model.expireTargets();
        QCOMPARE(model.count(), 2);
        QVERIFY(model.containsFreshTarget(3));
        now = 6000;
        // Freshness is checked even before the next timer tick removes a row.
        QVERIFY(!model.containsFreshTarget(3));
        QVERIFY(model.containsFreshTarget(6));
        model.expireTargets();
        QCOMPARE(model.count(), 1);
        QCOMPARE(model.data(model.index(0), RadarTargetModel::TargetIdRole).toInt(), 6);
        now = 6500;
        model.updateTarget(second);
        now = 12500;
        model.expireTargets();
        QCOMPARE(model.count(), 0);
        QVERIFY(!model.containsFreshTarget(6));
        model.updateTarget(first);
        QCOMPARE(model.count(), 1);
        QVERIFY(model.containsFreshTarget(3));
    }

    void explicitRemovalAndUnknownFields()
    {
        qint64 now = 100;
        RadarTargetModel model(nullptr, [&now]() { return now; });
        QSignalSpy counts(&model, &RadarTargetModel::countChanged);
        RadarTargetModel::Target target;
        target.id = 65535;
        model.updateTarget(target);
        QCOMPARE(model.data(model.index(0), RadarTargetModel::TargetIdRole).toInt(), 65535);
        QVERIFY(std::isnan(model.data(model.index(0), RadarTargetModel::DistanceRole).toDouble()));
        model.removeTarget(1);
        QCOMPARE(counts.count(), 1);
        model.removeTarget(65535);
        QCOMPARE(model.count(), 0);
        QCOMPARE(counts.count(), 2);
        QVERIFY(!model.data({}).isValid());
    }

    void defaultClockAndTimerExpireTargets()
    {
        RadarTargetModel model;
        RadarTargetModel::Target target;
        target.id = 1;
        model.updateTarget(target);
        QVERIFY(model.containsFreshTarget(1));
        QTRY_VERIFY(model.data(model.index(0), RadarTargetModel::AgeSecondsRole).toDouble() > 0.0);

        qint64 now = 0;
        RadarTargetModel timed(nullptr, [&now]() { return now; });
        timed.updateTarget(target);
        now = RadarTargetModel::TargetTimeoutMs;
        QTRY_COMPARE_WITH_TIMEOUT(timed.count(), 0, 1000);
    }
};

QTEST_GUILESS_MAIN(RadarTargetModelTest)
#include "RadarTargetModelTest.moc"
