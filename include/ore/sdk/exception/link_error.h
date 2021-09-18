/*******************************************************************************
 * Copyright 2021 Kyrylo Rud
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include <ore/sdk/exception/exception.h>

namespace ore::sdk {

class link_error : public ore::sdk::exception {
public:
   explicit link_error(const std::string& what_arg);
   explicit link_error(const char* what_arg);
   link_error(const link_error& other) noexcept;

   link_error& operator=(const link_error& other) noexcept;
};

}
