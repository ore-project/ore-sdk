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

#include <ore/sdk/exception/exception.h>

#include "helper.h"

using namespace ore::sdk;

exception::exception(const std::string& what_arg)
: std::runtime_error{ what_arg }
{
   // do nothing
}

exception::exception(const char* what_arg)
: std::runtime_error{ what_arg }
{
   // do nothing
}

exception::exception(const exception& other) noexcept = default;

exception& exception::operator=(const exception& other) noexcept
{
   parrent_assign_operator<std::runtime_error>(this, other);

   return *this;
}
