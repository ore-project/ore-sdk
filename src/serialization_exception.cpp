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

#include <ore/sdk/serialization_exception.h>

using namespace ore::sdk;

serialization_exception::serialization_exception(const std::string& what)
: exception{ exception_type::serialization, what }
{
}

serialization_exception::serialization_exception(std::string&& what)
: exception{ exception_type::serialization, std::move(what) }
{
}

serialization_exception::serialization_exception(const serialization_exception& object)
: exception{ *dynamic_cast<const exception*>(&object) }
{
}

serialization_exception::serialization_exception(serialization_exception&& object) noexcept
: exception{ std::move(*dynamic_cast<exception*>(&object)) }
{
}

serialization_exception&
   serialization_exception::operator=(const serialization_exception& object)
{
   exception::operator=(*dynamic_cast<const exception*>(&object));

   return *this;
}

serialization_exception&
   serialization_exception::operator=(serialization_exception&& object) noexcept
{
   exception::operator=(std::move(*dynamic_cast<exception*>(&object)));

   return *this;
}
