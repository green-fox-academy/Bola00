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
CMAKE_SOURCE_DIR = "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/exercise_round5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise_round5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise_round5.dir/flags.make

CMakeFiles/exercise_round5.dir/main.cpp.obj: CMakeFiles/exercise_round5.dir/flags.make
CMakeFiles/exercise_round5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exercise_round5.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\exercise_round5.dir\main.cpp.obj -c "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\main.cpp"

CMakeFiles/exercise_round5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise_round5.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\main.cpp" > CMakeFiles\exercise_round5.dir\main.cpp.i

CMakeFiles/exercise_round5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise_round5.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\main.cpp" -o CMakeFiles\exercise_round5.dir\main.cpp.s

# Object files for target exercise_round5
exercise_round5_OBJECTS = \
"CMakeFiles/exercise_round5.dir/main.cpp.obj"

# External object files for target exercise_round5
exercise_round5_EXTERNAL_OBJECTS =

exercise_round5.exe: CMakeFiles/exercise_round5.dir/main.cpp.obj
exercise_round5.exe: CMakeFiles/exercise_round5.dir/build.make
exercise_round5.exe: CMakeFiles/exercise_round5.dir/linklibs.rsp
exercise_round5.exe: CMakeFiles/exercise_round5.dir/objects1.rsp
exercise_round5.exe: CMakeFiles/exercise_round5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exercise_round5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exercise_round5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise_round5.dir/build: exercise_round5.exe

.PHONY : CMakeFiles/exercise_round5.dir/build

CMakeFiles/exercise_round5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exercise_round5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exercise_round5.dir/clean

CMakeFiles/exercise_round5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5" "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5" "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\cmake-build-debug" "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\cmake-build-debug" "C:\Users\bolar\greenfox\Bola00\week-01\day-3a\exercise round5\cmake-build-debug\CMakeFiles\exercise_round5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exercise_round5.dir/depend
