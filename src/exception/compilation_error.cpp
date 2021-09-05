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

#include <ore/sdk/exception/compilation_error.h>

#include "helper.h"

using namespace ore::sdk;

compilation_error::compilation_error(const std::string& what_arg)
: exception{ what_arg }
{
   // do nothing
}

compilation_error::compilation_error(const char* what_arg)
: exception{ what_arg }
{
   // do nothing
}

compilation_error::compilation_error(const compilation_error& other) = default;

compilation_error& compilation_error::operator=(const compilation_error& other) noexcept
{
   parrent_assign_operator<exception>(this, other);
   m_cause_info = other.m_cause_info;

   return *this;
}

void compilation_error::set_cause_info(const cause_info& other)
{
   m_cause_info = other;
}

void compilation_error::set_cause_info(cause_info&& other)
{
   m_cause_info = std::move(other);
}

std::optional<compilation_error::cause_info> compilation_error::cause()
{
   return m_cause_info;
}
