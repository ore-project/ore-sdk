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

#include <ore/sdk/frontend/parser.h>

#include <ore/sdk/exception/parse_error.h>

using namespace ore::sdk;

ast ore::sdk::parse(const std::string& file_name, const source_file& source)
{
   if( source.empty() ) {
      throw parse_error{ "Input source is empty!" };
   }

   // Just for testing purposes
   if( source.front() == "error" ) {
      static const auto make_parse_error = [&file_name]() {
         parse_error error{ "Error in Ore sources!" };
         error.set_cause_info(compilation_error::cause_info{
            .source = "This is error.",
            .file   = file_name,
            .line   = 117, // NOLINT (cppcoreguidelines-avoid-magic-numbers)
            // NOLINTNEXTLINE (cppcoreguidelines-avoid-magic-numbers)
            .highlighting = { compilation_error::highlight{ .index = 7, .length = 5 } } });

         return error;
      };

      throw make_parse_error();
   }

   return ast{};
}
