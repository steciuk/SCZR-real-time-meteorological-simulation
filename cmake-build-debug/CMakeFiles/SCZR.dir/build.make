# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/jestemleon/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jestemleon/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jestemleon/Dokumenty/ProjektSCZR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SCZR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SCZR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SCZR.dir/flags.make

CMakeFiles/SCZR.dir/src/main.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SCZR.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/main.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/main.cpp

CMakeFiles/SCZR.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/main.cpp > CMakeFiles/SCZR.dir/src/main.cpp.i

CMakeFiles/SCZR.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/main.cpp -o CMakeFiles/SCZR.dir/src/main.cpp.s

CMakeFiles/SCZR.dir/src/Station.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/Station.cpp.o: ../src/Station.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SCZR.dir/src/Station.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/Station.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/Station.cpp

CMakeFiles/SCZR.dir/src/Station.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/Station.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/Station.cpp > CMakeFiles/SCZR.dir/src/Station.cpp.i

CMakeFiles/SCZR.dir/src/Station.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/Station.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/Station.cpp -o CMakeFiles/SCZR.dir/src/Station.cpp.s

CMakeFiles/SCZR.dir/src/Stations.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/Stations.cpp.o: ../src/Stations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SCZR.dir/src/Stations.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/Stations.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/Stations.cpp

CMakeFiles/SCZR.dir/src/Stations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/Stations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/Stations.cpp > CMakeFiles/SCZR.dir/src/Stations.cpp.i

CMakeFiles/SCZR.dir/src/Stations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/Stations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/Stations.cpp -o CMakeFiles/SCZR.dir/src/Stations.cpp.s

CMakeFiles/SCZR.dir/src/SharedMemory.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/SharedMemory.cpp.o: ../src/SharedMemory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SCZR.dir/src/SharedMemory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/SharedMemory.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/SharedMemory.cpp

CMakeFiles/SCZR.dir/src/SharedMemory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/SharedMemory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/SharedMemory.cpp > CMakeFiles/SCZR.dir/src/SharedMemory.cpp.i

CMakeFiles/SCZR.dir/src/SharedMemory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/SharedMemory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/SharedMemory.cpp -o CMakeFiles/SCZR.dir/src/SharedMemory.cpp.s

CMakeFiles/SCZR.dir/src/SharedQueue.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/SharedQueue.cpp.o: ../src/SharedQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SCZR.dir/src/SharedQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/SharedQueue.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/SharedQueue.cpp

CMakeFiles/SCZR.dir/src/SharedQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/SharedQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/SharedQueue.cpp > CMakeFiles/SCZR.dir/src/SharedQueue.cpp.i

CMakeFiles/SCZR.dir/src/SharedQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/SharedQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/SharedQueue.cpp -o CMakeFiles/SCZR.dir/src/SharedQueue.cpp.s

CMakeFiles/SCZR.dir/src/ProcessB.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/ProcessB.cpp.o: ../src/ProcessB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SCZR.dir/src/ProcessB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/ProcessB.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessB.cpp

CMakeFiles/SCZR.dir/src/ProcessB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/ProcessB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessB.cpp > CMakeFiles/SCZR.dir/src/ProcessB.cpp.i

CMakeFiles/SCZR.dir/src/ProcessB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/ProcessB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessB.cpp -o CMakeFiles/SCZR.dir/src/ProcessB.cpp.s

CMakeFiles/SCZR.dir/src/ProcessA.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/ProcessA.cpp.o: ../src/ProcessA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SCZR.dir/src/ProcessA.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/ProcessA.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessA.cpp

CMakeFiles/SCZR.dir/src/ProcessA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/ProcessA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessA.cpp > CMakeFiles/SCZR.dir/src/ProcessA.cpp.i

CMakeFiles/SCZR.dir/src/ProcessA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/ProcessA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessA.cpp -o CMakeFiles/SCZR.dir/src/ProcessA.cpp.s

CMakeFiles/SCZR.dir/src/ProcessC.cpp.o: CMakeFiles/SCZR.dir/flags.make
CMakeFiles/SCZR.dir/src/ProcessC.cpp.o: ../src/ProcessC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SCZR.dir/src/ProcessC.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCZR.dir/src/ProcessC.cpp.o -c /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessC.cpp

CMakeFiles/SCZR.dir/src/ProcessC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCZR.dir/src/ProcessC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessC.cpp > CMakeFiles/SCZR.dir/src/ProcessC.cpp.i

CMakeFiles/SCZR.dir/src/ProcessC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCZR.dir/src/ProcessC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jestemleon/Dokumenty/ProjektSCZR/src/ProcessC.cpp -o CMakeFiles/SCZR.dir/src/ProcessC.cpp.s

# Object files for target SCZR
SCZR_OBJECTS = \
"CMakeFiles/SCZR.dir/src/main.cpp.o" \
"CMakeFiles/SCZR.dir/src/Station.cpp.o" \
"CMakeFiles/SCZR.dir/src/Stations.cpp.o" \
"CMakeFiles/SCZR.dir/src/SharedMemory.cpp.o" \
"CMakeFiles/SCZR.dir/src/SharedQueue.cpp.o" \
"CMakeFiles/SCZR.dir/src/ProcessB.cpp.o" \
"CMakeFiles/SCZR.dir/src/ProcessA.cpp.o" \
"CMakeFiles/SCZR.dir/src/ProcessC.cpp.o"

# External object files for target SCZR
SCZR_EXTERNAL_OBJECTS =

SCZR: CMakeFiles/SCZR.dir/src/main.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/Station.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/Stations.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/SharedMemory.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/SharedQueue.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/ProcessB.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/ProcessA.cpp.o
SCZR: CMakeFiles/SCZR.dir/src/ProcessC.cpp.o
SCZR: CMakeFiles/SCZR.dir/build.make
SCZR: /usr/lib64/librt.so
SCZR: CMakeFiles/SCZR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable SCZR"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SCZR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SCZR.dir/build: SCZR

.PHONY : CMakeFiles/SCZR.dir/build

CMakeFiles/SCZR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SCZR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SCZR.dir/clean

CMakeFiles/SCZR.dir/depend:
	cd /home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jestemleon/Dokumenty/ProjektSCZR /home/jestemleon/Dokumenty/ProjektSCZR /home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug /home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug /home/jestemleon/Dokumenty/ProjektSCZR/cmake-build-debug/CMakeFiles/SCZR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SCZR.dir/depend

