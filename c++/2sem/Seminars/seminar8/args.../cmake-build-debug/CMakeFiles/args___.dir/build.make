# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args...

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/args___.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/args___.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/args___.dir/flags.make

CMakeFiles/args___.dir/main.cpp.o: CMakeFiles/args___.dir/flags.make
CMakeFiles/args___.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/args___.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/args___.dir/main.cpp.o -c /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../main.cpp

CMakeFiles/args___.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/args___.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../main.cpp > CMakeFiles/args___.dir/main.cpp.i

CMakeFiles/args___.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/args___.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../main.cpp -o CMakeFiles/args___.dir/main.cpp.s

# Object files for target args___
args____OBJECTS = \
"CMakeFiles/args___.dir/main.cpp.o"

# External object files for target args___
args____EXTERNAL_OBJECTS =

args___: CMakeFiles/args___.dir/main.cpp.o
args___: CMakeFiles/args___.dir/build.make
args___: CMakeFiles/args___.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable args___"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/args___.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/args___.dir/build: args___

.PHONY : CMakeFiles/args___.dir/build

CMakeFiles/args___.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/args___.dir/cmake_clean.cmake
.PHONY : CMakeFiles/args___.dir/clean

CMakeFiles/args___.dir/depend:
	cd /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args... /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args... /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/Seminars/seminar8/args.../cmake-build-debug/CMakeFiles/args___.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/args___.dir/depend
