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

#include <ore/sdk/compilation_exception.h>

using namespace ore::sdk;

compilation_exception::compilation_exception(const ore::sdk::compilation_exception_type type,
                                             const std::string& what,
                                             const cause_info& cause) // NOLINT(modernize-pass-by-value)
: exception{ exception_type::compilation, what }
, m_compilation_exception_type{ type }
, m_cause_info{ cause }
{
}

compilation_exception::compilation_exception(const ore::sdk::compilation_exception_type type,
                                             std::string&& what,
                                             const cause_info& cause) // NOLINT(modernize-pass-by-value)
: exception{ exception_type::compilation, std::move(what) }
, m_compilation_exception_type{ type }
, m_cause_info{ cause }
{
}

compilation_exception::compilation_exception(const ore::sdk::compilation_exception_type type,
                                             const std::string& what,
                                             cause_info&&       cause)
: exception{ exception_type::compilation, what }
, m_compilation_exception_type{ type }
, m_cause_info{ std::move(cause) }
{
}

compilation_exception::compilation_exception(const ore::sdk::compilation_exception_type type,
                                             std::string&& what,
                                             cause_info&&  cause)
: exception{ exception_type::compilation, std::move(what) }
, m_compilation_exception_type{ type }
, m_cause_info{ std::move(cause) }
{
}

compilation_exception::compilation_exception(const compilation_exception& object)
: exception{ *dynamic_cast<const exception*>(&object) }
, m_compilation_exception_type{ object.m_compilation_exception_type }
, m_cause_info{ object.m_cause_info }
{
}

compilation_exception::compilation_exception(compilation_exception&& object) noexcept
: exception{ std::move(*dynamic_cast<exception*>(&object)) }
, m_compilation_exception_type{ object.m_compilation_exception_type }
, m_cause_info{ std::move(object.m_cause_info) }
{
}

compilation_exception& compilation_exception::operator=(const compilation_exception& object)
{
   m_compilation_exception_type = object.m_compilation_exception_type;
   m_cause_info                 = object.m_cause_info;

   exception::operator=(*dynamic_cast<const exception*>(&object));

   return *this;
}

compilation_exception& compilation_exception::operator=(compilation_exception&& object) noexcept
{
   m_compilation_exception_type = object.m_compilation_exception_type;
   m_cause_info                 = std::move(object.m_cause_info);

   exception::operator=(std::move(*dynamic_cast<exception*>(&object)));

   return *this;
}

ore::sdk::compilation_exception_type compilation_exception::compilation_exception_type() const
{
   return m_compilation_exception_type;
}

const ore::sdk::compilation_exception::cause_info& compilation_exception::cause() const
{
   return m_cause_info;
}
