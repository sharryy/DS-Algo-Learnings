# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/QueueWithLinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QueueWithLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QueueWithLinkedList.dir/flags.make

CMakeFiles/QueueWithLinkedList.dir/main.cpp.obj: CMakeFiles/QueueWithLinkedList.dir/flags.make
CMakeFiles/QueueWithLinkedList.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QueueWithLinkedList.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\QueueWithLinkedList.dir\main.cpp.obj -c "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\main.cpp"

CMakeFiles/QueueWithLinkedList.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QueueWithLinkedList.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\main.cpp" > CMakeFiles\QueueWithLinkedList.dir\main.cpp.i

CMakeFiles/QueueWithLinkedList.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QueueWithLinkedList.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\main.cpp" -o CMakeFiles\QueueWithLinkedList.dir\main.cpp.s

# Object files for target QueueWithLinkedList
QueueWithLinkedList_OBJECTS = \
"CMakeFiles/QueueWithLinkedList.dir/main.cpp.obj"

# External object files for target QueueWithLinkedList
QueueWithLinkedList_EXTERNAL_OBJECTS =

QueueWithLinkedList.exe: CMakeFiles/QueueWithLinkedList.dir/main.cpp.obj
QueueWithLinkedList.exe: CMakeFiles/QueueWithLinkedList.dir/build.make
QueueWithLinkedList.exe: CMakeFiles/QueueWithLinkedList.dir/linklibs.rsp
QueueWithLinkedList.exe: CMakeFiles/QueueWithLinkedList.dir/objects1.rsp
QueueWithLinkedList.exe: CMakeFiles/QueueWithLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable QueueWithLinkedList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\QueueWithLinkedList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QueueWithLinkedList.dir/build: QueueWithLinkedList.exe

.PHONY : CMakeFiles/QueueWithLinkedList.dir/build

CMakeFiles/QueueWithLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QueueWithLinkedList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QueueWithLinkedList.dir/clean

CMakeFiles/QueueWithLinkedList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList" "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList" "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\cmake-build-debug" "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\cmake-build-debug" "C:\Users\Dar Laptop\CLionProjects\QueueWithLinkedList\cmake-build-debug\CMakeFiles\QueueWithLinkedList.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/QueueWithLinkedList.dir/depend

