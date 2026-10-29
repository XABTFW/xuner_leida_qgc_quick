#pragma once
// MESSAGE UAV_INFO PACKING

#define MAVLINK_MSG_ID_UAV_INFO 12921


typedef struct __mavlink_uav_info_t {
 uint32_t mavid; /*<  mavid information.*/
 uint32_t group_id; /*<  swarm group id.*/
 float lat; /*<  host lattitude information.*/
 float lon; /*<  host longitude infomation.*/
 float yaw; /*<  host yaw infomation.*/
 float yaw_speed; /*<  host yaw speed infomation.*/
 float rel_alt; /*< [m] Altitude AMSL; legacy field name retained for wire compatibility.*/
 float vx; /*<  host infomation of vx.*/
 float vy; /*<  host infomation of vy.*/
 float vz; /*<  host infomation of vz.*/
 uint32_t land; /*<  ture if host Landing.*/
 uint8_t is_leader; /*<  1 if leader, 0 if follower.*/
} mavlink_uav_info_t;

#define MAVLINK_MSG_ID_UAV_INFO_LEN 45
#define MAVLINK_MSG_ID_UAV_INFO_MIN_LEN 45
#define MAVLINK_MSG_ID_12921_LEN 45
#define MAVLINK_MSG_ID_12921_MIN_LEN 45

#define MAVLINK_MSG_ID_UAV_INFO_CRC 100
#define MAVLINK_MSG_ID_12921_CRC 100



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UAV_INFO { \
    12921, \
    "UAV_INFO", \
    12, \
    {  { "mavid", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_uav_info_t, mavid) }, \
         { "group_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_uav_info_t, group_id) }, \
         { "is_leader", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_uav_info_t, is_leader) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_uav_info_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_uav_info_t, lon) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_uav_info_t, yaw) }, \
         { "yaw_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_uav_info_t, yaw_speed) }, \
         { "rel_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_uav_info_t, rel_alt) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_uav_info_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_uav_info_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_uav_info_t, vz) }, \
         { "land", NULL, MAVLINK_TYPE_UINT32_T, 0, 40, offsetof(mavlink_uav_info_t, land) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UAV_INFO { \
    "UAV_INFO", \
    12, \
    {  { "mavid", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_uav_info_t, mavid) }, \
         { "group_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_uav_info_t, group_id) }, \
         { "is_leader", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_uav_info_t, is_leader) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_uav_info_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_uav_info_t, lon) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_uav_info_t, yaw) }, \
         { "yaw_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_uav_info_t, yaw_speed) }, \
         { "rel_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_uav_info_t, rel_alt) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_uav_info_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_uav_info_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_uav_info_t, vz) }, \
         { "land", NULL, MAVLINK_TYPE_UINT32_T, 0, 40, offsetof(mavlink_uav_info_t, land) }, \
         } \
}
#endif

/**
 * @brief Pack a uav_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mavid  mavid information.
 * @param group_id  swarm group id.
 * @param is_leader  1 if leader, 0 if follower.
 * @param lat  host lattitude information.
 * @param lon  host longitude infomation.
 * @param yaw  host yaw infomation.
 * @param yaw_speed  host yaw speed infomation.
 * @param rel_alt [m] Altitude AMSL; legacy field name retained for wire compatibility.
 * @param vx  host infomation of vx.
 * @param vy  host infomation of vy.
 * @param vz  host infomation of vz.
 * @param land  ture if host Landing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_uav_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t mavid, uint32_t group_id, uint8_t is_leader, float lat, float lon, float yaw, float yaw_speed, float rel_alt, float vx, float vy, float vz, uint32_t land)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UAV_INFO_LEN];
    _mav_put_uint32_t(buf, 0, mavid);
    _mav_put_uint32_t(buf, 4, group_id);
    _mav_put_float(buf, 8, lat);
    _mav_put_float(buf, 12, lon);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, yaw_speed);
    _mav_put_float(buf, 24, rel_alt);
    _mav_put_float(buf, 28, vx);
    _mav_put_float(buf, 32, vy);
    _mav_put_float(buf, 36, vz);
    _mav_put_uint32_t(buf, 40, land);
    _mav_put_uint8_t(buf, 44, is_leader);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UAV_INFO_LEN);
#else
    mavlink_uav_info_t packet;
    packet.mavid = mavid;
    packet.group_id = group_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.yaw = yaw;
    packet.yaw_speed = yaw_speed;
    packet.rel_alt = rel_alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.land = land;
    packet.is_leader = is_leader;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UAV_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UAV_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
}

/**
 * @brief Pack a uav_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param mavid  mavid information.
 * @param group_id  swarm group id.
 * @param is_leader  1 if leader, 0 if follower.
 * @param lat  host lattitude information.
 * @param lon  host longitude infomation.
 * @param yaw  host yaw infomation.
 * @param yaw_speed  host yaw speed infomation.
 * @param rel_alt [m] Altitude AMSL; legacy field name retained for wire compatibility.
 * @param vx  host infomation of vx.
 * @param vy  host infomation of vy.
 * @param vz  host infomation of vz.
 * @param land  ture if host Landing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_uav_info_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t mavid, uint32_t group_id, uint8_t is_leader, float lat, float lon, float yaw, float yaw_speed, float rel_alt, float vx, float vy, float vz, uint32_t land)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UAV_INFO_LEN];
    _mav_put_uint32_t(buf, 0, mavid);
    _mav_put_uint32_t(buf, 4, group_id);
    _mav_put_float(buf, 8, lat);
    _mav_put_float(buf, 12, lon);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, yaw_speed);
    _mav_put_float(buf, 24, rel_alt);
    _mav_put_float(buf, 28, vx);
    _mav_put_float(buf, 32, vy);
    _mav_put_float(buf, 36, vz);
    _mav_put_uint32_t(buf, 40, land);
    _mav_put_uint8_t(buf, 44, is_leader);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UAV_INFO_LEN);
#else
    mavlink_uav_info_t packet;
    packet.mavid = mavid;
    packet.group_id = group_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.yaw = yaw;
    packet.yaw_speed = yaw_speed;
    packet.rel_alt = rel_alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.land = land;
    packet.is_leader = is_leader;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UAV_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UAV_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN);
#endif
}

/**
 * @brief Pack a uav_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mavid  mavid information.
 * @param group_id  swarm group id.
 * @param is_leader  1 if leader, 0 if follower.
 * @param lat  host lattitude information.
 * @param lon  host longitude infomation.
 * @param yaw  host yaw infomation.
 * @param yaw_speed  host yaw speed infomation.
 * @param rel_alt [m] Altitude AMSL; legacy field name retained for wire compatibility.
 * @param vx  host infomation of vx.
 * @param vy  host infomation of vy.
 * @param vz  host infomation of vz.
 * @param land  ture if host Landing.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_uav_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t mavid,uint32_t group_id,uint8_t is_leader,float lat,float lon,float yaw,float yaw_speed,float rel_alt,float vx,float vy,float vz,uint32_t land)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UAV_INFO_LEN];
    _mav_put_uint32_t(buf, 0, mavid);
    _mav_put_uint32_t(buf, 4, group_id);
    _mav_put_float(buf, 8, lat);
    _mav_put_float(buf, 12, lon);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, yaw_speed);
    _mav_put_float(buf, 24, rel_alt);
    _mav_put_float(buf, 28, vx);
    _mav_put_float(buf, 32, vy);
    _mav_put_float(buf, 36, vz);
    _mav_put_uint32_t(buf, 40, land);
    _mav_put_uint8_t(buf, 44, is_leader);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UAV_INFO_LEN);
#else
    mavlink_uav_info_t packet;
    packet.mavid = mavid;
    packet.group_id = group_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.yaw = yaw;
    packet.yaw_speed = yaw_speed;
    packet.rel_alt = rel_alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.land = land;
    packet.is_leader = is_leader;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UAV_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UAV_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
}

/**
 * @brief Encode a uav_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param uav_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_uav_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_uav_info_t* uav_info)
{
    return mavlink_msg_uav_info_pack(system_id, component_id, msg, uav_info->mavid, uav_info->group_id, uav_info->is_leader, uav_info->lat, uav_info->lon, uav_info->yaw, uav_info->yaw_speed, uav_info->rel_alt, uav_info->vx, uav_info->vy, uav_info->vz, uav_info->land);
}

/**
 * @brief Encode a uav_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uav_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_uav_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_uav_info_t* uav_info)
{
    return mavlink_msg_uav_info_pack_chan(system_id, component_id, chan, msg, uav_info->mavid, uav_info->group_id, uav_info->is_leader, uav_info->lat, uav_info->lon, uav_info->yaw, uav_info->yaw_speed, uav_info->rel_alt, uav_info->vx, uav_info->vy, uav_info->vz, uav_info->land);
}

/**
 * @brief Encode a uav_info struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param uav_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_uav_info_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_uav_info_t* uav_info)
{
    return mavlink_msg_uav_info_pack_status(system_id, component_id, _status, msg,  uav_info->mavid, uav_info->group_id, uav_info->is_leader, uav_info->lat, uav_info->lon, uav_info->yaw, uav_info->yaw_speed, uav_info->rel_alt, uav_info->vx, uav_info->vy, uav_info->vz, uav_info->land);
}

/**
 * @brief Send a uav_info message
 * @param chan MAVLink channel to send the message
 *
 * @param mavid  mavid information.
 * @param group_id  swarm group id.
 * @param is_leader  1 if leader, 0 if follower.
 * @param lat  host lattitude information.
 * @param lon  host longitude infomation.
 * @param yaw  host yaw infomation.
 * @param yaw_speed  host yaw speed infomation.
 * @param rel_alt [m] Altitude AMSL; legacy field name retained for wire compatibility.
 * @param vx  host infomation of vx.
 * @param vy  host infomation of vy.
 * @param vz  host infomation of vz.
 * @param land  ture if host Landing.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_uav_info_send(mavlink_channel_t chan, uint32_t mavid, uint32_t group_id, uint8_t is_leader, float lat, float lon, float yaw, float yaw_speed, float rel_alt, float vx, float vy, float vz, uint32_t land)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UAV_INFO_LEN];
    _mav_put_uint32_t(buf, 0, mavid);
    _mav_put_uint32_t(buf, 4, group_id);
    _mav_put_float(buf, 8, lat);
    _mav_put_float(buf, 12, lon);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, yaw_speed);
    _mav_put_float(buf, 24, rel_alt);
    _mav_put_float(buf, 28, vx);
    _mav_put_float(buf, 32, vy);
    _mav_put_float(buf, 36, vz);
    _mav_put_uint32_t(buf, 40, land);
    _mav_put_uint8_t(buf, 44, is_leader);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UAV_INFO, buf, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
#else
    mavlink_uav_info_t packet;
    packet.mavid = mavid;
    packet.group_id = group_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.yaw = yaw;
    packet.yaw_speed = yaw_speed;
    packet.rel_alt = rel_alt;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.land = land;
    packet.is_leader = is_leader;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UAV_INFO, (const char *)&packet, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
#endif
}

/**
 * @brief Send a uav_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_uav_info_send_struct(mavlink_channel_t chan, const mavlink_uav_info_t* uav_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_uav_info_send(chan, uav_info->mavid, uav_info->group_id, uav_info->is_leader, uav_info->lat, uav_info->lon, uav_info->yaw, uav_info->yaw_speed, uav_info->rel_alt, uav_info->vx, uav_info->vy, uav_info->vz, uav_info->land);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UAV_INFO, (const char *)uav_info, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_UAV_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_uav_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t mavid, uint32_t group_id, uint8_t is_leader, float lat, float lon, float yaw, float yaw_speed, float rel_alt, float vx, float vy, float vz, uint32_t land)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, mavid);
    _mav_put_uint32_t(buf, 4, group_id);
    _mav_put_float(buf, 8, lat);
    _mav_put_float(buf, 12, lon);
    _mav_put_float(buf, 16, yaw);
    _mav_put_float(buf, 20, yaw_speed);
    _mav_put_float(buf, 24, rel_alt);
    _mav_put_float(buf, 28, vx);
    _mav_put_float(buf, 32, vy);
    _mav_put_float(buf, 36, vz);
    _mav_put_uint32_t(buf, 40, land);
    _mav_put_uint8_t(buf, 44, is_leader);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UAV_INFO, buf, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
#else
    mavlink_uav_info_t *packet = (mavlink_uav_info_t *)msgbuf;
    packet->mavid = mavid;
    packet->group_id = group_id;
    packet->lat = lat;
    packet->lon = lon;
    packet->yaw = yaw;
    packet->yaw_speed = yaw_speed;
    packet->rel_alt = rel_alt;
    packet->vx = vx;
    packet->vy = vy;
    packet->vz = vz;
    packet->land = land;
    packet->is_leader = is_leader;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UAV_INFO, (const char *)packet, MAVLINK_MSG_ID_UAV_INFO_MIN_LEN, MAVLINK_MSG_ID_UAV_INFO_LEN, MAVLINK_MSG_ID_UAV_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE UAV_INFO UNPACKING


/**
 * @brief Get field mavid from uav_info message
 *
 * @return  mavid information.
 */
static inline uint32_t mavlink_msg_uav_info_get_mavid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field group_id from uav_info message
 *
 * @return  swarm group id.
 */
static inline uint32_t mavlink_msg_uav_info_get_group_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field is_leader from uav_info message
 *
 * @return  1 if leader, 0 if follower.
 */
static inline uint8_t mavlink_msg_uav_info_get_is_leader(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field lat from uav_info message
 *
 * @return  host lattitude information.
 */
static inline float mavlink_msg_uav_info_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field lon from uav_info message
 *
 * @return  host longitude infomation.
 */
static inline float mavlink_msg_uav_info_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw from uav_info message
 *
 * @return  host yaw infomation.
 */
static inline float mavlink_msg_uav_info_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field yaw_speed from uav_info message
 *
 * @return  host yaw speed infomation.
 */
static inline float mavlink_msg_uav_info_get_yaw_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field rel_alt from uav_info message
 *
 * @return [m] Altitude AMSL; legacy field name retained for wire compatibility.
 */
static inline float mavlink_msg_uav_info_get_rel_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field vx from uav_info message
 *
 * @return  host infomation of vx.
 */
static inline float mavlink_msg_uav_info_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field vy from uav_info message
 *
 * @return  host infomation of vy.
 */
static inline float mavlink_msg_uav_info_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field vz from uav_info message
 *
 * @return  host infomation of vz.
 */
static inline float mavlink_msg_uav_info_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field land from uav_info message
 *
 * @return  ture if host Landing.
 */
static inline uint32_t mavlink_msg_uav_info_get_land(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  40);
}

/**
 * @brief Decode a uav_info message into a struct
 *
 * @param msg The message to decode
 * @param uav_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_uav_info_decode(const mavlink_message_t* msg, mavlink_uav_info_t* uav_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    uav_info->mavid = mavlink_msg_uav_info_get_mavid(msg);
    uav_info->group_id = mavlink_msg_uav_info_get_group_id(msg);
    uav_info->lat = mavlink_msg_uav_info_get_lat(msg);
    uav_info->lon = mavlink_msg_uav_info_get_lon(msg);
    uav_info->yaw = mavlink_msg_uav_info_get_yaw(msg);
    uav_info->yaw_speed = mavlink_msg_uav_info_get_yaw_speed(msg);
    uav_info->rel_alt = mavlink_msg_uav_info_get_rel_alt(msg);
    uav_info->vx = mavlink_msg_uav_info_get_vx(msg);
    uav_info->vy = mavlink_msg_uav_info_get_vy(msg);
    uav_info->vz = mavlink_msg_uav_info_get_vz(msg);
    uav_info->land = mavlink_msg_uav_info_get_land(msg);
    uav_info->is_leader = mavlink_msg_uav_info_get_is_leader(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UAV_INFO_LEN? msg->len : MAVLINK_MSG_ID_UAV_INFO_LEN;
        memset(uav_info, 0, MAVLINK_MSG_ID_UAV_INFO_LEN);
    memcpy(uav_info, _MAV_PAYLOAD(msg), len);
#endif
}
