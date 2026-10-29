#pragma once
// MESSAGE DYT_SYSTEM_STATUS PACKING

#define MAVLINK_MSG_ID_DYT_SYSTEM_STATUS 12926


typedef struct __mavlink_dyt_system_status_t {
 uint32_t time_boot_ms; /*<  Timestamp since boot.*/
 uint32_t command_sequence; /*<  Sequence of the latest DYT_GUIDANCE_COMMAND.*/
 uint32_t net_trigger_count; /*<  Number of net-capture trigger commands sent since boot.*/
 float los_age_s; /*<  Age of the latest line-of-sight sample.*/
 float frame_dt_s; /*<  Payload frame interval.*/
 float delay_s; /*<  Configured guidance delay.*/
 float los_ned[3]; /*<  Filtered line-of-sight vector in NED.*/
 float omega_los_ned[3]; /*<  Line-of-sight angular rate in NED.*/
 float velocity_sp[3]; /*<  Guidance velocity setpoint in NED.*/
 float acceleration_sp[3]; /*<  Guidance acceleration setpoint in NED.*/
 float yaw_sp; /*<  Guidance yaw setpoint.*/
 float yaw_rate_sp; /*<  Guidance yaw-rate setpoint.*/
 uint16_t status_flags; /*<  Bitmask: 0 armed, 1 guidance active, 2 target locked, 3 DYT controls vehicle, 4 target fresh, 5 intercept allowed, 6 midcourse active, 7 midcourse target valid, 8 net trigger sent.*/
 uint8_t vehicle_type; /*<  0 unknown, 1 fighter, 2 net-capture.*/
 uint8_t guidance_phase; /*<  Actual phase: 0 disarmed, 1 initial/takeoff, 2 midcourse, 3 terminal.*/
 uint8_t gcs_phase_request; /*<  Accepted active GCS phase request, or zero.*/
 uint8_t command_phase; /*<  Phase in the latest ground command.*/
 uint8_t command_result; /*<  0 none, 1 pending, 2 accepted, 3 denied, 4 failed.*/
 uint8_t guidance_state; /*<  Detailed DYT guidance state.*/
 uint8_t requested_submode; /*<  Requested terminal submode.*/
 uint8_t active_submode; /*<  Active terminal submode.*/
 uint8_t lost_reason; /*<  Guidance loss reason.*/
} mavlink_dyt_system_status_t;

#define MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN 91
#define MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN 91
#define MAVLINK_MSG_ID_12926_LEN 91
#define MAVLINK_MSG_ID_12926_MIN_LEN 91

#define MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC 0
#define MAVLINK_MSG_ID_12926_CRC 0

#define MAVLINK_MSG_DYT_SYSTEM_STATUS_FIELD_LOS_NED_LEN 3
#define MAVLINK_MSG_DYT_SYSTEM_STATUS_FIELD_OMEGA_LOS_NED_LEN 3
#define MAVLINK_MSG_DYT_SYSTEM_STATUS_FIELD_VELOCITY_SP_LEN 3
#define MAVLINK_MSG_DYT_SYSTEM_STATUS_FIELD_ACCELERATION_SP_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DYT_SYSTEM_STATUS { \
    12926, \
    "DYT_SYSTEM_STATUS", \
    22, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_system_status_t, time_boot_ms) }, \
         { "command_sequence", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dyt_system_status_t, command_sequence) }, \
         { "net_trigger_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_dyt_system_status_t, net_trigger_count) }, \
         { "los_age_s", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dyt_system_status_t, los_age_s) }, \
         { "frame_dt_s", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dyt_system_status_t, frame_dt_s) }, \
         { "delay_s", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dyt_system_status_t, delay_s) }, \
         { "los_ned", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_dyt_system_status_t, los_ned) }, \
         { "omega_los_ned", NULL, MAVLINK_TYPE_FLOAT, 3, 36, offsetof(mavlink_dyt_system_status_t, omega_los_ned) }, \
         { "velocity_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 48, offsetof(mavlink_dyt_system_status_t, velocity_sp) }, \
         { "acceleration_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 60, offsetof(mavlink_dyt_system_status_t, acceleration_sp) }, \
         { "yaw_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_dyt_system_status_t, yaw_sp) }, \
         { "yaw_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_dyt_system_status_t, yaw_rate_sp) }, \
         { "status_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 80, offsetof(mavlink_dyt_system_status_t, status_flags) }, \
         { "vehicle_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_dyt_system_status_t, vehicle_type) }, \
         { "guidance_phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 83, offsetof(mavlink_dyt_system_status_t, guidance_phase) }, \
         { "gcs_phase_request", NULL, MAVLINK_TYPE_UINT8_T, 0, 84, offsetof(mavlink_dyt_system_status_t, gcs_phase_request) }, \
         { "command_phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 85, offsetof(mavlink_dyt_system_status_t, command_phase) }, \
         { "command_result", NULL, MAVLINK_TYPE_UINT8_T, 0, 86, offsetof(mavlink_dyt_system_status_t, command_result) }, \
         { "guidance_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 87, offsetof(mavlink_dyt_system_status_t, guidance_state) }, \
         { "requested_submode", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_dyt_system_status_t, requested_submode) }, \
         { "active_submode", NULL, MAVLINK_TYPE_UINT8_T, 0, 89, offsetof(mavlink_dyt_system_status_t, active_submode) }, \
         { "lost_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 90, offsetof(mavlink_dyt_system_status_t, lost_reason) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DYT_SYSTEM_STATUS { \
    "DYT_SYSTEM_STATUS", \
    22, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_system_status_t, time_boot_ms) }, \
         { "command_sequence", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dyt_system_status_t, command_sequence) }, \
         { "net_trigger_count", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_dyt_system_status_t, net_trigger_count) }, \
         { "los_age_s", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dyt_system_status_t, los_age_s) }, \
         { "frame_dt_s", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dyt_system_status_t, frame_dt_s) }, \
         { "delay_s", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dyt_system_status_t, delay_s) }, \
         { "los_ned", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_dyt_system_status_t, los_ned) }, \
         { "omega_los_ned", NULL, MAVLINK_TYPE_FLOAT, 3, 36, offsetof(mavlink_dyt_system_status_t, omega_los_ned) }, \
         { "velocity_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 48, offsetof(mavlink_dyt_system_status_t, velocity_sp) }, \
         { "acceleration_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 60, offsetof(mavlink_dyt_system_status_t, acceleration_sp) }, \
         { "yaw_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_dyt_system_status_t, yaw_sp) }, \
         { "yaw_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_dyt_system_status_t, yaw_rate_sp) }, \
         { "status_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 80, offsetof(mavlink_dyt_system_status_t, status_flags) }, \
         { "vehicle_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_dyt_system_status_t, vehicle_type) }, \
         { "guidance_phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 83, offsetof(mavlink_dyt_system_status_t, guidance_phase) }, \
         { "gcs_phase_request", NULL, MAVLINK_TYPE_UINT8_T, 0, 84, offsetof(mavlink_dyt_system_status_t, gcs_phase_request) }, \
         { "command_phase", NULL, MAVLINK_TYPE_UINT8_T, 0, 85, offsetof(mavlink_dyt_system_status_t, command_phase) }, \
         { "command_result", NULL, MAVLINK_TYPE_UINT8_T, 0, 86, offsetof(mavlink_dyt_system_status_t, command_result) }, \
         { "guidance_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 87, offsetof(mavlink_dyt_system_status_t, guidance_state) }, \
         { "requested_submode", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_dyt_system_status_t, requested_submode) }, \
         { "active_submode", NULL, MAVLINK_TYPE_UINT8_T, 0, 89, offsetof(mavlink_dyt_system_status_t, active_submode) }, \
         { "lost_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 90, offsetof(mavlink_dyt_system_status_t, lost_reason) }, \
         } \
}
#endif

/**
 * @brief Pack a dyt_system_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Timestamp since boot.
 * @param command_sequence  Sequence of the latest DYT_GUIDANCE_COMMAND.
 * @param net_trigger_count  Number of net-capture trigger commands sent since boot.
 * @param los_age_s  Age of the latest line-of-sight sample.
 * @param frame_dt_s  Payload frame interval.
 * @param delay_s  Configured guidance delay.
 * @param los_ned  Filtered line-of-sight vector in NED.
 * @param omega_los_ned  Line-of-sight angular rate in NED.
 * @param velocity_sp  Guidance velocity setpoint in NED.
 * @param acceleration_sp  Guidance acceleration setpoint in NED.
 * @param yaw_sp  Guidance yaw setpoint.
 * @param yaw_rate_sp  Guidance yaw-rate setpoint.
 * @param status_flags  Bitmask: 0 armed, 1 guidance active, 2 target locked, 3 DYT controls vehicle, 4 target fresh, 5 intercept allowed, 6 midcourse active, 7 midcourse target valid, 8 net trigger sent.
 * @param vehicle_type  0 unknown, 1 fighter, 2 net-capture.
 * @param guidance_phase  Actual phase: 0 disarmed, 1 initial/takeoff, 2 midcourse, 3 terminal.
 * @param gcs_phase_request  Accepted active GCS phase request, or zero.
 * @param command_phase  Phase in the latest ground command.
 * @param command_result  0 none, 1 pending, 2 accepted, 3 denied, 4 failed.
 * @param guidance_state  Detailed DYT guidance state.
 * @param requested_submode  Requested terminal submode.
 * @param active_submode  Active terminal submode.
 * @param lost_reason  Guidance loss reason.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_system_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t command_sequence, uint32_t net_trigger_count, float los_age_s, float frame_dt_s, float delay_s, const float *los_ned, const float *omega_los_ned, const float *velocity_sp, const float *acceleration_sp, float yaw_sp, float yaw_rate_sp, uint16_t status_flags, uint8_t vehicle_type, uint8_t guidance_phase, uint8_t gcs_phase_request, uint8_t command_phase, uint8_t command_result, uint8_t guidance_state, uint8_t requested_submode, uint8_t active_submode, uint8_t lost_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, command_sequence);
    _mav_put_uint32_t(buf, 8, net_trigger_count);
    _mav_put_float(buf, 12, los_age_s);
    _mav_put_float(buf, 16, frame_dt_s);
    _mav_put_float(buf, 20, delay_s);
    _mav_put_float(buf, 72, yaw_sp);
    _mav_put_float(buf, 76, yaw_rate_sp);
    _mav_put_uint16_t(buf, 80, status_flags);
    _mav_put_uint8_t(buf, 82, vehicle_type);
    _mav_put_uint8_t(buf, 83, guidance_phase);
    _mav_put_uint8_t(buf, 84, gcs_phase_request);
    _mav_put_uint8_t(buf, 85, command_phase);
    _mav_put_uint8_t(buf, 86, command_result);
    _mav_put_uint8_t(buf, 87, guidance_state);
    _mav_put_uint8_t(buf, 88, requested_submode);
    _mav_put_uint8_t(buf, 89, active_submode);
    _mav_put_uint8_t(buf, 90, lost_reason);
    _mav_put_float_array(buf, 24, los_ned, 3);
    _mav_put_float_array(buf, 36, omega_los_ned, 3);
    _mav_put_float_array(buf, 48, velocity_sp, 3);
    _mav_put_float_array(buf, 60, acceleration_sp, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#else
    mavlink_dyt_system_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.command_sequence = command_sequence;
    packet.net_trigger_count = net_trigger_count;
    packet.los_age_s = los_age_s;
    packet.frame_dt_s = frame_dt_s;
    packet.delay_s = delay_s;
    packet.yaw_sp = yaw_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.status_flags = status_flags;
    packet.vehicle_type = vehicle_type;
    packet.guidance_phase = guidance_phase;
    packet.gcs_phase_request = gcs_phase_request;
    packet.command_phase = command_phase;
    packet.command_result = command_result;
    packet.guidance_state = guidance_state;
    packet.requested_submode = requested_submode;
    packet.active_submode = active_submode;
    packet.lost_reason = lost_reason;
    mav_array_memcpy(packet.los_ned, los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.omega_los_ned, omega_los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.acceleration_sp, acceleration_sp, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_SYSTEM_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
}

/**
 * @brief Pack a dyt_system_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Timestamp since boot.
 * @param command_sequence  Sequence of the latest DYT_GUIDANCE_COMMAND.
 * @param net_trigger_count  Number of net-capture trigger commands sent since boot.
 * @param los_age_s  Age of the latest line-of-sight sample.
 * @param frame_dt_s  Payload frame interval.
 * @param delay_s  Configured guidance delay.
 * @param los_ned  Filtered line-of-sight vector in NED.
 * @param omega_los_ned  Line-of-sight angular rate in NED.
 * @param velocity_sp  Guidance velocity setpoint in NED.
 * @param acceleration_sp  Guidance acceleration setpoint in NED.
 * @param yaw_sp  Guidance yaw setpoint.
 * @param yaw_rate_sp  Guidance yaw-rate setpoint.
 * @param status_flags  Bitmask: 0 armed, 1 guidance active, 2 target locked, 3 DYT controls vehicle, 4 target fresh, 5 intercept allowed, 6 midcourse active, 7 midcourse target valid, 8 net trigger sent.
 * @param vehicle_type  0 unknown, 1 fighter, 2 net-capture.
 * @param guidance_phase  Actual phase: 0 disarmed, 1 initial/takeoff, 2 midcourse, 3 terminal.
 * @param gcs_phase_request  Accepted active GCS phase request, or zero.
 * @param command_phase  Phase in the latest ground command.
 * @param command_result  0 none, 1 pending, 2 accepted, 3 denied, 4 failed.
 * @param guidance_state  Detailed DYT guidance state.
 * @param requested_submode  Requested terminal submode.
 * @param active_submode  Active terminal submode.
 * @param lost_reason  Guidance loss reason.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_system_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t command_sequence, uint32_t net_trigger_count, float los_age_s, float frame_dt_s, float delay_s, const float *los_ned, const float *omega_los_ned, const float *velocity_sp, const float *acceleration_sp, float yaw_sp, float yaw_rate_sp, uint16_t status_flags, uint8_t vehicle_type, uint8_t guidance_phase, uint8_t gcs_phase_request, uint8_t command_phase, uint8_t command_result, uint8_t guidance_state, uint8_t requested_submode, uint8_t active_submode, uint8_t lost_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, command_sequence);
    _mav_put_uint32_t(buf, 8, net_trigger_count);
    _mav_put_float(buf, 12, los_age_s);
    _mav_put_float(buf, 16, frame_dt_s);
    _mav_put_float(buf, 20, delay_s);
    _mav_put_float(buf, 72, yaw_sp);
    _mav_put_float(buf, 76, yaw_rate_sp);
    _mav_put_uint16_t(buf, 80, status_flags);
    _mav_put_uint8_t(buf, 82, vehicle_type);
    _mav_put_uint8_t(buf, 83, guidance_phase);
    _mav_put_uint8_t(buf, 84, gcs_phase_request);
    _mav_put_uint8_t(buf, 85, command_phase);
    _mav_put_uint8_t(buf, 86, command_result);
    _mav_put_uint8_t(buf, 87, guidance_state);
    _mav_put_uint8_t(buf, 88, requested_submode);
    _mav_put_uint8_t(buf, 89, active_submode);
    _mav_put_uint8_t(buf, 90, lost_reason);
    _mav_put_float_array(buf, 24, los_ned, 3);
    _mav_put_float_array(buf, 36, omega_los_ned, 3);
    _mav_put_float_array(buf, 48, velocity_sp, 3);
    _mav_put_float_array(buf, 60, acceleration_sp, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#else
    mavlink_dyt_system_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.command_sequence = command_sequence;
    packet.net_trigger_count = net_trigger_count;
    packet.los_age_s = los_age_s;
    packet.frame_dt_s = frame_dt_s;
    packet.delay_s = delay_s;
    packet.yaw_sp = yaw_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.status_flags = status_flags;
    packet.vehicle_type = vehicle_type;
    packet.guidance_phase = guidance_phase;
    packet.gcs_phase_request = gcs_phase_request;
    packet.command_phase = command_phase;
    packet.command_result = command_result;
    packet.guidance_state = guidance_state;
    packet.requested_submode = requested_submode;
    packet.active_submode = active_submode;
    packet.lost_reason = lost_reason;
    mav_array_memcpy(packet.los_ned, los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.omega_los_ned, omega_los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.acceleration_sp, acceleration_sp, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_SYSTEM_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#endif
}

/**
 * @brief Pack a dyt_system_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms  Timestamp since boot.
 * @param command_sequence  Sequence of the latest DYT_GUIDANCE_COMMAND.
 * @param net_trigger_count  Number of net-capture trigger commands sent since boot.
 * @param los_age_s  Age of the latest line-of-sight sample.
 * @param frame_dt_s  Payload frame interval.
 * @param delay_s  Configured guidance delay.
 * @param los_ned  Filtered line-of-sight vector in NED.
 * @param omega_los_ned  Line-of-sight angular rate in NED.
 * @param velocity_sp  Guidance velocity setpoint in NED.
 * @param acceleration_sp  Guidance acceleration setpoint in NED.
 * @param yaw_sp  Guidance yaw setpoint.
 * @param yaw_rate_sp  Guidance yaw-rate setpoint.
 * @param status_flags  Bitmask: 0 armed, 1 guidance active, 2 target locked, 3 DYT controls vehicle, 4 target fresh, 5 intercept allowed, 6 midcourse active, 7 midcourse target valid, 8 net trigger sent.
 * @param vehicle_type  0 unknown, 1 fighter, 2 net-capture.
 * @param guidance_phase  Actual phase: 0 disarmed, 1 initial/takeoff, 2 midcourse, 3 terminal.
 * @param gcs_phase_request  Accepted active GCS phase request, or zero.
 * @param command_phase  Phase in the latest ground command.
 * @param command_result  0 none, 1 pending, 2 accepted, 3 denied, 4 failed.
 * @param guidance_state  Detailed DYT guidance state.
 * @param requested_submode  Requested terminal submode.
 * @param active_submode  Active terminal submode.
 * @param lost_reason  Guidance loss reason.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_system_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t command_sequence,uint32_t net_trigger_count,float los_age_s,float frame_dt_s,float delay_s,const float *los_ned,const float *omega_los_ned,const float *velocity_sp,const float *acceleration_sp,float yaw_sp,float yaw_rate_sp,uint16_t status_flags,uint8_t vehicle_type,uint8_t guidance_phase,uint8_t gcs_phase_request,uint8_t command_phase,uint8_t command_result,uint8_t guidance_state,uint8_t requested_submode,uint8_t active_submode,uint8_t lost_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, command_sequence);
    _mav_put_uint32_t(buf, 8, net_trigger_count);
    _mav_put_float(buf, 12, los_age_s);
    _mav_put_float(buf, 16, frame_dt_s);
    _mav_put_float(buf, 20, delay_s);
    _mav_put_float(buf, 72, yaw_sp);
    _mav_put_float(buf, 76, yaw_rate_sp);
    _mav_put_uint16_t(buf, 80, status_flags);
    _mav_put_uint8_t(buf, 82, vehicle_type);
    _mav_put_uint8_t(buf, 83, guidance_phase);
    _mav_put_uint8_t(buf, 84, gcs_phase_request);
    _mav_put_uint8_t(buf, 85, command_phase);
    _mav_put_uint8_t(buf, 86, command_result);
    _mav_put_uint8_t(buf, 87, guidance_state);
    _mav_put_uint8_t(buf, 88, requested_submode);
    _mav_put_uint8_t(buf, 89, active_submode);
    _mav_put_uint8_t(buf, 90, lost_reason);
    _mav_put_float_array(buf, 24, los_ned, 3);
    _mav_put_float_array(buf, 36, omega_los_ned, 3);
    _mav_put_float_array(buf, 48, velocity_sp, 3);
    _mav_put_float_array(buf, 60, acceleration_sp, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#else
    mavlink_dyt_system_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.command_sequence = command_sequence;
    packet.net_trigger_count = net_trigger_count;
    packet.los_age_s = los_age_s;
    packet.frame_dt_s = frame_dt_s;
    packet.delay_s = delay_s;
    packet.yaw_sp = yaw_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.status_flags = status_flags;
    packet.vehicle_type = vehicle_type;
    packet.guidance_phase = guidance_phase;
    packet.gcs_phase_request = gcs_phase_request;
    packet.command_phase = command_phase;
    packet.command_result = command_result;
    packet.guidance_state = guidance_state;
    packet.requested_submode = requested_submode;
    packet.active_submode = active_submode;
    packet.lost_reason = lost_reason;
    mav_array_memcpy(packet.los_ned, los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.omega_los_ned, omega_los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.acceleration_sp, acceleration_sp, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_SYSTEM_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
}

/**
 * @brief Encode a dyt_system_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dyt_system_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_system_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dyt_system_status_t* dyt_system_status)
{
    return mavlink_msg_dyt_system_status_pack(system_id, component_id, msg, dyt_system_status->time_boot_ms, dyt_system_status->command_sequence, dyt_system_status->net_trigger_count, dyt_system_status->los_age_s, dyt_system_status->frame_dt_s, dyt_system_status->delay_s, dyt_system_status->los_ned, dyt_system_status->omega_los_ned, dyt_system_status->velocity_sp, dyt_system_status->acceleration_sp, dyt_system_status->yaw_sp, dyt_system_status->yaw_rate_sp, dyt_system_status->status_flags, dyt_system_status->vehicle_type, dyt_system_status->guidance_phase, dyt_system_status->gcs_phase_request, dyt_system_status->command_phase, dyt_system_status->command_result, dyt_system_status->guidance_state, dyt_system_status->requested_submode, dyt_system_status->active_submode, dyt_system_status->lost_reason);
}

/**
 * @brief Encode a dyt_system_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dyt_system_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_system_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dyt_system_status_t* dyt_system_status)
{
    return mavlink_msg_dyt_system_status_pack_chan(system_id, component_id, chan, msg, dyt_system_status->time_boot_ms, dyt_system_status->command_sequence, dyt_system_status->net_trigger_count, dyt_system_status->los_age_s, dyt_system_status->frame_dt_s, dyt_system_status->delay_s, dyt_system_status->los_ned, dyt_system_status->omega_los_ned, dyt_system_status->velocity_sp, dyt_system_status->acceleration_sp, dyt_system_status->yaw_sp, dyt_system_status->yaw_rate_sp, dyt_system_status->status_flags, dyt_system_status->vehicle_type, dyt_system_status->guidance_phase, dyt_system_status->gcs_phase_request, dyt_system_status->command_phase, dyt_system_status->command_result, dyt_system_status->guidance_state, dyt_system_status->requested_submode, dyt_system_status->active_submode, dyt_system_status->lost_reason);
}

/**
 * @brief Encode a dyt_system_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param dyt_system_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_system_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_dyt_system_status_t* dyt_system_status)
{
    return mavlink_msg_dyt_system_status_pack_status(system_id, component_id, _status, msg,  dyt_system_status->time_boot_ms, dyt_system_status->command_sequence, dyt_system_status->net_trigger_count, dyt_system_status->los_age_s, dyt_system_status->frame_dt_s, dyt_system_status->delay_s, dyt_system_status->los_ned, dyt_system_status->omega_los_ned, dyt_system_status->velocity_sp, dyt_system_status->acceleration_sp, dyt_system_status->yaw_sp, dyt_system_status->yaw_rate_sp, dyt_system_status->status_flags, dyt_system_status->vehicle_type, dyt_system_status->guidance_phase, dyt_system_status->gcs_phase_request, dyt_system_status->command_phase, dyt_system_status->command_result, dyt_system_status->guidance_state, dyt_system_status->requested_submode, dyt_system_status->active_submode, dyt_system_status->lost_reason);
}

/**
 * @brief Send a dyt_system_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms  Timestamp since boot.
 * @param command_sequence  Sequence of the latest DYT_GUIDANCE_COMMAND.
 * @param net_trigger_count  Number of net-capture trigger commands sent since boot.
 * @param los_age_s  Age of the latest line-of-sight sample.
 * @param frame_dt_s  Payload frame interval.
 * @param delay_s  Configured guidance delay.
 * @param los_ned  Filtered line-of-sight vector in NED.
 * @param omega_los_ned  Line-of-sight angular rate in NED.
 * @param velocity_sp  Guidance velocity setpoint in NED.
 * @param acceleration_sp  Guidance acceleration setpoint in NED.
 * @param yaw_sp  Guidance yaw setpoint.
 * @param yaw_rate_sp  Guidance yaw-rate setpoint.
 * @param status_flags  Bitmask: 0 armed, 1 guidance active, 2 target locked, 3 DYT controls vehicle, 4 target fresh, 5 intercept allowed, 6 midcourse active, 7 midcourse target valid, 8 net trigger sent.
 * @param vehicle_type  0 unknown, 1 fighter, 2 net-capture.
 * @param guidance_phase  Actual phase: 0 disarmed, 1 initial/takeoff, 2 midcourse, 3 terminal.
 * @param gcs_phase_request  Accepted active GCS phase request, or zero.
 * @param command_phase  Phase in the latest ground command.
 * @param command_result  0 none, 1 pending, 2 accepted, 3 denied, 4 failed.
 * @param guidance_state  Detailed DYT guidance state.
 * @param requested_submode  Requested terminal submode.
 * @param active_submode  Active terminal submode.
 * @param lost_reason  Guidance loss reason.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dyt_system_status_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t command_sequence, uint32_t net_trigger_count, float los_age_s, float frame_dt_s, float delay_s, const float *los_ned, const float *omega_los_ned, const float *velocity_sp, const float *acceleration_sp, float yaw_sp, float yaw_rate_sp, uint16_t status_flags, uint8_t vehicle_type, uint8_t guidance_phase, uint8_t gcs_phase_request, uint8_t command_phase, uint8_t command_result, uint8_t guidance_state, uint8_t requested_submode, uint8_t active_submode, uint8_t lost_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, command_sequence);
    _mav_put_uint32_t(buf, 8, net_trigger_count);
    _mav_put_float(buf, 12, los_age_s);
    _mav_put_float(buf, 16, frame_dt_s);
    _mav_put_float(buf, 20, delay_s);
    _mav_put_float(buf, 72, yaw_sp);
    _mav_put_float(buf, 76, yaw_rate_sp);
    _mav_put_uint16_t(buf, 80, status_flags);
    _mav_put_uint8_t(buf, 82, vehicle_type);
    _mav_put_uint8_t(buf, 83, guidance_phase);
    _mav_put_uint8_t(buf, 84, gcs_phase_request);
    _mav_put_uint8_t(buf, 85, command_phase);
    _mav_put_uint8_t(buf, 86, command_result);
    _mav_put_uint8_t(buf, 87, guidance_state);
    _mav_put_uint8_t(buf, 88, requested_submode);
    _mav_put_uint8_t(buf, 89, active_submode);
    _mav_put_uint8_t(buf, 90, lost_reason);
    _mav_put_float_array(buf, 24, los_ned, 3);
    _mav_put_float_array(buf, 36, omega_los_ned, 3);
    _mav_put_float_array(buf, 48, velocity_sp, 3);
    _mav_put_float_array(buf, 60, acceleration_sp, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS, buf, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
#else
    mavlink_dyt_system_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.command_sequence = command_sequence;
    packet.net_trigger_count = net_trigger_count;
    packet.los_age_s = los_age_s;
    packet.frame_dt_s = frame_dt_s;
    packet.delay_s = delay_s;
    packet.yaw_sp = yaw_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.status_flags = status_flags;
    packet.vehicle_type = vehicle_type;
    packet.guidance_phase = guidance_phase;
    packet.gcs_phase_request = gcs_phase_request;
    packet.command_phase = command_phase;
    packet.command_result = command_result;
    packet.guidance_state = guidance_state;
    packet.requested_submode = requested_submode;
    packet.active_submode = active_submode;
    packet.lost_reason = lost_reason;
    mav_array_memcpy(packet.los_ned, los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.omega_los_ned, omega_los_ned, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.acceleration_sp, acceleration_sp, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS, (const char *)&packet, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
#endif
}

/**
 * @brief Send a dyt_system_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dyt_system_status_send_struct(mavlink_channel_t chan, const mavlink_dyt_system_status_t* dyt_system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dyt_system_status_send(chan, dyt_system_status->time_boot_ms, dyt_system_status->command_sequence, dyt_system_status->net_trigger_count, dyt_system_status->los_age_s, dyt_system_status->frame_dt_s, dyt_system_status->delay_s, dyt_system_status->los_ned, dyt_system_status->omega_los_ned, dyt_system_status->velocity_sp, dyt_system_status->acceleration_sp, dyt_system_status->yaw_sp, dyt_system_status->yaw_rate_sp, dyt_system_status->status_flags, dyt_system_status->vehicle_type, dyt_system_status->guidance_phase, dyt_system_status->gcs_phase_request, dyt_system_status->command_phase, dyt_system_status->command_result, dyt_system_status->guidance_state, dyt_system_status->requested_submode, dyt_system_status->active_submode, dyt_system_status->lost_reason);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS, (const char *)dyt_system_status, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dyt_system_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t command_sequence, uint32_t net_trigger_count, float los_age_s, float frame_dt_s, float delay_s, const float *los_ned, const float *omega_los_ned, const float *velocity_sp, const float *acceleration_sp, float yaw_sp, float yaw_rate_sp, uint16_t status_flags, uint8_t vehicle_type, uint8_t guidance_phase, uint8_t gcs_phase_request, uint8_t command_phase, uint8_t command_result, uint8_t guidance_state, uint8_t requested_submode, uint8_t active_submode, uint8_t lost_reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, command_sequence);
    _mav_put_uint32_t(buf, 8, net_trigger_count);
    _mav_put_float(buf, 12, los_age_s);
    _mav_put_float(buf, 16, frame_dt_s);
    _mav_put_float(buf, 20, delay_s);
    _mav_put_float(buf, 72, yaw_sp);
    _mav_put_float(buf, 76, yaw_rate_sp);
    _mav_put_uint16_t(buf, 80, status_flags);
    _mav_put_uint8_t(buf, 82, vehicle_type);
    _mav_put_uint8_t(buf, 83, guidance_phase);
    _mav_put_uint8_t(buf, 84, gcs_phase_request);
    _mav_put_uint8_t(buf, 85, command_phase);
    _mav_put_uint8_t(buf, 86, command_result);
    _mav_put_uint8_t(buf, 87, guidance_state);
    _mav_put_uint8_t(buf, 88, requested_submode);
    _mav_put_uint8_t(buf, 89, active_submode);
    _mav_put_uint8_t(buf, 90, lost_reason);
    _mav_put_float_array(buf, 24, los_ned, 3);
    _mav_put_float_array(buf, 36, omega_los_ned, 3);
    _mav_put_float_array(buf, 48, velocity_sp, 3);
    _mav_put_float_array(buf, 60, acceleration_sp, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS, buf, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
#else
    mavlink_dyt_system_status_t *packet = (mavlink_dyt_system_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->command_sequence = command_sequence;
    packet->net_trigger_count = net_trigger_count;
    packet->los_age_s = los_age_s;
    packet->frame_dt_s = frame_dt_s;
    packet->delay_s = delay_s;
    packet->yaw_sp = yaw_sp;
    packet->yaw_rate_sp = yaw_rate_sp;
    packet->status_flags = status_flags;
    packet->vehicle_type = vehicle_type;
    packet->guidance_phase = guidance_phase;
    packet->gcs_phase_request = gcs_phase_request;
    packet->command_phase = command_phase;
    packet->command_result = command_result;
    packet->guidance_state = guidance_state;
    packet->requested_submode = requested_submode;
    packet->active_submode = active_submode;
    packet->lost_reason = lost_reason;
    mav_array_memcpy(packet->los_ned, los_ned, sizeof(float)*3);
    mav_array_memcpy(packet->omega_los_ned, omega_los_ned, sizeof(float)*3);
    mav_array_memcpy(packet->velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet->acceleration_sp, acceleration_sp, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS, (const char *)packet, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE DYT_SYSTEM_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from dyt_system_status message
 *
 * @return  Timestamp since boot.
 */
static inline uint32_t mavlink_msg_dyt_system_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field command_sequence from dyt_system_status message
 *
 * @return  Sequence of the latest DYT_GUIDANCE_COMMAND.
 */
static inline uint32_t mavlink_msg_dyt_system_status_get_command_sequence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field net_trigger_count from dyt_system_status message
 *
 * @return  Number of net-capture trigger commands sent since boot.
 */
static inline uint32_t mavlink_msg_dyt_system_status_get_net_trigger_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field los_age_s from dyt_system_status message
 *
 * @return  Age of the latest line-of-sight sample.
 */
static inline float mavlink_msg_dyt_system_status_get_los_age_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field frame_dt_s from dyt_system_status message
 *
 * @return  Payload frame interval.
 */
static inline float mavlink_msg_dyt_system_status_get_frame_dt_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field delay_s from dyt_system_status message
 *
 * @return  Configured guidance delay.
 */
static inline float mavlink_msg_dyt_system_status_get_delay_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field los_ned from dyt_system_status message
 *
 * @return  Filtered line-of-sight vector in NED.
 */
static inline uint16_t mavlink_msg_dyt_system_status_get_los_ned(const mavlink_message_t* msg, float *los_ned)
{
    return _MAV_RETURN_float_array(msg, los_ned, 3,  24);
}

/**
 * @brief Get field omega_los_ned from dyt_system_status message
 *
 * @return  Line-of-sight angular rate in NED.
 */
static inline uint16_t mavlink_msg_dyt_system_status_get_omega_los_ned(const mavlink_message_t* msg, float *omega_los_ned)
{
    return _MAV_RETURN_float_array(msg, omega_los_ned, 3,  36);
}

/**
 * @brief Get field velocity_sp from dyt_system_status message
 *
 * @return  Guidance velocity setpoint in NED.
 */
static inline uint16_t mavlink_msg_dyt_system_status_get_velocity_sp(const mavlink_message_t* msg, float *velocity_sp)
{
    return _MAV_RETURN_float_array(msg, velocity_sp, 3,  48);
}

/**
 * @brief Get field acceleration_sp from dyt_system_status message
 *
 * @return  Guidance acceleration setpoint in NED.
 */
static inline uint16_t mavlink_msg_dyt_system_status_get_acceleration_sp(const mavlink_message_t* msg, float *acceleration_sp)
{
    return _MAV_RETURN_float_array(msg, acceleration_sp, 3,  60);
}

/**
 * @brief Get field yaw_sp from dyt_system_status message
 *
 * @return  Guidance yaw setpoint.
 */
static inline float mavlink_msg_dyt_system_status_get_yaw_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field yaw_rate_sp from dyt_system_status message
 *
 * @return  Guidance yaw-rate setpoint.
 */
static inline float mavlink_msg_dyt_system_status_get_yaw_rate_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field status_flags from dyt_system_status message
 *
 * @return  Bitmask: 0 armed, 1 guidance active, 2 target locked, 3 DYT controls vehicle, 4 target fresh, 5 intercept allowed, 6 midcourse active, 7 midcourse target valid, 8 net trigger sent.
 */
static inline uint16_t mavlink_msg_dyt_system_status_get_status_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  80);
}

/**
 * @brief Get field vehicle_type from dyt_system_status message
 *
 * @return  0 unknown, 1 fighter, 2 net-capture.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_vehicle_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  82);
}

/**
 * @brief Get field guidance_phase from dyt_system_status message
 *
 * @return  Actual phase: 0 disarmed, 1 initial/takeoff, 2 midcourse, 3 terminal.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_guidance_phase(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  83);
}

/**
 * @brief Get field gcs_phase_request from dyt_system_status message
 *
 * @return  Accepted active GCS phase request, or zero.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_gcs_phase_request(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  84);
}

/**
 * @brief Get field command_phase from dyt_system_status message
 *
 * @return  Phase in the latest ground command.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_command_phase(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  85);
}

/**
 * @brief Get field command_result from dyt_system_status message
 *
 * @return  0 none, 1 pending, 2 accepted, 3 denied, 4 failed.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_command_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  86);
}

/**
 * @brief Get field guidance_state from dyt_system_status message
 *
 * @return  Detailed DYT guidance state.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_guidance_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  87);
}

/**
 * @brief Get field requested_submode from dyt_system_status message
 *
 * @return  Requested terminal submode.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_requested_submode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  88);
}

/**
 * @brief Get field active_submode from dyt_system_status message
 *
 * @return  Active terminal submode.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_active_submode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  89);
}

/**
 * @brief Get field lost_reason from dyt_system_status message
 *
 * @return  Guidance loss reason.
 */
static inline uint8_t mavlink_msg_dyt_system_status_get_lost_reason(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  90);
}

/**
 * @brief Decode a dyt_system_status message into a struct
 *
 * @param msg The message to decode
 * @param dyt_system_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_dyt_system_status_decode(const mavlink_message_t* msg, mavlink_dyt_system_status_t* dyt_system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dyt_system_status->time_boot_ms = mavlink_msg_dyt_system_status_get_time_boot_ms(msg);
    dyt_system_status->command_sequence = mavlink_msg_dyt_system_status_get_command_sequence(msg);
    dyt_system_status->net_trigger_count = mavlink_msg_dyt_system_status_get_net_trigger_count(msg);
    dyt_system_status->los_age_s = mavlink_msg_dyt_system_status_get_los_age_s(msg);
    dyt_system_status->frame_dt_s = mavlink_msg_dyt_system_status_get_frame_dt_s(msg);
    dyt_system_status->delay_s = mavlink_msg_dyt_system_status_get_delay_s(msg);
    mavlink_msg_dyt_system_status_get_los_ned(msg, dyt_system_status->los_ned);
    mavlink_msg_dyt_system_status_get_omega_los_ned(msg, dyt_system_status->omega_los_ned);
    mavlink_msg_dyt_system_status_get_velocity_sp(msg, dyt_system_status->velocity_sp);
    mavlink_msg_dyt_system_status_get_acceleration_sp(msg, dyt_system_status->acceleration_sp);
    dyt_system_status->yaw_sp = mavlink_msg_dyt_system_status_get_yaw_sp(msg);
    dyt_system_status->yaw_rate_sp = mavlink_msg_dyt_system_status_get_yaw_rate_sp(msg);
    dyt_system_status->status_flags = mavlink_msg_dyt_system_status_get_status_flags(msg);
    dyt_system_status->vehicle_type = mavlink_msg_dyt_system_status_get_vehicle_type(msg);
    dyt_system_status->guidance_phase = mavlink_msg_dyt_system_status_get_guidance_phase(msg);
    dyt_system_status->gcs_phase_request = mavlink_msg_dyt_system_status_get_gcs_phase_request(msg);
    dyt_system_status->command_phase = mavlink_msg_dyt_system_status_get_command_phase(msg);
    dyt_system_status->command_result = mavlink_msg_dyt_system_status_get_command_result(msg);
    dyt_system_status->guidance_state = mavlink_msg_dyt_system_status_get_guidance_state(msg);
    dyt_system_status->requested_submode = mavlink_msg_dyt_system_status_get_requested_submode(msg);
    dyt_system_status->active_submode = mavlink_msg_dyt_system_status_get_active_submode(msg);
    dyt_system_status->lost_reason = mavlink_msg_dyt_system_status_get_lost_reason(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN? msg->len : MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN;
        memset(dyt_system_status, 0, MAVLINK_MSG_ID_DYT_SYSTEM_STATUS_LEN);
    memcpy(dyt_system_status, _MAV_PAYLOAD(msg), len);
#endif
}
