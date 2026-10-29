#pragma once
// MESSAGE DYT_STATUS_REPLY PACKING

#define MAVLINK_MSG_ID_DYT_STATUS_REPLY 12928


typedef struct __mavlink_dyt_status_reply_t {
 uint32_t time_boot_ms; /*<  Reception timestamp since boot.*/
 uint32_t time_sample_ms; /*<  Reply sample timestamp since boot.*/
 uint16_t parse_error_count; /*<  Payload parser error count.*/
 uint8_t control_code; /*<  Reply control code.*/
 uint8_t param_length; /*<  Number of valid parameter bytes.*/
 uint8_t truncated; /*<  One if the reply exceeded the uORB buffer.*/
 uint8_t params[16]; /*<  Reply parameter bytes.*/
} mavlink_dyt_status_reply_t;

#define MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN 29
#define MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN 29
#define MAVLINK_MSG_ID_12928_LEN 29
#define MAVLINK_MSG_ID_12928_MIN_LEN 29

#define MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC 227
#define MAVLINK_MSG_ID_12928_CRC 227

#define MAVLINK_MSG_DYT_STATUS_REPLY_FIELD_PARAMS_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DYT_STATUS_REPLY { \
    12928, \
    "DYT_STATUS_REPLY", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_status_reply_t, time_boot_ms) }, \
         { "time_sample_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dyt_status_reply_t, time_sample_ms) }, \
         { "parse_error_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_dyt_status_reply_t, parse_error_count) }, \
         { "control_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_dyt_status_reply_t, control_code) }, \
         { "param_length", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_dyt_status_reply_t, param_length) }, \
         { "truncated", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_dyt_status_reply_t, truncated) }, \
         { "params", NULL, MAVLINK_TYPE_UINT8_T, 16, 13, offsetof(mavlink_dyt_status_reply_t, params) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DYT_STATUS_REPLY { \
    "DYT_STATUS_REPLY", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_status_reply_t, time_boot_ms) }, \
         { "time_sample_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dyt_status_reply_t, time_sample_ms) }, \
         { "parse_error_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_dyt_status_reply_t, parse_error_count) }, \
         { "control_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_dyt_status_reply_t, control_code) }, \
         { "param_length", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_dyt_status_reply_t, param_length) }, \
         { "truncated", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_dyt_status_reply_t, truncated) }, \
         { "params", NULL, MAVLINK_TYPE_UINT8_T, 16, 13, offsetof(mavlink_dyt_status_reply_t, params) }, \
         } \
}
#endif

/**
 * @brief Pack a dyt_status_reply message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Reply sample timestamp since boot.
 * @param parse_error_count  Payload parser error count.
 * @param control_code  Reply control code.
 * @param param_length  Number of valid parameter bytes.
 * @param truncated  One if the reply exceeded the uORB buffer.
 * @param params  Reply parameter bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_status_reply_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t time_sample_ms, uint16_t parse_error_count, uint8_t control_code, uint8_t param_length, uint8_t truncated, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint16_t(buf, 8, parse_error_count);
    _mav_put_uint8_t(buf, 10, control_code);
    _mav_put_uint8_t(buf, 11, param_length);
    _mav_put_uint8_t(buf, 12, truncated);
    _mav_put_uint8_t_array(buf, 13, params, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#else
    mavlink_dyt_status_reply_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.parse_error_count = parse_error_count;
    packet.control_code = control_code;
    packet.param_length = param_length;
    packet.truncated = truncated;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_STATUS_REPLY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
}

/**
 * @brief Pack a dyt_status_reply message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Reply sample timestamp since boot.
 * @param parse_error_count  Payload parser error count.
 * @param control_code  Reply control code.
 * @param param_length  Number of valid parameter bytes.
 * @param truncated  One if the reply exceeded the uORB buffer.
 * @param params  Reply parameter bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_status_reply_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t time_sample_ms, uint16_t parse_error_count, uint8_t control_code, uint8_t param_length, uint8_t truncated, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint16_t(buf, 8, parse_error_count);
    _mav_put_uint8_t(buf, 10, control_code);
    _mav_put_uint8_t(buf, 11, param_length);
    _mav_put_uint8_t(buf, 12, truncated);
    _mav_put_uint8_t_array(buf, 13, params, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#else
    mavlink_dyt_status_reply_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.parse_error_count = parse_error_count;
    packet.control_code = control_code;
    packet.param_length = param_length;
    packet.truncated = truncated;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_STATUS_REPLY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#endif
}

/**
 * @brief Pack a dyt_status_reply message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Reply sample timestamp since boot.
 * @param parse_error_count  Payload parser error count.
 * @param control_code  Reply control code.
 * @param param_length  Number of valid parameter bytes.
 * @param truncated  One if the reply exceeded the uORB buffer.
 * @param params  Reply parameter bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_status_reply_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t time_sample_ms,uint16_t parse_error_count,uint8_t control_code,uint8_t param_length,uint8_t truncated,const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint16_t(buf, 8, parse_error_count);
    _mav_put_uint8_t(buf, 10, control_code);
    _mav_put_uint8_t(buf, 11, param_length);
    _mav_put_uint8_t(buf, 12, truncated);
    _mav_put_uint8_t_array(buf, 13, params, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#else
    mavlink_dyt_status_reply_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.parse_error_count = parse_error_count;
    packet.control_code = control_code;
    packet.param_length = param_length;
    packet.truncated = truncated;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_STATUS_REPLY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
}

/**
 * @brief Encode a dyt_status_reply struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dyt_status_reply C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_status_reply_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dyt_status_reply_t* dyt_status_reply)
{
    return mavlink_msg_dyt_status_reply_pack(system_id, component_id, msg, dyt_status_reply->time_boot_ms, dyt_status_reply->time_sample_ms, dyt_status_reply->parse_error_count, dyt_status_reply->control_code, dyt_status_reply->param_length, dyt_status_reply->truncated, dyt_status_reply->params);
}

/**
 * @brief Encode a dyt_status_reply struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dyt_status_reply C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_status_reply_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dyt_status_reply_t* dyt_status_reply)
{
    return mavlink_msg_dyt_status_reply_pack_chan(system_id, component_id, chan, msg, dyt_status_reply->time_boot_ms, dyt_status_reply->time_sample_ms, dyt_status_reply->parse_error_count, dyt_status_reply->control_code, dyt_status_reply->param_length, dyt_status_reply->truncated, dyt_status_reply->params);
}

/**
 * @brief Encode a dyt_status_reply struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param dyt_status_reply C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_status_reply_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_dyt_status_reply_t* dyt_status_reply)
{
    return mavlink_msg_dyt_status_reply_pack_status(system_id, component_id, _status, msg,  dyt_status_reply->time_boot_ms, dyt_status_reply->time_sample_ms, dyt_status_reply->parse_error_count, dyt_status_reply->control_code, dyt_status_reply->param_length, dyt_status_reply->truncated, dyt_status_reply->params);
}

/**
 * @brief Send a dyt_status_reply message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Reply sample timestamp since boot.
 * @param parse_error_count  Payload parser error count.
 * @param control_code  Reply control code.
 * @param param_length  Number of valid parameter bytes.
 * @param truncated  One if the reply exceeded the uORB buffer.
 * @param params  Reply parameter bytes.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dyt_status_reply_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t time_sample_ms, uint16_t parse_error_count, uint8_t control_code, uint8_t param_length, uint8_t truncated, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint16_t(buf, 8, parse_error_count);
    _mav_put_uint8_t(buf, 10, control_code);
    _mav_put_uint8_t(buf, 11, param_length);
    _mav_put_uint8_t(buf, 12, truncated);
    _mav_put_uint8_t_array(buf, 13, params, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_STATUS_REPLY, buf, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
#else
    mavlink_dyt_status_reply_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.parse_error_count = parse_error_count;
    packet.control_code = control_code;
    packet.param_length = param_length;
    packet.truncated = truncated;
    mav_array_memcpy(packet.params, params, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_STATUS_REPLY, (const char *)&packet, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
#endif
}

/**
 * @brief Send a dyt_status_reply message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dyt_status_reply_send_struct(mavlink_channel_t chan, const mavlink_dyt_status_reply_t* dyt_status_reply)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dyt_status_reply_send(chan, dyt_status_reply->time_boot_ms, dyt_status_reply->time_sample_ms, dyt_status_reply->parse_error_count, dyt_status_reply->control_code, dyt_status_reply->param_length, dyt_status_reply->truncated, dyt_status_reply->params);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_STATUS_REPLY, (const char *)dyt_status_reply, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
#endif
}

#if MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dyt_status_reply_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t time_sample_ms, uint16_t parse_error_count, uint8_t control_code, uint8_t param_length, uint8_t truncated, const uint8_t *params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint16_t(buf, 8, parse_error_count);
    _mav_put_uint8_t(buf, 10, control_code);
    _mav_put_uint8_t(buf, 11, param_length);
    _mav_put_uint8_t(buf, 12, truncated);
    _mav_put_uint8_t_array(buf, 13, params, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_STATUS_REPLY, buf, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
#else
    mavlink_dyt_status_reply_t *packet = (mavlink_dyt_status_reply_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->time_sample_ms = time_sample_ms;
    packet->parse_error_count = parse_error_count;
    packet->control_code = control_code;
    packet->param_length = param_length;
    packet->truncated = truncated;
    mav_array_memcpy(packet->params, params, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_STATUS_REPLY, (const char *)packet, MAVLINK_MSG_ID_DYT_STATUS_REPLY_MIN_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN, MAVLINK_MSG_ID_DYT_STATUS_REPLY_CRC);
#endif
}
#endif

#endif

// MESSAGE DYT_STATUS_REPLY UNPACKING


/**
 * @brief Get field time_boot_ms from dyt_status_reply message
 *
 * @return  Reception timestamp since boot.
 */
static inline uint32_t mavlink_msg_dyt_status_reply_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field time_sample_ms from dyt_status_reply message
 *
 * @return  Reply sample timestamp since boot.
 */
static inline uint32_t mavlink_msg_dyt_status_reply_get_time_sample_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field parse_error_count from dyt_status_reply message
 *
 * @return  Payload parser error count.
 */
static inline uint16_t mavlink_msg_dyt_status_reply_get_parse_error_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field control_code from dyt_status_reply message
 *
 * @return  Reply control code.
 */
static inline uint8_t mavlink_msg_dyt_status_reply_get_control_code(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field param_length from dyt_status_reply message
 *
 * @return  Number of valid parameter bytes.
 */
static inline uint8_t mavlink_msg_dyt_status_reply_get_param_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field truncated from dyt_status_reply message
 *
 * @return  One if the reply exceeded the uORB buffer.
 */
static inline uint8_t mavlink_msg_dyt_status_reply_get_truncated(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field params from dyt_status_reply message
 *
 * @return  Reply parameter bytes.
 */
static inline uint16_t mavlink_msg_dyt_status_reply_get_params(const mavlink_message_t* msg, uint8_t *params)
{
    return _MAV_RETURN_uint8_t_array(msg, params, 16,  13);
}

/**
 * @brief Decode a dyt_status_reply message into a struct
 *
 * @param msg The message to decode
 * @param dyt_status_reply C-struct to decode the message contents into
 */
static inline void mavlink_msg_dyt_status_reply_decode(const mavlink_message_t* msg, mavlink_dyt_status_reply_t* dyt_status_reply)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dyt_status_reply->time_boot_ms = mavlink_msg_dyt_status_reply_get_time_boot_ms(msg);
    dyt_status_reply->time_sample_ms = mavlink_msg_dyt_status_reply_get_time_sample_ms(msg);
    dyt_status_reply->parse_error_count = mavlink_msg_dyt_status_reply_get_parse_error_count(msg);
    dyt_status_reply->control_code = mavlink_msg_dyt_status_reply_get_control_code(msg);
    dyt_status_reply->param_length = mavlink_msg_dyt_status_reply_get_param_length(msg);
    dyt_status_reply->truncated = mavlink_msg_dyt_status_reply_get_truncated(msg);
    mavlink_msg_dyt_status_reply_get_params(msg, dyt_status_reply->params);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN? msg->len : MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN;
        memset(dyt_status_reply, 0, MAVLINK_MSG_ID_DYT_STATUS_REPLY_LEN);
    memcpy(dyt_status_reply, _MAV_PAYLOAD(msg), len);
#endif
}
