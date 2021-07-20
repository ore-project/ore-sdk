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

TEST(ut_sdk_include, basic)
{
   // Test that all essence are accessible via ore/sdk.h include

   ore::sdk::exception_type             exception_type;
   ore::sdk::exception                  exception{ exception_type, "" };
   ore::sdk::deserialization_exception  deserialization_exception{ "" };
   ore::sdk::serialization_exception    serialization_exception{ "" };
   ore::sdk::compilation_exception_type compilation_exception_type;
   ore::sdk::compilation_exception compilation_exception{ compilation_exception_type, "", {} };
   ore::sdk::serialize<std::string>({});

   EXPECT_TRUE(true); // Successfull build of this test, is it the validation
}
