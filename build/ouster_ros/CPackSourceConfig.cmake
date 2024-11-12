# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/home/student/Desktop/workspace/src/ouster-ros/ouster-ros;/home/student/Desktop/workspace/build/ouster_ros")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libjsoncpp-dev, libeigen3-dev, libtins-dev, libglfw3-dev, libglew-dev, libspdlog-dev, libpng-dev, libflatbuffers-dev")
set(CPACK_DEBIAN_PACKAGE_NAME "ouster-sdk")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "ouster_ros built using CMake")
set(CPACK_GENERATOR "TGZ;ZIP")
set(CPACK_IGNORE_FILES "/.git;/dist")
set(CPACK_INSTALLED_DIRECTORIES "/home/student/Desktop/workspace/src/ouster-ros/ouster-ros;/")
set(CPACK_INSTALL_CMAKE_PROJECTS "")
set(CPACK_INSTALL_PREFIX "/home/student/Desktop/workspace/install/ouster_ros")
set(CPACK_MODULE_PATH "/opt/ros/humble/share/fastrtps_cmake_module/cmake/Modules;/home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/cmake;/usr/lib/x86_64-linux-gnu/cmake/pcl/Modules;/home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/cmake")
set(CPACK_NSIS_DISPLAY_NAME "ouster_sdk 20231031")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "ouster_sdk 20231031")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "/home/student/Desktop/workspace/build/ouster_ros/CPackConfig.cmake")
set(CPACK_PACKAGE_CONTACT "oss@ouster.io")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.22/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Ouster sensor SDK")
set(CPACK_PACKAGE_FILE_NAME "ouster_sdk-20231031-Source")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "ouster_sdk 20231031")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "ouster_sdk 20231031")
set(CPACK_PACKAGE_NAME "ouster_sdk")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Ouster")
set(CPACK_PACKAGE_VERSION "20231031")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_PACKAGING_INSTALL_PREFIX "/opt/ouster")
set(CPACK_RESOURCE_FILE_LICENSE "/home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/LICENSE")
set(CPACK_RESOURCE_FILE_README "/home/student/Desktop/workspace/src/ouster-ros/ouster-ros/ouster-sdk/README.rst")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-3.22/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_PACKAGE_SOURCES "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES "/.git;/dist")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "/home/student/Desktop/workspace/src/ouster-ros/ouster-ros;/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/student/Desktop/workspace/build/ouster_ros/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "ouster_sdk-20231031-Source")
set(CPACK_SOURCE_TOPLEVEL_TAG "x86_64-Source")
set(CPACK_STRIP_FILES "")
set(CPACK_SYSTEM_NAME "x86_64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "x86_64-Source")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/student/Desktop/workspace/build/ouster_ros/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
