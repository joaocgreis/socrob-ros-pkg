# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/build

# Include any dependencies generated for this target.
include CMakeFiles/telemetry_settings.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/telemetry_settings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/telemetry_settings.dir/flags.make

CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o: CMakeFiles/telemetry_settings.dir/flags.make
CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o: ../src/telemetry_settings.cpp
CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o: ../manifest.xml
CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o: /opt/ros/fuerte/share/roslang/manifest.xml
CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o: /opt/ros/fuerte/share/roscpp/manifest.xml
CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o: /opt/ros/fuerte/share/rospy/manifest.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o -c /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/src/telemetry_settings.cpp

CMakeFiles/telemetry_settings.dir/src/telemetry_settings.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/telemetry_settings.dir/src/telemetry_settings.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/src/telemetry_settings.cpp > CMakeFiles/telemetry_settings.dir/src/telemetry_settings.i

CMakeFiles/telemetry_settings.dir/src/telemetry_settings.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/telemetry_settings.dir/src/telemetry_settings.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/src/telemetry_settings.cpp -o CMakeFiles/telemetry_settings.dir/src/telemetry_settings.s

CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.requires:
.PHONY : CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.requires

CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.provides: CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.requires
	$(MAKE) -f CMakeFiles/telemetry_settings.dir/build.make CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.provides.build
.PHONY : CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.provides

CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.provides.build: CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o

# Object files for target telemetry_settings
telemetry_settings_OBJECTS = \
"CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o"

# External object files for target telemetry_settings
telemetry_settings_EXTERNAL_OBJECTS =

../bin/telemetry_settings: CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o
../bin/telemetry_settings: CMakeFiles/telemetry_settings.dir/build.make
../bin/telemetry_settings: CMakeFiles/telemetry_settings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/telemetry_settings"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/telemetry_settings.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/telemetry_settings.dir/build: ../bin/telemetry_settings
.PHONY : CMakeFiles/telemetry_settings.dir/build

CMakeFiles/telemetry_settings.dir/requires: CMakeFiles/telemetry_settings.dir/src/telemetry_settings.o.requires
.PHONY : CMakeFiles/telemetry_settings.dir/requires

CMakeFiles/telemetry_settings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/telemetry_settings.dir/cmake_clean.cmake
.PHONY : CMakeFiles/telemetry_settings.dir/clean

CMakeFiles/telemetry_settings.dir/depend:
	cd /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/build /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/build /home/quadbase/ros/quad_ros/quad_drivers/telemetry_settings/build/CMakeFiles/telemetry_settings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/telemetry_settings.dir/depend
