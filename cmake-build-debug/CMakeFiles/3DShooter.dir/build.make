# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gefre\Desktop\Sezino\C++\3DShooter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gefre\Desktop\Sezino\C++\3DShooter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3DShooter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3DShooter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3DShooter.dir/flags.make

CMakeFiles/3DShooter.dir/main.cpp.obj: CMakeFiles/3DShooter.dir/flags.make
CMakeFiles/3DShooter.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gefre\Desktop\Sezino\C++\3DShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3DShooter.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\3DShooter.dir\main.cpp.obj -c C:\Users\gefre\Desktop\Sezino\C++\3DShooter\main.cpp

CMakeFiles/3DShooter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DShooter.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gefre\Desktop\Sezino\C++\3DShooter\main.cpp > CMakeFiles\3DShooter.dir\main.cpp.i

CMakeFiles/3DShooter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DShooter.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gefre\Desktop\Sezino\C++\3DShooter\main.cpp -o CMakeFiles\3DShooter.dir\main.cpp.s

# Object files for target 3DShooter
3DShooter_OBJECTS = \
"CMakeFiles/3DShooter.dir/main.cpp.obj"

# External object files for target 3DShooter
3DShooter_EXTERNAL_OBJECTS =

3DShooter.exe: CMakeFiles/3DShooter.dir/main.cpp.obj
3DShooter.exe: CMakeFiles/3DShooter.dir/build.make
3DShooter.exe: CMakeFiles/3DShooter.dir/linklibs.rsp
3DShooter.exe: CMakeFiles/3DShooter.dir/objects1.rsp
3DShooter.exe: CMakeFiles/3DShooter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gefre\Desktop\Sezino\C++\3DShooter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3DShooter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3DShooter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3DShooter.dir/build: 3DShooter.exe

.PHONY : CMakeFiles/3DShooter.dir/build

CMakeFiles/3DShooter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3DShooter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3DShooter.dir/clean

CMakeFiles/3DShooter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gefre\Desktop\Sezino\C++\3DShooter C:\Users\gefre\Desktop\Sezino\C++\3DShooter C:\Users\gefre\Desktop\Sezino\C++\3DShooter\cmake-build-debug C:\Users\gefre\Desktop\Sezino\C++\3DShooter\cmake-build-debug C:\Users\gefre\Desktop\Sezino\C++\3DShooter\cmake-build-debug\CMakeFiles\3DShooter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3DShooter.dir/depend

