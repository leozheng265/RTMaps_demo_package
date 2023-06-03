cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 17)

project("demo_package.u")

# TODO: modify the path to RTMaps folder
set(RTMAPS_SDKDIR "D:\\RTMaps 4" CACHE PATH "")


if (NOT DEFINED RTMAPS_SDKDIR)
    if (DEFINED ENV{RTMAPS_SDKDIR})
        set(RTMAPS_SDKDIR "$ENV{RTMAPS_SDKDIR}" CACHE PATH "")
    else()
        message(FATAL_ERROR "RTMAPS_SDKDIR not defined")
    endif()
endif()

include_directories(${EIGEN_DIR})
include("${RTMAPS_SDKDIR}/templates.u/rtmaps.cmake")

add_rtmaps_package(
        demo_package                   # Package name
        PCKINFO "demo_package.pckinfo"         # Package info file
        "src"                         # Directory containing the source files
)