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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/czolg/studia/jipp/labs/philosophers/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/czolg/studia/jipp/labs/philosophers/project/build

# Include any dependencies generated for this target.
include CMakeFiles/dine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dine.dir/flags.make

CMakeFiles/dine.dir/src/main.cpp.o: CMakeFiles/dine.dir/flags.make
CMakeFiles/dine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/czolg/studia/jipp/labs/philosophers/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dine.dir/src/main.cpp.o -c /home/czolg/studia/jipp/labs/philosophers/project/src/main.cpp

CMakeFiles/dine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/czolg/studia/jipp/labs/philosophers/project/src/main.cpp > CMakeFiles/dine.dir/src/main.cpp.i

CMakeFiles/dine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/czolg/studia/jipp/labs/philosophers/project/src/main.cpp -o CMakeFiles/dine.dir/src/main.cpp.s

CMakeFiles/dine.dir/src/philosopher.cpp.o: CMakeFiles/dine.dir/flags.make
CMakeFiles/dine.dir/src/philosopher.cpp.o: ../src/philosopher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/czolg/studia/jipp/labs/philosophers/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dine.dir/src/philosopher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dine.dir/src/philosopher.cpp.o -c /home/czolg/studia/jipp/labs/philosophers/project/src/philosopher.cpp

CMakeFiles/dine.dir/src/philosopher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dine.dir/src/philosopher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/czolg/studia/jipp/labs/philosophers/project/src/philosopher.cpp > CMakeFiles/dine.dir/src/philosopher.cpp.i

CMakeFiles/dine.dir/src/philosopher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dine.dir/src/philosopher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/czolg/studia/jipp/labs/philosophers/project/src/philosopher.cpp -o CMakeFiles/dine.dir/src/philosopher.cpp.s

CMakeFiles/dine.dir/src/table.cpp.o: CMakeFiles/dine.dir/flags.make
CMakeFiles/dine.dir/src/table.cpp.o: ../src/table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/czolg/studia/jipp/labs/philosophers/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dine.dir/src/table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dine.dir/src/table.cpp.o -c /home/czolg/studia/jipp/labs/philosophers/project/src/table.cpp

CMakeFiles/dine.dir/src/table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dine.dir/src/table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/czolg/studia/jipp/labs/philosophers/project/src/table.cpp > CMakeFiles/dine.dir/src/table.cpp.i

CMakeFiles/dine.dir/src/table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dine.dir/src/table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/czolg/studia/jipp/labs/philosophers/project/src/table.cpp -o CMakeFiles/dine.dir/src/table.cpp.s

# Object files for target dine
dine_OBJECTS = \
"CMakeFiles/dine.dir/src/main.cpp.o" \
"CMakeFiles/dine.dir/src/philosopher.cpp.o" \
"CMakeFiles/dine.dir/src/table.cpp.o"

# External object files for target dine
dine_EXTERNAL_OBJECTS =

dine: CMakeFiles/dine.dir/src/main.cpp.o
dine: CMakeFiles/dine.dir/src/philosopher.cpp.o
dine: CMakeFiles/dine.dir/src/table.cpp.o
dine: CMakeFiles/dine.dir/build.make
dine: CMakeFiles/dine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/czolg/studia/jipp/labs/philosophers/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable dine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dine.dir/build: dine

.PHONY : CMakeFiles/dine.dir/build

CMakeFiles/dine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dine.dir/clean

CMakeFiles/dine.dir/depend:
	cd /home/czolg/studia/jipp/labs/philosophers/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/czolg/studia/jipp/labs/philosophers/project /home/czolg/studia/jipp/labs/philosophers/project /home/czolg/studia/jipp/labs/philosophers/project/build /home/czolg/studia/jipp/labs/philosophers/project/build /home/czolg/studia/jipp/labs/philosophers/project/build/CMakeFiles/dine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dine.dir/depend

