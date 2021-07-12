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

# CODE_ANALYSIS_INCLUDE list of directory paths for analysis
# CODE_ANALYSIS_EXCLUDE list of exclude regex from analysis

# CMAKE_EXPORT_COMPILE_COMMANDS environment variable should be "ON"
if(CMAKE_EXPORT_COMPILE_COMMANDS)
   find_program(clang-tidy NAMES clang-tidy REQUIRED)
   find_program(python3 NAMES python3 REQUIRED)
   find_program(run-clang-tidy NAMES run-clang-tidy run-clang-tidy.py REQUIRED)

   foreach(INCLUDE_PATH IN LISTS CODE_ANALYSIS_INCLUDE)
      file(
         GLOB_RECURSE
         INCLUDE_SOURCES
         ${INCLUDE_PATH}*.C
         ${INCLUDE_PATH}*.c
         ${INCLUDE_PATH}*.c++
         ${INCLUDE_PATH}*.cc
         ${INCLUDE_PATH}*.cpp
         ${INCLUDE_PATH}*.cxx
         ${INCLUDE_PATH}*.h
         ${INCLUDE_PATH}*.H
         ${INCLUDE_PATH}*.h++
         ${INCLUDE_PATH}*.hh
         ${INCLUDE_PATH}*.hpp
         ${INCLUDE_PATH}*.hxx
      )
      list(APPEND SOURCES ${INCLUDE_SOURCES})
   endforeach()

   foreach(EXCLUDE_REGEX IN LISTS CODE_ANALYSIS_EXCLUDE)
      list(FILTER SOURCES EXCLUDE REGEX "${EXCLUDE_REGEX}")
   endforeach()

   list(APPEND RUN_CLANG_TIDY_CLI "-clang-tidy-binary ${clang-tidy}")
   list(APPEND RUN_CLANG_TIDY_CLI "-j `nproc`")
   list(APPEND RUN_CLANG_TIDY_CLI "-p ${CMAKE_BINARY_DIR}")
   list(APPEND RUN_CLANG_TIDY_CLI "${SOURCES}")
   list(APPEND RUN_CLANG_TIDY_CLI ">")
   list(APPEND RUN_CLANG_TIDY_CLI
        "${CMAKE_CURRENT_BINARY_DIR}/code_analysis.txt"
   )

   list(JOIN RUN_CLANG_TIDY_CLI " " RUN_CLANG_TIDY_CLI)

   add_custom_target(
      code_analysis VERBATIM COMMAND bash -c
                                     "${run-clang-tidy} ${RUN_CLANG_TIDY_CLI}"
   )
endif()
