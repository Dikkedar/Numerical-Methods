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
CMAKE_SOURCE_DIR = /home/emil/Documents/Code/C++/numerical_routines/odes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emil/Documents/Code/C++/numerical_routines/odes/build_both

# Include any dependencies generated for this target.
include CMakeFiles/rk4Project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rk4Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rk4Project.dir/flags.make

CMakeFiles/rk4Project.dir/rk4.cpp.o: CMakeFiles/rk4Project.dir/flags.make
CMakeFiles/rk4Project.dir/rk4.cpp.o: ../rk4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emil/Documents/Code/C++/numerical_routines/odes/build_both/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rk4Project.dir/rk4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rk4Project.dir/rk4.cpp.o -c /home/emil/Documents/Code/C++/numerical_routines/odes/rk4.cpp

CMakeFiles/rk4Project.dir/rk4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rk4Project.dir/rk4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emil/Documents/Code/C++/numerical_routines/odes/rk4.cpp > CMakeFiles/rk4Project.dir/rk4.cpp.i

CMakeFiles/rk4Project.dir/rk4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rk4Project.dir/rk4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emil/Documents/Code/C++/numerical_routines/odes/rk4.cpp -o CMakeFiles/rk4Project.dir/rk4.cpp.s

CMakeFiles/rk4Project.dir/rk4.cpp.o.requires:

.PHONY : CMakeFiles/rk4Project.dir/rk4.cpp.o.requires

CMakeFiles/rk4Project.dir/rk4.cpp.o.provides: CMakeFiles/rk4Project.dir/rk4.cpp.o.requires
	$(MAKE) -f CMakeFiles/rk4Project.dir/build.make CMakeFiles/rk4Project.dir/rk4.cpp.o.provides.build
.PHONY : CMakeFiles/rk4Project.dir/rk4.cpp.o.provides

CMakeFiles/rk4Project.dir/rk4.cpp.o.provides.build: CMakeFiles/rk4Project.dir/rk4.cpp.o


# Object files for target rk4Project
rk4Project_OBJECTS = \
"CMakeFiles/rk4Project.dir/rk4.cpp.o"

# External object files for target rk4Project
rk4Project_EXTERNAL_OBJECTS =

rk4Project: CMakeFiles/rk4Project.dir/rk4.cpp.o
rk4Project: CMakeFiles/rk4Project.dir/build.make
rk4Project: CMakeFiles/rk4Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emil/Documents/Code/C++/numerical_routines/odes/build_both/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rk4Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rk4Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rk4Project.dir/build: rk4Project

.PHONY : CMakeFiles/rk4Project.dir/build

CMakeFiles/rk4Project.dir/requires: CMakeFiles/rk4Project.dir/rk4.cpp.o.requires

.PHONY : CMakeFiles/rk4Project.dir/requires

CMakeFiles/rk4Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rk4Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rk4Project.dir/clean

CMakeFiles/rk4Project.dir/depend:
	cd /home/emil/Documents/Code/C++/numerical_routines/odes/build_both && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emil/Documents/Code/C++/numerical_routines/odes /home/emil/Documents/Code/C++/numerical_routines/odes /home/emil/Documents/Code/C++/numerical_routines/odes/build_both /home/emil/Documents/Code/C++/numerical_routines/odes/build_both /home/emil/Documents/Code/C++/numerical_routines/odes/build_both/CMakeFiles/rk4Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rk4Project.dir/depend

