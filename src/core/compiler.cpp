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

#include <ore/sdk/core/compiler.h>

#include <ore/sdk/exception/compilation_error.h>
#include <ore/sdk/exception/link_error.h>

using namespace ore::sdk;

opr ore::sdk::compile(const std::vector<ast>& trees)
{
   if( trees.empty() ) {
      throw compilation_error{ "Input is empty, no asts are found!" };
   }

   // Just for testing purposes
   if( trees.size() == 2 ) {
      static const auto make_compilation_error = []() {
         compilation_error error{ "Error in Ore sources!" };
         error.set_cause_info(compilation_error::cause_info{
            .source = "This is error.",
            .file   = "some/file",
            .line   = 117, // NOLINT (cppcoreguidelines-avoid-magic-numbers)
            // NOLINTNEXTLINE (cppcoreguidelines-avoid-magic-numbers)
            .highlighting = { compilation_error::highlight{ .index = 7, .length = 5 } } });

         return error;
      };

      throw make_compilation_error();
   }

   return opr{};
}

opr ore::sdk::link(const std::vector<opr>& objects)
{
   if( objects.empty() ) {
      throw link_error{ "Input is empty, no objects are found!" };
   }

   // Just for testing purposes
   if( objects.size() == 2 ) {
      throw link_error("Error in Ore objects!");
   }

   return opr{};
}
