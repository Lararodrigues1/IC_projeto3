# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/henriqueramos/Desktop/IC/IC_projeto3/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/henriqueramos/Desktop/IC/IC_projeto3/src/build

# Include any dependencies generated for this target.
include CMakeFiles/test_fcm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_fcm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_fcm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_fcm.dir/flags.make

CMakeFiles/test_fcm.dir/test_fcm.cpp.o: CMakeFiles/test_fcm.dir/flags.make
CMakeFiles/test_fcm.dir/test_fcm.cpp.o: /home/henriqueramos/Desktop/IC/IC_projeto3/src/test_fcm.cpp
CMakeFiles/test_fcm.dir/test_fcm.cpp.o: CMakeFiles/test_fcm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/henriqueramos/Desktop/IC/IC_projeto3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_fcm.dir/test_fcm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_fcm.dir/test_fcm.cpp.o -MF CMakeFiles/test_fcm.dir/test_fcm.cpp.o.d -o CMakeFiles/test_fcm.dir/test_fcm.cpp.o -c /home/henriqueramos/Desktop/IC/IC_projeto3/src/test_fcm.cpp

CMakeFiles/test_fcm.dir/test_fcm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_fcm.dir/test_fcm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/henriqueramos/Desktop/IC/IC_projeto3/src/test_fcm.cpp > CMakeFiles/test_fcm.dir/test_fcm.cpp.i

CMakeFiles/test_fcm.dir/test_fcm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_fcm.dir/test_fcm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/henriqueramos/Desktop/IC/IC_projeto3/src/test_fcm.cpp -o CMakeFiles/test_fcm.dir/test_fcm.cpp.s

# Object files for target test_fcm
test_fcm_OBJECTS = \
"CMakeFiles/test_fcm.dir/test_fcm.cpp.o"

# External object files for target test_fcm
test_fcm_EXTERNAL_OBJECTS =

/home/henriqueramos/Desktop/IC/IC_projeto3/bin/test_fcm: CMakeFiles/test_fcm.dir/test_fcm.cpp.o
/home/henriqueramos/Desktop/IC/IC_projeto3/bin/test_fcm: CMakeFiles/test_fcm.dir/build.make
/home/henriqueramos/Desktop/IC/IC_projeto3/bin/test_fcm: CMakeFiles/test_fcm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/henriqueramos/Desktop/IC/IC_projeto3/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/henriqueramos/Desktop/IC/IC_projeto3/bin/test_fcm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_fcm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_fcm.dir/build: /home/henriqueramos/Desktop/IC/IC_projeto3/bin/test_fcm
.PHONY : CMakeFiles/test_fcm.dir/build

CMakeFiles/test_fcm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_fcm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_fcm.dir/clean

CMakeFiles/test_fcm.dir/depend:
	cd /home/henriqueramos/Desktop/IC/IC_projeto3/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/henriqueramos/Desktop/IC/IC_projeto3/src /home/henriqueramos/Desktop/IC/IC_projeto3/src /home/henriqueramos/Desktop/IC/IC_projeto3/src/build /home/henriqueramos/Desktop/IC/IC_projeto3/src/build /home/henriqueramos/Desktop/IC/IC_projeto3/src/build/CMakeFiles/test_fcm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_fcm.dir/depend

