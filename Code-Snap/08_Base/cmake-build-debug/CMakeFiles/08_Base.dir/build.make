# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/08_Base.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/08_Base.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/08_Base.dir/flags.make

CMakeFiles/08_Base.dir/main.cpp.o: CMakeFiles/08_Base.dir/flags.make
CMakeFiles/08_Base.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/08_Base.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/08_Base.dir/main.cpp.o -c /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/main.cpp

CMakeFiles/08_Base.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/08_Base.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/main.cpp > CMakeFiles/08_Base.dir/main.cpp.i

CMakeFiles/08_Base.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/08_Base.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/main.cpp -o CMakeFiles/08_Base.dir/main.cpp.s

CMakeFiles/08_Base.dir/ThreadPool.cpp.o: CMakeFiles/08_Base.dir/flags.make
CMakeFiles/08_Base.dir/ThreadPool.cpp.o: ../ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/08_Base.dir/ThreadPool.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/08_Base.dir/ThreadPool.cpp.o -c /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/ThreadPool.cpp

CMakeFiles/08_Base.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/08_Base.dir/ThreadPool.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/ThreadPool.cpp > CMakeFiles/08_Base.dir/ThreadPool.cpp.i

CMakeFiles/08_Base.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/08_Base.dir/ThreadPool.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/ThreadPool.cpp -o CMakeFiles/08_Base.dir/ThreadPool.cpp.s

# Object files for target 08_Base
08_Base_OBJECTS = \
"CMakeFiles/08_Base.dir/main.cpp.o" \
"CMakeFiles/08_Base.dir/ThreadPool.cpp.o"

# External object files for target 08_Base
08_Base_EXTERNAL_OBJECTS =

08_Base: CMakeFiles/08_Base.dir/main.cpp.o
08_Base: CMakeFiles/08_Base.dir/ThreadPool.cpp.o
08_Base: CMakeFiles/08_Base.dir/build.make
08_Base: CMakeFiles/08_Base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 08_Base"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/08_Base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/08_Base.dir/build: 08_Base

.PHONY : CMakeFiles/08_Base.dir/build

CMakeFiles/08_Base.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/08_Base.dir/cmake_clean.cmake
.PHONY : CMakeFiles/08_Base.dir/clean

CMakeFiles/08_Base.dir/depend:
	cd /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug /Users/xuqi/Documents/Linux-NoteBook/Code-Snap/08_Base/cmake-build-debug/CMakeFiles/08_Base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/08_Base.dir/depend

