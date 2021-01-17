# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build

# Include any dependencies generated for this target.
include lcm-logger/CMakeFiles/lcm-logplayer.dir/depend.make

# Include the progress variables for this target.
include lcm-logger/CMakeFiles/lcm-logplayer.dir/progress.make

# Include the compile flags for this target's objects.
include lcm-logger/CMakeFiles/lcm-logplayer.dir/flags.make

lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o: lcm-logger/CMakeFiles/lcm-logplayer.dir/flags.make
lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o: ../lcm-logger/lcm_logplayer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o"
	cd /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o   -c /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/lcm-logger/lcm_logplayer.c

lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.i"
	cd /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/lcm-logger/lcm_logplayer.c > CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.i

lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.s"
	cd /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/lcm-logger/lcm_logplayer.c -o CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.s

lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.requires:

.PHONY : lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.requires

lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.provides: lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.requires
	$(MAKE) -f lcm-logger/CMakeFiles/lcm-logplayer.dir/build.make lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.provides.build
.PHONY : lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.provides

lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.provides.build: lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o


# Object files for target lcm-logplayer
lcm__logplayer_OBJECTS = \
"CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o"

# External object files for target lcm-logplayer
lcm__logplayer_EXTERNAL_OBJECTS =

lcm-logger/lcm-logplayer: lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o
lcm-logger/lcm-logplayer: lcm-logger/CMakeFiles/lcm-logplayer.dir/build.make
lcm-logger/lcm-logplayer: lcm/liblcm.so.1.4.0
lcm-logger/lcm-logplayer: /usr/lib/x86_64-linux-gnu/libglib-2.0.so
lcm-logger/lcm-logplayer: lcm-logger/CMakeFiles/lcm-logplayer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lcm-logplayer"
	cd /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcm-logplayer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lcm-logger/CMakeFiles/lcm-logplayer.dir/build: lcm-logger/lcm-logplayer

.PHONY : lcm-logger/CMakeFiles/lcm-logplayer.dir/build

lcm-logger/CMakeFiles/lcm-logplayer.dir/requires: lcm-logger/CMakeFiles/lcm-logplayer.dir/lcm_logplayer.c.o.requires

.PHONY : lcm-logger/CMakeFiles/lcm-logplayer.dir/requires

lcm-logger/CMakeFiles/lcm-logplayer.dir/clean:
	cd /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger && $(CMAKE_COMMAND) -P CMakeFiles/lcm-logplayer.dir/cmake_clean.cmake
.PHONY : lcm-logger/CMakeFiles/lcm-logplayer.dir/clean

lcm-logger/CMakeFiles/lcm-logplayer.dir/depend:
	cd /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/lcm-logger /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger /home/david/AutonSimulator/Plugins/LCM_Plugin/Source/ThirdParty/lcm/build/lcm-logger/CMakeFiles/lcm-logplayer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lcm-logger/CMakeFiles/lcm-logplayer.dir/depend

