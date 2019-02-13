cmake_minimum_required(VERSION 2.8)

# Package name (will be called "${PCK}.pck" by default)
set(PCK PointCloud)
project("${PCK}.u")

# Set the RTMaps SDK directory
if (NOT DEFINED RTMAPS_SDKDIR)
    if (DEFINED ENV{RTMAPS_SDKDIR})
        # Use the default RTMaps installation
        set(RTMAPS_SDKDIR "$ENV{RTMAPS_SDKDIR}" CACHE PATH "")
    else()
        message(FATAL_ERROR "RTMAPS_SDKDIR not defined. Either pass -D RTMAPS_SDKDIR=... to CMake or define a RTMAPS_SDKDIR environment variable")
    endif()
endif()

# Include the RTMaps CMake configuration file
include("${RTMAPS_SDKDIR}/templates.u/rtmaps.cmake")

# Create the pck target
# NB: dir(pckInfoFile)/local_interfaces, dir(pckInfoFile)/protected_interfaces and dir(pckInfoFile)/public_interfaces
#     will be automatically added to the list of include directories
add_rtmaps_package("${PCK}" PCKINFO "./${PCK}.pckinfo"
    # add sources, headers and/or directories
    "./local_interfaces"
    "./src"
)


