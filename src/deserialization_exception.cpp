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

#include <ore/sdk/deserialization_exception.h>

using namespace ore::sdk;

deserialization_exception::deserialization_exception(const std::string& what)
: exception{ exception_type::deserialization, what }
{
}

deserialization_exception::deserialization_exception(std::string&& what)
: exception{ exception_type::deserialization, std::move(what) }
{
}

deserialization_exception::deserialization_exception(const deserialization_exception& object)
: exception{ *dynamic_cast<const exception*>(&object) }
{
}

deserialization_exception::deserialization_exception(deserialization_exception&& object) noexcept
: exception{ std::move(*dynamic_cast<exception*>(&object)) }
{
}

deserialization_exception&
   deserialization_exception::operator=(const deserialization_exception& object)
{
   exception::operator=(*dynamic_cast<const exception*>(&object));

   return *this;
}

deserialization_exception&
   deserialization_exception::operator=(deserialization_exception&& object) noexcept
{
   exception::operator=(std::move(*dynamic_cast<exception*>(&object)));

   return *this;
}
