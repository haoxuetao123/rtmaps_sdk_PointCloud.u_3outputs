# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build

# Include any dependencies generated for this target.
include CMakeFiles/PointCloud.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PointCloud.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PointCloud.dir/flags.make

CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o: CMakeFiles/PointCloud.dir/flags.make
CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o: ../src/maps_PcTrans_noGRB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o -c /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/src/maps_PcTrans_noGRB.cpp

CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/src/maps_PcTrans_noGRB.cpp > CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.i

CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/src/maps_PcTrans_noGRB.cpp -o CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.s

CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.requires:

.PHONY : CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.requires

CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.provides: CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.requires
	$(MAKE) -f CMakeFiles/PointCloud.dir/build.make CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.provides.build
.PHONY : CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.provides

CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.provides.build: CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o


CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o: CMakeFiles/PointCloud.dir/flags.make
CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o: ../src/maps_naiveMerge_noRGB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o -c /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/src/maps_naiveMerge_noRGB.cpp

CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/src/maps_naiveMerge_noRGB.cpp > CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.i

CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/src/maps_naiveMerge_noRGB.cpp -o CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.s

CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.requires:

.PHONY : CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.requires

CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.provides: CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.requires
	$(MAKE) -f CMakeFiles/PointCloud.dir/build.make CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.provides.build
.PHONY : CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.provides

CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.provides.build: CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o


# Object files for target PointCloud
PointCloud_OBJECTS = \
"CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o" \
"CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o"

# External object files for target PointCloud
PointCloud_EXTERNAL_OBJECTS =

PointCloud.pck: CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o
PointCloud.pck: CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o
PointCloud.pck: CMakeFiles/PointCloud.dir/build.make
PointCloud.pck: /opt/rtmaps/sdk/ubuntu1604_x86_64/lib/librtmaps_pck.a
PointCloud.pck: CMakeFiles/PointCloud.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library PointCloud.pck"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PointCloud.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Signing RTMaps Package [PointCloud]"
	/opt/rtmaps/bin/rtmaps_package_sign -package /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build/PointCloud.pck -info /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/PointCloud.pckinfo -os ubuntu1604 -arch x86_64
	/usr/bin/cmake -E echo -----------------
	/usr/bin/cmake -E echo "                 "
	/usr/bin/cmake -E echo "PACKAGE FILE PATH /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build/PointCloud.pck"
	/usr/bin/cmake -E echo "                 "
	/usr/bin/cmake -E echo -----------------

# Rule to build all files generated by this target.
CMakeFiles/PointCloud.dir/build: PointCloud.pck

.PHONY : CMakeFiles/PointCloud.dir/build

CMakeFiles/PointCloud.dir/requires: CMakeFiles/PointCloud.dir/src/maps_PcTrans_noGRB.cpp.o.requires
CMakeFiles/PointCloud.dir/requires: CMakeFiles/PointCloud.dir/src/maps_naiveMerge_noRGB.cpp.o.requires

.PHONY : CMakeFiles/PointCloud.dir/requires

CMakeFiles/PointCloud.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PointCloud.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PointCloud.dir/clean

CMakeFiles/PointCloud.dir/depend:
	cd /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build /home/saiclei/rtmaps_sdk_xuetao/rtmaps/rtmaps_sdk/PointCloud.u/build/CMakeFiles/PointCloud.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PointCloud.dir/depend
