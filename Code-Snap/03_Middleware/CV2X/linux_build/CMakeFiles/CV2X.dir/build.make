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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build

# Include any dependencies generated for this target.
include CMakeFiles/CV2X.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CV2X.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CV2X.dir/flags.make

CMakeFiles/CV2X.dir/src/main.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CV2X.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/main.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/main.cpp

CMakeFiles/CV2X.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/main.cpp > CMakeFiles/CV2X.dir/src/main.cpp.i

CMakeFiles/CV2X.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/main.cpp -o CMakeFiles/CV2X.dir/src/main.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.o: ../src/v2xApp/V2xAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithm.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithm.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithm.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.o: ../src/v2xApp/V2xAlgorithmAdapter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmAdapter.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmAdapter.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmAdapter.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.o: ../src/v2xApp/V2xAlgorithmScene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmScene.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmScene.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmScene.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.o: ../src/v2xApp/V2xAlgorithmTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmTest.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmTest.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xAlgorithmTest.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.o: ../src/v2xApp/V2xApp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xApp.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xApp.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xApp.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.o: ../src/v2xApp/V2xBroker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xBroker.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xBroker.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xBroker.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.o: ../src/v2xApp/V2xCarObjectMgnt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xCarObjectMgnt.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xCarObjectMgnt.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xCarObjectMgnt.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.o: ../src/v2xApp/V2xHvMapSpatCal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xHvMapSpatCal.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xHvMapSpatCal.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xHvMapSpatCal.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.o: ../src/v2xApp/V2xReceiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xReceiver.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xReceiver.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xReceiver.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.o: ../src/v2xApp/V2xReceiverProxy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xReceiverProxy.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xReceiverProxy.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xReceiverProxy.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.o: ../src/v2xApp/V2xRvAsyncFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvAsyncFilter.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvAsyncFilter.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvAsyncFilter.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.o: ../src/v2xApp/V2xRvFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvFilter.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvFilter.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvFilter.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.o: ../src/v2xApp/V2xRvThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvThreadPool.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvThreadPool.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xRvThreadPool.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.o: ../src/v2xApp/V2xSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xSender.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xSender.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xSender.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.s

CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.o: ../src/v2xApp/V2xSetting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xSetting.cpp

CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xSetting.cpp > CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.i

CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xApp/V2xSetting.cpp -o CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.s

CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.o: ../src/v2xUtil/V2xMsg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xMsg.cpp

CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xMsg.cpp > CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.i

CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xMsg.cpp -o CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.s

CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.o: ../src/v2xUtil/V2xThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xThread.cpp

CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xThread.cpp > CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.i

CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xThread.cpp -o CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.s

CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.o: CMakeFiles/CV2X.dir/flags.make
CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.o: ../src/v2xUtil/V2xThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xThreadPool.cpp

CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xThreadPool.cpp > CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.i

CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/src/v2xUtil/V2xThreadPool.cpp -o CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.s

# Object files for target CV2X
CV2X_OBJECTS = \
"CMakeFiles/CV2X.dir/src/main.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.o" \
"CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.o"

# External object files for target CV2X
CV2X_EXTERNAL_OBJECTS =

bin/CV2X: CMakeFiles/CV2X.dir/src/main.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithm.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmAdapter.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmScene.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xAlgorithmTest.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xApp.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xBroker.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xCarObjectMgnt.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xHvMapSpatCal.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiver.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xReceiverProxy.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xRvAsyncFilter.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xRvFilter.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xRvThreadPool.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xSender.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xApp/V2xSetting.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xUtil/V2xMsg.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xUtil/V2xThread.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/src/v2xUtil/V2xThreadPool.cpp.o
bin/CV2X: CMakeFiles/CV2X.dir/build.make
bin/CV2X: lib/libtoolkit.a
bin/CV2X: lib/libasn1.a
bin/CV2X: lib/libv2xapp.a
bin/CV2X: CMakeFiles/CV2X.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable bin/CV2X"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CV2X.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CV2X.dir/build: bin/CV2X

.PHONY : CMakeFiles/CV2X.dir/build

CMakeFiles/CV2X.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CV2X.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CV2X.dir/clean

CMakeFiles/CV2X.dir/depend:
	cd /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles/CV2X.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CV2X.dir/depend

