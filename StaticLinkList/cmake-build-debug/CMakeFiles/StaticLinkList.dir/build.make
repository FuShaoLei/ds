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
CMAKE_SOURCE_DIR = E:\ds\StaticLinkList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\ds\StaticLinkList\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StaticLinkList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StaticLinkList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaticLinkList.dir/flags.make

CMakeFiles/StaticLinkList.dir/main.c.obj: CMakeFiles/StaticLinkList.dir/flags.make
CMakeFiles/StaticLinkList.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ds\StaticLinkList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/StaticLinkList.dir/main.c.obj"
	E:\env\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\StaticLinkList.dir\main.c.obj -c E:\ds\StaticLinkList\main.c

CMakeFiles/StaticLinkList.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/StaticLinkList.dir/main.c.i"
	E:\env\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\ds\StaticLinkList\main.c > CMakeFiles\StaticLinkList.dir\main.c.i

CMakeFiles/StaticLinkList.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/StaticLinkList.dir/main.c.s"
	E:\env\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\ds\StaticLinkList\main.c -o CMakeFiles\StaticLinkList.dir\main.c.s

# Object files for target StaticLinkList
StaticLinkList_OBJECTS = \
"CMakeFiles/StaticLinkList.dir/main.c.obj"

# External object files for target StaticLinkList
StaticLinkList_EXTERNAL_OBJECTS =

StaticLinkList.exe: CMakeFiles/StaticLinkList.dir/main.c.obj
StaticLinkList.exe: CMakeFiles/StaticLinkList.dir/build.make
StaticLinkList.exe: CMakeFiles/StaticLinkList.dir/linklibs.rsp
StaticLinkList.exe: CMakeFiles/StaticLinkList.dir/objects1.rsp
StaticLinkList.exe: CMakeFiles/StaticLinkList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\ds\StaticLinkList\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable StaticLinkList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StaticLinkList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaticLinkList.dir/build: StaticLinkList.exe

.PHONY : CMakeFiles/StaticLinkList.dir/build

CMakeFiles/StaticLinkList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StaticLinkList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StaticLinkList.dir/clean

CMakeFiles/StaticLinkList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\ds\StaticLinkList E:\ds\StaticLinkList E:\ds\StaticLinkList\cmake-build-debug E:\ds\StaticLinkList\cmake-build-debug E:\ds\StaticLinkList\cmake-build-debug\CMakeFiles\StaticLinkList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StaticLinkList.dir/depend

