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

#include <ore/sdk/compilation_exception_type.h>
#include <ore/sdk/exception.h>
#include <vector>

namespace ore::sdk {
   class compilation_exception : public exception {
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
      compilation_exception(const compilation_exception_type type,
                            const std::string&               what,
                            const cause_info&                cause);
      compilation_exception(const compilation_exception_type type,
                            std::string&&                    what,
                            const cause_info&                cause);
      compilation_exception(const compilation_exception_type type,
                            const std::string&               what,
                            cause_info&&                     cause);
      compilation_exception(const compilation_exception_type type,
                            std::string&&                    what,
                            cause_info&&                     cause);
      compilation_exception(const compilation_exception& object);
      compilation_exception(compilation_exception&& object) noexcept;

      compilation_exception& operator=(const compilation_exception& object);
      compilation_exception& operator=(compilation_exception&& object) noexcept;

      ore::sdk::compilation_exception_type compilation_exception_type() const;

      const cause_info& cause() const;

   private:
      ore::sdk::compilation_exception_type m_compilation_exception_type;
      cause_info                           m_cause_info;
   };
};
