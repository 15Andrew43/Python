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
CMAKE_SOURCE_DIR = /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unique_ptr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unique_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unique_ptr.dir/flags.make

CMakeFiles/unique_ptr.dir/main.cpp.o: CMakeFiles/unique_ptr.dir/flags.make
CMakeFiles/unique_ptr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unique_ptr.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unique_ptr.dir/main.cpp.o -c /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/main.cpp

CMakeFiles/unique_ptr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unique_ptr.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/main.cpp > CMakeFiles/unique_ptr.dir/main.cpp.i

CMakeFiles/unique_ptr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unique_ptr.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/main.cpp -o CMakeFiles/unique_ptr.dir/main.cpp.s

# Object files for target unique_ptr
unique_ptr_OBJECTS = \
"CMakeFiles/unique_ptr.dir/main.cpp.o"

# External object files for target unique_ptr
unique_ptr_EXTERNAL_OBJECTS =

unique_ptr: CMakeFiles/unique_ptr.dir/main.cpp.o
unique_ptr: CMakeFiles/unique_ptr.dir/build.make
unique_ptr: CMakeFiles/unique_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unique_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unique_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unique_ptr.dir/build: unique_ptr

.PHONY : CMakeFiles/unique_ptr.dir/build

CMakeFiles/unique_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unique_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unique_ptr.dir/clean

CMakeFiles/unique_ptr.dir/depend:
	cd /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug /Users/andrew_borovets/Desktop/proga/PROGA/Proga2019-2020/c++/2sem/contest/contest3/unique_ptr/cmake-build-debug/CMakeFiles/unique_ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unique_ptr.dir/depend

