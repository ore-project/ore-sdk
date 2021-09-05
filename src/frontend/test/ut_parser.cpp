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

#include <ore/sdk/exception/parse_error.h>

TEST(ut_parser, empty_input)
{
   EXPECT_THROW(ore::sdk::parse("", {}), ore::sdk::parse_error);
}

TEST(ut_parser, parse_with_error)
{
   EXPECT_THROW(ore::sdk::parse("", { "error" }), ore::sdk::parse_error);
}

TEST(ut_parser, parse_with_success)
{
   EXPECT_NO_THROW({ ore::sdk::parse("", { "source" }); });
}
