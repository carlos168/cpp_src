# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lsx/data/src/err_code_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lsx/data/src/err_code_test

# Include any dependencies generated for this target.
include CMakeFiles/err_code_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/err_code_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/err_code_test.dir/flags.make

CMakeFiles/err_code_test.dir/main.c.o: CMakeFiles/err_code_test.dir/flags.make
CMakeFiles/err_code_test.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lsx/data/src/err_code_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/err_code_test.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/err_code_test.dir/main.c.o   -c /Users/lsx/data/src/err_code_test/main.c

CMakeFiles/err_code_test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/err_code_test.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/lsx/data/src/err_code_test/main.c > CMakeFiles/err_code_test.dir/main.c.i

CMakeFiles/err_code_test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/err_code_test.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/lsx/data/src/err_code_test/main.c -o CMakeFiles/err_code_test.dir/main.c.s

# Object files for target err_code_test
err_code_test_OBJECTS = \
"CMakeFiles/err_code_test.dir/main.c.o"

# External object files for target err_code_test
err_code_test_EXTERNAL_OBJECTS =

err_code_test: CMakeFiles/err_code_test.dir/main.c.o
err_code_test: CMakeFiles/err_code_test.dir/build.make
err_code_test: CMakeFiles/err_code_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lsx/data/src/err_code_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable err_code_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/err_code_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/err_code_test.dir/build: err_code_test

.PHONY : CMakeFiles/err_code_test.dir/build

CMakeFiles/err_code_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/err_code_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/err_code_test.dir/clean

CMakeFiles/err_code_test.dir/depend:
	cd /Users/lsx/data/src/err_code_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lsx/data/src/err_code_test /Users/lsx/data/src/err_code_test /Users/lsx/data/src/err_code_test /Users/lsx/data/src/err_code_test /Users/lsx/data/src/err_code_test/CMakeFiles/err_code_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/err_code_test.dir/depend

