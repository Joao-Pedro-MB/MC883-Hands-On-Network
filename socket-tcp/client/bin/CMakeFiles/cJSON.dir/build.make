# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin

# Include any dependencies generated for this target.
include CMakeFiles/cJSON.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cJSON.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cJSON.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cJSON.dir/flags.make

CMakeFiles/cJSON.dir/lib/cJSON.c.o: CMakeFiles/cJSON.dir/flags.make
CMakeFiles/cJSON.dir/lib/cJSON.c.o: ../lib/cJSON.c
CMakeFiles/cJSON.dir/lib/cJSON.c.o: CMakeFiles/cJSON.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cJSON.dir/lib/cJSON.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cJSON.dir/lib/cJSON.c.o -MF CMakeFiles/cJSON.dir/lib/cJSON.c.o.d -o CMakeFiles/cJSON.dir/lib/cJSON.c.o -c /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/lib/cJSON.c

CMakeFiles/cJSON.dir/lib/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cJSON.dir/lib/cJSON.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/lib/cJSON.c > CMakeFiles/cJSON.dir/lib/cJSON.c.i

CMakeFiles/cJSON.dir/lib/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cJSON.dir/lib/cJSON.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/lib/cJSON.c -o CMakeFiles/cJSON.dir/lib/cJSON.c.s

# Object files for target cJSON
cJSON_OBJECTS = \
"CMakeFiles/cJSON.dir/lib/cJSON.c.o"

# External object files for target cJSON
cJSON_EXTERNAL_OBJECTS =

libcJSON.a: CMakeFiles/cJSON.dir/lib/cJSON.c.o
libcJSON.a: CMakeFiles/cJSON.dir/build.make
libcJSON.a: CMakeFiles/cJSON.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libcJSON.a"
	$(CMAKE_COMMAND) -P CMakeFiles/cJSON.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cJSON.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cJSON.dir/build: libcJSON.a
.PHONY : CMakeFiles/cJSON.dir/build

CMakeFiles/cJSON.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cJSON.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cJSON.dir/clean

CMakeFiles/cJSON.dir/depend:
	cd /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin /home/pedrodearaujo/Documentos/Unicamp/MC833/MC833-Hands-On-Network/client/bin/CMakeFiles/cJSON.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cJSON.dir/depend

