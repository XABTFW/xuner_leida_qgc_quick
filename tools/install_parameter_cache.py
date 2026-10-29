#!/usr/bin/env python3
"""Portable PX4 parameter-cache patch for the matching Qt6/QGroundControl source family.

Python 3.8+ standard library only; no Git, downloads, firmware/parameter writes,
or automatic builds. Copy this single file to the other computer.

Preview: python3 install_parameter_cache.py --source /path/to/qgc --diff
Install: python3 install_parameter_cache.py --source /path/to/qgc --apply
Restore: python3 install_parameter_cache.py --source /path/to/qgc --rollback BACKUP --apply

Other QGC versions/customizations are refused if exact patch contexts differ.
Rebuild QGC and launch the newly built executable after installation/restoration.
The payload encodes context replacements only, never executable Python code.
"""

import argparse
import datetime
import difflib
import hashlib
import json
import os
from pathlib import Path
import stat
import sys
import tempfile


PATCH_ID = 'px4-verified-parameter-cache-v1'
PATCHES = json.loads(r'''[{"file":"src/FactSystem/ParameterManager.cc","name":"atomic-file-include","old":"#include <QtCore/QFile>\n","new":"#include <QtCore/QFile>\n#include <QtCore/QSaveFile>\n"},{"file":"src/FactSystem/ParameterManager.cc","name":"cache-timers","old":"    // Ensure the cache directory exists\n    (void) QFileInfo(QSettings().fileName()).dir().mkdir(\"ParamCache\");","new":"    // Ensure the cache directory exists\n    (void) QDir().mkpath(parameterCacheDir().absolutePath());\n\n    _cacheHashTimeoutTimer.setSingleShot(true);\n    _cacheHashTimeoutTimer.setInterval(1500);\n    connect(&_cacheHashTimeoutTimer, &QTimer::timeout, this, [this] {\n        if (!_initialLoadComplete) {\n            qCInfo(ParameterManagerLog) << \"Parameter cache hash timed out; downloading parameters\";\n            refreshAllParameters();\n        }\n    });\n    _cacheWriteTimer.setSingleShot(true);\n    _cacheWriteTimer.setInterval(250);\n    connect(&_cacheWriteTimer, &QTimer::timeout, this, [this] {\n        for (const int componentId: _confirmedCacheValues.keys()) {\n            _writeLocalParamCache(_vehicle->id(), componentId);\n        }\n    });"},{"file":"src/FactSystem/ParameterManager.cc","name":"hash-response","old":"            _tryCacheHashLoad(_vehicle->id(), componentId, parameterValue);","new":"            const bool hashOnlyRequest = _cacheHashTimeoutTimer.isActive() && componentId == _vehicle->defaultComponentId();\n            if (hashOnlyRequest) {\n                _cacheHashTimeoutTimer.stop();\n            }\n            const bool loaded = _tryCacheHashLoad(_vehicle->id(), componentId, parameterValue, parameterCount);\n            if (hashOnlyRequest && !loaded) {\n                refreshAllParameters();\n            }"},{"file":"src/FactSystem/ParameterManager.cc","name":"confirmed-values","old":"    fact->containerSetRawValue(parameterValue);\n\n    // Update param cache. The param cache is only used on PX4 Firmware since ArduPilot and Solo have volatile params","new":"    fact->containerSetRawValue(parameterValue);\n\n    _confirmedCacheValues[componentId][parameterName] = ParamTypeVal(fact->type(), parameterValue);\n\n    // Update param cache. The param cache is only used on PX4 Firmware since ArduPilot and Solo have volatile params"},{"file":"src/FactSystem/ParameterManager.cc","name":"deferred-safe-cache-write","old":"    if (!_logReplay && _vehicle->px4Firmware()) {\n        if (((_prevWaitingReadParamIndexCount + _prevWaitingReadParamNameCount) != 0) && (readWaitingParamCount == 0)) {\n            // All reads just finished, update the cache\n            _writeLocalParamCache(_vehicle->id(), componentId);\n        }\n    }","new":"    if (!_logReplay && _vehicle->px4Firmware() && !_loadingFromCache && readWaitingParamCount == 0) {\n        // Coalesce updates, including acknowledged writes after the first load.\n        // The writer independently checks completeness for every component.\n        _cacheWriteTimer.start();\n    }"},{"file":"src/FactSystem/ParameterManager.cc","name":"hash-before-full-list","old":"    if (_tryftp && ((componentId == MAV_COMP_ID_ALL) || (componentId == MAV_COMP_ID_AUTOPILOT1))) {","new":"    if (!_initialLoadComplete && !_logReplay && _vehicle->px4Firmware() && !_cacheHashAttempted &&\n            (componentId == MAV_COMP_ID_ALL || componentId == _vehicle->defaultComponentId()) &&\n            QFileInfo::exists(_vehicleCacheFile(_vehicle->defaultComponentId()))) {\n        _cacheHashAttempted = true;\n        _cacheHashTimeoutTimer.start();\n        qCInfo(ParameterManagerLog) << \"Checking parameter cache before requesting full list\"\n                                   << _vehicleCacheFile(_vehicle->defaultComponentId());\n        _readParameterRaw(_vehicle->defaultComponentId(), QStringLiteral(\"_HASH_CHECK\"), -1);\n        return;\n    }\n\n    if (_tryftp && ((componentId == MAV_COMP_ID_ALL) || (componentId == MAV_COMP_ID_AUTOPILOT1))) {"},{"file":"src/FactSystem/ParameterManager.cc","name":"fresh-download-completeness","old":"    } else {\n        // Reset index wait lists","new":"    } else {\n        // A new full download must earn completeness again. Old Facts remain\n        // available for the UI, but are not evidence that this download worked.\n        for (const int cid: _confirmedCacheValues.keys()) {\n            if (componentId == MAV_COMP_ID_ALL || componentId == cid) {\n                _confirmedCacheValues[cid].clear();\n                _failedReadParamIndexMap[cid].clear();\n            }\n        }\n        // Reset index wait lists"},{"file":"src/FactSystem/ParameterManager.cc","name":"complete-atomic-cache","old":"void ParameterManager::_writeLocalParamCache(int vehicleId, int componentId)\n{\n    CacheMapName2ParamTypeVal cacheMap;\n\n    for (const QString &paramName: _mapCompId2FactMap[componentId].keys()) {\n        const Fact *const fact = _mapCompId2FactMap[componentId][paramName];\n        cacheMap[paramName] = ParamTypeVal(fact->type(), fact->rawValue());\n    }\n\n    QFile cacheFile(parameterCacheFile(vehicleId, componentId));\n    if (cacheFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {\n        QDataStream ds(&cacheFile);\n        ds << cacheMap;\n    } else {\n        qCWarning(ParameterManagerLog) << \"Failed to open cache file for writing\" << cacheFile.fileName();\n    }\n}","new":"void ParameterManager::_writeLocalParamCache(int vehicleId, int componentId)\n{\n    Q_UNUSED(vehicleId);\n    const CacheMapName2ParamTypeVal &cacheMap = _confirmedCacheValues[componentId];\n    if (_loadingFromCache || _paramCountMap.value(componentId) <= 0 ||\n            cacheMap.count() != _paramCountMap.value(componentId) ||\n            !_waitingReadParamIndexMap.value(componentId).isEmpty() ||\n            !_waitingReadParamNameMap.value(componentId).isEmpty() ||\n            !_waitingWriteParamNameMap.value(componentId).isEmpty() ||\n            !_failedReadParamIndexMap.value(componentId).isEmpty()) {\n        return; // Never overwrite a complete cache with a partial/failed download.\n    }\n\n    const QString path = _vehicleCacheFile(componentId);\n    if (!QDir().mkpath(QFileInfo(path).absolutePath())) {\n        qCWarning(ParameterManagerLog) << \"Failed to create parameter cache directory\" << path;\n        return;\n    }\n    QSaveFile cacheFile(path);\n    if (cacheFile.open(QIODevice::WriteOnly)) {\n        QDataStream ds(&cacheFile);\n        ds << cacheMap;\n        if (ds.status() != QDataStream::Ok) {\n            cacheFile.cancelWriting();\n            qCWarning(ParameterManagerLog) << \"Failed to serialize parameter cache\" << path;\n        } else if (!cacheFile.commit()) {\n            qCWarning(ParameterManagerLog) << \"Failed to commit parameter cache\" << path;\n        } else {\n            qCInfo(ParameterManagerLog) << \"Saved complete parameter cache\" << path << cacheMap.count();\n        }\n    } else {\n        qCWarning(ParameterManagerLog) << \"Failed to open cache file for writing\" << cacheFile.fileName();\n    }\n}"},{"file":"src/FactSystem/ParameterManager.cc","name":"validated-uid-cache-load","old":"void ParameterManager::_tryCacheHashLoad(int vehicleId, int componentId, const QVariant &hashValue)\n{\n    qCInfo(ParameterManagerLog) << \"Attemping load from cache\";\n\n    /* The datastructure of the cache table */\n    CacheMapName2ParamTypeVal cacheMap;\n    QFile cacheFile(parameterCacheFile(vehicleId, componentId));\n    if (!cacheFile.exists()) {\n        /* no local cache, just wait for them to come in*/\n        return;\n    }\n    (void) cacheFile.open(QIODevice::ReadOnly);\n\n    /* Deserialize the parameter cache table */\n    QDataStream ds(&cacheFile);\n    ds >> cacheMap;\n\n    /* compute the crc of the local cache to check against the remote */\n    uint32_t crc32_value = 0;\n    for (const QString &name: cacheMap.keys()) {\n        const ParamTypeVal &paramTypeVal = cacheMap[name];\n        const FactMetaData::ValueType_t factType = static_cast<FactMetaData::ValueType_t>(paramTypeVal.first);\n\n        if (_vehicle->compInfoManager()->compInfoParam(MAV_COMP_ID_AUTOPILOT1)->factMetaDataForName(name, factType)->volatileValue()) {\n            // Does not take part in CRC\n            qCDebug(ParameterManagerLog) << \"Volatile parameter\" << name;\n        } else {\n            const void *const vdat = paramTypeVal.second.constData();\n            const FactMetaData::ValueType_t factType = static_cast<FactMetaData::ValueType_t>(paramTypeVal.first);\n            crc32_value = QGC::crc32(reinterpret_cast<const uint8_t *>(qPrintable(name)), name.length(),  crc32_value);\n            crc32_value = QGC::crc32(static_cast<const uint8_t *>(vdat), FactMetaData::typeToSize(factType), crc32_value);\n        }\n    }\n\n    /* if the two param set hashes match, just load from the disk */\n    if (crc32_value == hashValue.toUInt()) {\n        qCInfo(ParameterManagerLog) << \"Parameters loaded from cache\" << qPrintable(QFileInfo(cacheFile).absoluteFilePath());\n\n        const int count = cacheMap.count();\n        int index = 0;\n        for (const QString &name: cacheMap.keys()) {\n            const ParamTypeVal &paramTypeVal = cacheMap[name];\n            const FactMetaData::ValueType_t factType = static_cast<FactMetaData::ValueType_t>(paramTypeVal.first);\n            const MAV_PARAM_TYPE mavParamType = factTypeToMavType(factType);\n            _handleParamValue(componentId, name, count, index++, mavParamType, paramTypeVal.second);\n        }\n\n        const SharedLinkInterfacePtr sharedLink = _vehicle->vehicleLinkManager()->primaryLink().lock();\n        if (sharedLink) {\n            mavlink_param_set_t p{};\n            mavlink_param_union_t union_value{};\n\n            // Return the hash value to notify we don't want any more updates\n            p.param_type = MAV_PARAM_TYPE_UINT32;\n            (void) strncpy(p.param_id, \"_HASH_CHECK\", sizeof(p.param_id));\n            union_value.param_uint32 = crc32_value;\n            p.param_value = union_value.param_float;\n            p.target_system = static_cast<uint8_t>(_vehicle->id());\n            p.target_component = static_cast<uint8_t>(componentId);\n\n            mavlink_message_t msg{};\n            (void) mavlink_msg_param_set_encode_chan(MAVLinkProtocol::instance()->getSystemId(),\n                                                     MAVLinkProtocol::getComponentId(),\n                                                     sharedLink->mavlinkChannel(),\n                                                     &msg,\n                                                     &p);\n            (void) _vehicle->sendMessageOnLinkThreadSafe(sharedLink.get(), msg);\n        }\n\n        // Give the user some feedback things loaded properly\n        QVariantAnimation *const ani = new QVariantAnimation(this);\n        ani->setEasingCurve(QEasingCurve::OutCubic);\n        ani->setStartValue(0.0);\n        ani->setEndValue(1.0);\n        ani->setDuration(750);\n\n        (void) connect(ani, &QVariantAnimation::valueChanged, this, [this](const QVariant &value) {\n            _setLoadProgress(value.toDouble());\n        });\n\n        // Hide 500ms after animation finishes\n        connect(ani, &QVariantAnimation::finished, this, [this] {\n            QTimer::singleShot(500, [this] {\n                _setLoadProgress(0);\n            });\n        });\n\n        ani->start(QAbstractAnimation::DeleteWhenStopped);\n    } else {\n        qCInfo(ParameterManagerLog) << \"Parameters cache match failed\" << qPrintable(QFileInfo(cacheFile).absoluteFilePath());\n        if (ParameterManagerDebugCacheFailureLog().isDebugEnabled()) {\n            _debugCacheCRC[componentId] = true;\n            _debugCacheMap[componentId] = cacheMap;\n            for (const QString &name: cacheMap.keys()) {\n                _debugCacheParamSeen[componentId][name] = false;\n            }\n            qgcApp()->showAppMessage(tr(\"Parameter cache CRC match failed\"));\n        }\n    }\n}","new":"QString ParameterManager::_vehicleCacheFile(int componentId) const\n{\n    // UID is known before the initial parameter request. Retain SYSID as well\n    // because SITL instances may advertise the same hardware UID. If no UID is\n    // available, the remote CRC still MUST match before a SYSID cache is used.\n    const quint64 uid = _vehicle->vehicleUID();\n    if (uid != 0) {\n        return parameterCacheDir().filePath(QStringLiteral(\"uid_%1/%2_%3.v2\")\n                                          .arg(uid, 0, 16).arg(_vehicle->id()).arg(componentId));\n    }\n    return parameterCacheFile(_vehicle->id(), componentId);\n}\n\nbool ParameterManager::_tryCacheHashLoad(int vehicleId, int componentId, const QVariant &hashValue, int parameterCount)\n{\n    Q_UNUSED(vehicleId);\n    qCInfo(ParameterManagerLog) << \"Attemping load from cache\";\n\n    /* The datastructure of the cache table */\n    CacheMapName2ParamTypeVal cacheMap;\n    QFile cacheFile(_vehicleCacheFile(componentId));\n    if (!cacheFile.exists()) {\n        /* no local cache, just wait for them to come in*/\n        return false;\n    }\n    if (!cacheFile.open(QIODevice::ReadOnly)) {\n        return false;\n    }\n\n    /* Deserialize the parameter cache table */\n    QDataStream ds(&cacheFile);\n    ds >> cacheMap;\n    if (ds.status() != QDataStream::Ok || cacheMap.isEmpty() ||\n            (parameterCount > 0 && parameterCount != cacheMap.count())) {\n        qCWarning(ParameterManagerLog) << \"Incomplete or corrupt parameter cache; downloading\" << cacheFile.fileName();\n        return false;\n    }\n\n    /* compute the crc of the local cache to check against the remote */\n    uint32_t crc32_value = 0;\n    for (const QString &name: cacheMap.keys()) {\n        const ParamTypeVal &paramTypeVal = cacheMap[name];\n        const FactMetaData::ValueType_t factType = static_cast<FactMetaData::ValueType_t>(paramTypeVal.first);\n\n        // PX4's parameter protocol supports INT32 and REAL32. Validate the\n        // serialized variant before using its raw bytes for the CRC.\n        if (!((factType == FactMetaData::valueTypeInt32 && paramTypeVal.second.metaType().id() == QMetaType::Int) ||\n              (factType == FactMetaData::valueTypeFloat && paramTypeVal.second.metaType().id() == QMetaType::Float))) {\n            qCWarning(ParameterManagerLog) << \"Unsupported parameter cache type\" << name;\n            return false;\n        }\n\n        if (_vehicle->compInfoManager()->compInfoParam(componentId)->factMetaDataForName(name, factType)->volatileValue()) {\n            // Does not take part in CRC\n            qCDebug(ParameterManagerLog) << \"Volatile parameter\" << name;\n        } else {\n            const void *const vdat = paramTypeVal.second.constData();\n            const FactMetaData::ValueType_t factType = static_cast<FactMetaData::ValueType_t>(paramTypeVal.first);\n            crc32_value = QGC::crc32(reinterpret_cast<const uint8_t *>(qPrintable(name)), name.length(),  crc32_value);\n            crc32_value = QGC::crc32(static_cast<const uint8_t *>(vdat), FactMetaData::typeToSize(factType), crc32_value);\n        }\n    }\n\n    /* if the two param set hashes match, just load from the disk */\n    if (crc32_value == hashValue.toUInt()) {\n        qCInfo(ParameterManagerLog) << \"Parameters loaded from cache\" << qPrintable(QFileInfo(cacheFile).absoluteFilePath());\n\n        const int count = cacheMap.count();\n        int index = 0;\n        _loadingFromCache = true;\n        for (const QString &name: cacheMap.keys()) {\n            const ParamTypeVal &paramTypeVal = cacheMap[name];\n            const FactMetaData::ValueType_t factType = static_cast<FactMetaData::ValueType_t>(paramTypeVal.first);\n            const MAV_PARAM_TYPE mavParamType = factTypeToMavType(factType);\n            _handleParamValue(componentId, name, count, index++, mavParamType, paramTypeVal.second);\n        }\n        _loadingFromCache = false;\n\n        const SharedLinkInterfacePtr sharedLink = _vehicle->vehicleLinkManager()->primaryLink().lock();\n        if (sharedLink) {\n            mavlink_param_set_t p{};\n            mavlink_param_union_t union_value{};\n\n            // Return the hash value to notify we don't want any more updates\n            p.param_type = MAV_PARAM_TYPE_UINT32;\n            (void) strncpy(p.param_id, \"_HASH_CHECK\", sizeof(p.param_id));\n            union_value.param_uint32 = crc32_value;\n            p.param_value = union_value.param_float;\n            p.target_system = static_cast<uint8_t>(_vehicle->id());\n            p.target_component = static_cast<uint8_t>(componentId);\n\n            mavlink_message_t msg{};\n            (void) mavlink_msg_param_set_encode_chan(MAVLinkProtocol::instance()->getSystemId(),\n                                                     MAVLinkProtocol::getComponentId(),\n                                                     sharedLink->mavlinkChannel(),\n                                                     &msg,\n                                                     &p);\n            (void) _vehicle->sendMessageOnLinkThreadSafe(sharedLink.get(), msg);\n        }\n\n        // Give the user some feedback things loaded properly\n        QVariantAnimation *const ani = new QVariantAnimation(this);\n        ani->setEasingCurve(QEasingCurve::OutCubic);\n        ani->setStartValue(0.0);\n        ani->setEndValue(1.0);\n        ani->setDuration(750);\n\n        (void) connect(ani, &QVariantAnimation::valueChanged, this, [this](const QVariant &value) {\n            _setLoadProgress(value.toDouble());\n        });\n\n        // Hide 500ms after animation finishes\n        connect(ani, &QVariantAnimation::finished, this, [this] {\n            QTimer::singleShot(500, this, [this] {\n                _setLoadProgress(0);\n            });\n        });\n\n        ani->start(QAbstractAnimation::DeleteWhenStopped);\n        return true;\n    } else {\n        qCInfo(ParameterManagerLog) << \"Parameters cache match failed\" << qPrintable(QFileInfo(cacheFile).absoluteFilePath());\n        if (ParameterManagerDebugCacheFailureLog().isDebugEnabled()) {\n            _debugCacheCRC[componentId] = true;\n            _debugCacheMap[componentId] = cacheMap;\n            for (const QString &name: cacheMap.keys()) {\n                _debugCacheParamSeen[componentId][name] = false;\n            }\n            qgcApp()->showAppMessage(tr(\"Parameter cache CRC match failed\"));\n        }\n    }\n    return false;\n}"},{"file":"src/FactSystem/ParameterManager.cc","name":"stop-hash-probe-on-completion","old":"    // We aren't waiting for any more initial parameter updates, initial parameter loading is complete\n    _initialLoadComplete = true;","new":"    // We aren't waiting for any more initial parameter updates, initial parameter loading is complete\n    _initialLoadComplete = true;\n    _cacheHashTimeoutTimer.stop();"},{"file":"src/FactSystem/ParameterManager.h","name":"cache-load-interface","old":"    void _tryCacheHashLoad(int vehicleId, int componentId, const QVariant &hashValue);","new":"    bool _tryCacheHashLoad(int vehicleId, int componentId, const QVariant &hashValue, int parameterCount);\n    QString _vehicleCacheFile(int componentId) const;"},{"file":"src/FactSystem/ParameterManager.h","name":"cache-state","old":"    QMap<int /* component id */, bool> _debugCacheCRC","new":"    // Only values acknowledged by the vehicle, never unacknowledged UI edits.\n    QMap<int, CacheMapName2ParamTypeVal> _confirmedCacheValues;\n    QTimer _cacheHashTimeoutTimer;\n    QTimer _cacheWriteTimer;\n    bool _cacheHashAttempted = false;\n    bool _loadingFromCache = false;\n\n    QMap<int /* component id */, bool> _debugCacheCRC"}]''')
FILES = ('src/FactSystem/ParameterManager.cc', 'src/FactSystem/ParameterManager.h')


class PatchError(Exception):
    pass


def digest(data):
    return hashlib.sha256(data).hexdigest()


def source_file(root, relative):
    if relative not in FILES:
        raise PatchError('Unexpected target file: '+relative)
    path = root/relative
    if path.is_symlink():
        raise PatchError('Refusing to replace a symbolic link: '+str(path))
    try:
        path.resolve().relative_to(root)
    except ValueError:
        raise PatchError('Target escapes source directory: '+str(path))
    if not path.is_file():
        raise PatchError('Missing source file: '+str(path))
    return path


def atomic_write(path, data, mode):
    """Same-directory replace; no direct-write fallback that could truncate originals."""
    descriptor, name = tempfile.mkstemp(prefix='.'+path.name+'.cache-patch-', dir=str(path.parent))
    temporary = Path(name)
    try:
        with os.fdopen(descriptor, 'wb') as handle:
            handle.write(data)
            handle.flush()
            os.fsync(handle.fileno())
        temporary.chmod(mode)
        os.replace(str(temporary), str(path))
    finally:
        if temporary.exists():
            temporary.unlink()


def plan_install(root):
    cmake = root/'CMakeLists.txt'
    vehicle = root/'src/Vehicle/Vehicle.h'
    if not cmake.is_file() or 'Qt6' not in cmake.read_text(encoding='utf-8'):
        raise PatchError('Only the matching Qt6 QGroundControl source family is supported.')
    if not vehicle.is_file() or 'vehicleUID()' not in vehicle.read_text(encoding='utf-8'):
        raise PatchError('Missing compatible Vehicle::vehicleUID() interface.')
    plan = {}
    states = []
    for relative in FILES:
        path = source_file(root, relative)
        before = path.read_bytes()
        text = before.decode('utf-8').replace('\r\n', '\n')
        for patch in (p for p in PATCHES if p['file'] == relative):
            old, new = patch['old'], patch['new']
            if text.count(new) == 1:
                states.append('installed')
            elif text.count(old) == 1 and new not in text:
                states.append('original')
                text = text.replace(old, new, 1)
            else:
                raise PatchError('Incompatible/modified context: '+relative+' ['+patch['name']+']. No files changed.')
        # Preserve Windows CRLF files rather than silently changing all lines.
        if b'\r\n' in before and b'\n' not in before.replace(b'\r\n', b''):
            text = text.replace('\n', '\r\n')
        plan[relative] = (before, text.encode('utf-8'), stat.S_IMODE(path.stat().st_mode))
    if len(set(states)) != 1:
        raise PatchError('Partial installation or overlapping customization detected. No files changed; review or restore a backup first.')
    return plan, states[0] == 'installed'


def plan_rollback(root, backup):
    manifest = json.loads((backup/'manifest.json').read_text(encoding='utf-8'))
    if manifest.get('patch_id') != PATCH_ID or set(manifest.get('files', {})) != set(FILES):
        raise PatchError('Invalid/incompatible backup manifest.')
    plan = {}
    for relative in FILES:
        info = manifest['files'][relative]
        path = source_file(root, relative)
        saved = backup/relative
        if saved.is_symlink():
            raise PatchError('Backup must not be a symbolic link.')
        before, original = path.read_bytes(), saved.read_bytes()
        if digest(original) != info['original_sha256']:
            raise PatchError('Backup integrity check failed: '+relative)
        if digest(before) not in (info['installed_sha256'], info['original_sha256']):
            raise PatchError('Source changed since installation; refusing to overwrite your edits: '+relative)
        plan[relative] = (before, original, info['mode'])
    return plan


def commit_plan(root, plan):
    # Check every file before any write; check again immediately before replacing.
    for relative, (before, _, _) in plan.items():
        if source_file(root, relative).read_bytes() != before:
            raise PatchError('Source changed during preflight: '+relative)
    changed = []
    try:
        for relative, (before, after, mode) in plan.items():
            path = source_file(root, relative)
            if before == after:
                continue
            if path.read_bytes() != before:
                raise PatchError('Source changed during installation: '+relative)
            atomic_write(path, after, mode)
            changed.append(relative)
    except Exception:
        # Restore our own completed writes, never a concurrent user's edits.
        for relative in reversed(changed):
            before, after, mode = plan[relative]
            path = source_file(root, relative)
            if path.read_bytes() == after:
                atomic_write(path, before, mode)
            else:
                print('WARNING: Concurrent edit retained; use the backup to review '+relative, file=sys.stderr)
        raise


def save_backup(root, plan):
    parent = root/'.parameter-cache-backups'
    parent.mkdir(exist_ok=True)
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ-')
    backup = Path(tempfile.mkdtemp(prefix=stamp, dir=str(parent)))
    manifest = dict(patch_id=PATCH_ID, source=str(root), files={})
    for relative, (before, after, mode) in plan.items():
        saved = backup/relative
        saved.parent.mkdir(parents=True, exist_ok=True)
        atomic_write(saved, before, mode)
        manifest['files'][relative] = dict(original_sha256=digest(before), installed_sha256=digest(after), mode=mode)
    atomic_write(backup/'manifest.json', json.dumps(manifest, indent=2).encode('utf-8'), 0o600)
    return backup


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--source', type=Path, required=True, help='QGroundControl source root (not the executable/build directory)')
    parser.add_argument('--apply', action='store_true', help='actually modify source; otherwise perform read-only preflight')
    parser.add_argument('--diff', action='store_true', help='show the exact proposed source changes')
    parser.add_argument('--rollback', type=Path, help='restore the specific backup directory printed during installation')
    args = parser.parse_args(argv)
    try:
        root = args.source.expanduser().resolve()
        if args.rollback:
            plan = plan_rollback(root, args.rollback.expanduser().resolve())
            installed = False
        else:
            plan, installed = plan_install(root)
        if installed:
            print('Already installed. No files changed.')
            return 0
        if args.diff:
            for relative, (before, after, _) in plan.items():
                sys.stdout.writelines(difflib.unified_diff(before.decode('utf-8').splitlines(True),
                    after.decode('utf-8').splitlines(True), fromfile=relative+' (before)', tofile=relative+' (after)'))
        if not args.apply:
            print('Preflight OK. No files changed. Add --apply to '+('restore.' if args.rollback else 'install.'))
            return 0
        if not args.rollback:
            backup = save_backup(root, plan)
            print('Backup: '+str(backup), flush=True)
        commit_plan(root, plan)
        print(('Restored.' if args.rollback else 'Installed.')+' Rebuild QGroundControl and launch the newly built executable.')
        return 0
    except (PatchError, OSError, UnicodeError, ValueError, KeyError, TypeError) as error:
        print('ERROR: '+str(error), file=sys.stderr)
        return 1


if __name__ == '__main__':
    sys.exit(main())