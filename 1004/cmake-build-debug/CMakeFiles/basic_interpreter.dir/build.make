# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code2022A\CPP\1004

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code2022A\CPP\1004\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/basic_interpreter.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/basic_interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basic_interpreter.dir/flags.make

CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.obj: CMakeFiles/basic_interpreter.dir/flags.make
CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.obj: ../basic_interpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code2022A\CPP\1004\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.obj"
	D:\enviro\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\basic_interpreter.dir\basic_interpreter.cpp.obj -c D:\Code2022A\CPP\1004\basic_interpreter.cpp

CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.i"
	D:\enviro\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code2022A\CPP\1004\basic_interpreter.cpp > CMakeFiles\basic_interpreter.dir\basic_interpreter.cpp.i

CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.s"
	D:\enviro\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code2022A\CPP\1004\basic_interpreter.cpp -o CMakeFiles\basic_interpreter.dir\basic_interpreter.cpp.s

# Object files for target basic_interpreter
basic_interpreter_OBJECTS = \
"CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.obj"

# External object files for target basic_interpreter
basic_interpreter_EXTERNAL_OBJECTS =

basic_interpreter.exe: CMakeFiles/basic_interpreter.dir/basic_interpreter.cpp.obj
basic_interpreter.exe: CMakeFiles/basic_interpreter.dir/build.make
basic_interpreter.exe: CMakeFiles/basic_interpreter.dir/linklibs.rsp
basic_interpreter.exe: CMakeFiles/basic_interpreter.dir/objects1.rsp
basic_interpreter.exe: CMakeFiles/basic_interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code2022A\CPP\1004\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basic_interpreter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\basic_interpreter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basic_interpreter.dir/build: basic_interpreter.exe
.PHONY : CMakeFiles/basic_interpreter.dir/build

CMakeFiles/basic_interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\basic_interpreter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/basic_interpreter.dir/clean

CMakeFiles/basic_interpreter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code2022A\CPP\1004 D:\Code2022A\CPP\1004 D:\Code2022A\CPP\1004\cmake-build-debug D:\Code2022A\CPP\1004\cmake-build-debug D:\Code2022A\CPP\1004\cmake-build-debug\CMakeFiles\basic_interpreter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basic_interpreter.dir/depend
