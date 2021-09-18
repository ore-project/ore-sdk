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

#include <ore/sdk/core/opr.h>

using namespace ore::sdk;

std::istream& ore::sdk::operator>>(std::istream& istream, opr& /*object*/)
{
   char        c = 0;
   std::string s;

   // 10 because "opr-source"
   // NOLINTNEXTLINE (cppcoreguidelines-avoid-magic-numbers)
   for( unsigned int i = 0, size = 10; i < size; ++i ) {
      istream >> c;
      s += c;
   }

   if( s != "opr-source" ) {
      throw std::runtime_error{ "Wrong opr data!" };
   }

   return istream;
}

std::ostream& ore::sdk::operator<<(std::ostream& ostream, const opr& /*object*/)
{
   ostream << "opr-source";

   return ostream;
}
