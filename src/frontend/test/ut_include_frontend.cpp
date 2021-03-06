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

#include <ore/sdk/exception/parse_error.h>
#include <ore/sdk/frontend.h>

TEST(ut_include, frontend)
{
   // Test that all essence are accessible via ore/sdk/frontend.h include

   ore::sdk::ast ast;
   EXPECT_THROW(ore::sdk::parse("", {}), ore::sdk::parse_error);

   EXPECT_TRUE(true); // Successfull build of this test, is it the validation
}
