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

#include <ore/sdk/core.h>
#include <ore/sdk/exception/compilation_error.h>
#include <ore/sdk/exception/link_error.h>

TEST(ut_include, core)
{
   // Test that all essence are accessible via ore/sdk/core.h include

   ore::sdk::opr opr;
   EXPECT_THROW(ore::sdk::compile({}), ore::sdk::compilation_error);
   EXPECT_THROW(ore::sdk::link({}), ore::sdk::link_error);

   EXPECT_TRUE(true); // Successfull build of this test, is it the validation
}
