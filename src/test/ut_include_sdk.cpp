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

#include <ore/sdk.h>

TEST(ut_include, sdk)
{
   // Test that all essence are accessible via ore/sdk.h include

   ore::sdk::exception             exception{ "" };
   ore::sdk::compilation_error     compilation_error{ "" };
   ore::sdk::serialization_error   serialization_error{ "" };
   ore::sdk::deserialization_error deserialization_error{ "" };
   ore::sdk::parse_error           parse_error{ "" };
   ore::sdk::link_error            link_error{ "" };
   ore::sdk::translation_error     translation_error{ "" };

   ore::sdk::serialize<std::string>({});

   ore::sdk::ast ast;
   EXPECT_THROW(ore::sdk::parse("", {}), ore::sdk::parse_error);

   ore::sdk::opr opr;
   EXPECT_THROW(ore::sdk::compile({}), ore::sdk::compilation_error);
   EXPECT_THROW(ore::sdk::link({}), ore::sdk::link_error);

   // Temporary representation of an invalid OPR object
   const ore::sdk::opr* invalid_object = nullptr;
   EXPECT_THROW(ore::sdk::translate(*invalid_object), ore::sdk::translation_error);

   EXPECT_TRUE(true); // Successfull build of this test, is it the validation
}
