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

find_program(cmake-format NAMES cmake-format REQUIRED)

set(CMAKE_FILE_REGEX ".*(CMakeLists\\.txt|\\.cmake)$")
set(CMAKE_FIND_INC "-regex '${CMAKE_FILE_REGEX}'")
set(CMAKE_FIND_EXC "-not -path '${CMAKE_BINARY_DIR}/*'")
set(CMAKE_FIND_CLI
    "find ${CMAKE_SOURCE_DIR} ${CMAKE_FIND_INC} ${CMAKE_FIND_EXC}"
)
string(REPLACE "|" "\\|" CMAKE_FIND_CLI ${CMAKE_FIND_CLI})
string(REPLACE "(" "\\(" CMAKE_FIND_CLI ${CMAKE_FIND_CLI})
string(REPLACE ")" "\\)" CMAKE_FIND_CLI ${CMAKE_FIND_CLI})

add_custom_target(
   cmake_format
   VERBATIM
   COMMAND bash -c "${CMAKE_FIND_CLI} | xargs -n 1 ${cmake-format} -i"
)
