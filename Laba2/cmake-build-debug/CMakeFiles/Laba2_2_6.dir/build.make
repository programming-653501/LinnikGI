# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "/Users/gleblinkin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/163.13906.23/CLion.app/Contents/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/Users/gleblinkin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/163.13906.23/CLion.app/Contents/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gleblinkin/Desktop/Программирование/Laba2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Laba2_2_6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Laba2_2_6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laba2_2_6.dir/flags.make

CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o: CMakeFiles/Laba2_2_6.dir/flags.make
CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o: ../Laba2_2_6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o   -c /Users/gleblinkin/Desktop/Программирование/Laba2/Laba2_2_6.c

CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gleblinkin/Desktop/Программирование/Laba2/Laba2_2_6.c > CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.i

CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gleblinkin/Desktop/Программирование/Laba2/Laba2_2_6.c -o CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.s

CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.requires:

.PHONY : CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.requires

CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.provides: CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.requires
	$(MAKE) -f CMakeFiles/Laba2_2_6.dir/build.make CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.provides.build
.PHONY : CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.provides

CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.provides.build: CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o


# Object files for target Laba2_2_6
Laba2_2_6_OBJECTS = \
"CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o"

# External object files for target Laba2_2_6
Laba2_2_6_EXTERNAL_OBJECTS =

Laba2_2_6: CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o
Laba2_2_6: CMakeFiles/Laba2_2_6.dir/build.make
Laba2_2_6: CMakeFiles/Laba2_2_6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Laba2_2_6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Laba2_2_6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laba2_2_6.dir/build: Laba2_2_6

.PHONY : CMakeFiles/Laba2_2_6.dir/build

CMakeFiles/Laba2_2_6.dir/requires: CMakeFiles/Laba2_2_6.dir/Laba2_2_6.c.o.requires

.PHONY : CMakeFiles/Laba2_2_6.dir/requires

CMakeFiles/Laba2_2_6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Laba2_2_6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Laba2_2_6.dir/clean

CMakeFiles/Laba2_2_6.dir/depend:
	cd /Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gleblinkin/Desktop/Программирование/Laba2 /Users/gleblinkin/Desktop/Программирование/Laba2 /Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug /Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug /Users/gleblinkin/Desktop/Программирование/Laba2/cmake-build-debug/CMakeFiles/Laba2_2_6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Laba2_2_6.dir/depend
