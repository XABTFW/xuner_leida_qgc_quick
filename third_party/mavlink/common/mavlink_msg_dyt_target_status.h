#pragma once
// MESSAGE DYT_TARGET_STATUS PACKING

#define MAVLINK_MSG_ID_DYT_TARGET_STATUS 12927


typedef struct __mavlink_dyt_target_status_t {
 uint32_t time_boot_ms; /*<  Reception timestamp since boot.*/
 uint32_t time_sample_ms; /*<  Payload sample timestamp since boot.*/
 uint32_t frame_counter; /*<  Payload frame counter.*/
 float los_x_rad; /*<  Horizontal line-of-sight error.*/
 float los_y_rad; /*<  Vertical line-of-sight error.*/
 float gimbal_roll_rad; /*<  Gimbal roll angle.*/
 float gimbal_pitch_frame_rad; /*<  Gimbal pitch frame angle.*/
 float gimbal_pitch_rad; /*<  Gimbal pitch attitude angle.*/
 float gimbal_yaw_rad; /*<  Gimbal yaw angle.*/
 float gimbal_roll_rate_rad_s; /*<  Gimbal roll rate.*/
 float gimbal_pitch_rate_rad_s; /*<  Gimbal pitch rate.*/
 float gimbal_yaw_rate_rad_s; /*<  Gimbal yaw rate.*/
 float bbox_width_px; /*<  Tracking box width.*/
 float bbox_height_px; /*<  Tracking box height.*/
 float range_m; /*<  Payload range measurement.*/
 float zoom_ratio; /*<  Payload zoom ratio.*/
 float frame_dt_s; /*<  Payload frame interval.*/
 float last_rx_age_s; /*<  Age of the last received payload byte.*/
 uint16_t parse_error_count; /*<  Payload parser error count.*/
 uint16_t target_flags; /*<  Bitmask: 0 valid, 1 auto hint, 2 image enhance, 3 recording, 4 motor on, 5 follow mode, 6 laser on, 7 self-test done, 8 gyro calibration failed, 9 servo fault, 10 image-board fault.*/
 uint8_t tracking_state; /*<  Tracking state.*/
 uint8_t video_source; /*<  Active video source.*/
 uint8_t tracking_algorithm; /*<  Tracking algorithm.*/
 uint8_t status1; /*<  Raw payload status byte 1.*/
 uint8_t status2; /*<  Raw payload status byte 2.*/
 uint8_t status3; /*<  Raw payload status byte 3.*/
 uint8_t self_test_raw; /*<  Raw self-test byte.*/
} mavlink_dyt_target_status_t;

#define MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN 83
#define MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN 83
#define MAVLINK_MSG_ID_12927_LEN 83
#define MAVLINK_MSG_ID_12927_MIN_LEN 83

#define MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC 157
#define MAVLINK_MSG_ID_12927_CRC 157



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DYT_TARGET_STATUS { \
    12927, \
    "DYT_TARGET_STATUS", \
    27, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_target_status_t, time_boot_ms) }, \
         { "time_sample_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dyt_target_status_t, time_sample_ms) }, \
         { "frame_counter", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_dyt_target_status_t, frame_counter) }, \
         { "los_x_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dyt_target_status_t, los_x_rad) }, \
         { "los_y_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dyt_target_status_t, los_y_rad) }, \
         { "gimbal_roll_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dyt_target_status_t, gimbal_roll_rad) }, \
         { "gimbal_pitch_frame_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dyt_target_status_t, gimbal_pitch_frame_rad) }, \
         { "gimbal_pitch_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dyt_target_status_t, gimbal_pitch_rad) }, \
         { "gimbal_yaw_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dyt_target_status_t, gimbal_yaw_rad) }, \
         { "gimbal_roll_rate_rad_s", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dyt_target_status_t, gimbal_roll_rate_rad_s) }, \
         { "gimbal_pitch_rate_rad_s", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dyt_target_status_t, gimbal_pitch_rate_rad_s) }, \
         { "gimbal_yaw_rate_rad_s", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dyt_target_status_t, gimbal_yaw_rate_rad_s) }, \
         { "bbox_width_px", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dyt_target_status_t, bbox_width_px) }, \
         { "bbox_height_px", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dyt_target_status_t, bbox_height_px) }, \
         { "range_m", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dyt_target_status_t, range_m) }, \
         { "zoom_ratio", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dyt_target_status_t, zoom_ratio) }, \
         { "frame_dt_s", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dyt_target_status_t, frame_dt_s) }, \
         { "last_rx_age_s", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_dyt_target_status_t, last_rx_age_s) }, \
         { "parse_error_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_dyt_target_status_t, parse_error_count) }, \
         { "target_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 74, offsetof(mavlink_dyt_target_status_t, target_flags) }, \
         { "tracking_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 76, offsetof(mavlink_dyt_target_status_t, tracking_state) }, \
         { "video_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 77, offsetof(mavlink_dyt_target_status_t, video_source) }, \
         { "tracking_algorithm", NULL, MAVLINK_TYPE_UINT8_T, 0, 78, offsetof(mavlink_dyt_target_status_t, tracking_algorithm) }, \
         { "status1", NULL, MAVLINK_TYPE_UINT8_T, 0, 79, offsetof(mavlink_dyt_target_status_t, status1) }, \
         { "status2", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_dyt_target_status_t, status2) }, \
         { "status3", NULL, MAVLINK_TYPE_UINT8_T, 0, 81, offsetof(mavlink_dyt_target_status_t, status3) }, \
         { "self_test_raw", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_dyt_target_status_t, self_test_raw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DYT_TARGET_STATUS { \
    "DYT_TARGET_STATUS", \
    27, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_dyt_target_status_t, time_boot_ms) }, \
         { "time_sample_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_dyt_target_status_t, time_sample_ms) }, \
         { "frame_counter", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_dyt_target_status_t, frame_counter) }, \
         { "los_x_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_dyt_target_status_t, los_x_rad) }, \
         { "los_y_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_dyt_target_status_t, los_y_rad) }, \
         { "gimbal_roll_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_dyt_target_status_t, gimbal_roll_rad) }, \
         { "gimbal_pitch_frame_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_dyt_target_status_t, gimbal_pitch_frame_rad) }, \
         { "gimbal_pitch_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_dyt_target_status_t, gimbal_pitch_rad) }, \
         { "gimbal_yaw_rad", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_dyt_target_status_t, gimbal_yaw_rad) }, \
         { "gimbal_roll_rate_rad_s", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_dyt_target_status_t, gimbal_roll_rate_rad_s) }, \
         { "gimbal_pitch_rate_rad_s", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_dyt_target_status_t, gimbal_pitch_rate_rad_s) }, \
         { "gimbal_yaw_rate_rad_s", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_dyt_target_status_t, gimbal_yaw_rate_rad_s) }, \
         { "bbox_width_px", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_dyt_target_status_t, bbox_width_px) }, \
         { "bbox_height_px", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_dyt_target_status_t, bbox_height_px) }, \
         { "range_m", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_dyt_target_status_t, range_m) }, \
         { "zoom_ratio", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_dyt_target_status_t, zoom_ratio) }, \
         { "frame_dt_s", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_dyt_target_status_t, frame_dt_s) }, \
         { "last_rx_age_s", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_dyt_target_status_t, last_rx_age_s) }, \
         { "parse_error_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_dyt_target_status_t, parse_error_count) }, \
         { "target_flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 74, offsetof(mavlink_dyt_target_status_t, target_flags) }, \
         { "tracking_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 76, offsetof(mavlink_dyt_target_status_t, tracking_state) }, \
         { "video_source", NULL, MAVLINK_TYPE_UINT8_T, 0, 77, offsetof(mavlink_dyt_target_status_t, video_source) }, \
         { "tracking_algorithm", NULL, MAVLINK_TYPE_UINT8_T, 0, 78, offsetof(mavlink_dyt_target_status_t, tracking_algorithm) }, \
         { "status1", NULL, MAVLINK_TYPE_UINT8_T, 0, 79, offsetof(mavlink_dyt_target_status_t, status1) }, \
         { "status2", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_dyt_target_status_t, status2) }, \
         { "status3", NULL, MAVLINK_TYPE_UINT8_T, 0, 81, offsetof(mavlink_dyt_target_status_t, status3) }, \
         { "self_test_raw", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_dyt_target_status_t, self_test_raw) }, \
         } \
}
#endif

/**
 * @brief Pack a dyt_target_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Payload sample timestamp since boot.
 * @param frame_counter  Payload frame counter.
 * @param los_x_rad  Horizontal line-of-sight error.
 * @param los_y_rad  Vertical line-of-sight error.
 * @param gimbal_roll_rad  Gimbal roll angle.
 * @param gimbal_pitch_frame_rad  Gimbal pitch frame angle.
 * @param gimbal_pitch_rad  Gimbal pitch attitude angle.
 * @param gimbal_yaw_rad  Gimbal yaw angle.
 * @param gimbal_roll_rate_rad_s  Gimbal roll rate.
 * @param gimbal_pitch_rate_rad_s  Gimbal pitch rate.
 * @param gimbal_yaw_rate_rad_s  Gimbal yaw rate.
 * @param bbox_width_px  Tracking box width.
 * @param bbox_height_px  Tracking box height.
 * @param range_m  Payload range measurement.
 * @param zoom_ratio  Payload zoom ratio.
 * @param frame_dt_s  Payload frame interval.
 * @param last_rx_age_s  Age of the last received payload byte.
 * @param parse_error_count  Payload parser error count.
 * @param target_flags  Bitmask: 0 valid, 1 auto hint, 2 image enhance, 3 recording, 4 motor on, 5 follow mode, 6 laser on, 7 self-test done, 8 gyro calibration failed, 9 servo fault, 10 image-board fault.
 * @param tracking_state  Tracking state.
 * @param video_source  Active video source.
 * @param tracking_algorithm  Tracking algorithm.
 * @param status1  Raw payload status byte 1.
 * @param status2  Raw payload status byte 2.
 * @param status3  Raw payload status byte 3.
 * @param self_test_raw  Raw self-test byte.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_target_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t frame_counter, float los_x_rad, float los_y_rad, float gimbal_roll_rad, float gimbal_pitch_frame_rad, float gimbal_pitch_rad, float gimbal_yaw_rad, float gimbal_roll_rate_rad_s, float gimbal_pitch_rate_rad_s, float gimbal_yaw_rate_rad_s, float bbox_width_px, float bbox_height_px, float range_m, float zoom_ratio, float frame_dt_s, float last_rx_age_s, uint16_t parse_error_count, uint16_t target_flags, uint8_t tracking_state, uint8_t video_source, uint8_t tracking_algorithm, uint8_t status1, uint8_t status2, uint8_t status3, uint8_t self_test_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, frame_counter);
    _mav_put_float(buf, 12, los_x_rad);
    _mav_put_float(buf, 16, los_y_rad);
    _mav_put_float(buf, 20, gimbal_roll_rad);
    _mav_put_float(buf, 24, gimbal_pitch_frame_rad);
    _mav_put_float(buf, 28, gimbal_pitch_rad);
    _mav_put_float(buf, 32, gimbal_yaw_rad);
    _mav_put_float(buf, 36, gimbal_roll_rate_rad_s);
    _mav_put_float(buf, 40, gimbal_pitch_rate_rad_s);
    _mav_put_float(buf, 44, gimbal_yaw_rate_rad_s);
    _mav_put_float(buf, 48, bbox_width_px);
    _mav_put_float(buf, 52, bbox_height_px);
    _mav_put_float(buf, 56, range_m);
    _mav_put_float(buf, 60, zoom_ratio);
    _mav_put_float(buf, 64, frame_dt_s);
    _mav_put_float(buf, 68, last_rx_age_s);
    _mav_put_uint16_t(buf, 72, parse_error_count);
    _mav_put_uint16_t(buf, 74, target_flags);
    _mav_put_uint8_t(buf, 76, tracking_state);
    _mav_put_uint8_t(buf, 77, video_source);
    _mav_put_uint8_t(buf, 78, tracking_algorithm);
    _mav_put_uint8_t(buf, 79, status1);
    _mav_put_uint8_t(buf, 80, status2);
    _mav_put_uint8_t(buf, 81, status3);
    _mav_put_uint8_t(buf, 82, self_test_raw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#else
    mavlink_dyt_target_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.frame_counter = frame_counter;
    packet.los_x_rad = los_x_rad;
    packet.los_y_rad = los_y_rad;
    packet.gimbal_roll_rad = gimbal_roll_rad;
    packet.gimbal_pitch_frame_rad = gimbal_pitch_frame_rad;
    packet.gimbal_pitch_rad = gimbal_pitch_rad;
    packet.gimbal_yaw_rad = gimbal_yaw_rad;
    packet.gimbal_roll_rate_rad_s = gimbal_roll_rate_rad_s;
    packet.gimbal_pitch_rate_rad_s = gimbal_pitch_rate_rad_s;
    packet.gimbal_yaw_rate_rad_s = gimbal_yaw_rate_rad_s;
    packet.bbox_width_px = bbox_width_px;
    packet.bbox_height_px = bbox_height_px;
    packet.range_m = range_m;
    packet.zoom_ratio = zoom_ratio;
    packet.frame_dt_s = frame_dt_s;
    packet.last_rx_age_s = last_rx_age_s;
    packet.parse_error_count = parse_error_count;
    packet.target_flags = target_flags;
    packet.tracking_state = tracking_state;
    packet.video_source = video_source;
    packet.tracking_algorithm = tracking_algorithm;
    packet.status1 = status1;
    packet.status2 = status2;
    packet.status3 = status3;
    packet.self_test_raw = self_test_raw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_TARGET_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
}

/**
 * @brief Pack a dyt_target_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Payload sample timestamp since boot.
 * @param frame_counter  Payload frame counter.
 * @param los_x_rad  Horizontal line-of-sight error.
 * @param los_y_rad  Vertical line-of-sight error.
 * @param gimbal_roll_rad  Gimbal roll angle.
 * @param gimbal_pitch_frame_rad  Gimbal pitch frame angle.
 * @param gimbal_pitch_rad  Gimbal pitch attitude angle.
 * @param gimbal_yaw_rad  Gimbal yaw angle.
 * @param gimbal_roll_rate_rad_s  Gimbal roll rate.
 * @param gimbal_pitch_rate_rad_s  Gimbal pitch rate.
 * @param gimbal_yaw_rate_rad_s  Gimbal yaw rate.
 * @param bbox_width_px  Tracking box width.
 * @param bbox_height_px  Tracking box height.
 * @param range_m  Payload range measurement.
 * @param zoom_ratio  Payload zoom ratio.
 * @param frame_dt_s  Payload frame interval.
 * @param last_rx_age_s  Age of the last received payload byte.
 * @param parse_error_count  Payload parser error count.
 * @param target_flags  Bitmask: 0 valid, 1 auto hint, 2 image enhance, 3 recording, 4 motor on, 5 follow mode, 6 laser on, 7 self-test done, 8 gyro calibration failed, 9 servo fault, 10 image-board fault.
 * @param tracking_state  Tracking state.
 * @param video_source  Active video source.
 * @param tracking_algorithm  Tracking algorithm.
 * @param status1  Raw payload status byte 1.
 * @param status2  Raw payload status byte 2.
 * @param status3  Raw payload status byte 3.
 * @param self_test_raw  Raw self-test byte.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_target_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t frame_counter, float los_x_rad, float los_y_rad, float gimbal_roll_rad, float gimbal_pitch_frame_rad, float gimbal_pitch_rad, float gimbal_yaw_rad, float gimbal_roll_rate_rad_s, float gimbal_pitch_rate_rad_s, float gimbal_yaw_rate_rad_s, float bbox_width_px, float bbox_height_px, float range_m, float zoom_ratio, float frame_dt_s, float last_rx_age_s, uint16_t parse_error_count, uint16_t target_flags, uint8_t tracking_state, uint8_t video_source, uint8_t tracking_algorithm, uint8_t status1, uint8_t status2, uint8_t status3, uint8_t self_test_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, frame_counter);
    _mav_put_float(buf, 12, los_x_rad);
    _mav_put_float(buf, 16, los_y_rad);
    _mav_put_float(buf, 20, gimbal_roll_rad);
    _mav_put_float(buf, 24, gimbal_pitch_frame_rad);
    _mav_put_float(buf, 28, gimbal_pitch_rad);
    _mav_put_float(buf, 32, gimbal_yaw_rad);
    _mav_put_float(buf, 36, gimbal_roll_rate_rad_s);
    _mav_put_float(buf, 40, gimbal_pitch_rate_rad_s);
    _mav_put_float(buf, 44, gimbal_yaw_rate_rad_s);
    _mav_put_float(buf, 48, bbox_width_px);
    _mav_put_float(buf, 52, bbox_height_px);
    _mav_put_float(buf, 56, range_m);
    _mav_put_float(buf, 60, zoom_ratio);
    _mav_put_float(buf, 64, frame_dt_s);
    _mav_put_float(buf, 68, last_rx_age_s);
    _mav_put_uint16_t(buf, 72, parse_error_count);
    _mav_put_uint16_t(buf, 74, target_flags);
    _mav_put_uint8_t(buf, 76, tracking_state);
    _mav_put_uint8_t(buf, 77, video_source);
    _mav_put_uint8_t(buf, 78, tracking_algorithm);
    _mav_put_uint8_t(buf, 79, status1);
    _mav_put_uint8_t(buf, 80, status2);
    _mav_put_uint8_t(buf, 81, status3);
    _mav_put_uint8_t(buf, 82, self_test_raw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#else
    mavlink_dyt_target_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.frame_counter = frame_counter;
    packet.los_x_rad = los_x_rad;
    packet.los_y_rad = los_y_rad;
    packet.gimbal_roll_rad = gimbal_roll_rad;
    packet.gimbal_pitch_frame_rad = gimbal_pitch_frame_rad;
    packet.gimbal_pitch_rad = gimbal_pitch_rad;
    packet.gimbal_yaw_rad = gimbal_yaw_rad;
    packet.gimbal_roll_rate_rad_s = gimbal_roll_rate_rad_s;
    packet.gimbal_pitch_rate_rad_s = gimbal_pitch_rate_rad_s;
    packet.gimbal_yaw_rate_rad_s = gimbal_yaw_rate_rad_s;
    packet.bbox_width_px = bbox_width_px;
    packet.bbox_height_px = bbox_height_px;
    packet.range_m = range_m;
    packet.zoom_ratio = zoom_ratio;
    packet.frame_dt_s = frame_dt_s;
    packet.last_rx_age_s = last_rx_age_s;
    packet.parse_error_count = parse_error_count;
    packet.target_flags = target_flags;
    packet.tracking_state = tracking_state;
    packet.video_source = video_source;
    packet.tracking_algorithm = tracking_algorithm;
    packet.status1 = status1;
    packet.status2 = status2;
    packet.status3 = status3;
    packet.self_test_raw = self_test_raw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_TARGET_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#endif
}

/**
 * @brief Pack a dyt_target_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Payload sample timestamp since boot.
 * @param frame_counter  Payload frame counter.
 * @param los_x_rad  Horizontal line-of-sight error.
 * @param los_y_rad  Vertical line-of-sight error.
 * @param gimbal_roll_rad  Gimbal roll angle.
 * @param gimbal_pitch_frame_rad  Gimbal pitch frame angle.
 * @param gimbal_pitch_rad  Gimbal pitch attitude angle.
 * @param gimbal_yaw_rad  Gimbal yaw angle.
 * @param gimbal_roll_rate_rad_s  Gimbal roll rate.
 * @param gimbal_pitch_rate_rad_s  Gimbal pitch rate.
 * @param gimbal_yaw_rate_rad_s  Gimbal yaw rate.
 * @param bbox_width_px  Tracking box width.
 * @param bbox_height_px  Tracking box height.
 * @param range_m  Payload range measurement.
 * @param zoom_ratio  Payload zoom ratio.
 * @param frame_dt_s  Payload frame interval.
 * @param last_rx_age_s  Age of the last received payload byte.
 * @param parse_error_count  Payload parser error count.
 * @param target_flags  Bitmask: 0 valid, 1 auto hint, 2 image enhance, 3 recording, 4 motor on, 5 follow mode, 6 laser on, 7 self-test done, 8 gyro calibration failed, 9 servo fault, 10 image-board fault.
 * @param tracking_state  Tracking state.
 * @param video_source  Active video source.
 * @param tracking_algorithm  Tracking algorithm.
 * @param status1  Raw payload status byte 1.
 * @param status2  Raw payload status byte 2.
 * @param status3  Raw payload status byte 3.
 * @param self_test_raw  Raw self-test byte.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dyt_target_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t time_sample_ms,uint32_t frame_counter,float los_x_rad,float los_y_rad,float gimbal_roll_rad,float gimbal_pitch_frame_rad,float gimbal_pitch_rad,float gimbal_yaw_rad,float gimbal_roll_rate_rad_s,float gimbal_pitch_rate_rad_s,float gimbal_yaw_rate_rad_s,float bbox_width_px,float bbox_height_px,float range_m,float zoom_ratio,float frame_dt_s,float last_rx_age_s,uint16_t parse_error_count,uint16_t target_flags,uint8_t tracking_state,uint8_t video_source,uint8_t tracking_algorithm,uint8_t status1,uint8_t status2,uint8_t status3,uint8_t self_test_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, frame_counter);
    _mav_put_float(buf, 12, los_x_rad);
    _mav_put_float(buf, 16, los_y_rad);
    _mav_put_float(buf, 20, gimbal_roll_rad);
    _mav_put_float(buf, 24, gimbal_pitch_frame_rad);
    _mav_put_float(buf, 28, gimbal_pitch_rad);
    _mav_put_float(buf, 32, gimbal_yaw_rad);
    _mav_put_float(buf, 36, gimbal_roll_rate_rad_s);
    _mav_put_float(buf, 40, gimbal_pitch_rate_rad_s);
    _mav_put_float(buf, 44, gimbal_yaw_rate_rad_s);
    _mav_put_float(buf, 48, bbox_width_px);
    _mav_put_float(buf, 52, bbox_height_px);
    _mav_put_float(buf, 56, range_m);
    _mav_put_float(buf, 60, zoom_ratio);
    _mav_put_float(buf, 64, frame_dt_s);
    _mav_put_float(buf, 68, last_rx_age_s);
    _mav_put_uint16_t(buf, 72, parse_error_count);
    _mav_put_uint16_t(buf, 74, target_flags);
    _mav_put_uint8_t(buf, 76, tracking_state);
    _mav_put_uint8_t(buf, 77, video_source);
    _mav_put_uint8_t(buf, 78, tracking_algorithm);
    _mav_put_uint8_t(buf, 79, status1);
    _mav_put_uint8_t(buf, 80, status2);
    _mav_put_uint8_t(buf, 81, status3);
    _mav_put_uint8_t(buf, 82, self_test_raw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#else
    mavlink_dyt_target_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.frame_counter = frame_counter;
    packet.los_x_rad = los_x_rad;
    packet.los_y_rad = los_y_rad;
    packet.gimbal_roll_rad = gimbal_roll_rad;
    packet.gimbal_pitch_frame_rad = gimbal_pitch_frame_rad;
    packet.gimbal_pitch_rad = gimbal_pitch_rad;
    packet.gimbal_yaw_rad = gimbal_yaw_rad;
    packet.gimbal_roll_rate_rad_s = gimbal_roll_rate_rad_s;
    packet.gimbal_pitch_rate_rad_s = gimbal_pitch_rate_rad_s;
    packet.gimbal_yaw_rate_rad_s = gimbal_yaw_rate_rad_s;
    packet.bbox_width_px = bbox_width_px;
    packet.bbox_height_px = bbox_height_px;
    packet.range_m = range_m;
    packet.zoom_ratio = zoom_ratio;
    packet.frame_dt_s = frame_dt_s;
    packet.last_rx_age_s = last_rx_age_s;
    packet.parse_error_count = parse_error_count;
    packet.target_flags = target_flags;
    packet.tracking_state = tracking_state;
    packet.video_source = video_source;
    packet.tracking_algorithm = tracking_algorithm;
    packet.status1 = status1;
    packet.status2 = status2;
    packet.status3 = status3;
    packet.self_test_raw = self_test_raw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DYT_TARGET_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
}

/**
 * @brief Encode a dyt_target_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dyt_target_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_target_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dyt_target_status_t* dyt_target_status)
{
    return mavlink_msg_dyt_target_status_pack(system_id, component_id, msg, dyt_target_status->time_boot_ms, dyt_target_status->time_sample_ms, dyt_target_status->frame_counter, dyt_target_status->los_x_rad, dyt_target_status->los_y_rad, dyt_target_status->gimbal_roll_rad, dyt_target_status->gimbal_pitch_frame_rad, dyt_target_status->gimbal_pitch_rad, dyt_target_status->gimbal_yaw_rad, dyt_target_status->gimbal_roll_rate_rad_s, dyt_target_status->gimbal_pitch_rate_rad_s, dyt_target_status->gimbal_yaw_rate_rad_s, dyt_target_status->bbox_width_px, dyt_target_status->bbox_height_px, dyt_target_status->range_m, dyt_target_status->zoom_ratio, dyt_target_status->frame_dt_s, dyt_target_status->last_rx_age_s, dyt_target_status->parse_error_count, dyt_target_status->target_flags, dyt_target_status->tracking_state, dyt_target_status->video_source, dyt_target_status->tracking_algorithm, dyt_target_status->status1, dyt_target_status->status2, dyt_target_status->status3, dyt_target_status->self_test_raw);
}

/**
 * @brief Encode a dyt_target_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dyt_target_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_target_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dyt_target_status_t* dyt_target_status)
{
    return mavlink_msg_dyt_target_status_pack_chan(system_id, component_id, chan, msg, dyt_target_status->time_boot_ms, dyt_target_status->time_sample_ms, dyt_target_status->frame_counter, dyt_target_status->los_x_rad, dyt_target_status->los_y_rad, dyt_target_status->gimbal_roll_rad, dyt_target_status->gimbal_pitch_frame_rad, dyt_target_status->gimbal_pitch_rad, dyt_target_status->gimbal_yaw_rad, dyt_target_status->gimbal_roll_rate_rad_s, dyt_target_status->gimbal_pitch_rate_rad_s, dyt_target_status->gimbal_yaw_rate_rad_s, dyt_target_status->bbox_width_px, dyt_target_status->bbox_height_px, dyt_target_status->range_m, dyt_target_status->zoom_ratio, dyt_target_status->frame_dt_s, dyt_target_status->last_rx_age_s, dyt_target_status->parse_error_count, dyt_target_status->target_flags, dyt_target_status->tracking_state, dyt_target_status->video_source, dyt_target_status->tracking_algorithm, dyt_target_status->status1, dyt_target_status->status2, dyt_target_status->status3, dyt_target_status->self_test_raw);
}

/**
 * @brief Encode a dyt_target_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param dyt_target_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dyt_target_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_dyt_target_status_t* dyt_target_status)
{
    return mavlink_msg_dyt_target_status_pack_status(system_id, component_id, _status, msg,  dyt_target_status->time_boot_ms, dyt_target_status->time_sample_ms, dyt_target_status->frame_counter, dyt_target_status->los_x_rad, dyt_target_status->los_y_rad, dyt_target_status->gimbal_roll_rad, dyt_target_status->gimbal_pitch_frame_rad, dyt_target_status->gimbal_pitch_rad, dyt_target_status->gimbal_yaw_rad, dyt_target_status->gimbal_roll_rate_rad_s, dyt_target_status->gimbal_pitch_rate_rad_s, dyt_target_status->gimbal_yaw_rate_rad_s, dyt_target_status->bbox_width_px, dyt_target_status->bbox_height_px, dyt_target_status->range_m, dyt_target_status->zoom_ratio, dyt_target_status->frame_dt_s, dyt_target_status->last_rx_age_s, dyt_target_status->parse_error_count, dyt_target_status->target_flags, dyt_target_status->tracking_state, dyt_target_status->video_source, dyt_target_status->tracking_algorithm, dyt_target_status->status1, dyt_target_status->status2, dyt_target_status->status3, dyt_target_status->self_test_raw);
}

/**
 * @brief Send a dyt_target_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms  Reception timestamp since boot.
 * @param time_sample_ms  Payload sample timestamp since boot.
 * @param frame_counter  Payload frame counter.
 * @param los_x_rad  Horizontal line-of-sight error.
 * @param los_y_rad  Vertical line-of-sight error.
 * @param gimbal_roll_rad  Gimbal roll angle.
 * @param gimbal_pitch_frame_rad  Gimbal pitch frame angle.
 * @param gimbal_pitch_rad  Gimbal pitch attitude angle.
 * @param gimbal_yaw_rad  Gimbal yaw angle.
 * @param gimbal_roll_rate_rad_s  Gimbal roll rate.
 * @param gimbal_pitch_rate_rad_s  Gimbal pitch rate.
 * @param gimbal_yaw_rate_rad_s  Gimbal yaw rate.
 * @param bbox_width_px  Tracking box width.
 * @param bbox_height_px  Tracking box height.
 * @param range_m  Payload range measurement.
 * @param zoom_ratio  Payload zoom ratio.
 * @param frame_dt_s  Payload frame interval.
 * @param last_rx_age_s  Age of the last received payload byte.
 * @param parse_error_count  Payload parser error count.
 * @param target_flags  Bitmask: 0 valid, 1 auto hint, 2 image enhance, 3 recording, 4 motor on, 5 follow mode, 6 laser on, 7 self-test done, 8 gyro calibration failed, 9 servo fault, 10 image-board fault.
 * @param tracking_state  Tracking state.
 * @param video_source  Active video source.
 * @param tracking_algorithm  Tracking algorithm.
 * @param status1  Raw payload status byte 1.
 * @param status2  Raw payload status byte 2.
 * @param status3  Raw payload status byte 3.
 * @param self_test_raw  Raw self-test byte.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dyt_target_status_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t frame_counter, float los_x_rad, float los_y_rad, float gimbal_roll_rad, float gimbal_pitch_frame_rad, float gimbal_pitch_rad, float gimbal_yaw_rad, float gimbal_roll_rate_rad_s, float gimbal_pitch_rate_rad_s, float gimbal_yaw_rate_rad_s, float bbox_width_px, float bbox_height_px, float range_m, float zoom_ratio, float frame_dt_s, float last_rx_age_s, uint16_t parse_error_count, uint16_t target_flags, uint8_t tracking_state, uint8_t video_source, uint8_t tracking_algorithm, uint8_t status1, uint8_t status2, uint8_t status3, uint8_t self_test_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, frame_counter);
    _mav_put_float(buf, 12, los_x_rad);
    _mav_put_float(buf, 16, los_y_rad);
    _mav_put_float(buf, 20, gimbal_roll_rad);
    _mav_put_float(buf, 24, gimbal_pitch_frame_rad);
    _mav_put_float(buf, 28, gimbal_pitch_rad);
    _mav_put_float(buf, 32, gimbal_yaw_rad);
    _mav_put_float(buf, 36, gimbal_roll_rate_rad_s);
    _mav_put_float(buf, 40, gimbal_pitch_rate_rad_s);
    _mav_put_float(buf, 44, gimbal_yaw_rate_rad_s);
    _mav_put_float(buf, 48, bbox_width_px);
    _mav_put_float(buf, 52, bbox_height_px);
    _mav_put_float(buf, 56, range_m);
    _mav_put_float(buf, 60, zoom_ratio);
    _mav_put_float(buf, 64, frame_dt_s);
    _mav_put_float(buf, 68, last_rx_age_s);
    _mav_put_uint16_t(buf, 72, parse_error_count);
    _mav_put_uint16_t(buf, 74, target_flags);
    _mav_put_uint8_t(buf, 76, tracking_state);
    _mav_put_uint8_t(buf, 77, video_source);
    _mav_put_uint8_t(buf, 78, tracking_algorithm);
    _mav_put_uint8_t(buf, 79, status1);
    _mav_put_uint8_t(buf, 80, status2);
    _mav_put_uint8_t(buf, 81, status3);
    _mav_put_uint8_t(buf, 82, self_test_raw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TARGET_STATUS, buf, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
#else
    mavlink_dyt_target_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.time_sample_ms = time_sample_ms;
    packet.frame_counter = frame_counter;
    packet.los_x_rad = los_x_rad;
    packet.los_y_rad = los_y_rad;
    packet.gimbal_roll_rad = gimbal_roll_rad;
    packet.gimbal_pitch_frame_rad = gimbal_pitch_frame_rad;
    packet.gimbal_pitch_rad = gimbal_pitch_rad;
    packet.gimbal_yaw_rad = gimbal_yaw_rad;
    packet.gimbal_roll_rate_rad_s = gimbal_roll_rate_rad_s;
    packet.gimbal_pitch_rate_rad_s = gimbal_pitch_rate_rad_s;
    packet.gimbal_yaw_rate_rad_s = gimbal_yaw_rate_rad_s;
    packet.bbox_width_px = bbox_width_px;
    packet.bbox_height_px = bbox_height_px;
    packet.range_m = range_m;
    packet.zoom_ratio = zoom_ratio;
    packet.frame_dt_s = frame_dt_s;
    packet.last_rx_age_s = last_rx_age_s;
    packet.parse_error_count = parse_error_count;
    packet.target_flags = target_flags;
    packet.tracking_state = tracking_state;
    packet.video_source = video_source;
    packet.tracking_algorithm = tracking_algorithm;
    packet.status1 = status1;
    packet.status2 = status2;
    packet.status3 = status3;
    packet.self_test_raw = self_test_raw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TARGET_STATUS, (const char *)&packet, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
#endif
}

/**
 * @brief Send a dyt_target_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dyt_target_status_send_struct(mavlink_channel_t chan, const mavlink_dyt_target_status_t* dyt_target_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dyt_target_status_send(chan, dyt_target_status->time_boot_ms, dyt_target_status->time_sample_ms, dyt_target_status->frame_counter, dyt_target_status->los_x_rad, dyt_target_status->los_y_rad, dyt_target_status->gimbal_roll_rad, dyt_target_status->gimbal_pitch_frame_rad, dyt_target_status->gimbal_pitch_rad, dyt_target_status->gimbal_yaw_rad, dyt_target_status->gimbal_roll_rate_rad_s, dyt_target_status->gimbal_pitch_rate_rad_s, dyt_target_status->gimbal_yaw_rate_rad_s, dyt_target_status->bbox_width_px, dyt_target_status->bbox_height_px, dyt_target_status->range_m, dyt_target_status->zoom_ratio, dyt_target_status->frame_dt_s, dyt_target_status->last_rx_age_s, dyt_target_status->parse_error_count, dyt_target_status->target_flags, dyt_target_status->tracking_state, dyt_target_status->video_source, dyt_target_status->tracking_algorithm, dyt_target_status->status1, dyt_target_status->status2, dyt_target_status->status3, dyt_target_status->self_test_raw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TARGET_STATUS, (const char *)dyt_target_status, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dyt_target_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t time_sample_ms, uint32_t frame_counter, float los_x_rad, float los_y_rad, float gimbal_roll_rad, float gimbal_pitch_frame_rad, float gimbal_pitch_rad, float gimbal_yaw_rad, float gimbal_roll_rate_rad_s, float gimbal_pitch_rate_rad_s, float gimbal_yaw_rate_rad_s, float bbox_width_px, float bbox_height_px, float range_m, float zoom_ratio, float frame_dt_s, float last_rx_age_s, uint16_t parse_error_count, uint16_t target_flags, uint8_t tracking_state, uint8_t video_source, uint8_t tracking_algorithm, uint8_t status1, uint8_t status2, uint8_t status3, uint8_t self_test_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, time_sample_ms);
    _mav_put_uint32_t(buf, 8, frame_counter);
    _mav_put_float(buf, 12, los_x_rad);
    _mav_put_float(buf, 16, los_y_rad);
    _mav_put_float(buf, 20, gimbal_roll_rad);
    _mav_put_float(buf, 24, gimbal_pitch_frame_rad);
    _mav_put_float(buf, 28, gimbal_pitch_rad);
    _mav_put_float(buf, 32, gimbal_yaw_rad);
    _mav_put_float(buf, 36, gimbal_roll_rate_rad_s);
    _mav_put_float(buf, 40, gimbal_pitch_rate_rad_s);
    _mav_put_float(buf, 44, gimbal_yaw_rate_rad_s);
    _mav_put_float(buf, 48, bbox_width_px);
    _mav_put_float(buf, 52, bbox_height_px);
    _mav_put_float(buf, 56, range_m);
    _mav_put_float(buf, 60, zoom_ratio);
    _mav_put_float(buf, 64, frame_dt_s);
    _mav_put_float(buf, 68, last_rx_age_s);
    _mav_put_uint16_t(buf, 72, parse_error_count);
    _mav_put_uint16_t(buf, 74, target_flags);
    _mav_put_uint8_t(buf, 76, tracking_state);
    _mav_put_uint8_t(buf, 77, video_source);
    _mav_put_uint8_t(buf, 78, tracking_algorithm);
    _mav_put_uint8_t(buf, 79, status1);
    _mav_put_uint8_t(buf, 80, status2);
    _mav_put_uint8_t(buf, 81, status3);
    _mav_put_uint8_t(buf, 82, self_test_raw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TARGET_STATUS, buf, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
#else
    mavlink_dyt_target_status_t *packet = (mavlink_dyt_target_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->time_sample_ms = time_sample_ms;
    packet->frame_counter = frame_counter;
    packet->los_x_rad = los_x_rad;
    packet->los_y_rad = los_y_rad;
    packet->gimbal_roll_rad = gimbal_roll_rad;
    packet->gimbal_pitch_frame_rad = gimbal_pitch_frame_rad;
    packet->gimbal_pitch_rad = gimbal_pitch_rad;
    packet->gimbal_yaw_rad = gimbal_yaw_rad;
    packet->gimbal_roll_rate_rad_s = gimbal_roll_rate_rad_s;
    packet->gimbal_pitch_rate_rad_s = gimbal_pitch_rate_rad_s;
    packet->gimbal_yaw_rate_rad_s = gimbal_yaw_rate_rad_s;
    packet->bbox_width_px = bbox_width_px;
    packet->bbox_height_px = bbox_height_px;
    packet->range_m = range_m;
    packet->zoom_ratio = zoom_ratio;
    packet->frame_dt_s = frame_dt_s;
    packet->last_rx_age_s = last_rx_age_s;
    packet->parse_error_count = parse_error_count;
    packet->target_flags = target_flags;
    packet->tracking_state = tracking_state;
    packet->video_source = video_source;
    packet->tracking_algorithm = tracking_algorithm;
    packet->status1 = status1;
    packet->status2 = status2;
    packet->status3 = status3;
    packet->self_test_raw = self_test_raw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DYT_TARGET_STATUS, (const char *)packet, MAVLINK_MSG_ID_DYT_TARGET_STATUS_MIN_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN, MAVLINK_MSG_ID_DYT_TARGET_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE DYT_TARGET_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from dyt_target_status message
 *
 * @return  Reception timestamp since boot.
 */
static inline uint32_t mavlink_msg_dyt_target_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field time_sample_ms from dyt_target_status message
 *
 * @return  Payload sample timestamp since boot.
 */
static inline uint32_t mavlink_msg_dyt_target_status_get_time_sample_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field frame_counter from dyt_target_status message
 *
 * @return  Payload frame counter.
 */
static inline uint32_t mavlink_msg_dyt_target_status_get_frame_counter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field los_x_rad from dyt_target_status message
 *
 * @return  Horizontal line-of-sight error.
 */
static inline float mavlink_msg_dyt_target_status_get_los_x_rad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field los_y_rad from dyt_target_status message
 *
 * @return  Vertical line-of-sight error.
 */
static inline float mavlink_msg_dyt_target_status_get_los_y_rad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field gimbal_roll_rad from dyt_target_status message
 *
 * @return  Gimbal roll angle.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_roll_rad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field gimbal_pitch_frame_rad from dyt_target_status message
 *
 * @return  Gimbal pitch frame angle.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_pitch_frame_rad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field gimbal_pitch_rad from dyt_target_status message
 *
 * @return  Gimbal pitch attitude angle.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_pitch_rad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field gimbal_yaw_rad from dyt_target_status message
 *
 * @return  Gimbal yaw angle.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_yaw_rad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field gimbal_roll_rate_rad_s from dyt_target_status message
 *
 * @return  Gimbal roll rate.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_roll_rate_rad_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field gimbal_pitch_rate_rad_s from dyt_target_status message
 *
 * @return  Gimbal pitch rate.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_pitch_rate_rad_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field gimbal_yaw_rate_rad_s from dyt_target_status message
 *
 * @return  Gimbal yaw rate.
 */
static inline float mavlink_msg_dyt_target_status_get_gimbal_yaw_rate_rad_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field bbox_width_px from dyt_target_status message
 *
 * @return  Tracking box width.
 */
static inline float mavlink_msg_dyt_target_status_get_bbox_width_px(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field bbox_height_px from dyt_target_status message
 *
 * @return  Tracking box height.
 */
static inline float mavlink_msg_dyt_target_status_get_bbox_height_px(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field range_m from dyt_target_status message
 *
 * @return  Payload range measurement.
 */
static inline float mavlink_msg_dyt_target_status_get_range_m(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field zoom_ratio from dyt_target_status message
 *
 * @return  Payload zoom ratio.
 */
static inline float mavlink_msg_dyt_target_status_get_zoom_ratio(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field frame_dt_s from dyt_target_status message
 *
 * @return  Payload frame interval.
 */
static inline float mavlink_msg_dyt_target_status_get_frame_dt_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field last_rx_age_s from dyt_target_status message
 *
 * @return  Age of the last received payload byte.
 */
static inline float mavlink_msg_dyt_target_status_get_last_rx_age_s(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field parse_error_count from dyt_target_status message
 *
 * @return  Payload parser error count.
 */
static inline uint16_t mavlink_msg_dyt_target_status_get_parse_error_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  72);
}

/**
 * @brief Get field target_flags from dyt_target_status message
 *
 * @return  Bitmask: 0 valid, 1 auto hint, 2 image enhance, 3 recording, 4 motor on, 5 follow mode, 6 laser on, 7 self-test done, 8 gyro calibration failed, 9 servo fault, 10 image-board fault.
 */
static inline uint16_t mavlink_msg_dyt_target_status_get_target_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  74);
}

/**
 * @brief Get field tracking_state from dyt_target_status message
 *
 * @return  Tracking state.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_tracking_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  76);
}

/**
 * @brief Get field video_source from dyt_target_status message
 *
 * @return  Active video source.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_video_source(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  77);
}

/**
 * @brief Get field tracking_algorithm from dyt_target_status message
 *
 * @return  Tracking algorithm.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_tracking_algorithm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  78);
}

/**
 * @brief Get field status1 from dyt_target_status message
 *
 * @return  Raw payload status byte 1.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_status1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  79);
}

/**
 * @brief Get field status2 from dyt_target_status message
 *
 * @return  Raw payload status byte 2.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_status2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  80);
}

/**
 * @brief Get field status3 from dyt_target_status message
 *
 * @return  Raw payload status byte 3.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_status3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  81);
}

/**
 * @brief Get field self_test_raw from dyt_target_status message
 *
 * @return  Raw self-test byte.
 */
static inline uint8_t mavlink_msg_dyt_target_status_get_self_test_raw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  82);
}

/**
 * @brief Decode a dyt_target_status message into a struct
 *
 * @param msg The message to decode
 * @param dyt_target_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_dyt_target_status_decode(const mavlink_message_t* msg, mavlink_dyt_target_status_t* dyt_target_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dyt_target_status->time_boot_ms = mavlink_msg_dyt_target_status_get_time_boot_ms(msg);
    dyt_target_status->time_sample_ms = mavlink_msg_dyt_target_status_get_time_sample_ms(msg);
    dyt_target_status->frame_counter = mavlink_msg_dyt_target_status_get_frame_counter(msg);
    dyt_target_status->los_x_rad = mavlink_msg_dyt_target_status_get_los_x_rad(msg);
    dyt_target_status->los_y_rad = mavlink_msg_dyt_target_status_get_los_y_rad(msg);
    dyt_target_status->gimbal_roll_rad = mavlink_msg_dyt_target_status_get_gimbal_roll_rad(msg);
    dyt_target_status->gimbal_pitch_frame_rad = mavlink_msg_dyt_target_status_get_gimbal_pitch_frame_rad(msg);
    dyt_target_status->gimbal_pitch_rad = mavlink_msg_dyt_target_status_get_gimbal_pitch_rad(msg);
    dyt_target_status->gimbal_yaw_rad = mavlink_msg_dyt_target_status_get_gimbal_yaw_rad(msg);
    dyt_target_status->gimbal_roll_rate_rad_s = mavlink_msg_dyt_target_status_get_gimbal_roll_rate_rad_s(msg);
    dyt_target_status->gimbal_pitch_rate_rad_s = mavlink_msg_dyt_target_status_get_gimbal_pitch_rate_rad_s(msg);
    dyt_target_status->gimbal_yaw_rate_rad_s = mavlink_msg_dyt_target_status_get_gimbal_yaw_rate_rad_s(msg);
    dyt_target_status->bbox_width_px = mavlink_msg_dyt_target_status_get_bbox_width_px(msg);
    dyt_target_status->bbox_height_px = mavlink_msg_dyt_target_status_get_bbox_height_px(msg);
    dyt_target_status->range_m = mavlink_msg_dyt_target_status_get_range_m(msg);
    dyt_target_status->zoom_ratio = mavlink_msg_dyt_target_status_get_zoom_ratio(msg);
    dyt_target_status->frame_dt_s = mavlink_msg_dyt_target_status_get_frame_dt_s(msg);
    dyt_target_status->last_rx_age_s = mavlink_msg_dyt_target_status_get_last_rx_age_s(msg);
    dyt_target_status->parse_error_count = mavlink_msg_dyt_target_status_get_parse_error_count(msg);
    dyt_target_status->target_flags = mavlink_msg_dyt_target_status_get_target_flags(msg);
    dyt_target_status->tracking_state = mavlink_msg_dyt_target_status_get_tracking_state(msg);
    dyt_target_status->video_source = mavlink_msg_dyt_target_status_get_video_source(msg);
    dyt_target_status->tracking_algorithm = mavlink_msg_dyt_target_status_get_tracking_algorithm(msg);
    dyt_target_status->status1 = mavlink_msg_dyt_target_status_get_status1(msg);
    dyt_target_status->status2 = mavlink_msg_dyt_target_status_get_status2(msg);
    dyt_target_status->status3 = mavlink_msg_dyt_target_status_get_status3(msg);
    dyt_target_status->self_test_raw = mavlink_msg_dyt_target_status_get_self_test_raw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN? msg->len : MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN;
        memset(dyt_target_status, 0, MAVLINK_MSG_ID_DYT_TARGET_STATUS_LEN);
    memcpy(dyt_target_status, _MAV_PAYLOAD(msg), len);
#endif
}
