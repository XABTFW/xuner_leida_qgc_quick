#pragma once
// MESSAGE LEADER_GROUP_ID PACKING

#define MAVLINK_MSG_ID_LEADER_GROUP_ID 12922


typedef struct __mavlink_leader_group_id_t {
 uint32_t group_id; /*<  host id.*/
 uint8_t leader; /*<  leader is true.*/
} mavlink_leader_group_id_t;

#define MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN 5
#define MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN 5
#define MAVLINK_MSG_ID_12922_LEN 5
#define MAVLINK_MSG_ID_12922_MIN_LEN 5

#define MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC 153
#define MAVLINK_MSG_ID_12922_CRC 153



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LEADER_GROUP_ID { \
    12922, \
    "LEADER_GROUP_ID", \
    2, \
    {  { "group_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_leader_group_id_t, group_id) }, \
         { "leader", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_leader_group_id_t, leader) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LEADER_GROUP_ID { \
    "LEADER_GROUP_ID", \
    2, \
    {  { "group_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_leader_group_id_t, group_id) }, \
         { "leader", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_leader_group_id_t, leader) }, \
         } \
}
#endif

/**
 * @brief Pack a leader_group_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param group_id  host id.
 * @param leader  leader is true.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leader_group_id_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t group_id, uint8_t leader)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN];
    _mav_put_uint32_t(buf, 0, group_id);
    _mav_put_uint8_t(buf, 4, leader);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#else
    mavlink_leader_group_id_t packet;
    packet.group_id = group_id;
    packet.leader = leader;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEADER_GROUP_ID;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
}

/**
 * @brief Pack a leader_group_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param group_id  host id.
 * @param leader  leader is true.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leader_group_id_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t group_id, uint8_t leader)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN];
    _mav_put_uint32_t(buf, 0, group_id);
    _mav_put_uint8_t(buf, 4, leader);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#else
    mavlink_leader_group_id_t packet;
    packet.group_id = group_id;
    packet.leader = leader;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEADER_GROUP_ID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#endif
}

/**
 * @brief Pack a leader_group_id message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param group_id  host id.
 * @param leader  leader is true.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leader_group_id_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t group_id,uint8_t leader)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN];
    _mav_put_uint32_t(buf, 0, group_id);
    _mav_put_uint8_t(buf, 4, leader);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#else
    mavlink_leader_group_id_t packet;
    packet.group_id = group_id;
    packet.leader = leader;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEADER_GROUP_ID;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
}

/**
 * @brief Encode a leader_group_id struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param leader_group_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leader_group_id_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_leader_group_id_t* leader_group_id)
{
    return mavlink_msg_leader_group_id_pack(system_id, component_id, msg, leader_group_id->group_id, leader_group_id->leader);
}

/**
 * @brief Encode a leader_group_id struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param leader_group_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leader_group_id_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_leader_group_id_t* leader_group_id)
{
    return mavlink_msg_leader_group_id_pack_chan(system_id, component_id, chan, msg, leader_group_id->group_id, leader_group_id->leader);
}

/**
 * @brief Encode a leader_group_id struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param leader_group_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leader_group_id_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_leader_group_id_t* leader_group_id)
{
    return mavlink_msg_leader_group_id_pack_status(system_id, component_id, _status, msg,  leader_group_id->group_id, leader_group_id->leader);
}

/**
 * @brief Send a leader_group_id message
 * @param chan MAVLink channel to send the message
 *
 * @param group_id  host id.
 * @param leader  leader is true.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_leader_group_id_send(mavlink_channel_t chan, uint32_t group_id, uint8_t leader)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN];
    _mav_put_uint32_t(buf, 0, group_id);
    _mav_put_uint8_t(buf, 4, leader);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEADER_GROUP_ID, buf, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
#else
    mavlink_leader_group_id_t packet;
    packet.group_id = group_id;
    packet.leader = leader;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEADER_GROUP_ID, (const char *)&packet, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
#endif
}

/**
 * @brief Send a leader_group_id message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_leader_group_id_send_struct(mavlink_channel_t chan, const mavlink_leader_group_id_t* leader_group_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_leader_group_id_send(chan, leader_group_id->group_id, leader_group_id->leader);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEADER_GROUP_ID, (const char *)leader_group_id, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
#endif
}

#if MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_leader_group_id_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t group_id, uint8_t leader)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, group_id);
    _mav_put_uint8_t(buf, 4, leader);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEADER_GROUP_ID, buf, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
#else
    mavlink_leader_group_id_t *packet = (mavlink_leader_group_id_t *)msgbuf;
    packet->group_id = group_id;
    packet->leader = leader;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEADER_GROUP_ID, (const char *)packet, MAVLINK_MSG_ID_LEADER_GROUP_ID_MIN_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN, MAVLINK_MSG_ID_LEADER_GROUP_ID_CRC);
#endif
}
#endif

#endif

// MESSAGE LEADER_GROUP_ID UNPACKING


/**
 * @brief Get field group_id from leader_group_id message
 *
 * @return  host id.
 */
static inline uint32_t mavlink_msg_leader_group_id_get_group_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field leader from leader_group_id message
 *
 * @return  leader is true.
 */
static inline uint8_t mavlink_msg_leader_group_id_get_leader(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a leader_group_id message into a struct
 *
 * @param msg The message to decode
 * @param leader_group_id C-struct to decode the message contents into
 */
static inline void mavlink_msg_leader_group_id_decode(const mavlink_message_t* msg, mavlink_leader_group_id_t* leader_group_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    leader_group_id->group_id = mavlink_msg_leader_group_id_get_group_id(msg);
    leader_group_id->leader = mavlink_msg_leader_group_id_get_leader(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN? msg->len : MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN;
        memset(leader_group_id, 0, MAVLINK_MSG_ID_LEADER_GROUP_ID_LEN);
    memcpy(leader_group_id, _MAV_PAYLOAD(msg), len);
#endif
}
