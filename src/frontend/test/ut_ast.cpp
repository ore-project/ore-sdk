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

#include <ore/sdk/frontend.h>
#include <ore/sdk/serializer.h>

TEST(ut_ast, serialize)
{
   ore::sdk::ast tree;

   std::vector<std::byte> actual_data;

   EXPECT_NO_THROW({ actual_data = ore::sdk::serialize(tree); });

   const auto actual_string = ore::sdk::deserialize(actual_data);

   ASSERT_STREQ(actual_string.c_str(), "ast-source");
}

TEST(ut_ast, deserialize)
{
   const auto input_data = ore::sdk::serialize("ast-source");

   EXPECT_NO_THROW({ ore::sdk::deserialize<ore::sdk::ast>(input_data); });
}
