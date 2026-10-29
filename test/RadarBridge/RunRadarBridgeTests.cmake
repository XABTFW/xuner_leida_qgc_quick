execute_process(COMMAND "${TEST_EXECUTABLE}" -o "${RESULT_FILE},txt"
    RESULT_VARIABLE test_result)
if(EXISTS "${RESULT_FILE}")
    file(READ "${RESULT_FILE}" test_report)
endif()
if(NOT test_result EQUAL 0)
    message(FATAL_ERROR "RadarBridgeTests exited with ${test_result}\n${test_report}")
endif()
message("${test_report}")
