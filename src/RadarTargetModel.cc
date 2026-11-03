#include "RadarTargetModel.h"

#include <utility>

RadarTargetModel::RadarTargetModel(QObject *parent, Clock clock)
    : QAbstractListModel(parent)
    , _clock(std::move(clock))
{
    _elapsed.start();
    if (!_clock) {
        _clock = [this]() { return _elapsed.elapsed(); };
    }
    _expiryTimer.setInterval(250);
    connect(&_expiryTimer, &QTimer::timeout, this, &RadarTargetModel::expireTargets);
    _expiryTimer.start();
}

int RadarTargetModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : count();
}

QVariant RadarTargetModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.model() != this || index.column() != 0 ||
        index.row() < 0 || index.row() >= count()) {
        return {};
    }
    const Entry &entry = _entries[index.row()];
    const Target &target = entry.target;
    switch (role) {
    case TargetIdRole: return static_cast<int>(target.id);
    case LatitudeRole: return target.latitude;
    case LongitudeRole: return target.longitude;
    case AltitudeRole: return target.altitude;
    case SpeedRole: return target.speed;
    case DistanceRole: return target.distance;
    case AzimuthRole: return target.azimuth;
    case ElevationRole: return target.elevation;
    case TrackTypeRole: return static_cast<int>(target.trackType);
    case TargetAttributeRole: return static_cast<int>(target.targetAttribute);
    case AgeSecondsRole: return static_cast<double>(_ageMs(entry, _clock())) / 1000.0;
    default: return {};
    }
}

QHash<int, QByteArray> RadarTargetModel::roleNames() const
{
    return {
        {TargetIdRole, "targetId"}, {LatitudeRole, "latitude"}, {LongitudeRole, "longitude"},
        {AltitudeRole, "altitude"}, {SpeedRole, "speed"}, {DistanceRole, "distance"},
        {AzimuthRole, "azimuth"}, {ElevationRole, "elevation"}, {TrackTypeRole, "trackType"},
        {TargetAttributeRole, "targetAttribute"}, {AgeSecondsRole, "ageSeconds"}
    };
}

void RadarTargetModel::updateTarget(const Target &target)
{
    const int row = _findTarget(target.id);
    const Entry entry{target, _clock()};
    if (row >= 0) {
        _entries[row] = entry;
        emit dataChanged(index(row), index(row));
        return;
    }
    const int newRow = count();
    beginInsertRows({}, newRow, newRow);
    _entries.append(entry);
    endInsertRows();
    emit countChanged();
}

void RadarTargetModel::removeTarget(uint16_t id)
{
    const int row = _findTarget(id);
    if (row < 0) {
        return;
    }
    beginRemoveRows({}, row, row);
    _entries.removeAt(row);
    endRemoveRows();
    emit countChanged();
}

bool RadarTargetModel::containsFreshTarget(uint16_t id) const
{
    const int row = _findTarget(id);
    return row >= 0 && _ageMs(_entries[row], _clock()) < TargetTimeoutMs;
}

void RadarTargetModel::expireTargets()
{
    const qint64 now = _clock();
    bool removed = false;
    for (int row = count() - 1; row >= 0; --row) {
        if (_ageMs(_entries[row], now) >= TargetTimeoutMs) {
            beginRemoveRows({}, row, row);
            _entries.removeAt(row);
            endRemoveRows();
            removed = true;
        }
    }
    if (removed) {
        emit countChanged();
    }
    if (!_entries.isEmpty()) {
        emit dataChanged(index(0), index(count() - 1), {AgeSecondsRole});
    }
}

int RadarTargetModel::_findTarget(uint16_t id) const
{
    for (int row = 0; row < count(); ++row) {
        if (_entries[row].target.id == id) {
            return row;
        }
    }
    return -1;
}

qint64 RadarTargetModel::_ageMs(const Entry &entry, qint64 now) const
{
    return qMax(qint64(0), now - entry.lastUpdateMs);
}
