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
CMAKE_SOURCE_DIR = /home/student/Desktop/workspace/src/object_tracking_messages

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/workspace/build/object_tracking_messages

# Utility rule file for object_tracking_messages.

# Include any custom commands dependencies for this target.
include CMakeFiles/object_tracking_messages.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/object_tracking_messages.dir/progress.make

CMakeFiles/object_tracking_messages: /home/student/Desktop/workspace/src/object_tracking_messages/msg/BoundingBox.msg
CMakeFiles/object_tracking_messages: /home/student/Desktop/workspace/src/object_tracking_messages/msg/DetectedPerson.msg
CMakeFiles/object_tracking_messages: /home/student/Desktop/workspace/src/object_tracking_messages/msg/DetectedPersons.msg
CMakeFiles/object_tracking_messages: /home/student/Desktop/workspace/src/object_tracking_messages/msg/PersonDistance.msg

object_tracking_messages: CMakeFiles/object_tracking_messages
object_tracking_messages: CMakeFiles/object_tracking_messages.dir/build.make
.PHONY : object_tracking_messages

# Rule to build all files generated by this target.
CMakeFiles/object_tracking_messages.dir/build: object_tracking_messages
.PHONY : CMakeFiles/object_tracking_messages.dir/build

CMakeFiles/object_tracking_messages.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/object_tracking_messages.dir/cmake_clean.cmake
.PHONY : CMakeFiles/object_tracking_messages.dir/clean

CMakeFiles/object_tracking_messages.dir/depend:
	cd /home/student/Desktop/workspace/build/object_tracking_messages && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/workspace/src/object_tracking_messages /home/student/Desktop/workspace/src/object_tracking_messages /home/student/Desktop/workspace/build/object_tracking_messages /home/student/Desktop/workspace/build/object_tracking_messages /home/student/Desktop/workspace/build/object_tracking_messages/CMakeFiles/object_tracking_messages.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/object_tracking_messages.dir/depend

