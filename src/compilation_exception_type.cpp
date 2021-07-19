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

#include <ore/sdk/compilation_exception_type.h>

using namespace ore::sdk;

std::string ore::sdk::to_string(const compilation_exception_type object)
{
   switch( object ) {
      case compilation_exception_type::parse: return "parse";
      case compilation_exception_type::compile: return "compile";
      case compilation_exception_type::translate: return "translate";
   }

   return {}; // Disable build warning
}