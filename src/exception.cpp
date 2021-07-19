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

#include <ore/sdk/exception.h>

using namespace ore::sdk;

exception::exception(const ore::sdk::exception_type type, const std::string& what)
: std::runtime_error{ what }
, m_exception_type{ type }
{
}

exception::exception(const ore::sdk::exception_type type, std::string&& what)
: std::runtime_error{ what }
, m_exception_type{ type }
{
   if( what.empty() == false ) {
      what.clear(); // Clear, because values is not moved by std::runtime_error
   }
}

exception::exception(const exception& object)
: std::runtime_error{ *dynamic_cast<const std::runtime_error*>(&object) }
, m_exception_type{ object.m_exception_type }
{
}

exception::exception(exception&& object) noexcept
: std::runtime_error{ std::move(*dynamic_cast<std::runtime_error*>(&object)) }
, m_exception_type{ object.m_exception_type }
{
}

exception& exception::operator=(const exception& object)
{
   m_exception_type = object.m_exception_type;

   std::runtime_error::operator=(*dynamic_cast<const std::runtime_error*>(&object));

   return *this;
}

exception& exception::operator=(exception&& object) noexcept
{
   m_exception_type = object.m_exception_type;

   std::runtime_error::operator=(std::move(*dynamic_cast<std::runtime_error*>(&object)));

   return *this;
}

ore::sdk::exception_type exception::exception_type() const
{
   return m_exception_type;
}
