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

#pragma once

#include <optional>
#include <ore/sdk/exception/exception.h>
#include <vector>

namespace ore::sdk {

class compilation_error : public ore::sdk::exception {
public:
   struct highlight {
      unsigned int index;
      unsigned int length;
   };

   struct cause_info {
      std::string            source;
      std::string            file;
      unsigned int           line;
      std::vector<highlight> highlighting;
   };

public:
   explicit compilation_error(const std::string& what_arg);
   explicit compilation_error(const char* what_arg);
   compilation_error(const compilation_error& other);

   compilation_error& operator=(const compilation_error& other) noexcept;

   void set_cause_info(const cause_info& other);
   void set_cause_info(cause_info&& other);

   std::optional<cause_info> cause();

private:
   std::optional<cause_info> m_cause_info;
};

}
