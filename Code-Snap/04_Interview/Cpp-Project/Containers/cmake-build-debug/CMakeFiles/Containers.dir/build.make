# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/xuqi/Tool/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/xuqi/Tool/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Containers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Containers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Containers.dir/flags.make

CMakeFiles/Containers.dir/main.cpp.o: CMakeFiles/Containers.dir/flags.make
CMakeFiles/Containers.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Containers.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Containers.dir/main.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/main.cpp

CMakeFiles/Containers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Containers.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/main.cpp > CMakeFiles/Containers.dir/main.cpp.i

CMakeFiles/Containers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Containers.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/main.cpp -o CMakeFiles/Containers.dir/main.cpp.s

CMakeFiles/Containers.dir/SequenceContainer.cpp.o: CMakeFiles/Containers.dir/flags.make
CMakeFiles/Containers.dir/SequenceContainer.cpp.o: ../SequenceContainer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Containers.dir/SequenceContainer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Containers.dir/SequenceContainer.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/SequenceContainer.cpp

CMakeFiles/Containers.dir/SequenceContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Containers.dir/SequenceContainer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/SequenceContainer.cpp > CMakeFiles/Containers.dir/SequenceContainer.cpp.i

CMakeFiles/Containers.dir/SequenceContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Containers.dir/SequenceContainer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/SequenceContainer.cpp -o CMakeFiles/Containers.dir/SequenceContainer.cpp.s

# Object files for target Containers
Containers_OBJECTS = \
"CMakeFiles/Containers.dir/main.cpp.o" \
"CMakeFiles/Containers.dir/SequenceContainer.cpp.o"

# External object files for target Containers
Containers_EXTERNAL_OBJECTS =

Containers: CMakeFiles/Containers.dir/main.cpp.o
Containers: CMakeFiles/Containers.dir/SequenceContainer.cpp.o
Containers: CMakeFiles/Containers.dir/build.make
Containers: CMakeFiles/Containers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Containers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Containers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Containers.dir/build: Containers

.PHONY : CMakeFiles/Containers.dir/build

CMakeFiles/Containers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Containers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Containers.dir/clean

CMakeFiles/Containers.dir/depend:
	cd /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/04_Interview/Cpp-Project/Containers/cmake-build-debug/CMakeFiles/Containers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Containers.dir/depend

