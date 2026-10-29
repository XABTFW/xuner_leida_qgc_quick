cmake_minimum_required(VERSION 3.24)
project(RadarBridgeTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Network Test)

get_filename_component(QGC_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
file(GLOB MAVLINK_CACHE_DIRS "${QGC_SOURCE_DIR}/build/*/cpm_modules/mavlink/*")
find_path(MAVLINK_INCLUDE_DIR NAMES all/mavlink.h
    HINTS "${QGC_SOURCE_DIR}/third_party/mavlink" ${MAVLINK_CACHE_DIRS}
    DOC "Root of the generated MAVLink C headers (contains all/mavlink.h)")
if(NOT MAVLINK_INCLUDE_DIR)
    message(FATAL_ERROR "Set MAVLINK_INCLUDE_DIR to the generated MAVLink C header root")
endif()

# Exercise the production bridge with real Qt sockets and MAVLink encoding.
# Only QGC vehicle/link services are replaced; no aircraft connection is made.
foreach(header MAVLinkProtocol.h MAVLinkLib.h MultiVehicleManager.h Vehicle.h
               VehicleLinkManager.h LinkInterface.h QGCLoggingCategory.h)
    file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/stubs/${header}"
        CONTENT "#pragma once\n#include \"QgcRadarTestStubs.h\"\n")
endforeach()
add_executable(RadarBridgeTests RadarBridgeTest.cc QgcRadarTestStubs.h
    "${QGC_SOURCE_DIR}/src/RadarBridge.cc" "${QGC_SOURCE_DIR}/src/RadarBridge.h")
target_include_directories(RadarBridgeTests PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/stubs"
    "${CMAKE_CURRENT_LIST_DIR}" "${QGC_SOURCE_DIR}/src" "${MAVLINK_INCLUDE_DIR}")
target_link_libraries(RadarBridgeTests PRIVATE Qt6::Core Qt6::Network Qt6::Test)
if(MSVC)
    target_compile_options(RadarBridgeTests PRIVATE /utf-8 /W4)
endif()
enable_testing()
add_test(NAME RadarBridgeTests COMMAND "${CMAKE_COMMAND}"
    "-DTEST_EXECUTABLE=$<TARGET_FILE:RadarBridgeTests>"
    "-DRESULT_FILE=${CMAKE_CURRENT_BINARY_DIR}/radar-test-results.txt"
    -P "${CMAKE_CURRENT_LIST_DIR}/RunRadarBridgeTests.cmake")
