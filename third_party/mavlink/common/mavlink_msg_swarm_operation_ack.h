#pragma once
// MESSAGE SWARM_OPERATION_ACK PACKING

#define MAVLINK_MSG_ID_SWARM_OPERATION_ACK 12924


typedef struct __mavlink_swarm_operation_ack_t {
 uint64_t timestamp; /*<  Timestamp in microseconds since system boot.*/
 uint32_t old_value; /*<  Previous value before operation.*/
 uint32_t new_value; /*<  New value after operation.*/
 uint8_t target_system; /*<  Target system ID (aircraft that performed the operation).*/
 uint8_t operation_type; /*<  Operation type: 1=GROUP_CHANGE, 2=LEADER_CHANGE.*/
 uint8_t result; /*<  Operation result: 0=SUCCESS, 1=FAILED.*/
} mavlink_swarm_operation_ack_t;

#define MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN 19
#define MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN 19
#define MAVLINK_MSG_ID_12924_LEN 19
#define MAVLINK_MSG_ID_12924_MIN_LEN 19

#define MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC 71
#define MAVLINK_MSG_ID_12924_CRC 71



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SWARM_OPERATION_ACK { \
    12924, \
    "SWARM_OPERATION_ACK", \
    6, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_swarm_operation_ack_t, timestamp) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_swarm_operation_ack_t, target_system) }, \
         { "operation_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_swarm_operation_ack_t, operation_type) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_swarm_operation_ack_t, result) }, \
         { "old_value", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_swarm_operation_ack_t, old_value) }, \
         { "new_value", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_swarm_operation_ack_t, new_value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SWARM_OPERATION_ACK { \
    "SWARM_OPERATION_ACK", \
    6, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_swarm_operation_ack_t, timestamp) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_swarm_operation_ack_t, target_system) }, \
         { "operation_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_swarm_operation_ack_t, operation_type) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_swarm_operation_ack_t, result) }, \
         { "old_value", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_swarm_operation_ack_t, old_value) }, \
         { "new_value", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_swarm_operation_ack_t, new_value) }, \
         } \
}
#endif

/**
 * @brief Pack a swarm_operation_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param target_system  Target system ID (aircraft that performed the operation).
 * @param operation_type  Operation type: 1=GROUP_CHANGE, 2=LEADER_CHANGE.
 * @param result  Operation result: 0=SUCCESS, 1=FAILED.
 * @param old_value  Previous value before operation.
 * @param new_value  New value after operation.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_operation_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t target_system, uint8_t operation_type, uint8_t result, uint32_t old_value, uint32_t new_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, old_value);
    _mav_put_uint32_t(buf, 12, new_value);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, operation_type);
    _mav_put_uint8_t(buf, 18, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#else
    mavlink_swarm_operation_ack_t packet;
    packet.timestamp = timestamp;
    packet.old_value = old_value;
    packet.new_value = new_value;
    packet.target_system = target_system;
    packet.operation_type = operation_type;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_OPERATION_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
}

/**
 * @brief Pack a swarm_operation_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param target_system  Target system ID (aircraft that performed the operation).
 * @param operation_type  Operation type: 1=GROUP_CHANGE, 2=LEADER_CHANGE.
 * @param result  Operation result: 0=SUCCESS, 1=FAILED.
 * @param old_value  Previous value before operation.
 * @param new_value  New value after operation.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_operation_ack_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t target_system, uint8_t operation_type, uint8_t result, uint32_t old_value, uint32_t new_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, old_value);
    _mav_put_uint32_t(buf, 12, new_value);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, operation_type);
    _mav_put_uint8_t(buf, 18, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#else
    mavlink_swarm_operation_ack_t packet;
    packet.timestamp = timestamp;
    packet.old_value = old_value;
    packet.new_value = new_value;
    packet.target_system = target_system;
    packet.operation_type = operation_type;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_OPERATION_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#endif
}

/**
 * @brief Pack a swarm_operation_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param target_system  Target system ID (aircraft that performed the operation).
 * @param operation_type  Operation type: 1=GROUP_CHANGE, 2=LEADER_CHANGE.
 * @param result  Operation result: 0=SUCCESS, 1=FAILED.
 * @param old_value  Previous value before operation.
 * @param new_value  New value after operation.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_operation_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t target_system,uint8_t operation_type,uint8_t result,uint32_t old_value,uint32_t new_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, old_value);
    _mav_put_uint32_t(buf, 12, new_value);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, operation_type);
    _mav_put_uint8_t(buf, 18, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#else
    mavlink_swarm_operation_ack_t packet;
    packet.timestamp = timestamp;
    packet.old_value = old_value;
    packet.new_value = new_value;
    packet.target_system = target_system;
    packet.operation_type = operation_type;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SWARM_OPERATION_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
}

/**
 * @brief Encode a swarm_operation_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param swarm_operation_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_operation_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_swarm_operation_ack_t* swarm_operation_ack)
{
    return mavlink_msg_swarm_operation_ack_pack(system_id, component_id, msg, swarm_operation_ack->timestamp, swarm_operation_ack->target_system, swarm_operation_ack->operation_type, swarm_operation_ack->result, swarm_operation_ack->old_value, swarm_operation_ack->new_value);
}

/**
 * @brief Encode a swarm_operation_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param swarm_operation_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_operation_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_swarm_operation_ack_t* swarm_operation_ack)
{
    return mavlink_msg_swarm_operation_ack_pack_chan(system_id, component_id, chan, msg, swarm_operation_ack->timestamp, swarm_operation_ack->target_system, swarm_operation_ack->operation_type, swarm_operation_ack->result, swarm_operation_ack->old_value, swarm_operation_ack->new_value);
}

/**
 * @brief Encode a swarm_operation_ack struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param swarm_operation_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_operation_ack_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_swarm_operation_ack_t* swarm_operation_ack)
{
    return mavlink_msg_swarm_operation_ack_pack_status(system_id, component_id, _status, msg,  swarm_operation_ack->timestamp, swarm_operation_ack->target_system, swarm_operation_ack->operation_type, swarm_operation_ack->result, swarm_operation_ack->old_value, swarm_operation_ack->new_value);
}

/**
 * @brief Send a swarm_operation_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp in microseconds since system boot.
 * @param target_system  Target system ID (aircraft that performed the operation).
 * @param operation_type  Operation type: 1=GROUP_CHANGE, 2=LEADER_CHANGE.
 * @param result  Operation result: 0=SUCCESS, 1=FAILED.
 * @param old_value  Previous value before operation.
 * @param new_value  New value after operation.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_swarm_operation_ack_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t target_system, uint8_t operation_type, uint8_t result, uint32_t old_value, uint32_t new_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, old_value);
    _mav_put_uint32_t(buf, 12, new_value);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, operation_type);
    _mav_put_uint8_t(buf, 18, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_OPERATION_ACK, buf, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
#else
    mavlink_swarm_operation_ack_t packet;
    packet.timestamp = timestamp;
    packet.old_value = old_value;
    packet.new_value = new_value;
    packet.target_system = target_system;
    packet.operation_type = operation_type;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_OPERATION_ACK, (const char *)&packet, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
#endif
}

/**
 * @brief Send a swarm_operation_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_swarm_operation_ack_send_struct(mavlink_channel_t chan, const mavlink_swarm_operation_ack_t* swarm_operation_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_swarm_operation_ack_send(chan, swarm_operation_ack->timestamp, swarm_operation_ack->target_system, swarm_operation_ack->operation_type, swarm_operation_ack->result, swarm_operation_ack->old_value, swarm_operation_ack->new_value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_OPERATION_ACK, (const char *)swarm_operation_ack, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_swarm_operation_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t target_system, uint8_t operation_type, uint8_t result, uint32_t old_value, uint32_t new_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, old_value);
    _mav_put_uint32_t(buf, 12, new_value);
    _mav_put_uint8_t(buf, 16, target_system);
    _mav_put_uint8_t(buf, 17, operation_type);
    _mav_put_uint8_t(buf, 18, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_OPERATION_ACK, buf, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
#else
    mavlink_swarm_operation_ack_t *packet = (mavlink_swarm_operation_ack_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->old_value = old_value;
    packet->new_value = new_value;
    packet->target_system = target_system;
    packet->operation_type = operation_type;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_OPERATION_ACK, (const char *)packet, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_MIN_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE SWARM_OPERATION_ACK UNPACKING


/**
 * @brief Get field timestamp from swarm_operation_ack message
 *
 * @return  Timestamp in microseconds since system boot.
 */
static inline uint64_t mavlink_msg_swarm_operation_ack_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from swarm_operation_ack message
 *
 * @return  Target system ID (aircraft that performed the operation).
 */
static inline uint8_t mavlink_msg_swarm_operation_ack_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field operation_type from swarm_operation_ack message
 *
 * @return  Operation type: 1=GROUP_CHANGE, 2=LEADER_CHANGE.
 */
static inline uint8_t mavlink_msg_swarm_operation_ack_get_operation_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field result from swarm_operation_ack message
 *
 * @return  Operation result: 0=SUCCESS, 1=FAILED.
 */
static inline uint8_t mavlink_msg_swarm_operation_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field old_value from swarm_operation_ack message
 *
 * @return  Previous value before operation.
 */
static inline uint32_t mavlink_msg_swarm_operation_ack_get_old_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field new_value from swarm_operation_ack message
 *
 * @return  New value after operation.
 */
static inline uint32_t mavlink_msg_swarm_operation_ack_get_new_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Decode a swarm_operation_ack message into a struct
 *
 * @param msg The message to decode
 * @param swarm_operation_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_swarm_operation_ack_decode(const mavlink_message_t* msg, mavlink_swarm_operation_ack_t* swarm_operation_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    swarm_operation_ack->timestamp = mavlink_msg_swarm_operation_ack_get_timestamp(msg);
    swarm_operation_ack->old_value = mavlink_msg_swarm_operation_ack_get_old_value(msg);
    swarm_operation_ack->new_value = mavlink_msg_swarm_operation_ack_get_new_value(msg);
    swarm_operation_ack->target_system = mavlink_msg_swarm_operation_ack_get_target_system(msg);
    swarm_operation_ack->operation_type = mavlink_msg_swarm_operation_ack_get_operation_type(msg);
    swarm_operation_ack->result = mavlink_msg_swarm_operation_ack_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN? msg->len : MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN;
        memset(swarm_operation_ack, 0, MAVLINK_MSG_ID_SWARM_OPERATION_ACK_LEN);
    memcpy(swarm_operation_ack, _MAV_PAYLOAD(msg), len);
#endif
}
