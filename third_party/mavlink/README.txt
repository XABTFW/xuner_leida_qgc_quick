Custom MAVLink generated C headers

This directory contains the exact 473 generated headers used by the verified
Qt 6.8.3/MSVC build of this project. The embedded MAVLINK_BUILD_DATE is
2026-08-22. They were previously present only in the local CPM build cache.

The project-specific dialect includes UAV_INFO and swarm messages unavailable
in the official c_library_v2 revision formerly referenced by the build.
Related message-definition project: https://github.com/XABTFW/mavlink
The COPYING file from that upstream project is retained here.

CMake uses this snapshot by default via QGC_MAVLINK_SOURCE_DIR. Setting that
option to an empty value enables the existing Git-based dependency path, which
requires a compatible custom dialect for this application.

SHA256SUMS records all generated headers. Keep dialect tables, message headers
and CRC extras synchronized when regenerating or updating the protocol.
