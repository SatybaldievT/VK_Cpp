# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\VK_CPP\VK_Cpp\hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\VK_CPP\VK_Cpp\hw1\build

# Include any dependencies generated for this target.
include external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/compiler_depend.make

# Include the progress variables for this target.
include external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/flags.make

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/flags.make
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/includes_C.rsp
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: ../external/glfw-3.3.8/examples/offscreen.c
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\VK_CPP\VK_Cpp\hw1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj -MF CMakeFiles\offscreen.dir\offscreen.c.obj.d -o CMakeFiles\offscreen.dir\offscreen.c.obj -c D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\examples\offscreen.c

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\examples\offscreen.c > CMakeFiles\offscreen.dir\offscreen.c.i

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\examples\offscreen.c -o CMakeFiles\offscreen.dir\offscreen.c.s

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/glfw.rc.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/flags.make
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/glfw.rc.obj: ../external/glfw-3.3.8/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\VK_CPP\VK_Cpp\hw1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/glfw.rc.obj"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\examples\glfw.rc CMakeFiles\offscreen.dir\glfw.rc.obj

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/flags.make
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/includes_C.rsp
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: ../external/glfw-3.3.8/deps/glad_gl.c
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\VK_CPP\VK_Cpp\hw1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\offscreen.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\offscreen.dir\__\deps\glad_gl.c.obj -c D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\deps\glad_gl.c

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\deps\glad_gl.c > CMakeFiles\offscreen.dir\__\deps\glad_gl.c.i

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\deps\glad_gl.c -o CMakeFiles\offscreen.dir\__\deps\glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.obj" \
"CMakeFiles/offscreen.dir/glfw.rc.obj" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/offscreen.c.obj
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/glfw.rc.obj
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/build.make
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/src/libglfw3.a
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/linklibs.rsp
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/objects1.rsp
external/glfw-3.3.8/examples/offscreen.exe: external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\VK_CPP\VK_Cpp\hw1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable offscreen.exe"
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\offscreen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/build: external/glfw-3.3.8/examples/offscreen.exe
.PHONY : external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/build

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/clean:
	cd /d D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples && $(CMAKE_COMMAND) -P CMakeFiles\offscreen.dir\cmake_clean.cmake
.PHONY : external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/clean

external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\VK_CPP\VK_Cpp\hw1 D:\VK_CPP\VK_Cpp\hw1\external\glfw-3.3.8\examples D:\VK_CPP\VK_Cpp\hw1\build D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples D:\VK_CPP\VK_Cpp\hw1\build\external\glfw-3.3.8\examples\CMakeFiles\offscreen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.3.8/examples/CMakeFiles/offscreen.dir/depend

