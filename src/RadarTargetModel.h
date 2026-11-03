#pragma once

#include <QtCore/QAbstractListModel>
#include <QtCore/QElapsedTimer>
#include <QtCore/QTimer>
#include <QtCore/QVector>

#include <cstdint>
#include <functional>
#include <limits>

/// Live radar targets keyed by their original radar ID. Classification is done by RadarBridge.
class RadarTargetModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    using Clock = std::function<qint64()>;
    static constexpr qint64 TargetTimeoutMs = 6000;

    struct Target {
        uint16_t id = 0;
        double latitude = std::numeric_limits<double>::quiet_NaN();
        double longitude = std::numeric_limits<double>::quiet_NaN();
        double altitude = std::numeric_limits<double>::quiet_NaN();
        double speed = std::numeric_limits<double>::quiet_NaN();
        double distance = std::numeric_limits<double>::quiet_NaN();
        double azimuth = std::numeric_limits<double>::quiet_NaN();
        double elevation = std::numeric_limits<double>::quiet_NaN();
        uint8_t trackType = 0;
        uint8_t targetAttribute = 0;
    };

    enum Role {
        TargetIdRole = Qt::UserRole + 1,
        LatitudeRole,
        LongitudeRole,
        AltitudeRole,
        SpeedRole,
        DistanceRole,
        AzimuthRole,
        ElevationRole,
        TrackTypeRole,
        TargetAttributeRole,
        AgeSecondsRole
    };
    Q_ENUM(Role)

    explicit RadarTargetModel(QObject *parent = nullptr, Clock clock = {});

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    int count() const { return static_cast<int>(_entries.size()); }

    void updateTarget(const Target &target);
    void removeTarget(uint16_t id);
    bool containsFreshTarget(uint16_t id) const;
    void expireTargets();

signals:
    void countChanged();

private:
    struct Entry {
        Target target;
        qint64 lastUpdateMs = 0;
    };

    int _findTarget(uint16_t id) const;
    qint64 _ageMs(const Entry &entry, qint64 now) const;

    QElapsedTimer _elapsed;
    Clock _clock;
    QTimer _expiryTimer;
    QVector<Entry> _entries;
};
