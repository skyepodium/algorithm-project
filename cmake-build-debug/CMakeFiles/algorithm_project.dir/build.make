# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /Users/skyepodium/dev/c++/algorithm-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithm_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithm_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithm_project.dir/flags.make

CMakeFiles/algorithm_project.dir/c++_project/main.cpp.o: CMakeFiles/algorithm_project.dir/flags.make
CMakeFiles/algorithm_project.dir/c++_project/main.cpp.o: ../c++\ project/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithm_project.dir/c++_project/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algorithm_project.dir/c++_project/main.cpp.o -c "/Users/skyepodium/dev/c++/algorithm-project/c++ project/main.cpp"

CMakeFiles/algorithm_project.dir/c++_project/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithm_project.dir/c++_project/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/skyepodium/dev/c++/algorithm-project/c++ project/main.cpp" > CMakeFiles/algorithm_project.dir/c++_project/main.cpp.i

CMakeFiles/algorithm_project.dir/c++_project/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithm_project.dir/c++_project/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/skyepodium/dev/c++/algorithm-project/c++ project/main.cpp" -o CMakeFiles/algorithm_project.dir/c++_project/main.cpp.s

# Object files for target algorithm_project
algorithm_project_OBJECTS = \
"CMakeFiles/algorithm_project.dir/c++_project/main.cpp.o"

# External object files for target algorithm_project
algorithm_project_EXTERNAL_OBJECTS =

algorithm_project: CMakeFiles/algorithm_project.dir/c++_project/main.cpp.o
algorithm_project: CMakeFiles/algorithm_project.dir/build.make
algorithm_project: CMakeFiles/algorithm_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorithm_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algorithm_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithm_project.dir/build: algorithm_project

.PHONY : CMakeFiles/algorithm_project.dir/build

CMakeFiles/algorithm_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algorithm_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algorithm_project.dir/clean

CMakeFiles/algorithm_project.dir/depend:
	cd /Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/skyepodium/dev/c++/algorithm-project /Users/skyepodium/dev/c++/algorithm-project /Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug /Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug /Users/skyepodium/dev/c++/algorithm-project/cmake-build-debug/CMakeFiles/algorithm_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algorithm_project.dir/depend

