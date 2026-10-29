#pragma once
// MESSAGE SWARM_MISSION_ITEM PACKING

#define MAVLINK_MSG_ID_SWARM_MISSION_ITEM 12931


typedef struct __mavlink_swarm_mission_item_t {
 uint64_t timestamp; /*<  Timestamp in microseconds since system boot.*/
 double lat; /*<  Latitude in degrees.*/
 double lon; /*<  Longitude in degrees.*/
 uint32_t mission_id; /*<  Mission ID for detecting updates.*/
 float alt; /*<  Altitude in meters (AMSL).*/
 float yaw; /*<  Yaw angle in radians.*/
 float acceptance_radius; /*<  Waypoint acceptance radius in meters.*/
 float loiter_radius; /*<  Loiter radius in meters.*/
 float time_inside; /*<  Time to stay at waypoint in seconds.*/
 uint16_t total_count; /*<  Total number of waypoints in mission.*/
 uint16_t current_seq; /*<  Current waypoint sequence being executed.*/
 uint16_t seq; /*<  Waypoint sequence number.*/
 uint16_t nav_cmd; /*<  Navigation command type.*/
 uint8_t group_id; /*<  Swarm group ID.*/
 uint8_t leader_id; /*<  Leader aircraft ID.*/
 uint8_t autocontinue; /*<  1 if auto-continue to next waypoint.*/
 uint8_t sync_type; /*<  Sync type: 0=single, 1=start, 2=end, 3=clear.*/
} mavlink_swarm_mission_item_t;

#define MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN 60
#define MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN 60
#define MAVLINK_MSG_ID_12931_LEN 60
#define MAVLINK_MSG_ID_12931_MIN_LEN 60

#define MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC 39
#define MAVLINK_MSG_ID_12931_CRC 39



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SWARM_MISSION_ITEM { \
    12931, \
    "SWARM_MISSION_ITEM", \
    17, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_swarm_mission_item_t, timestamp) }, \
         { "group_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_swarm_mission_item_t, group_id) }, \
         { "leader_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_swarm_mission_item_t, leader_id) }, \
         { "mission_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_swarm_mission_item_t, mission_id) }, \
         { "total_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_swarm_mission_item_t, total_count) }, \
         { "current_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_swarm_mission_item_t, current_seq) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_swarm_mission_item_t, seq) }, \
         { "nav_cmd", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_swarm_mission_item_t, nav_cmd) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_swarm_mission_item_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_swarm_mission_item_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_swarm_mission_item_t, alt) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_swarm_mission_item_t, yaw) }, \
         { "acceptance_radius", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_swarm_mission_item_t, acceptance_radius) }, \
         { "loiter_radius", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_swarm_mission_item_t, loiter_radius) }, \
         { "time_inside", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_swarm_mission_item_t, time_inside) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_swarm_mission_item_t, autocontinue) }, \
         { "sync_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 59, offsetof(mavlink_swarm_mission_item_t, sync_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SWARM_MISSION_ITEM { \
    "SWARM_MISSION_ITEM", \
    17, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_swarm_mission_item_t, timestamp) }, \
         { "group_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_swarm_mission_item_t, group_id) }, \
         { "leader_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_swarm_mission_item_t, leader_id) }, \
         { "mission_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_swarm_mission_item_t, mission_id) }, \
         { "total_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_swarm_mission_item_t, total_count) }, \
         { "current_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_swarm_mission_item_t, current_seq) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_swarm_mission_item_t, seq) }, \
         { "nav_cmd", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_swarm_mission_item_t, nav_cmd) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_swarm_mission_item_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_swarm_mission_item_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_swarm_mission_item_t, alt) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_swarm_mission_item_t, yaw) }, \
         { "acceptance_radius", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_swarm_mission_item_t, acceptance_radius) }, \
         { "loiter_radius", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_swarm_mission_item_t, loiter_radius) }, \
         { "time_inside", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_swarm_mission_item_t, time_inside) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 58, offsetof(mavlink_swarm_mission_item_t, autocontinue) }, \
         { "sync_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 59, offsetof(mavlink_swarm_mission_item_t, sync_type) }, \
         } \
}
#endif

/**
 * @brief Pack a swarm_mission_item message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param group_id  Swarm group ID.
 * @param leader_id  Leader aircraft ID.
 * @param mission_id  Mission ID for detecting updates.
 * @param total_count  Total number of waypoints in mission.
 * @param current_seq  Current waypoint sequence being executed.
 * @param seq  Waypoint sequence number.
 * @param nav_cmd  Navigation command type.
 * @param lat  Latitude in degrees.
 * @param lon  Longitude in degrees.
 * @param alt  Altitude in meters (AMSL).
 * @param yaw  Yaw angle in radians.
 * @param acceptance_radius  Waypoint acceptance radius in meters.
 * @param loiter_radius  Loiter radius in meters.
 * @param time_inside  Time to stay at waypoint in seconds.
 * @param autocontinue  1 if auto-continue to next waypoint.
 * @param sync_type  Sync type: 0=single, 1=start, 2=end, 3=clear.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_mission_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t group_id, uint8_t leader_id, uint32_t mission_id, uint16_t total_count, uint16_t current_seq, uint16_t seq, uint16_t nav_cmd, double lat, double lon, float alt, float yaw, float acceptance_radius, float loiter_radius, float time_inside, uint8_t autocontinue, uint8_t sync_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_uint32_t(buf, 24, mission_id);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, acceptance_radius);
    _mav_put_float(buf, 40, loiter_radius);
    _mav_put_float(buf, 44, time_inside);
    _mav_put_uint16_t(buf, 48, total_count);
    _mav_put_uint16_t(buf, 50, current_seq);
    _mav_put_uint16_t(buf, 52, seq);
    _mav_put_uint16_t(buf, 54, nav_cmd);
    _mav_put_uint8_t(buf, 56, group_id);
    _mav_put_uint8_t(buf, 57, leader_id);
    _mav_put_uint8_t(buf, 58, autocontinue);
    _mav_put_uint8_t(buf, 59, sync_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#else
    mavlink_swarm_mission_item_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lon = lon;
    packet.mission_id = mission_id;
    packet.alt = alt;
    packet.yaw = yaw;
    packet.acceptance_radius = acceptance_radius;
    packet.loiter_radius = loiter_radius;
    packet.time_inside = time_inside;
    packet.total_count = total_count;
    packet.current_seq = current_seq;
    packet.seq = seq;
    packet.nav_cmd = nav_cmd;
    packet.group_id = group_id;
    packet.leader_id = leader_id;
    packet.autocontinue = autocontinue;
    packet.sync_type = sync_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_MISSION_ITEM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
}

/**
 * @brief Pack a swarm_mission_item message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param group_id  Swarm group ID.
 * @param leader_id  Leader aircraft ID.
 * @param mission_id  Mission ID for detecting updates.
 * @param total_count  Total number of waypoints in mission.
 * @param current_seq  Current waypoint sequence being executed.
 * @param seq  Waypoint sequence number.
 * @param nav_cmd  Navigation command type.
 * @param lat  Latitude in degrees.
 * @param lon  Longitude in degrees.
 * @param alt  Altitude in meters (AMSL).
 * @param yaw  Yaw angle in radians.
 * @param acceptance_radius  Waypoint acceptance radius in meters.
 * @param loiter_radius  Loiter radius in meters.
 * @param time_inside  Time to stay at waypoint in seconds.
 * @param autocontinue  1 if auto-continue to next waypoint.
 * @param sync_type  Sync type: 0=single, 1=start, 2=end, 3=clear.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_mission_item_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t group_id, uint8_t leader_id, uint32_t mission_id, uint16_t total_count, uint16_t current_seq, uint16_t seq, uint16_t nav_cmd, double lat, double lon, float alt, float yaw, float acceptance_radius, float loiter_radius, float time_inside, uint8_t autocontinue, uint8_t sync_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_uint32_t(buf, 24, mission_id);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, acceptance_radius);
    _mav_put_float(buf, 40, loiter_radius);
    _mav_put_float(buf, 44, time_inside);
    _mav_put_uint16_t(buf, 48, total_count);
    _mav_put_uint16_t(buf, 50, current_seq);
    _mav_put_uint16_t(buf, 52, seq);
    _mav_put_uint16_t(buf, 54, nav_cmd);
    _mav_put_uint8_t(buf, 56, group_id);
    _mav_put_uint8_t(buf, 57, leader_id);
    _mav_put_uint8_t(buf, 58, autocontinue);
    _mav_put_uint8_t(buf, 59, sync_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#else
    mavlink_swarm_mission_item_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lon = lon;
    packet.mission_id = mission_id;
    packet.alt = alt;
    packet.yaw = yaw;
    packet.acceptance_radius = acceptance_radius;
    packet.loiter_radius = loiter_radius;
    packet.time_inside = time_inside;
    packet.total_count = total_count;
    packet.current_seq = current_seq;
    packet.seq = seq;
    packet.nav_cmd = nav_cmd;
    packet.group_id = group_id;
    packet.leader_id = leader_id;
    packet.autocontinue = autocontinue;
    packet.sync_type = sync_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_MISSION_ITEM;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#endif
}

/**
 * @brief Pack a swarm_mission_item message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param group_id  Swarm group ID.
 * @param leader_id  Leader aircraft ID.
 * @param mission_id  Mission ID for detecting updates.
 * @param total_count  Total number of waypoints in mission.
 * @param current_seq  Current waypoint sequence being executed.
 * @param seq  Waypoint sequence number.
 * @param nav_cmd  Navigation command type.
 * @param lat  Latitude in degrees.
 * @param lon  Longitude in degrees.
 * @param alt  Altitude in meters (AMSL).
 * @param yaw  Yaw angle in radians.
 * @param acceptance_radius  Waypoint acceptance radius in meters.
 * @param loiter_radius  Loiter radius in meters.
 * @param time_inside  Time to stay at waypoint in seconds.
 * @param autocontinue  1 if auto-continue to next waypoint.
 * @param sync_type  Sync type: 0=single, 1=start, 2=end, 3=clear.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_mission_item_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t group_id,uint8_t leader_id,uint32_t mission_id,uint16_t total_count,uint16_t current_seq,uint16_t seq,uint16_t nav_cmd,double lat,double lon,float alt,float yaw,float acceptance_radius,float loiter_radius,float time_inside,uint8_t autocontinue,uint8_t sync_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_uint32_t(buf, 24, mission_id);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, acceptance_radius);
    _mav_put_float(buf, 40, loiter_radius);
    _mav_put_float(buf, 44, time_inside);
    _mav_put_uint16_t(buf, 48, total_count);
    _mav_put_uint16_t(buf, 50, current_seq);
    _mav_put_uint16_t(buf, 52, seq);
    _mav_put_uint16_t(buf, 54, nav_cmd);
    _mav_put_uint8_t(buf, 56, group_id);
    _mav_put_uint8_t(buf, 57, leader_id);
    _mav_put_uint8_t(buf, 58, autocontinue);
    _mav_put_uint8_t(buf, 59, sync_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#else
    mavlink_swarm_mission_item_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lon = lon;
    packet.mission_id = mission_id;
    packet.alt = alt;
    packet.yaw = yaw;
    packet.acceptance_radius = acceptance_radius;
    packet.loiter_radius = loiter_radius;
    packet.time_inside = time_inside;
    packet.total_count = total_count;
    packet.current_seq = current_seq;
    packet.seq = seq;
    packet.nav_cmd = nav_cmd;
    packet.group_id = group_id;
    packet.leader_id = leader_id;
    packet.autocontinue = autocontinue;
    packet.sync_type = sync_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_MISSION_ITEM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
}

/**
 * @brief Encode a swarm_mission_item struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param swarm_mission_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_mission_item_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_swarm_mission_item_t* swarm_mission_item)
{
    return mavlink_msg_swarm_mission_item_pack(system_id, component_id, msg, swarm_mission_item->timestamp, swarm_mission_item->group_id, swarm_mission_item->leader_id, swarm_mission_item->mission_id, swarm_mission_item->total_count, swarm_mission_item->current_seq, swarm_mission_item->seq, swarm_mission_item->nav_cmd, swarm_mission_item->lat, swarm_mission_item->lon, swarm_mission_item->alt, swarm_mission_item->yaw, swarm_mission_item->acceptance_radius, swarm_mission_item->loiter_radius, swarm_mission_item->time_inside, swarm_mission_item->autocontinue, swarm_mission_item->sync_type);
}

/**
 * @brief Encode a swarm_mission_item struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param swarm_mission_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_mission_item_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_swarm_mission_item_t* swarm_mission_item)
{
    return mavlink_msg_swarm_mission_item_pack_chan(system_id, component_id, chan, msg, swarm_mission_item->timestamp, swarm_mission_item->group_id, swarm_mission_item->leader_id, swarm_mission_item->mission_id, swarm_mission_item->total_count, swarm_mission_item->current_seq, swarm_mission_item->seq, swarm_mission_item->nav_cmd, swarm_mission_item->lat, swarm_mission_item->lon, swarm_mission_item->alt, swarm_mission_item->yaw, swarm_mission_item->acceptance_radius, swarm_mission_item->loiter_radius, swarm_mission_item->time_inside, swarm_mission_item->autocontinue, swarm_mission_item->sync_type);
}

/**
 * @brief Encode a swarm_mission_item struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param swarm_mission_item C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_mission_item_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_swarm_mission_item_t* swarm_mission_item)
{
    return mavlink_msg_swarm_mission_item_pack_status(system_id, component_id, _status, msg,  swarm_mission_item->timestamp, swarm_mission_item->group_id, swarm_mission_item->leader_id, swarm_mission_item->mission_id, swarm_mission_item->total_count, swarm_mission_item->current_seq, swarm_mission_item->seq, swarm_mission_item->nav_cmd, swarm_mission_item->lat, swarm_mission_item->lon, swarm_mission_item->alt, swarm_mission_item->yaw, swarm_mission_item->acceptance_radius, swarm_mission_item->loiter_radius, swarm_mission_item->time_inside, swarm_mission_item->autocontinue, swarm_mission_item->sync_type);
}

/**
 * @brief Send a swarm_mission_item message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param group_id  Swarm group ID.
 * @param leader_id  Leader aircraft ID.
 * @param mission_id  Mission ID for detecting updates.
 * @param total_count  Total number of waypoints in mission.
 * @param current_seq  Current waypoint sequence being executed.
 * @param seq  Waypoint sequence number.
 * @param nav_cmd  Navigation command type.
 * @param lat  Latitude in degrees.
 * @param lon  Longitude in degrees.
 * @param alt  Altitude in meters (AMSL).
 * @param yaw  Yaw angle in radians.
 * @param acceptance_radius  Waypoint acceptance radius in meters.
 * @param loiter_radius  Loiter radius in meters.
 * @param time_inside  Time to stay at waypoint in seconds.
 * @param autocontinue  1 if auto-continue to next waypoint.
 * @param sync_type  Sync type: 0=single, 1=start, 2=end, 3=clear.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_swarm_mission_item_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t group_id, uint8_t leader_id, uint32_t mission_id, uint16_t total_count, uint16_t current_seq, uint16_t seq, uint16_t nav_cmd, double lat, double lon, float alt, float yaw, float acceptance_radius, float loiter_radius, float time_inside, uint8_t autocontinue, uint8_t sync_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_uint32_t(buf, 24, mission_id);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, acceptance_radius);
    _mav_put_float(buf, 40, loiter_radius);
    _mav_put_float(buf, 44, time_inside);
    _mav_put_uint16_t(buf, 48, total_count);
    _mav_put_uint16_t(buf, 50, current_seq);
    _mav_put_uint16_t(buf, 52, seq);
    _mav_put_uint16_t(buf, 54, nav_cmd);
    _mav_put_uint8_t(buf, 56, group_id);
    _mav_put_uint8_t(buf, 57, leader_id);
    _mav_put_uint8_t(buf, 58, autocontinue);
    _mav_put_uint8_t(buf, 59, sync_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_MISSION_ITEM, buf, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
#else
    mavlink_swarm_mission_item_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lon = lon;
    packet.mission_id = mission_id;
    packet.alt = alt;
    packet.yaw = yaw;
    packet.acceptance_radius = acceptance_radius;
    packet.loiter_radius = loiter_radius;
    packet.time_inside = time_inside;
    packet.total_count = total_count;
    packet.current_seq = current_seq;
    packet.seq = seq;
    packet.nav_cmd = nav_cmd;
    packet.group_id = group_id;
    packet.leader_id = leader_id;
    packet.autocontinue = autocontinue;
    packet.sync_type = sync_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_MISSION_ITEM, (const char *)&packet, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
#endif
}

/**
 * @brief Send a swarm_mission_item message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_swarm_mission_item_send_struct(mavlink_channel_t chan, const mavlink_swarm_mission_item_t* swarm_mission_item)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_swarm_mission_item_send(chan, swarm_mission_item->timestamp, swarm_mission_item->group_id, swarm_mission_item->leader_id, swarm_mission_item->mission_id, swarm_mission_item->total_count, swarm_mission_item->current_seq, swarm_mission_item->seq, swarm_mission_item->nav_cmd, swarm_mission_item->lat, swarm_mission_item->lon, swarm_mission_item->alt, swarm_mission_item->yaw, swarm_mission_item->acceptance_radius, swarm_mission_item->loiter_radius, swarm_mission_item->time_inside, swarm_mission_item->autocontinue, swarm_mission_item->sync_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_MISSION_ITEM, (const char *)swarm_mission_item, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
#endif
}

#if MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_swarm_mission_item_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t group_id, uint8_t leader_id, uint32_t mission_id, uint16_t total_count, uint16_t current_seq, uint16_t seq, uint16_t nav_cmd, double lat, double lon, float alt, float yaw, float acceptance_radius, float loiter_radius, float time_inside, uint8_t autocontinue, uint8_t sync_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lon);
    _mav_put_uint32_t(buf, 24, mission_id);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, acceptance_radius);
    _mav_put_float(buf, 40, loiter_radius);
    _mav_put_float(buf, 44, time_inside);
    _mav_put_uint16_t(buf, 48, total_count);
    _mav_put_uint16_t(buf, 50, current_seq);
    _mav_put_uint16_t(buf, 52, seq);
    _mav_put_uint16_t(buf, 54, nav_cmd);
    _mav_put_uint8_t(buf, 56, group_id);
    _mav_put_uint8_t(buf, 57, leader_id);
    _mav_put_uint8_t(buf, 58, autocontinue);
    _mav_put_uint8_t(buf, 59, sync_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_MISSION_ITEM, buf, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
#else
    mavlink_swarm_mission_item_t *packet = (mavlink_swarm_mission_item_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->lat = lat;
    packet->lon = lon;
    packet->mission_id = mission_id;
    packet->alt = alt;
    packet->yaw = yaw;
    packet->acceptance_radius = acceptance_radius;
    packet->loiter_radius = loiter_radius;
    packet->time_inside = time_inside;
    packet->total_count = total_count;
    packet->current_seq = current_seq;
    packet->seq = seq;
    packet->nav_cmd = nav_cmd;
    packet->group_id = group_id;
    packet->leader_id = leader_id;
    packet->autocontinue = autocontinue;
    packet->sync_type = sync_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_MISSION_ITEM, (const char *)packet, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_MIN_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_CRC);
#endif
}
#endif

#endif

// MESSAGE SWARM_MISSION_ITEM UNPACKING


/**
 * @brief Get field timestamp from swarm_mission_item message
 *
 * @return  Timestamp in microseconds since system boot.
 */
static inline uint64_t mavlink_msg_swarm_mission_item_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field group_id from swarm_mission_item message
 *
 * @return  Swarm group ID.
 */
static inline uint8_t mavlink_msg_swarm_mission_item_get_group_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field leader_id from swarm_mission_item message
 *
 * @return  Leader aircraft ID.
 */
static inline uint8_t mavlink_msg_swarm_mission_item_get_leader_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Get field mission_id from swarm_mission_item message
 *
 * @return  Mission ID for detecting updates.
 */
static inline uint32_t mavlink_msg_swarm_mission_item_get_mission_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field total_count from swarm_mission_item message
 *
 * @return  Total number of waypoints in mission.
 */
static inline uint16_t mavlink_msg_swarm_mission_item_get_total_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field current_seq from swarm_mission_item message
 *
 * @return  Current waypoint sequence being executed.
 */
static inline uint16_t mavlink_msg_swarm_mission_item_get_current_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  50);
}

/**
 * @brief Get field seq from swarm_mission_item message
 *
 * @return  Waypoint sequence number.
 */
static inline uint16_t mavlink_msg_swarm_mission_item_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field nav_cmd from swarm_mission_item message
 *
 * @return  Navigation command type.
 */
static inline uint16_t mavlink_msg_swarm_mission_item_get_nav_cmd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  54);
}

/**
 * @brief Get field lat from swarm_mission_item message
 *
 * @return  Latitude in degrees.
 */
static inline double mavlink_msg_swarm_mission_item_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field lon from swarm_mission_item message
 *
 * @return  Longitude in degrees.
 */
static inline double mavlink_msg_swarm_mission_item_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field alt from swarm_mission_item message
 *
 * @return  Altitude in meters (AMSL).
 */
static inline float mavlink_msg_swarm_mission_item_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field yaw from swarm_mission_item message
 *
 * @return  Yaw angle in radians.
 */
static inline float mavlink_msg_swarm_mission_item_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field acceptance_radius from swarm_mission_item message
 *
 * @return  Waypoint acceptance radius in meters.
 */
static inline float mavlink_msg_swarm_mission_item_get_acceptance_radius(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field loiter_radius from swarm_mission_item message
 *
 * @return  Loiter radius in meters.
 */
static inline float mavlink_msg_swarm_mission_item_get_loiter_radius(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field time_inside from swarm_mission_item message
 *
 * @return  Time to stay at waypoint in seconds.
 */
static inline float mavlink_msg_swarm_mission_item_get_time_inside(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field autocontinue from swarm_mission_item message
 *
 * @return  1 if auto-continue to next waypoint.
 */
static inline uint8_t mavlink_msg_swarm_mission_item_get_autocontinue(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  58);
}

/**
 * @brief Get field sync_type from swarm_mission_item message
 *
 * @return  Sync type: 0=single, 1=start, 2=end, 3=clear.
 */
static inline uint8_t mavlink_msg_swarm_mission_item_get_sync_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  59);
}

/**
 * @brief Decode a swarm_mission_item message into a struct
 *
 * @param msg The message to decode
 * @param swarm_mission_item C-struct to decode the message contents into
 */
static inline void mavlink_msg_swarm_mission_item_decode(const mavlink_message_t* msg, mavlink_swarm_mission_item_t* swarm_mission_item)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    swarm_mission_item->timestamp = mavlink_msg_swarm_mission_item_get_timestamp(msg);
    swarm_mission_item->lat = mavlink_msg_swarm_mission_item_get_lat(msg);
    swarm_mission_item->lon = mavlink_msg_swarm_mission_item_get_lon(msg);
    swarm_mission_item->mission_id = mavlink_msg_swarm_mission_item_get_mission_id(msg);
    swarm_mission_item->alt = mavlink_msg_swarm_mission_item_get_alt(msg);
    swarm_mission_item->yaw = mavlink_msg_swarm_mission_item_get_yaw(msg);
    swarm_mission_item->acceptance_radius = mavlink_msg_swarm_mission_item_get_acceptance_radius(msg);
    swarm_mission_item->loiter_radius = mavlink_msg_swarm_mission_item_get_loiter_radius(msg);
    swarm_mission_item->time_inside = mavlink_msg_swarm_mission_item_get_time_inside(msg);
    swarm_mission_item->total_count = mavlink_msg_swarm_mission_item_get_total_count(msg);
    swarm_mission_item->current_seq = mavlink_msg_swarm_mission_item_get_current_seq(msg);
    swarm_mission_item->seq = mavlink_msg_swarm_mission_item_get_seq(msg);
    swarm_mission_item->nav_cmd = mavlink_msg_swarm_mission_item_get_nav_cmd(msg);
    swarm_mission_item->group_id = mavlink_msg_swarm_mission_item_get_group_id(msg);
    swarm_mission_item->leader_id = mavlink_msg_swarm_mission_item_get_leader_id(msg);
    swarm_mission_item->autocontinue = mavlink_msg_swarm_mission_item_get_autocontinue(msg);
    swarm_mission_item->sync_type = mavlink_msg_swarm_mission_item_get_sync_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN? msg->len : MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN;
        memset(swarm_mission_item, 0, MAVLINK_MSG_ID_SWARM_MISSION_ITEM_LEN);
    memcpy(swarm_mission_item, _MAV_PAYLOAD(msg), len);
#endif
}
