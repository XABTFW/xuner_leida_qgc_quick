#pragma once
// MESSAGE SWARM_START_FLAG PACKING

#define MAVLINK_MSG_ID_SWARM_START_FLAG 12923


typedef struct __mavlink_swarm_start_flag_t {
 uint8_t start_swarm_auto; /*<  start swarm function at auto-mode.*/
 uint8_t start_swarm; /*<  Start swarm function.*/
 uint8_t stop_swarm; /*<  Stop swarm function.*/
 uint8_t Pause_swarm; /*<  Pause swarm function.*/
 uint8_t continue_swarm; /*<  Continue_swarm swarm function.*/
} mavlink_swarm_start_flag_t;

#define MAVLINK_MSG_ID_SWARM_START_FLAG_LEN 5
#define MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN 5
#define MAVLINK_MSG_ID_12923_LEN 5
#define MAVLINK_MSG_ID_12923_MIN_LEN 5

#define MAVLINK_MSG_ID_SWARM_START_FLAG_CRC 125
#define MAVLINK_MSG_ID_12923_CRC 125



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SWARM_START_FLAG { \
    12923, \
    "SWARM_START_FLAG", \
    5, \
    {  { "start_swarm_auto", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_swarm_start_flag_t, start_swarm_auto) }, \
         { "start_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_swarm_start_flag_t, start_swarm) }, \
         { "stop_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_swarm_start_flag_t, stop_swarm) }, \
         { "Pause_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_swarm_start_flag_t, Pause_swarm) }, \
         { "continue_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_swarm_start_flag_t, continue_swarm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SWARM_START_FLAG { \
    "SWARM_START_FLAG", \
    5, \
    {  { "start_swarm_auto", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_swarm_start_flag_t, start_swarm_auto) }, \
         { "start_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_swarm_start_flag_t, start_swarm) }, \
         { "stop_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_swarm_start_flag_t, stop_swarm) }, \
         { "Pause_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_swarm_start_flag_t, Pause_swarm) }, \
         { "continue_swarm", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_swarm_start_flag_t, continue_swarm) }, \
         } \
}
#endif

/**
 * @brief Pack a swarm_start_flag message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param start_swarm_auto  start swarm function at auto-mode.
 * @param start_swarm  Start swarm function.
 * @param stop_swarm  Stop swarm function.
 * @param Pause_swarm  Pause swarm function.
 * @param continue_swarm  Continue_swarm swarm function.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_start_flag_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t start_swarm_auto, uint8_t start_swarm, uint8_t stop_swarm, uint8_t Pause_swarm, uint8_t continue_swarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_START_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, start_swarm_auto);
    _mav_put_uint8_t(buf, 1, start_swarm);
    _mav_put_uint8_t(buf, 2, stop_swarm);
    _mav_put_uint8_t(buf, 3, Pause_swarm);
    _mav_put_uint8_t(buf, 4, continue_swarm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#else
    mavlink_swarm_start_flag_t packet;
    packet.start_swarm_auto = start_swarm_auto;
    packet.start_swarm = start_swarm;
    packet.stop_swarm = stop_swarm;
    packet.Pause_swarm = Pause_swarm;
    packet.continue_swarm = continue_swarm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_START_FLAG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
}

/**
 * @brief Pack a swarm_start_flag message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param start_swarm_auto  start swarm function at auto-mode.
 * @param start_swarm  Start swarm function.
 * @param stop_swarm  Stop swarm function.
 * @param Pause_swarm  Pause swarm function.
 * @param continue_swarm  Continue_swarm swarm function.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_start_flag_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t start_swarm_auto, uint8_t start_swarm, uint8_t stop_swarm, uint8_t Pause_swarm, uint8_t continue_swarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_START_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, start_swarm_auto);
    _mav_put_uint8_t(buf, 1, start_swarm);
    _mav_put_uint8_t(buf, 2, stop_swarm);
    _mav_put_uint8_t(buf, 3, Pause_swarm);
    _mav_put_uint8_t(buf, 4, continue_swarm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#else
    mavlink_swarm_start_flag_t packet;
    packet.start_swarm_auto = start_swarm_auto;
    packet.start_swarm = start_swarm;
    packet.stop_swarm = stop_swarm;
    packet.Pause_swarm = Pause_swarm;
    packet.continue_swarm = continue_swarm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_START_FLAG;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#endif
}

/**
 * @brief Pack a swarm_start_flag message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param start_swarm_auto  start swarm function at auto-mode.
 * @param start_swarm  Start swarm function.
 * @param stop_swarm  Stop swarm function.
 * @param Pause_swarm  Pause swarm function.
 * @param continue_swarm  Continue_swarm swarm function.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_start_flag_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t start_swarm_auto,uint8_t start_swarm,uint8_t stop_swarm,uint8_t Pause_swarm,uint8_t continue_swarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_START_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, start_swarm_auto);
    _mav_put_uint8_t(buf, 1, start_swarm);
    _mav_put_uint8_t(buf, 2, stop_swarm);
    _mav_put_uint8_t(buf, 3, Pause_swarm);
    _mav_put_uint8_t(buf, 4, continue_swarm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#else
    mavlink_swarm_start_flag_t packet;
    packet.start_swarm_auto = start_swarm_auto;
    packet.start_swarm = start_swarm;
    packet.stop_swarm = stop_swarm;
    packet.Pause_swarm = Pause_swarm;
    packet.continue_swarm = continue_swarm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_START_FLAG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
}

/**
 * @brief Encode a swarm_start_flag struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param swarm_start_flag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_start_flag_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_swarm_start_flag_t* swarm_start_flag)
{
    return mavlink_msg_swarm_start_flag_pack(system_id, component_id, msg, swarm_start_flag->start_swarm_auto, swarm_start_flag->start_swarm, swarm_start_flag->stop_swarm, swarm_start_flag->Pause_swarm, swarm_start_flag->continue_swarm);
}

/**
 * @brief Encode a swarm_start_flag struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param swarm_start_flag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_start_flag_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_swarm_start_flag_t* swarm_start_flag)
{
    return mavlink_msg_swarm_start_flag_pack_chan(system_id, component_id, chan, msg, swarm_start_flag->start_swarm_auto, swarm_start_flag->start_swarm, swarm_start_flag->stop_swarm, swarm_start_flag->Pause_swarm, swarm_start_flag->continue_swarm);
}

/**
 * @brief Encode a swarm_start_flag struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param swarm_start_flag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_start_flag_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_swarm_start_flag_t* swarm_start_flag)
{
    return mavlink_msg_swarm_start_flag_pack_status(system_id, component_id, _status, msg,  swarm_start_flag->start_swarm_auto, swarm_start_flag->start_swarm, swarm_start_flag->stop_swarm, swarm_start_flag->Pause_swarm, swarm_start_flag->continue_swarm);
}

/**
 * @brief Send a swarm_start_flag message
 * @param chan MAVLink channel to send the message
 *
 * @param start_swarm_auto  start swarm function at auto-mode.
 * @param start_swarm  Start swarm function.
 * @param stop_swarm  Stop swarm function.
 * @param Pause_swarm  Pause swarm function.
 * @param continue_swarm  Continue_swarm swarm function.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_swarm_start_flag_send(mavlink_channel_t chan, uint8_t start_swarm_auto, uint8_t start_swarm, uint8_t stop_swarm, uint8_t Pause_swarm, uint8_t continue_swarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_START_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, start_swarm_auto);
    _mav_put_uint8_t(buf, 1, start_swarm);
    _mav_put_uint8_t(buf, 2, stop_swarm);
    _mav_put_uint8_t(buf, 3, Pause_swarm);
    _mav_put_uint8_t(buf, 4, continue_swarm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_START_FLAG, buf, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
#else
    mavlink_swarm_start_flag_t packet;
    packet.start_swarm_auto = start_swarm_auto;
    packet.start_swarm = start_swarm;
    packet.stop_swarm = stop_swarm;
    packet.Pause_swarm = Pause_swarm;
    packet.continue_swarm = continue_swarm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_START_FLAG, (const char *)&packet, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
#endif
}

/**
 * @brief Send a swarm_start_flag message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_swarm_start_flag_send_struct(mavlink_channel_t chan, const mavlink_swarm_start_flag_t* swarm_start_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_swarm_start_flag_send(chan, swarm_start_flag->start_swarm_auto, swarm_start_flag->start_swarm, swarm_start_flag->stop_swarm, swarm_start_flag->Pause_swarm, swarm_start_flag->continue_swarm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_START_FLAG, (const char *)swarm_start_flag, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
#endif
}

#if MAVLINK_MSG_ID_SWARM_START_FLAG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_swarm_start_flag_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t start_swarm_auto, uint8_t start_swarm, uint8_t stop_swarm, uint8_t Pause_swarm, uint8_t continue_swarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, start_swarm_auto);
    _mav_put_uint8_t(buf, 1, start_swarm);
    _mav_put_uint8_t(buf, 2, stop_swarm);
    _mav_put_uint8_t(buf, 3, Pause_swarm);
    _mav_put_uint8_t(buf, 4, continue_swarm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_START_FLAG, buf, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
#else
    mavlink_swarm_start_flag_t *packet = (mavlink_swarm_start_flag_t *)msgbuf;
    packet->start_swarm_auto = start_swarm_auto;
    packet->start_swarm = start_swarm;
    packet->stop_swarm = stop_swarm;
    packet->Pause_swarm = Pause_swarm;
    packet->continue_swarm = continue_swarm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_START_FLAG, (const char *)packet, MAVLINK_MSG_ID_SWARM_START_FLAG_MIN_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN, MAVLINK_MSG_ID_SWARM_START_FLAG_CRC);
#endif
}
#endif

#endif

// MESSAGE SWARM_START_FLAG UNPACKING


/**
 * @brief Get field start_swarm_auto from swarm_start_flag message
 *
 * @return  start swarm function at auto-mode.
 */
static inline uint8_t mavlink_msg_swarm_start_flag_get_start_swarm_auto(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field start_swarm from swarm_start_flag message
 *
 * @return  Start swarm function.
 */
static inline uint8_t mavlink_msg_swarm_start_flag_get_start_swarm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field stop_swarm from swarm_start_flag message
 *
 * @return  Stop swarm function.
 */
static inline uint8_t mavlink_msg_swarm_start_flag_get_stop_swarm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field Pause_swarm from swarm_start_flag message
 *
 * @return  Pause swarm function.
 */
static inline uint8_t mavlink_msg_swarm_start_flag_get_Pause_swarm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field continue_swarm from swarm_start_flag message
 *
 * @return  Continue_swarm swarm function.
 */
static inline uint8_t mavlink_msg_swarm_start_flag_get_continue_swarm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a swarm_start_flag message into a struct
 *
 * @param msg The message to decode
 * @param swarm_start_flag C-struct to decode the message contents into
 */
static inline void mavlink_msg_swarm_start_flag_decode(const mavlink_message_t* msg, mavlink_swarm_start_flag_t* swarm_start_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    swarm_start_flag->start_swarm_auto = mavlink_msg_swarm_start_flag_get_start_swarm_auto(msg);
    swarm_start_flag->start_swarm = mavlink_msg_swarm_start_flag_get_start_swarm(msg);
    swarm_start_flag->stop_swarm = mavlink_msg_swarm_start_flag_get_stop_swarm(msg);
    swarm_start_flag->Pause_swarm = mavlink_msg_swarm_start_flag_get_Pause_swarm(msg);
    swarm_start_flag->continue_swarm = mavlink_msg_swarm_start_flag_get_continue_swarm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SWARM_START_FLAG_LEN? msg->len : MAVLINK_MSG_ID_SWARM_START_FLAG_LEN;
        memset(swarm_start_flag, 0, MAVLINK_MSG_ID_SWARM_START_FLAG_LEN);
    memcpy(swarm_start_flag, _MAV_PAYLOAD(msg), len);
#endif
}
