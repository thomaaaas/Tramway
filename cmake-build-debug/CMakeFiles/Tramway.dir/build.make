# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/norma/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/norma/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/norma/CLionProjects/Tramway

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tramway.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tramway.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tramway.dir/flags.make

CMakeFiles/Tramway.dir/main.cpp.o: CMakeFiles/Tramway.dir/flags.make
CMakeFiles/Tramway.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tramway.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tramway.dir/main.cpp.o -c /cygdrive/c/Users/norma/CLionProjects/Tramway/main.cpp

CMakeFiles/Tramway.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tramway.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/norma/CLionProjects/Tramway/main.cpp > CMakeFiles/Tramway.dir/main.cpp.i

CMakeFiles/Tramway.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tramway.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/norma/CLionProjects/Tramway/main.cpp -o CMakeFiles/Tramway.dir/main.cpp.s

# Object files for target Tramway
Tramway_OBJECTS = \
"CMakeFiles/Tramway.dir/main.cpp.o"

# External object files for target Tramway
Tramway_EXTERNAL_OBJECTS =

Tramway.exe: CMakeFiles/Tramway.dir/main.cpp.o
Tramway.exe: CMakeFiles/Tramway.dir/build.make
Tramway.exe: CMakeFiles/Tramway.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tramway.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tramway.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tramway.dir/build: Tramway.exe

.PHONY : CMakeFiles/Tramway.dir/build

CMakeFiles/Tramway.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tramway.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tramway.dir/clean

CMakeFiles/Tramway.dir/depend:
	cd /cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/norma/CLionProjects/Tramway /cygdrive/c/Users/norma/CLionProjects/Tramway /cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug /cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug /cygdrive/c/Users/norma/CLionProjects/Tramway/cmake-build-debug/CMakeFiles/Tramway.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tramway.dir/depend

