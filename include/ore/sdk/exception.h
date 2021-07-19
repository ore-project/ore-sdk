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

#include <ore/sdk/exception_type.h>
#include <stdexcept>

namespace ore::sdk {
   class exception : public std::runtime_error {
   public:
      exception(const exception_type type, const std::string& what);
      exception(const exception_type type, std::string&& what);
      exception(const exception& object);
      exception(exception&& object) noexcept;

      exception& operator=(const exception& object);
      exception& operator=(exception&& object) noexcept;

      ore::sdk::exception_type exception_type() const;

   private:
      ore::sdk::exception_type m_exception_type;
   };
};
