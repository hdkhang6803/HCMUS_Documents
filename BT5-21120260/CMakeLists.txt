# Bitmap Demo 
# Copyright (c) 2021, Nguyen Minh Huy, nmhuy@fit.hcmus.edu.vn
# 
# This software is provided 'as-is', without any implied warranty.
# The authors will not be held liable for any damages arising from
# the use of this software.
# 
# Permission is granted to anyone to use, alter, and redistribute
# this software freely, subject to the following restrictions:
# 
# 1. The origin of this software must not be misrepresented;
#    you must not claim that you wrote the original software.
# 2. This notice may not be removed or altered from any source distribution.
# 
# *********************************************
# Use this file only when building by CMake.
# This file contains CMake build configuration.
# *********************************************

cmake_minimum_required (VERSION 3.0.0)
 
project (BmpDemo)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../${CMAKE_BUILD_TYPE})

FILE(GLOB_RECURSE SOURCE *.cpp)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER})

# Use this to link to X11 library when compiling on Linux
#target_link_libraries(${PROJECT_NAME} PUBLIC X11)

# Use this to link to SDL2 library
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2)
