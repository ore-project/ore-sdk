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

# cmake-format: off
add_gtest_executable(ut_compilation_error ut_compilation_error.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_deserialization_error ut_deserialization_error.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_exception ut_exception.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_include_exception ut_include_exception.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_link_error ut_link_error.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_parse_error ut_parse_error.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_serialization_error ut_serialization_error.cpp ${CMAKE_PROJECT_NAME})
add_gtest_executable(ut_translation_error ut_translation_error.cpp ${CMAKE_PROJECT_NAME})
# cmake-format: on
