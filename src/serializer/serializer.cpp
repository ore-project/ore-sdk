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

#include <ore/sdk/serializer.h>

using namespace ore::sdk;

std::vector<std::byte> ore::sdk::serialize(const std::string& source)
{
   const auto bytes_count = source.length();

   auto bytes = std::vector<std::byte>{ bytes_count };

   for( size_t index = 0; index < bytes_count; ++index ) {
      bytes[index] = static_cast<std::byte>(source[index]);
   }

   return bytes;
}

std::string ore::sdk::deserialize(const std::vector<std::byte>& bytes)
{
   const auto bytes_count = bytes.size();

   auto source = std::string(bytes_count, '0');

   for( size_t index = 0; index < bytes_count; ++index ) {
      source[index] = static_cast<char>(bytes[index]);
   }

   return source;
}
