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
CMAKE_SOURCE_DIR = /Users/adaubric/proj/rush-02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adaubric/proj/rush-02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rush-02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rush-02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rush-02.dir/flags.make

CMakeFiles/rush-02.dir/ex00/main.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/main.c.o: ../ex00/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rush-02.dir/ex00/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/main.c.o -c /Users/adaubric/proj/rush-02/ex00/main.c

CMakeFiles/rush-02.dir/ex00/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/main.c > CMakeFiles/rush-02.dir/ex00/main.c.i

CMakeFiles/rush-02.dir/ex00/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/main.c -o CMakeFiles/rush-02.dir/ex00/main.c.s

CMakeFiles/rush-02.dir/ex00/string_utils.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/string_utils.c.o: ../ex00/string_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/rush-02.dir/ex00/string_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/string_utils.c.o -c /Users/adaubric/proj/rush-02/ex00/string_utils.c

CMakeFiles/rush-02.dir/ex00/string_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/string_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/string_utils.c > CMakeFiles/rush-02.dir/ex00/string_utils.c.i

CMakeFiles/rush-02.dir/ex00/string_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/string_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/string_utils.c -o CMakeFiles/rush-02.dir/ex00/string_utils.c.s

CMakeFiles/rush-02.dir/ex00/file_utils.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/file_utils.c.o: ../ex00/file_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/rush-02.dir/ex00/file_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/file_utils.c.o -c /Users/adaubric/proj/rush-02/ex00/file_utils.c

CMakeFiles/rush-02.dir/ex00/file_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/file_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/file_utils.c > CMakeFiles/rush-02.dir/ex00/file_utils.c.i

CMakeFiles/rush-02.dir/ex00/file_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/file_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/file_utils.c -o CMakeFiles/rush-02.dir/ex00/file_utils.c.s

CMakeFiles/rush-02.dir/ex00/array_utils.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/array_utils.c.o: ../ex00/array_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/rush-02.dir/ex00/array_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/array_utils.c.o -c /Users/adaubric/proj/rush-02/ex00/array_utils.c

CMakeFiles/rush-02.dir/ex00/array_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/array_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/array_utils.c > CMakeFiles/rush-02.dir/ex00/array_utils.c.i

CMakeFiles/rush-02.dir/ex00/array_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/array_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/array_utils.c -o CMakeFiles/rush-02.dir/ex00/array_utils.c.s

CMakeFiles/rush-02.dir/ex00/math_utils.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/math_utils.c.o: ../ex00/math_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/rush-02.dir/ex00/math_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/math_utils.c.o -c /Users/adaubric/proj/rush-02/ex00/math_utils.c

CMakeFiles/rush-02.dir/ex00/math_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/math_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/math_utils.c > CMakeFiles/rush-02.dir/ex00/math_utils.c.i

CMakeFiles/rush-02.dir/ex00/math_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/math_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/math_utils.c -o CMakeFiles/rush-02.dir/ex00/math_utils.c.s

CMakeFiles/rush-02.dir/ex00/dict_entry.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/dict_entry.c.o: ../ex00/dict_entry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/rush-02.dir/ex00/dict_entry.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/dict_entry.c.o -c /Users/adaubric/proj/rush-02/ex00/dict_entry.c

CMakeFiles/rush-02.dir/ex00/dict_entry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/dict_entry.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/dict_entry.c > CMakeFiles/rush-02.dir/ex00/dict_entry.c.i

CMakeFiles/rush-02.dir/ex00/dict_entry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/dict_entry.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/dict_entry.c -o CMakeFiles/rush-02.dir/ex00/dict_entry.c.s

CMakeFiles/rush-02.dir/ex00/number_dict.c.o: CMakeFiles/rush-02.dir/flags.make
CMakeFiles/rush-02.dir/ex00/number_dict.c.o: ../ex00/number_dict.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/rush-02.dir/ex00/number_dict.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rush-02.dir/ex00/number_dict.c.o -c /Users/adaubric/proj/rush-02/ex00/number_dict.c

CMakeFiles/rush-02.dir/ex00/number_dict.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rush-02.dir/ex00/number_dict.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/adaubric/proj/rush-02/ex00/number_dict.c > CMakeFiles/rush-02.dir/ex00/number_dict.c.i

CMakeFiles/rush-02.dir/ex00/number_dict.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rush-02.dir/ex00/number_dict.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/adaubric/proj/rush-02/ex00/number_dict.c -o CMakeFiles/rush-02.dir/ex00/number_dict.c.s

# Object files for target rush-02
rush__02_OBJECTS = \
"CMakeFiles/rush-02.dir/ex00/main.c.o" \
"CMakeFiles/rush-02.dir/ex00/string_utils.c.o" \
"CMakeFiles/rush-02.dir/ex00/file_utils.c.o" \
"CMakeFiles/rush-02.dir/ex00/array_utils.c.o" \
"CMakeFiles/rush-02.dir/ex00/math_utils.c.o" \
"CMakeFiles/rush-02.dir/ex00/dict_entry.c.o" \
"CMakeFiles/rush-02.dir/ex00/number_dict.c.o"

# External object files for target rush-02
rush__02_EXTERNAL_OBJECTS =

rush-02: CMakeFiles/rush-02.dir/ex00/main.c.o
rush-02: CMakeFiles/rush-02.dir/ex00/string_utils.c.o
rush-02: CMakeFiles/rush-02.dir/ex00/file_utils.c.o
rush-02: CMakeFiles/rush-02.dir/ex00/array_utils.c.o
rush-02: CMakeFiles/rush-02.dir/ex00/math_utils.c.o
rush-02: CMakeFiles/rush-02.dir/ex00/dict_entry.c.o
rush-02: CMakeFiles/rush-02.dir/ex00/number_dict.c.o
rush-02: CMakeFiles/rush-02.dir/build.make
rush-02: CMakeFiles/rush-02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable rush-02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rush-02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rush-02.dir/build: rush-02

.PHONY : CMakeFiles/rush-02.dir/build

CMakeFiles/rush-02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rush-02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rush-02.dir/clean

CMakeFiles/rush-02.dir/depend:
	cd /Users/adaubric/proj/rush-02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adaubric/proj/rush-02 /Users/adaubric/proj/rush-02 /Users/adaubric/proj/rush-02/cmake-build-debug /Users/adaubric/proj/rush-02/cmake-build-debug /Users/adaubric/proj/rush-02/cmake-build-debug/CMakeFiles/rush-02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rush-02.dir/depend

