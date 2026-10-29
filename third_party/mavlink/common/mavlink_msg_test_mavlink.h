#pragma once
// MESSAGE TEST_MAVLINK PACKING

#define MAVLINK_MSG_ID_TEST_MAVLINK 12930


typedef struct __mavlink_test_mavlink_t {
 float test3; /*<   */
 int16_t test2; /*<   */
 uint8_t test1; /*<   */
} mavlink_test_mavlink_t;

#define MAVLINK_MSG_ID_TEST_MAVLINK_LEN 7
#define MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN 7
#define MAVLINK_MSG_ID_12930_LEN 7
#define MAVLINK_MSG_ID_12930_MIN_LEN 7

#define MAVLINK_MSG_ID_TEST_MAVLINK_CRC 140
#define MAVLINK_MSG_ID_12930_CRC 140



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TEST_MAVLINK { \
    12930, \
    "TEST_MAVLINK", \
    3, \
    {  { "test1", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_test_mavlink_t, test1) }, \
         { "test2", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_test_mavlink_t, test2) }, \
         { "test3", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_test_mavlink_t, test3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TEST_MAVLINK { \
    "TEST_MAVLINK", \
    3, \
    {  { "test1", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_test_mavlink_t, test1) }, \
         { "test2", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_test_mavlink_t, test2) }, \
         { "test3", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_test_mavlink_t, test3) }, \
         } \
}
#endif

/**
 * @brief Pack a test_mavlink message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param test1   
 * @param test2   
 * @param test3   
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test_mavlink_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t test1, int16_t test2, float test3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST_MAVLINK_LEN];
    _mav_put_float(buf, 0, test3);
    _mav_put_int16_t(buf, 4, test2);
    _mav_put_uint8_t(buf, 6, test1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#else
    mavlink_test_mavlink_t packet;
    packet.test3 = test3;
    packet.test2 = test2;
    packet.test1 = test1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TEST_MAVLINK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
}

/**
 * @brief Pack a test_mavlink message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param test1   
 * @param test2   
 * @param test3   
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test_mavlink_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t test1, int16_t test2, float test3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST_MAVLINK_LEN];
    _mav_put_float(buf, 0, test3);
    _mav_put_int16_t(buf, 4, test2);
    _mav_put_uint8_t(buf, 6, test1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#else
    mavlink_test_mavlink_t packet;
    packet.test3 = test3;
    packet.test2 = test2;
    packet.test1 = test1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TEST_MAVLINK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#endif
}

/**
 * @brief Pack a test_mavlink message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param test1   
 * @param test2   
 * @param test3   
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test_mavlink_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t test1,int16_t test2,float test3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST_MAVLINK_LEN];
    _mav_put_float(buf, 0, test3);
    _mav_put_int16_t(buf, 4, test2);
    _mav_put_uint8_t(buf, 6, test1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#else
    mavlink_test_mavlink_t packet;
    packet.test3 = test3;
    packet.test2 = test2;
    packet.test1 = test1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TEST_MAVLINK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
}

/**
 * @brief Encode a test_mavlink struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param test_mavlink C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_test_mavlink_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_test_mavlink_t* test_mavlink)
{
    return mavlink_msg_test_mavlink_pack(system_id, component_id, msg, test_mavlink->test1, test_mavlink->test2, test_mavlink->test3);
}

/**
 * @brief Encode a test_mavlink struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param test_mavlink C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_test_mavlink_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_test_mavlink_t* test_mavlink)
{
    return mavlink_msg_test_mavlink_pack_chan(system_id, component_id, chan, msg, test_mavlink->test1, test_mavlink->test2, test_mavlink->test3);
}

/**
 * @brief Encode a test_mavlink struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param test_mavlink C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_test_mavlink_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_test_mavlink_t* test_mavlink)
{
    return mavlink_msg_test_mavlink_pack_status(system_id, component_id, _status, msg,  test_mavlink->test1, test_mavlink->test2, test_mavlink->test3);
}

/**
 * @brief Send a test_mavlink message
 * @param chan MAVLink channel to send the message
 *
 * @param test1   
 * @param test2   
 * @param test3   
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_test_mavlink_send(mavlink_channel_t chan, uint8_t test1, int16_t test2, float test3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST_MAVLINK_LEN];
    _mav_put_float(buf, 0, test3);
    _mav_put_int16_t(buf, 4, test2);
    _mav_put_uint8_t(buf, 6, test1);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_MAVLINK, buf, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
#else
    mavlink_test_mavlink_t packet;
    packet.test3 = test3;
    packet.test2 = test2;
    packet.test1 = test1;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_MAVLINK, (const char *)&packet, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
#endif
}

/**
 * @brief Send a test_mavlink message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_test_mavlink_send_struct(mavlink_channel_t chan, const mavlink_test_mavlink_t* test_mavlink)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_test_mavlink_send(chan, test_mavlink->test1, test_mavlink->test2, test_mavlink->test3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_MAVLINK, (const char *)test_mavlink, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
#endif
}

#if MAVLINK_MSG_ID_TEST_MAVLINK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_test_mavlink_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t test1, int16_t test2, float test3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, test3);
    _mav_put_int16_t(buf, 4, test2);
    _mav_put_uint8_t(buf, 6, test1);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_MAVLINK, buf, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
#else
    mavlink_test_mavlink_t *packet = (mavlink_test_mavlink_t *)msgbuf;
    packet->test3 = test3;
    packet->test2 = test2;
    packet->test1 = test1;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_MAVLINK, (const char *)packet, MAVLINK_MSG_ID_TEST_MAVLINK_MIN_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_LEN, MAVLINK_MSG_ID_TEST_MAVLINK_CRC);
#endif
}
#endif

#endif

// MESSAGE TEST_MAVLINK UNPACKING


/**
 * @brief Get field test1 from test_mavlink message
 *
 * @return   
 */
static inline uint8_t mavlink_msg_test_mavlink_get_test1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field test2 from test_mavlink message
 *
 * @return   
 */
static inline int16_t mavlink_msg_test_mavlink_get_test2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field test3 from test_mavlink message
 *
 * @return   
 */
static inline float mavlink_msg_test_mavlink_get_test3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a test_mavlink message into a struct
 *
 * @param msg The message to decode
 * @param test_mavlink C-struct to decode the message contents into
 */
static inline void mavlink_msg_test_mavlink_decode(const mavlink_message_t* msg, mavlink_test_mavlink_t* test_mavlink)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    test_mavlink->test3 = mavlink_msg_test_mavlink_get_test3(msg);
    test_mavlink->test2 = mavlink_msg_test_mavlink_get_test2(msg);
    test_mavlink->test1 = mavlink_msg_test_mavlink_get_test1(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TEST_MAVLINK_LEN? msg->len : MAVLINK_MSG_ID_TEST_MAVLINK_LEN;
        memset(test_mavlink, 0, MAVLINK_MSG_ID_TEST_MAVLINK_LEN);
    memcpy(test_mavlink, _MAV_PAYLOAD(msg), len);
#endif
}
