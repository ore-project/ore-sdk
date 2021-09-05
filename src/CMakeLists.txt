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

add_subdirectory(exception)

set(TARGET ${CMAKE_PROJECT_NAME})

configure_file(info.cpp.in info.cpp NEWLINE_STYLE UNIX)

add_library(${TARGET} SHARED info.cpp serializer.cpp)

target_include_directories(
   ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

set_target_properties(
   ${TARGET} PROPERTIES VERSION "${CMAKE_PROJECT_VERSION}"
                        SOVERSION "${CMAKE_PROJECT_VERSION_MAJOR}"
)

target_sources(${TARGET} PRIVATE $<TARGET_OBJECTS:exception>)

add_subdirectory(test)
