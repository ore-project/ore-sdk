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
add_subdirectory(serializer)
add_subdirectory(frontend)
add_subdirectory(core)
add_subdirectory(backend)

set(TARGET ${CMAKE_PROJECT_NAME})

configure_file(version.cpp.in version.cpp NEWLINE_STYLE UNIX)

add_library(${TARGET} SHARED version.cpp)

target_include_directories(
   ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

set_target_properties(
   ${TARGET} PROPERTIES VERSION "${CMAKE_PROJECT_VERSION}"
                        SOVERSION "${CMAKE_PROJECT_VERSION_MAJOR}"
)

target_sources(
   ${TARGET}
   PRIVATE $<TARGET_OBJECTS:exception> $<TARGET_OBJECTS:serializer>
           $<TARGET_OBJECTS:frontend> $<TARGET_OBJECTS:core>
           $<TARGET_OBJECTS:backend>
)

install(
   TARGETS ${TARGET}
   EXPORT ${TARGET}
   LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
   INCLUDES
   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ore
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(CONFIGS_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})
set(PACKAGE_GENERAL_CONFIG_NAME ${CMAKE_PROJECT_NAME}Config.cmake)
set(PACKAGE_VERSION_CONFIG_NAME ${CMAKE_PROJECT_NAME}ConfigVersion.cmake)

configure_package_config_file(
   Config.cmake.in ${PACKAGE_GENERAL_CONFIG_NAME}
   INSTALL_DESTINATION ${CONFIGS_INSTALL_DIR}
)

write_basic_package_version_file(
   ${PACKAGE_VERSION_CONFIG_NAME} VERSION ${CMAKE_PROJECT_VERSION}
   COMPATIBILITY SameMajorVersion
)

install(FILES ${CMAKE_BINARY_DIR}/src/${PACKAGE_GENERAL_CONFIG_NAME}
              ${CMAKE_BINARY_DIR}/src/${PACKAGE_VERSION_CONFIG_NAME}
        DESTINATION ${CONFIGS_INSTALL_DIR}
)

install(
   EXPORT ${TARGET}
   FILE ${CMAKE_PROJECT_NAME}Targets.cmake
   DESTINATION ${CONFIGS_INSTALL_DIR}
   NAMESPACE ${GLOBAL_PROJECT_NAME}::
)

add_subdirectory(test)
