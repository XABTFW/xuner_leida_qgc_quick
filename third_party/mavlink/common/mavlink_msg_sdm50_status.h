#pragma once
// MESSAGE SDM50_STATUS PACKING

#define MAVLINK_MSG_ID_SDM50_STATUS 12929


typedef struct __mavlink_sdm50_status_t {
 uint32_t time_boot_ms; /*<  Publication timestamp since boot.*/
 uint32_t time_sample_ms; /*<  Range sample timestamp since boot.*/
 uint32_t device_id; /*<  PX4 distance sensor device ID.*/
 float distance_m; /*<  Measured target distance.*/
 float closing_speed_m_s; /*<  Filtered speed; positive means approaching the target.*/
 uint8_t status; /*<  Zero invalid, one valid.*/
} mavlink_sdm50_status_t;

#define MAVLINK_MSG_ID_SDM50_STATUS_LEN 21
#define MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN 21
#define MAVLINK_MSG_ID_12929_LEN 21
#define MAVLINK_MSG_ID_12929_MIN_LEN 21

#define MAVLINK_MSG_ID_SDM50_STATUS_CRC 172
#define MAVLINK_MSG_ID_12929_CRC 172



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SDM50_STATUS { \
    12929, \
    "SDM50_STATUS", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sdm50_status_t, time_boot_ms) }, \
         { "time_sample_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sdm50_status_t, time_sample_ms) }, \
         { "device_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sdm50_status_t, device_id) }, \
         { "distance_m", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sdm50_status_t, distance_m) }, \
         { "closing_speed_m_s", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sdm50_status_t, closing_speed_m_s) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_sdm50_status_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SDM50_STATUS { \
    "SDM50_STATUS", \
    6, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sdm50_status_t, time_boot_ms) }, \
         { "time_sample_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_sdm50_status_t, time_sample_ms) }, \
         { "device_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sdm50_status_t, device_id) }, \
         { "distance_m", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sdm50_status_t, distance_m) }, \
         { "closing_speed_m_s", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sdm50_status_t, closing_speed_m_s) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_sdm50_status_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a sdm50_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Publication timestamp since boot.
 * @param time_sample_ms  Range sample timestamp since boot.
 * @param device_id  PX4 distance sensor device ID.
 * @param distance_m  Measured target distance.
 * @param closing_speed_m_s  Filtered speed; positive means approaching the target.
 * @param status  Zero invalid, one valid.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sdm50_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t device_id, float distance_m, float closing_speed_m_s, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDM50_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, device_id);
    _mav_put_float(buf, 12, distance_m);
    _mav_put_float(buf, 16, closing_speed_m_s);
    _mav_put_uint8_t(buf, 20, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#else
    mavlink_sdm50_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.device_id = device_id;
    packet.distance_m = distance_m;
    packet.closing_speed_m_s = closing_speed_m_s;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SDM50_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
}

/**
 * @brief Pack a sdm50_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Publication timestamp since boot.
 * @param time_sample_ms  Range sample timestamp since boot.
 * @param device_id  PX4 distance sensor device ID.
 * @param distance_m  Measured target distance.
 * @param closing_speed_m_s  Filtered speed; positive means approaching the target.
 * @param status  Zero invalid, one valid.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sdm50_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t device_id, float distance_m, float closing_speed_m_s, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDM50_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, device_id);
    _mav_put_float(buf, 12, distance_m);
    _mav_put_float(buf, 16, closing_speed_m_s);
    _mav_put_uint8_t(buf, 20, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#else
    mavlink_sdm50_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.device_id = device_id;
    packet.distance_m = distance_m;
    packet.closing_speed_m_s = closing_speed_m_s;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SDM50_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#endif
}

/**
 * @brief Pack a sdm50_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms  Publication timestamp since boot.
 * @param time_sample_ms  Range sample timestamp since boot.
 * @param device_id  PX4 distance sensor device ID.
 * @param distance_m  Measured target distance.
 * @param closing_speed_m_s  Filtered speed; positive means approaching the target.
 * @param status  Zero invalid, one valid.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sdm50_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t time_sample_ms,uint32_t device_id,float distance_m,float closing_speed_m_s,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDM50_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, device_id);
    _mav_put_float(buf, 12, distance_m);
    _mav_put_float(buf, 16, closing_speed_m_s);
    _mav_put_uint8_t(buf, 20, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#else
    mavlink_sdm50_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.device_id = device_id;
    packet.distance_m = distance_m;
    packet.closing_speed_m_s = closing_speed_m_s;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SDM50_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
}

/**
 * @brief Encode a sdm50_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sdm50_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sdm50_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sdm50_status_t* sdm50_status)
{
    return mavlink_msg_sdm50_status_pack(system_id, component_id, msg, sdm50_status->time_boot_ms, sdm50_status->time_sample_ms, sdm50_status->device_id, sdm50_status->distance_m, sdm50_status->closing_speed_m_s, sdm50_status->status);
}

/**
 * @brief Encode a sdm50_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sdm50_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sdm50_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sdm50_status_t* sdm50_status)
{
    return mavlink_msg_sdm50_status_pack_chan(system_id, component_id, chan, msg, sdm50_status->time_boot_ms, sdm50_status->time_sample_ms, sdm50_status->device_id, sdm50_status->distance_m, sdm50_status->closing_speed_m_s, sdm50_status->status);
}

/**
 * @brief Encode a sdm50_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param sdm50_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sdm50_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_sdm50_status_t* sdm50_status)
{
    return mavlink_msg_sdm50_status_pack_status(system_id, component_id, _status, msg,  sdm50_status->time_boot_ms, sdm50_status->time_sample_ms, sdm50_status->device_id, sdm50_status->distance_m, sdm50_status->closing_speed_m_s, sdm50_status->status);
}

/**
 * @brief Send a sdm50_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms  Publication timestamp since boot.
 * @param time_sample_ms  Range sample timestamp since boot.
 * @param device_id  PX4 distance sensor device ID.
 * @param distance_m  Measured target distance.
 * @param closing_speed_m_s  Filtered speed; positive means approaching the target.
 * @param status  Zero invalid, one valid.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sdm50_status_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t device_id, float distance_m, float closing_speed_m_s, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SDM50_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, device_id);
    _mav_put_float(buf, 12, distance_m);
    _mav_put_float(buf, 16, closing_speed_m_s);
    _mav_put_uint8_t(buf, 20, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDM50_STATUS, buf, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
#else
    mavlink_sdm50_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.device_id = device_id;
    packet.distance_m = distance_m;
    packet.closing_speed_m_s = closing_speed_m_s;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDM50_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
#endif
}

/**
 * @brief Send a sdm50_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sdm50_status_send_struct(mavlink_channel_t chan, const mavlink_sdm50_status_t* sdm50_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sdm50_status_send(chan, sdm50_status->time_boot_ms, sdm50_status->time_sample_ms, sdm50_status->device_id, sdm50_status->distance_m, sdm50_status->closing_speed_m_s, sdm50_status->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDM50_STATUS, (const char *)sdm50_status, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SDM50_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sdm50_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t device_id, float distance_m, float closing_speed_m_s, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, device_id);
    _mav_put_float(buf, 12, distance_m);
    _mav_put_float(buf, 16, closing_speed_m_s);
    _mav_put_uint8_t(buf, 20, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDM50_STATUS, buf, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
#else
    mavlink_sdm50_status_t *packet = (mavlink_sdm50_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->time_sample_ms = time_sample_ms;
    packet->device_id = device_id;
    packet->distance_m = distance_m;
    packet->closing_speed_m_s = closing_speed_m_s;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SDM50_STATUS, (const char *)packet, MAVLINK_MSG_ID_SDM50_STATUS_MIN_LEN, MAVLINK_MSG_ID_SDM50_STATUS_LEN, MAVLINK_MSG_ID_SDM50_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SDM50_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from sdm50_status message
 *
 * @return  Publication timestamp since boot.
 */
static inline uint32_t mavlink_msg_sdm50_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field time_sample_ms from sdm50_status message
 *
 * @return  Range sample timestamp since boot.
 */
static inline uint32_t mavlink_msg_sdm50_status_get_time_sample_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field device_id from sdm50_status message
 *
 * @return  PX4 distance sensor device ID.
 */
static inline uint32_t mavlink_msg_sdm50_status_get_device_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field distance_m from sdm50_status message
 *
 * @return  Measured target distance.
 */
static inline float mavlink_msg_sdm50_status_get_distance_m(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field closing_speed_m_s from sdm50_status message
 *
 * @return  Filtered speed; positive means approaching the target.
 */
static inline float mavlink_msg_sdm50_status_get_closing_speed_m_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field status from sdm50_status message
 *
 * @return  Zero invalid, one valid.
 */
static inline uint8_t mavlink_msg_sdm50_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a sdm50_status message into a struct
 *
 * @param msg The message to decode
 * @param sdm50_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_sdm50_status_decode(const mavlink_message_t* msg, mavlink_sdm50_status_t* sdm50_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sdm50_status->time_boot_ms = mavlink_msg_sdm50_status_get_time_boot_ms(msg);
    sdm50_status->time_sample_ms = mavlink_msg_sdm50_status_get_time_sample_ms(msg);
    sdm50_status->device_id = mavlink_msg_sdm50_status_get_device_id(msg);
    sdm50_status->distance_m = mavlink_msg_sdm50_status_get_distance_m(msg);
    sdm50_status->closing_speed_m_s = mavlink_msg_sdm50_status_get_closing_speed_m_s(msg);
    sdm50_status->status = mavlink_msg_sdm50_status_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SDM50_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SDM50_STATUS_LEN;
        memset(sdm50_status, 0, MAVLINK_MSG_ID_SDM50_STATUS_LEN);
    memcpy(sdm50_status, _MAV_PAYLOAD(msg), len);
#endif
}
