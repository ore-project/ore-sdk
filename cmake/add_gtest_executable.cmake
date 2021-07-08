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

if(BUILD_UNIT_TESTS)
   enable_testing()
   find_package(GTest REQUIRED)
endif()

macro(add_gtest_executable TARGET SOURCE LIB)
   if(BUILD_UNIT_TESTS)
      add_executable(${TARGET} ${SOURCE})
      target_link_libraries(${TARGET} ${LIB} gtest gtest_main)
      add_test(NAME ${TARGET} COMMAND ${TARGET})
      include(GoogleTest)
      gtest_discover_tests(${TARGET})
   endif()
endmacro()
