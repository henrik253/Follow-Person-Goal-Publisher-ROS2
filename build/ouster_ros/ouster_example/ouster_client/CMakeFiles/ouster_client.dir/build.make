# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/student/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/student/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/Desktop/workspace/src/ouster-ros/ouster-ros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/workspace/build/ouster_ros

# Include any dependencies generated for this target.
include ouster_example/ouster_client/CMakeFiles/ouster_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.make

# Include the progress variables for this target.
include ouster_example/ouster_client/CMakeFiles/ouster_client.dir/progress.make

# Include the compile flags for this target's objects.
include ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/client.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.o -MF CMakeFiles/ouster_client.dir/src/client.cpp.o.d -o CMakeFiles/ouster_client.dir/src/client.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/client.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/client.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/client.cpp > CMakeFiles/ouster_client.dir/src/client.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/client.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/client.cpp -o CMakeFiles/ouster_client.dir/src/client.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/types.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.o -MF CMakeFiles/ouster_client.dir/src/types.cpp.o.d -o CMakeFiles/ouster_client.dir/src/types.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/types.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/types.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/types.cpp > CMakeFiles/ouster_client.dir/src/types.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/types.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/types.cpp -o CMakeFiles/ouster_client.dir/src/types.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_info.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o -MF CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o.d -o CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_info.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/sensor_info.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_info.cpp > CMakeFiles/ouster_client.dir/src/sensor_info.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/sensor_info.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_info.cpp -o CMakeFiles/ouster_client.dir/src/sensor_info.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/netcompat.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.o -MF CMakeFiles/ouster_client.dir/src/netcompat.cpp.o.d -o CMakeFiles/ouster_client.dir/src/netcompat.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/netcompat.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/netcompat.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/netcompat.cpp > CMakeFiles/ouster_client.dir/src/netcompat.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/netcompat.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/netcompat.cpp -o CMakeFiles/ouster_client.dir/src/netcompat.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/lidar_scan.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o -MF CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o.d -o CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/lidar_scan.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/lidar_scan.cpp > CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/lidar_scan.cpp -o CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/image_processing.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.o -MF CMakeFiles/ouster_client.dir/src/image_processing.cpp.o.d -o CMakeFiles/ouster_client.dir/src/image_processing.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/image_processing.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/image_processing.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/image_processing.cpp > CMakeFiles/ouster_client.dir/src/image_processing.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/image_processing.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/image_processing.cpp -o CMakeFiles/ouster_client.dir/src/image_processing.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/buffered_udp_source.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o -MF CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o.d -o CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/buffered_udp_source.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/buffered_udp_source.cpp > CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/buffered_udp_source.cpp -o CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/parsing.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.o -MF CMakeFiles/ouster_client.dir/src/parsing.cpp.o.d -o CMakeFiles/ouster_client.dir/src/parsing.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/parsing.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/parsing.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/parsing.cpp > CMakeFiles/ouster_client.dir/src/parsing.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/parsing.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/parsing.cpp -o CMakeFiles/ouster_client.dir/src/parsing.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o -MF CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o.d -o CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/sensor_http.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http.cpp > CMakeFiles/ouster_client.dir/src/sensor_http.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/sensor_http.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http.cpp -o CMakeFiles/ouster_client.dir/src/sensor_http.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http_imp.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o -MF CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o.d -o CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http_imp.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http_imp.cpp > CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_http_imp.cpp -o CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_tcp_imp.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o -MF CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o.d -o CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_tcp_imp.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_tcp_imp.cpp > CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/sensor_tcp_imp.cpp -o CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/logging.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.o -MF CMakeFiles/ouster_client.dir/src/logging.cpp.o.d -o CMakeFiles/ouster_client.dir/src/logging.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/logging.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/logging.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/logging.cpp > CMakeFiles/ouster_client.dir/src/logging.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/logging.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/logging.cpp -o CMakeFiles/ouster_client.dir/src/logging.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/profile_extension.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o -MF CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o.d -o CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/profile_extension.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/profile_extension.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/profile_extension.cpp > CMakeFiles/ouster_client.dir/src/profile_extension.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/profile_extension.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/profile_extension.cpp -o CMakeFiles/ouster_client.dir/src/profile_extension.cpp.s

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/flags.make
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.o: /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/util.cpp
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.o: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.o"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.o -MF CMakeFiles/ouster_client.dir/src/util.cpp.o.d -o CMakeFiles/ouster_client.dir/src/util.cpp.o -c /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/util.cpp

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ouster_client.dir/src/util.cpp.i"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/util.cpp > CMakeFiles/ouster_client.dir/src/util.cpp.i

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ouster_client.dir/src/util.cpp.s"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client/src/util.cpp -o CMakeFiles/ouster_client.dir/src/util.cpp.s

# Object files for target ouster_client
ouster_client_OBJECTS = \
"CMakeFiles/ouster_client.dir/src/client.cpp.o" \
"CMakeFiles/ouster_client.dir/src/types.cpp.o" \
"CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o" \
"CMakeFiles/ouster_client.dir/src/netcompat.cpp.o" \
"CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o" \
"CMakeFiles/ouster_client.dir/src/image_processing.cpp.o" \
"CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o" \
"CMakeFiles/ouster_client.dir/src/parsing.cpp.o" \
"CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o" \
"CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o" \
"CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o" \
"CMakeFiles/ouster_client.dir/src/logging.cpp.o" \
"CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o" \
"CMakeFiles/ouster_client.dir/src/util.cpp.o"

# External object files for target ouster_client
ouster_client_EXTERNAL_OBJECTS =

ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/client.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/types.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_info.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/netcompat.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/lidar_scan.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/image_processing.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/buffered_udp_source.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/parsing.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_http_imp.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/sensor_tcp_imp.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/logging.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/profile_extension.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/src/util.cpp.o
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/build.make
ouster_example/ouster_client/libouster_client.a: ouster_example/ouster_client/CMakeFiles/ouster_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/workspace/build/ouster_ros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX static library libouster_client.a"
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && $(CMAKE_COMMAND) -P CMakeFiles/ouster_client.dir/cmake_clean_target.cmake
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ouster_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ouster_example/ouster_client/CMakeFiles/ouster_client.dir/build: ouster_example/ouster_client/libouster_client.a
.PHONY : ouster_example/ouster_client/CMakeFiles/ouster_client.dir/build

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/clean:
	cd /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client && $(CMAKE_COMMAND) -P CMakeFiles/ouster_client.dir/cmake_clean.cmake
.PHONY : ouster_example/ouster_client/CMakeFiles/ouster_client.dir/clean

ouster_example/ouster_client/CMakeFiles/ouster_client.dir/depend:
	cd /home/student/Desktop/workspace/build/ouster_ros && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/workspace/src/ouster-ros/ouster-ros /home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/ouster_client /home/student/Desktop/workspace/build/ouster_ros /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client /home/student/Desktop/workspace/build/ouster_ros/ouster_example/ouster_client/CMakeFiles/ouster_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ouster_example/ouster_client/CMakeFiles/ouster_client.dir/depend

