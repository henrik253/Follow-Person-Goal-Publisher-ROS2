cmake_minimum_required(VERSION 3.8)
project(odometry_publisher)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)

# Include directories (if any)
include_directories(include)

# Add the executable
add_executable(odom_publisher_node src/odom_publisher_node.cpp)

# Specify dependencies for the executable
ament_target_dependencies(odom_publisher_node rclcpp nav_msgs tf2)

# Install the executable
install(TARGETS
  odom_publisher_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
