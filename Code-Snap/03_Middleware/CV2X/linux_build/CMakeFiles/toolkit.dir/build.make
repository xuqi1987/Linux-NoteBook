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
include CMakeFiles/toolkit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/toolkit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/toolkit.dir/flags.make

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.o: ../3rdpart/LinuxToolKit/src/Network/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/Buffer.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/Buffer.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/Buffer.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.o: ../3rdpart/LinuxToolKit/src/Network/SockUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.o: ../3rdpart/LinuxToolKit/src/Network/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/Socket.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/Socket.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/Socket.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.o: ../3rdpart/LinuxToolKit/src/Network/TcpClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.o: ../3rdpart/LinuxToolKit/src/Network/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.o: ../3rdpart/LinuxToolKit/src/Network/TcpSession.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.o: ../3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.o: ../3rdpart/LinuxToolKit/src/Poller/Pipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.o: ../3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.o: ../3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.o: ../3rdpart/LinuxToolKit/src/Poller/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/Timer.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/Timer.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Poller/Timer.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.o: ../3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.o: ../3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.o: ../3rdpart/LinuxToolKit/src/Util/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Logger.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Logger.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Logger.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.o: ../3rdpart/LinuxToolKit/src/Util/Mini.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Mini.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Mini.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Mini.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.o: ../3rdpart/LinuxToolKit/src/Util/SSLBox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.o: ../3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.o: ../3rdpart/LinuxToolKit/src/Util/Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Util.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Util.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/Util.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.s

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.o: CMakeFiles/toolkit.dir/flags.make
CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.o: ../3rdpart/LinuxToolKit/src/Util/uv_errno.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.o -c /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp > CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.i

CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp -o CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.s

# Object files for target toolkit
toolkit_OBJECTS = \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.o" \
"CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.o"

# External object files for target toolkit
toolkit_EXTERNAL_OBJECTS =

lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Buffer.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/SockUtil.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/Socket.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpClient.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpServer.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Network/TcpSession.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/EventPoller.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Pipe.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/PipeWrap.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/SelectWrap.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Poller/Timer.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/ThreadPoolResult.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Thread/WorkThreadPool.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Logger.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Mini.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLBox.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/SSLUtil.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/Util.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/3rdpart/LinuxToolKit/src/Util/uv_errno.cpp.o
lib/libtoolkit.a: CMakeFiles/toolkit.dir/build.make
lib/libtoolkit.a: CMakeFiles/toolkit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX static library lib/libtoolkit.a"
	$(CMAKE_COMMAND) -P CMakeFiles/toolkit.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/toolkit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/toolkit.dir/build: lib/libtoolkit.a

.PHONY : CMakeFiles/toolkit.dir/build

CMakeFiles/toolkit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/toolkit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/toolkit.dir/clean

CMakeFiles/toolkit.dir/depend:
	cd /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build /home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/03_Middleware/CV2X/linux_build/CMakeFiles/toolkit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/toolkit.dir/depend
