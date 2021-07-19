################################################################################
# Copyright 2021 Kyrylo Rud
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

cmake_minimum_required(VERSION 3.20)

project(
   ore-sdk
   VERSION 0.1.0
   DESCRIPTION "The Ore SDK"
   HOMEPAGE_URL oreproject.org
   LANGUAGES CXX
)

# ##############################################################################
# Build Settings Configuration
# ##############################################################################

if(NOT CMAKE_BUILD_TYPE MATCHES "Debug|Release")
   set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
   option(BUILD_UNIT_TESTS "Build unit tests" ON)
endif()

# Generate the compile_commands.json file which is used by clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "Export compile commands")

# ##############################################################################
# Configure files for static code analysis
# ##############################################################################

list(APPEND CODE_ANALYSIS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/src/")
list(APPEND CODE_ANALYSIS_EXCLUDE "^.*/test/.*$")

# ##############################################################################
# Include CMake-submodules
# ##############################################################################

include(cmake/add_gtest_executable.cmake)
include(cmake/code_analysis.cmake)
include(cmake/code_format.cmake)

# ##############################################################################
# CXX Configuration
# ##############################################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# LD fail on undefined symbols
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

# Make all warnings into errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

# ##############################################################################

add_subdirectory(src)
