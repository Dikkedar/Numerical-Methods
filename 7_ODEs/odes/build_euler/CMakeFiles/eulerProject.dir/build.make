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
CMAKE_SOURCE_DIR = /home/emil/Documents/Code/C++/numerical_routines

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emil/Documents/Code/C++/numerical_routines/build_euler

# Include any dependencies generated for this target.
include CMakeFiles/eulerProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eulerProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eulerProject.dir/flags.make

CMakeFiles/eulerProject.dir/euler.cpp.o: CMakeFiles/eulerProject.dir/flags.make
CMakeFiles/eulerProject.dir/euler.cpp.o: ../euler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emil/Documents/Code/C++/numerical_routines/build_euler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eulerProject.dir/euler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eulerProject.dir/euler.cpp.o -c /home/emil/Documents/Code/C++/numerical_routines/euler.cpp

CMakeFiles/eulerProject.dir/euler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eulerProject.dir/euler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emil/Documents/Code/C++/numerical_routines/euler.cpp > CMakeFiles/eulerProject.dir/euler.cpp.i

CMakeFiles/eulerProject.dir/euler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eulerProject.dir/euler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emil/Documents/Code/C++/numerical_routines/euler.cpp -o CMakeFiles/eulerProject.dir/euler.cpp.s

CMakeFiles/eulerProject.dir/euler.cpp.o.requires:

.PHONY : CMakeFiles/eulerProject.dir/euler.cpp.o.requires

CMakeFiles/eulerProject.dir/euler.cpp.o.provides: CMakeFiles/eulerProject.dir/euler.cpp.o.requires
	$(MAKE) -f CMakeFiles/eulerProject.dir/build.make CMakeFiles/eulerProject.dir/euler.cpp.o.provides.build
.PHONY : CMakeFiles/eulerProject.dir/euler.cpp.o.provides

CMakeFiles/eulerProject.dir/euler.cpp.o.provides.build: CMakeFiles/eulerProject.dir/euler.cpp.o


# Object files for target eulerProject
eulerProject_OBJECTS = \
"CMakeFiles/eulerProject.dir/euler.cpp.o"

# External object files for target eulerProject
eulerProject_EXTERNAL_OBJECTS =

eulerProject: CMakeFiles/eulerProject.dir/euler.cpp.o
eulerProject: CMakeFiles/eulerProject.dir/build.make
eulerProject: CMakeFiles/eulerProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emil/Documents/Code/C++/numerical_routines/build_euler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable eulerProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eulerProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eulerProject.dir/build: eulerProject

.PHONY : CMakeFiles/eulerProject.dir/build

CMakeFiles/eulerProject.dir/requires: CMakeFiles/eulerProject.dir/euler.cpp.o.requires

.PHONY : CMakeFiles/eulerProject.dir/requires

CMakeFiles/eulerProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/eulerProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/eulerProject.dir/clean

CMakeFiles/eulerProject.dir/depend:
	cd /home/emil/Documents/Code/C++/numerical_routines/build_euler && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emil/Documents/Code/C++/numerical_routines /home/emil/Documents/Code/C++/numerical_routines /home/emil/Documents/Code/C++/numerical_routines/build_euler /home/emil/Documents/Code/C++/numerical_routines/build_euler /home/emil/Documents/Code/C++/numerical_routines/build_euler/CMakeFiles/eulerProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eulerProject.dir/depend

