# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fangtao/cpp/object_based

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fangtao/cpp/object_based/build

# Include any dependencies generated for this target.
include CMakeFiles/executable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/executable.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/executable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executable.dir/flags.make

CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o: /home/fangtao/cpp/tool/tool.cpp
CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o: CMakeFiles/executable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fangtao/cpp/object_based/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o -MF CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o.d -o CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o -c /home/fangtao/cpp/tool/tool.cpp

CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fangtao/cpp/tool/tool.cpp > CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.i

CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fangtao/cpp/tool/tool.cpp -o CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.s

CMakeFiles/executable.dir/main.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/main.cpp.o: ../main.cpp
CMakeFiles/executable.dir/main.cpp.o: CMakeFiles/executable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fangtao/cpp/object_based/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/executable.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/executable.dir/main.cpp.o -MF CMakeFiles/executable.dir/main.cpp.o.d -o CMakeFiles/executable.dir/main.cpp.o -c /home/fangtao/cpp/object_based/main.cpp

CMakeFiles/executable.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fangtao/cpp/object_based/main.cpp > CMakeFiles/executable.dir/main.cpp.i

CMakeFiles/executable.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fangtao/cpp/object_based/main.cpp -o CMakeFiles/executable.dir/main.cpp.s

CMakeFiles/executable.dir/stack.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/stack.cpp.o: ../stack.cpp
CMakeFiles/executable.dir/stack.cpp.o: CMakeFiles/executable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fangtao/cpp/object_based/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/executable.dir/stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/executable.dir/stack.cpp.o -MF CMakeFiles/executable.dir/stack.cpp.o.d -o CMakeFiles/executable.dir/stack.cpp.o -c /home/fangtao/cpp/object_based/stack.cpp

CMakeFiles/executable.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fangtao/cpp/object_based/stack.cpp > CMakeFiles/executable.dir/stack.cpp.i

CMakeFiles/executable.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fangtao/cpp/object_based/stack.cpp -o CMakeFiles/executable.dir/stack.cpp.s

CMakeFiles/executable.dir/triangular.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/triangular.cpp.o: ../triangular.cpp
CMakeFiles/executable.dir/triangular.cpp.o: CMakeFiles/executable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fangtao/cpp/object_based/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/executable.dir/triangular.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/executable.dir/triangular.cpp.o -MF CMakeFiles/executable.dir/triangular.cpp.o.d -o CMakeFiles/executable.dir/triangular.cpp.o -c /home/fangtao/cpp/object_based/triangular.cpp

CMakeFiles/executable.dir/triangular.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/triangular.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fangtao/cpp/object_based/triangular.cpp > CMakeFiles/executable.dir/triangular.cpp.i

CMakeFiles/executable.dir/triangular.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/triangular.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fangtao/cpp/object_based/triangular.cpp -o CMakeFiles/executable.dir/triangular.cpp.s

CMakeFiles/executable.dir/triangular_iterator.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/triangular_iterator.cpp.o: ../triangular_iterator.cpp
CMakeFiles/executable.dir/triangular_iterator.cpp.o: CMakeFiles/executable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fangtao/cpp/object_based/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/executable.dir/triangular_iterator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/executable.dir/triangular_iterator.cpp.o -MF CMakeFiles/executable.dir/triangular_iterator.cpp.o.d -o CMakeFiles/executable.dir/triangular_iterator.cpp.o -c /home/fangtao/cpp/object_based/triangular_iterator.cpp

CMakeFiles/executable.dir/triangular_iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/triangular_iterator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fangtao/cpp/object_based/triangular_iterator.cpp > CMakeFiles/executable.dir/triangular_iterator.cpp.i

CMakeFiles/executable.dir/triangular_iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/triangular_iterator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fangtao/cpp/object_based/triangular_iterator.cpp -o CMakeFiles/executable.dir/triangular_iterator.cpp.s

# Object files for target executable
executable_OBJECTS = \
"CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o" \
"CMakeFiles/executable.dir/main.cpp.o" \
"CMakeFiles/executable.dir/stack.cpp.o" \
"CMakeFiles/executable.dir/triangular.cpp.o" \
"CMakeFiles/executable.dir/triangular_iterator.cpp.o"

# External object files for target executable
executable_EXTERNAL_OBJECTS =

executable: CMakeFiles/executable.dir/home/fangtao/cpp/tool/tool.cpp.o
executable: CMakeFiles/executable.dir/main.cpp.o
executable: CMakeFiles/executable.dir/stack.cpp.o
executable: CMakeFiles/executable.dir/triangular.cpp.o
executable: CMakeFiles/executable.dir/triangular_iterator.cpp.o
executable: CMakeFiles/executable.dir/build.make
executable: CMakeFiles/executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fangtao/cpp/object_based/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable executable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executable.dir/build: executable
.PHONY : CMakeFiles/executable.dir/build

CMakeFiles/executable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executable.dir/clean

CMakeFiles/executable.dir/depend:
	cd /home/fangtao/cpp/object_based/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fangtao/cpp/object_based /home/fangtao/cpp/object_based /home/fangtao/cpp/object_based/build /home/fangtao/cpp/object_based/build /home/fangtao/cpp/object_based/build/CMakeFiles/executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/executable.dir/depend
