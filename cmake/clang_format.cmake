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

find_program(clang-format NAMES clang-format REQUIRED)

set(CXX_FILE_EXTENSIONS "C|c|c++|cc|cpp|cxx|h|H|h++|hh|hpp|hxx")
set(CXX_FILE_REGEX ".*\\.(${CXX_FILE_EXTENSIONS})$")
set(CXX_FIND_INC "-regex '${CXX_FILE_REGEX}'")
set(CXX_FIND_EXC "-not -path '${CMAKE_BINARY_DIR}/*'")
set(CXX_FIND_CLI "find ${CMAKE_SOURCE_DIR} ${CXX_FIND_INC} ${CXX_FIND_EXC}")
string(REPLACE "|" "\\|" CXX_FIND_CLI ${CXX_FIND_CLI})
string(REPLACE "(" "\\(" CXX_FIND_CLI ${CXX_FIND_CLI})
string(REPLACE ")" "\\)" CXX_FIND_CLI ${CXX_FIND_CLI})

add_custom_target(clang_format VERBATIM
    COMMAND bash -c "${CXX_FIND_CLI} | xargs -n 1 ${clang-format} -i"
)
