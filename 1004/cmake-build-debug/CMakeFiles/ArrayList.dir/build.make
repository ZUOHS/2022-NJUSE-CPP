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
include CMakeFiles/ArrayList.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ArrayList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArrayList.dir/flags.make

CMakeFiles/ArrayList.dir/ArrayList.cpp.obj: CMakeFiles/ArrayList.dir/flags.make
CMakeFiles/ArrayList.dir/ArrayList.cpp.obj: ../ArrayList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code2022A\CPP\1004\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ArrayList.dir/ArrayList.cpp.obj"
	D:\enviro\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ArrayList.dir\ArrayList.cpp.obj -c D:\Code2022A\CPP\1004\ArrayList.cpp

CMakeFiles/ArrayList.dir/ArrayList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ArrayList.dir/ArrayList.cpp.i"
	D:\enviro\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code2022A\CPP\1004\ArrayList.cpp > CMakeFiles\ArrayList.dir\ArrayList.cpp.i

CMakeFiles/ArrayList.dir/ArrayList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ArrayList.dir/ArrayList.cpp.s"
	D:\enviro\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code2022A\CPP\1004\ArrayList.cpp -o CMakeFiles\ArrayList.dir\ArrayList.cpp.s

# Object files for target ArrayList
ArrayList_OBJECTS = \
"CMakeFiles/ArrayList.dir/ArrayList.cpp.obj"

# External object files for target ArrayList
ArrayList_EXTERNAL_OBJECTS =

ArrayList.exe: CMakeFiles/ArrayList.dir/ArrayList.cpp.obj
ArrayList.exe: CMakeFiles/ArrayList.dir/build.make
ArrayList.exe: CMakeFiles/ArrayList.dir/linklibs.rsp
ArrayList.exe: CMakeFiles/ArrayList.dir/objects1.rsp
ArrayList.exe: CMakeFiles/ArrayList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code2022A\CPP\1004\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ArrayList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ArrayList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArrayList.dir/build: ArrayList.exe
.PHONY : CMakeFiles/ArrayList.dir/build

CMakeFiles/ArrayList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ArrayList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ArrayList.dir/clean

CMakeFiles/ArrayList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code2022A\CPP\1004 D:\Code2022A\CPP\1004 D:\Code2022A\CPP\1004\cmake-build-debug D:\Code2022A\CPP\1004\cmake-build-debug D:\Code2022A\CPP\1004\cmake-build-debug\CMakeFiles\ArrayList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ArrayList.dir/depend
