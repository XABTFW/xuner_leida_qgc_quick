#pragma once
// MESSAGE DYT_TRACK_POINT_ACK PACKING

#define MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK 12936


typedef struct __mavlink_dyt_track_point_ack_t {
 uint32_t request_id; /*<  Request sequence copied from DYT_TRACK_POINT_COMMAND.*/
 uint16_t x_px; /*< [pix] Accepted or rejected horizontal pixel coordinate.*/
 uint16_t y_px; /*< [pix] Accepted or rejected vertical pixel coordinate.*/
 uint8_t target_system; /*<  System ID of the command sender.*/
 uint8_t target_component; /*<  Component ID of the command sender.*/
 uint8_t result; /*<  Command validation and publication result.*/
} mavlink_dyt_track_point_ack_t;

#define MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN 11
#define MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN 11
#define MAVLINK_MSG_ID_12936_LEN 11
#define MAVLINK_MSG_ID_12936_MIN_LEN 11

#define MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC 26
#define MAVLINK_MSG_ID_12936_CRC 26



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DYT_TRACK_POINT_ACK { \
    12936, \
    "DYT_TRACK_POINT_ACK", \
    6, \
    {  { "request_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_track_point_ack_t, request_id) }, \
         { "x_px", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_dyt_track_point_ack_t, x_px) }, \
         { "y_px", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_dyt_track_point_ack_t, y_px) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_dyt_track_point_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_dyt_track_point_ack_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_dyt_track_point_ack_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DYT_TRACK_POINT_ACK { \
    "DYT_TRACK_POINT_ACK", \
    6, \
    {  { "request_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_track_point_ack_t, request_id) }, \
         { "x_px", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_dyt_track_point_ack_t, x_px) }, \
         { "y_px", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_dyt_track_point_ack_t, y_px) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_dyt_track_point_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_dyt_track_point_ack_t, target_component) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_dyt_track_point_ack_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a dyt_track_point_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param request_id  Request sequence copied from DYT_TRACK_POINT_COMMAND.
 * @param x_px [pix] Accepted or rejected horizontal pixel coordinate.
 * @param y_px [pix] Accepted or rejected vertical pixel coordinate.
 * @param target_system  System ID of the command sender.
 * @param target_component  Component ID of the command sender.
 * @param result  Command validation and publication result.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t request_id, uint16_t x_px, uint16_t y_px, uint8_t target_system, uint8_t target_component, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN];
    _mav_put_uint32_t(buf, 0, request_id);
    _mav_put_uint16_t(buf, 4, x_px);
    _mav_put_uint16_t(buf, 6, y_px);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#else
    mavlink_dyt_track_point_ack_t packet;
    packet.request_id = request_id;
    packet.x_px = x_px;
    packet.y_px = y_px;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
}

/**
 * @brief Pack a dyt_track_point_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param request_id  Request sequence copied from DYT_TRACK_POINT_COMMAND.
 * @param x_px [pix] Accepted or rejected horizontal pixel coordinate.
 * @param y_px [pix] Accepted or rejected vertical pixel coordinate.
 * @param target_system  System ID of the command sender.
 * @param target_component  Component ID of the command sender.
 * @param result  Command validation and publication result.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t request_id, uint16_t x_px, uint16_t y_px, uint8_t target_system, uint8_t target_component, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN];
    _mav_put_uint32_t(buf, 0, request_id);
    _mav_put_uint16_t(buf, 4, x_px);
    _mav_put_uint16_t(buf, 6, y_px);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#else
    mavlink_dyt_track_point_ack_t packet;
    packet.request_id = request_id;
    packet.x_px = x_px;
    packet.y_px = y_px;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#endif
}

/**
 * @brief Pack a dyt_track_point_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_id  Request sequence copied from DYT_TRACK_POINT_COMMAND.
 * @param x_px [pix] Accepted or rejected horizontal pixel coordinate.
 * @param y_px [pix] Accepted or rejected vertical pixel coordinate.
 * @param target_system  System ID of the command sender.
 * @param target_component  Component ID of the command sender.
 * @param result  Command validation and publication result.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t request_id,uint16_t x_px,uint16_t y_px,uint8_t target_system,uint8_t target_component,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN];
    _mav_put_uint32_t(buf, 0, request_id);
    _mav_put_uint16_t(buf, 4, x_px);
    _mav_put_uint16_t(buf, 6, y_px);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#else
    mavlink_dyt_track_point_ack_t packet;
    packet.request_id = request_id;
    packet.x_px = x_px;
    packet.y_px = y_px;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
}

/**
 * @brief Encode a dyt_track_point_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dyt_track_point_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dyt_track_point_ack_t* dyt_track_point_ack)
{
    return mavlink_msg_dyt_track_point_ack_pack(system_id, component_id, msg, dyt_track_point_ack->request_id, dyt_track_point_ack->x_px, dyt_track_point_ack->y_px, dyt_track_point_ack->target_system, dyt_track_point_ack->target_component, dyt_track_point_ack->result);
}

/**
 * @brief Encode a dyt_track_point_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dyt_track_point_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dyt_track_point_ack_t* dyt_track_point_ack)
{
    return mavlink_msg_dyt_track_point_ack_pack_chan(system_id, component_id, chan, msg, dyt_track_point_ack->request_id, dyt_track_point_ack->x_px, dyt_track_point_ack->y_px, dyt_track_point_ack->target_system, dyt_track_point_ack->target_component, dyt_track_point_ack->result);
}

/**
 * @brief Encode a dyt_track_point_ack struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param dyt_track_point_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_dyt_track_point_ack_t* dyt_track_point_ack)
{
    return mavlink_msg_dyt_track_point_ack_pack_status(system_id, component_id, _status, msg,  dyt_track_point_ack->request_id, dyt_track_point_ack->x_px, dyt_track_point_ack->y_px, dyt_track_point_ack->target_system, dyt_track_point_ack->target_component, dyt_track_point_ack->result);
}

/**
 * @brief Send a dyt_track_point_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param request_id  Request sequence copied from DYT_TRACK_POINT_COMMAND.
 * @param x_px [pix] Accepted or rejected horizontal pixel coordinate.
 * @param y_px [pix] Accepted or rejected vertical pixel coordinate.
 * @param target_system  System ID of the command sender.
 * @param target_component  Component ID of the command sender.
 * @param result  Command validation and publication result.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dyt_track_point_ack_send(mavlink_channel_t chan, uint32_t request_id, uint16_t x_px, uint16_t y_px, uint8_t target_system, uint8_t target_component, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN];
    _mav_put_uint32_t(buf, 0, request_id);
    _mav_put_uint16_t(buf, 4, x_px);
    _mav_put_uint16_t(buf, 6, y_px);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK, buf, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
#else
    mavlink_dyt_track_point_ack_t packet;
    packet.request_id = request_id;
    packet.x_px = x_px;
    packet.y_px = y_px;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK, (const char *)&packet, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
#endif
}

/**
 * @brief Send a dyt_track_point_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dyt_track_point_ack_send_struct(mavlink_channel_t chan, const mavlink_dyt_track_point_ack_t* dyt_track_point_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dyt_track_point_ack_send(chan, dyt_track_point_ack->request_id, dyt_track_point_ack->x_px, dyt_track_point_ack->y_px, dyt_track_point_ack->target_system, dyt_track_point_ack->target_component, dyt_track_point_ack->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK, (const char *)dyt_track_point_ack, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dyt_track_point_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t request_id, uint16_t x_px, uint16_t y_px, uint8_t target_system, uint8_t target_component, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, request_id);
    _mav_put_uint16_t(buf, 4, x_px);
    _mav_put_uint16_t(buf, 6, y_px);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK, buf, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
#else
    mavlink_dyt_track_point_ack_t *packet = (mavlink_dyt_track_point_ack_t *)msgbuf;
    packet->request_id = request_id;
    packet->x_px = x_px;
    packet->y_px = y_px;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK, (const char *)packet, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_MIN_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE DYT_TRACK_POINT_ACK UNPACKING


/**
 * @brief Get field request_id from dyt_track_point_ack message
 *
 * @return  Request sequence copied from DYT_TRACK_POINT_COMMAND.
 */
static inline uint32_t mavlink_msg_dyt_track_point_ack_get_request_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field x_px from dyt_track_point_ack message
 *
 * @return [pix] Accepted or rejected horizontal pixel coordinate.
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_get_x_px(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field y_px from dyt_track_point_ack message
 *
 * @return [pix] Accepted or rejected vertical pixel coordinate.
 */
static inline uint16_t mavlink_msg_dyt_track_point_ack_get_y_px(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field target_system from dyt_track_point_ack message
 *
 * @return  System ID of the command sender.
 */
static inline uint8_t mavlink_msg_dyt_track_point_ack_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from dyt_track_point_ack message
 *
 * @return  Component ID of the command sender.
 */
static inline uint8_t mavlink_msg_dyt_track_point_ack_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field result from dyt_track_point_ack message
 *
 * @return  Command validation and publication result.
 */
static inline uint8_t mavlink_msg_dyt_track_point_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Decode a dyt_track_point_ack message into a struct
 *
 * @param msg The message to decode
 * @param dyt_track_point_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_dyt_track_point_ack_decode(const mavlink_message_t* msg, mavlink_dyt_track_point_ack_t* dyt_track_point_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dyt_track_point_ack->request_id = mavlink_msg_dyt_track_point_ack_get_request_id(msg);
    dyt_track_point_ack->x_px = mavlink_msg_dyt_track_point_ack_get_x_px(msg);
    dyt_track_point_ack->y_px = mavlink_msg_dyt_track_point_ack_get_y_px(msg);
    dyt_track_point_ack->target_system = mavlink_msg_dyt_track_point_ack_get_target_system(msg);
    dyt_track_point_ack->target_component = mavlink_msg_dyt_track_point_ack_get_target_component(msg);
    dyt_track_point_ack->result = mavlink_msg_dyt_track_point_ack_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN? msg->len : MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN;
        memset(dyt_track_point_ack, 0, MAVLINK_MSG_ID_DYT_TRACK_POINT_ACK_LEN);
    memcpy(dyt_track_point_ack, _MAV_PAYLOAD(msg), len);
#endif
}
