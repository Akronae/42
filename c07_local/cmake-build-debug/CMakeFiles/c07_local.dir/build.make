# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Users/adaubric/Documents/Apps/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/adaubric/Documents/Apps/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/adaubric/proj/c07_local

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adaubric/proj/c07_local/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c07_local.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c07_local.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c07_local.dir/flags.make

CMakeFiles/c07_local.dir/main.c.o: CMakeFiles/c07_local.dir/flags.make
CMakeFiles/c07_local.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/c07_local/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/c07_local.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/c07_local.dir/main.c.o -c /Users/adaubric/proj/c07_local/main.c

CMakeFiles/c07_local.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/c07_local.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/c07_local/main.c > CMakeFiles/c07_local.dir/main.c.i

CMakeFiles/c07_local.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/c07_local.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/c07_local/main.c -o CMakeFiles/c07_local.dir/main.c.s

# Object files for target c07_local
c07_local_OBJECTS = \
"CMakeFiles/c07_local.dir/main.c.o"

# External object files for target c07_local
c07_local_EXTERNAL_OBJECTS =

c07_local: CMakeFiles/c07_local.dir/main.c.o
c07_local: CMakeFiles/c07_local.dir/build.make
c07_local: CMakeFiles/c07_local.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adaubric/proj/c07_local/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable c07_local"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c07_local.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c07_local.dir/build: c07_local

.PHONY : CMakeFiles/c07_local.dir/build

CMakeFiles/c07_local.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c07_local.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c07_local.dir/clean

CMakeFiles/c07_local.dir/depend:
	cd /Users/adaubric/proj/c07_local/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adaubric/proj/c07_local /Users/adaubric/proj/c07_local /Users/adaubric/proj/c07_local/cmake-build-debug /Users/adaubric/proj/c07_local/cmake-build-debug /Users/adaubric/proj/c07_local/cmake-build-debug/CMakeFiles/c07_local.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c07_local.dir/depend
