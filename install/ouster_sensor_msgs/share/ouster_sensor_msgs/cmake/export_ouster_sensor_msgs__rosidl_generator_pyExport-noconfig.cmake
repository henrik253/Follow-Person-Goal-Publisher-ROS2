#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ouster_sensor_msgs::ouster_sensor_msgs__rosidl_generator_py" for configuration ""
set_property(TARGET ouster_sensor_msgs::ouster_sensor_msgs__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ouster_sensor_msgs::ouster_sensor_msgs__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libouster_sensor_msgs__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libouster_sensor_msgs__rosidl_generator_py.so"
  )

list(APPEND _cmake_import_check_targets ouster_sensor_msgs::ouster_sensor_msgs__rosidl_generator_py )
list(APPEND _cmake_import_check_files_for_ouster_sensor_msgs::ouster_sensor_msgs__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libouster_sensor_msgs__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
