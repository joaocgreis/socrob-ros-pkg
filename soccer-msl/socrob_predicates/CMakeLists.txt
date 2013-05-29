cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
rosbuild_genmsg()
#rosbuild_gensrv()
#rosbuild_add_boost_directories()

# Library
#file(GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
#rosbuild_add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_link_boost(${PROJECT_NAME} system thread)

# Tests
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)
foreach(TEST_SOURCE_FILE ${TEST_SOURCES})
  get_filename_component(TEST_BASENAME ${TEST_SOURCE_FILE} NAME_WE)
  rosbuild_add_executable(test_${TEST_BASENAME} ${TEST_SOURCE_FILE})
#  target_link_libraries(test_${TEST_BASENAME} ${PROJECT_NAME})
endforeach()
