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

#include <gtest/gtest.h>

#include <ore/sdk/exception.h>

TEST(ut_include, exception)
{
   // Test that all essence are accessible via ore/sdk/exception.h include

   ore::sdk::exception             exception{ "" };
   ore::sdk::compilation_error     compilation_error{ "" };
   ore::sdk::serialization_error   serialization_error{ "" };
   ore::sdk::deserialization_error deserialization_error{ "" };
   ore::sdk::parse_error           parse_error{ "" };
   ore::sdk::link_error            link_error{ "" };
   ore::sdk::translation_error     translation_error{ "" };

   EXPECT_TRUE(true); // Successfull build of this test, is its the validation
}
