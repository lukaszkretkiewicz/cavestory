# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/kretkiew/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/kretkiew/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kretkiew/visualExercises/cavestory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kretkiew/visualExercises/cavestory/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/CaveStory_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/CaveStory_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/CaveStory_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/CaveStory_lib.dir/flags.make

lib/CMakeFiles/CaveStory_lib.dir/example.cpp.o: lib/CMakeFiles/CaveStory_lib.dir/flags.make
lib/CMakeFiles/CaveStory_lib.dir/example.cpp.o: ../lib/example.cpp
lib/CMakeFiles/CaveStory_lib.dir/example.cpp.o: lib/CMakeFiles/CaveStory_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kretkiew/visualExercises/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/CaveStory_lib.dir/example.cpp.o"
	cd /home/kretkiew/visualExercises/cavestory/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/CaveStory_lib.dir/example.cpp.o -MF CMakeFiles/CaveStory_lib.dir/example.cpp.o.d -o CMakeFiles/CaveStory_lib.dir/example.cpp.o -c /home/kretkiew/visualExercises/cavestory/lib/example.cpp

lib/CMakeFiles/CaveStory_lib.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CaveStory_lib.dir/example.cpp.i"
	cd /home/kretkiew/visualExercises/cavestory/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kretkiew/visualExercises/cavestory/lib/example.cpp > CMakeFiles/CaveStory_lib.dir/example.cpp.i

lib/CMakeFiles/CaveStory_lib.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CaveStory_lib.dir/example.cpp.s"
	cd /home/kretkiew/visualExercises/cavestory/build/lib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kretkiew/visualExercises/cavestory/lib/example.cpp -o CMakeFiles/CaveStory_lib.dir/example.cpp.s

# Object files for target CaveStory_lib
CaveStory_lib_OBJECTS = \
"CMakeFiles/CaveStory_lib.dir/example.cpp.o"

# External object files for target CaveStory_lib
CaveStory_lib_EXTERNAL_OBJECTS =

lib/libCaveStory_lib.a: lib/CMakeFiles/CaveStory_lib.dir/example.cpp.o
lib/libCaveStory_lib.a: lib/CMakeFiles/CaveStory_lib.dir/build.make
lib/libCaveStory_lib.a: lib/CMakeFiles/CaveStory_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kretkiew/visualExercises/cavestory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCaveStory_lib.a"
	cd /home/kretkiew/visualExercises/cavestory/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/CaveStory_lib.dir/cmake_clean_target.cmake
	cd /home/kretkiew/visualExercises/cavestory/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CaveStory_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/CaveStory_lib.dir/build: lib/libCaveStory_lib.a
.PHONY : lib/CMakeFiles/CaveStory_lib.dir/build

lib/CMakeFiles/CaveStory_lib.dir/clean:
	cd /home/kretkiew/visualExercises/cavestory/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/CaveStory_lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/CaveStory_lib.dir/clean

lib/CMakeFiles/CaveStory_lib.dir/depend:
	cd /home/kretkiew/visualExercises/cavestory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kretkiew/visualExercises/cavestory /home/kretkiew/visualExercises/cavestory/lib /home/kretkiew/visualExercises/cavestory/build /home/kretkiew/visualExercises/cavestory/build/lib /home/kretkiew/visualExercises/cavestory/build/lib/CMakeFiles/CaveStory_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/CaveStory_lib.dir/depend

