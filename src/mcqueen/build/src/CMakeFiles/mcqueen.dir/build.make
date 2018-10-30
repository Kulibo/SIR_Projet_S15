# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mcqueen.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mcqueen.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mcqueen.dir/flags.make

src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o: src/CMakeFiles/mcqueen.dir/flags.make
src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o: ../src/mcqueen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o"
	cd /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcqueen.dir/mcqueen.cpp.o -c /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/src/mcqueen.cpp

src/CMakeFiles/mcqueen.dir/mcqueen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcqueen.dir/mcqueen.cpp.i"
	cd /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/src/mcqueen.cpp > CMakeFiles/mcqueen.dir/mcqueen.cpp.i

src/CMakeFiles/mcqueen.dir/mcqueen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcqueen.dir/mcqueen.cpp.s"
	cd /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/src/mcqueen.cpp -o CMakeFiles/mcqueen.dir/mcqueen.cpp.s

src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.requires:

.PHONY : src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.requires

src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.provides: src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/mcqueen.dir/build.make src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.provides.build
.PHONY : src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.provides

src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.provides.build: src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o


# Object files for target mcqueen
mcqueen_OBJECTS = \
"CMakeFiles/mcqueen.dir/mcqueen.cpp.o"

# External object files for target mcqueen
mcqueen_EXTERNAL_OBJECTS =

src/libmcqueen.so: src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o
src/libmcqueen.so: src/CMakeFiles/mcqueen.dir/build.make
src/libmcqueen.so: src/CMakeFiles/mcqueen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmcqueen.so"
	cd /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mcqueen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mcqueen.dir/build: src/libmcqueen.so

.PHONY : src/CMakeFiles/mcqueen.dir/build

src/CMakeFiles/mcqueen.dir/requires: src/CMakeFiles/mcqueen.dir/mcqueen.cpp.o.requires

.PHONY : src/CMakeFiles/mcqueen.dir/requires

src/CMakeFiles/mcqueen.dir/clean:
	cd /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mcqueen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mcqueen.dir/clean

src/CMakeFiles/mcqueen.dir/depend:
	cd /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/src /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src /usr/users/promo2018/prenleloup_tho/SIR_Projet_S15/src/mcqueen/build/src/CMakeFiles/mcqueen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mcqueen.dir/depend

