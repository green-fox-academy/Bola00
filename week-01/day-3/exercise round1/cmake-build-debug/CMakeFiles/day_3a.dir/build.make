# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\bolar\Downloads\CLion-2018.3.3\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\bolar\Downloads\CLion-2018.3.3\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/day_3a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/day_3a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day_3a.dir/flags.make

CMakeFiles/day_3a.dir/main.cpp.obj: CMakeFiles/day_3a.dir/flags.make
CMakeFiles/day_3a.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day_3a.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\day_3a.dir\main.cpp.obj -c "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\main.cpp"

CMakeFiles/day_3a.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day_3a.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\main.cpp" > CMakeFiles\day_3a.dir\main.cpp.i

CMakeFiles/day_3a.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day_3a.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\main.cpp" -o CMakeFiles\day_3a.dir\main.cpp.s

# Object files for target day_3a
day_3a_OBJECTS = \
"CMakeFiles/day_3a.dir/main.cpp.obj"

# External object files for target day_3a
day_3a_EXTERNAL_OBJECTS =

day_3a.exe: CMakeFiles/day_3a.dir/main.cpp.obj
day_3a.exe: CMakeFiles/day_3a.dir/build.make
day_3a.exe: CMakeFiles/day_3a.dir/linklibs.rsp
day_3a.exe: CMakeFiles/day_3a.dir/objects1.rsp
day_3a.exe: CMakeFiles/day_3a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day_3a.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\day_3a.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day_3a.dir/build: day_3a.exe

.PHONY : CMakeFiles/day_3a.dir/build

CMakeFiles/day_3a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\day_3a.dir\cmake_clean.cmake
.PHONY : CMakeFiles/day_3a.dir/clean

CMakeFiles/day_3a.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1" "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1" "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\cmake-build-debug" "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\cmake-build-debug" "C:\Users\bolar\greenfox\Bola00\week-01\day-3\exercise round1\cmake-build-debug\CMakeFiles\day_3a.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/day_3a.dir/depend

