# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\software\jetbrains\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = E:\software\jetbrains\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\code\DataStructure\0201_SqList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\code\DataStructure\0201_SqList\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/0201_SqList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/0201_SqList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/0201_SqList.dir/flags.make

CMakeFiles/0201_SqList.dir/main.c.obj: CMakeFiles/0201_SqList.dir/flags.make
CMakeFiles/0201_SqList.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\code\DataStructure\0201_SqList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/0201_SqList.dir/main.c.obj"
	E:\software\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\0201_SqList.dir\main.c.obj -c E:\code\DataStructure\0201_SqList\main.c

CMakeFiles/0201_SqList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/0201_SqList.dir/main.c.i"
	E:\software\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\code\DataStructure\0201_SqList\main.c > CMakeFiles\0201_SqList.dir\main.c.i

CMakeFiles/0201_SqList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/0201_SqList.dir/main.c.s"
	E:\software\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\code\DataStructure\0201_SqList\main.c -o CMakeFiles\0201_SqList.dir\main.c.s

CMakeFiles/0201_SqList.dir/SqList.c.obj: CMakeFiles/0201_SqList.dir/flags.make
CMakeFiles/0201_SqList.dir/SqList.c.obj: ../SqList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\code\DataStructure\0201_SqList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/0201_SqList.dir/SqList.c.obj"
	E:\software\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\0201_SqList.dir\SqList.c.obj -c E:\code\DataStructure\0201_SqList\SqList.c

CMakeFiles/0201_SqList.dir/SqList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/0201_SqList.dir/SqList.c.i"
	E:\software\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\code\DataStructure\0201_SqList\SqList.c > CMakeFiles\0201_SqList.dir\SqList.c.i

CMakeFiles/0201_SqList.dir/SqList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/0201_SqList.dir/SqList.c.s"
	E:\software\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\code\DataStructure\0201_SqList\SqList.c -o CMakeFiles\0201_SqList.dir\SqList.c.s

# Object files for target 0201_SqList
0201_SqList_OBJECTS = \
"CMakeFiles/0201_SqList.dir/main.c.obj" \
"CMakeFiles/0201_SqList.dir/SqList.c.obj"

# External object files for target 0201_SqList
0201_SqList_EXTERNAL_OBJECTS =

0201_SqList.exe: CMakeFiles/0201_SqList.dir/main.c.obj
0201_SqList.exe: CMakeFiles/0201_SqList.dir/SqList.c.obj
0201_SqList.exe: CMakeFiles/0201_SqList.dir/build.make
0201_SqList.exe: CMakeFiles/0201_SqList.dir/linklibs.rsp
0201_SqList.exe: CMakeFiles/0201_SqList.dir/objects1.rsp
0201_SqList.exe: CMakeFiles/0201_SqList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\code\DataStructure\0201_SqList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 0201_SqList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\0201_SqList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/0201_SqList.dir/build: 0201_SqList.exe

.PHONY : CMakeFiles/0201_SqList.dir/build

CMakeFiles/0201_SqList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\0201_SqList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/0201_SqList.dir/clean

CMakeFiles/0201_SqList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\code\DataStructure\0201_SqList E:\code\DataStructure\0201_SqList E:\code\DataStructure\0201_SqList\cmake-build-debug E:\code\DataStructure\0201_SqList\cmake-build-debug E:\code\DataStructure\0201_SqList\cmake-build-debug\CMakeFiles\0201_SqList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/0201_SqList.dir/depend
