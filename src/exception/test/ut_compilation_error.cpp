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

#include <ore/sdk/exception/compilation_error.h>

using highlight  = ore::sdk::compilation_error::highlight;
using cause_info = ore::sdk::compilation_error::cause_info;

namespace ore::sdk {

bool operator==(const highlight& first, const highlight& second)
{
   return { first.index == second.index && first.length == second.length };
}

bool operator==(const cause_info& first, const cause_info& second)
{
   return { first.source == second.source && first.file == second.file
            && first.line == second.line && first.highlighting == second.highlighting };
}

}

TEST(ut_compilation_error, string_initialization_constructor)
{
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::compilation_error exception{ expected_what };

   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_compilation_error, cstring_initialization_constructor)
{
   const auto expected_what = "xxx";

   ore::sdk::compilation_error exception{ expected_what };

   ASSERT_STREQ(expected_what, exception.what());
}

TEST(ut_compilation_error, copy_constructor)
{
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::compilation_error exception_1{ expected_what };
   ore::sdk::compilation_error exception_2{ exception_1 };

   ASSERT_STREQ(exception_1.what(), exception_2.what());
}

TEST(ut_compilation_error, assignment_operator)
{
   const auto expected_what     = std::string{ "xxx" };
   const auto not_expected_what = std::string{ "yyy" };

   ore::sdk::compilation_error exception_1{ expected_what };
   ore::sdk::compilation_error exception_2{ not_expected_what };

   exception_2 = exception_1;

   ASSERT_STREQ(exception_1.what(), exception_2.what());
}

TEST(ut_compilation_error, set_and_get_cause)
{
   const auto expected_cause_info =
      cause_info{ .source       = "source",
                  .file         = "file",
                  .line         = 1,
                  .highlighting = { highlight{ .index = 2, .length = 3 } } };

   ore::sdk::compilation_error exception{ "what" };

   ASSERT_FALSE(exception.cause().has_value());

   exception.set_cause_info(expected_cause_info);

   ASSERT_TRUE(exception.cause().has_value());
   ASSERT_TRUE(expected_cause_info == exception.cause().value());
}

TEST(ut_compilation_error, move_and_get_cause)
{
   const auto expected_cause_info =
      cause_info{ .source       = "source",
                  .file         = "file",
                  .line         = 1,
                  .highlighting = { highlight{ .index = 2, .length = 3 } } };

   auto moved_cause_info = expected_cause_info;

   ore::sdk::compilation_error exception{ "what" };

   ASSERT_FALSE(exception.cause().has_value());

   exception.set_cause_info(std::move(moved_cause_info));

   ASSERT_TRUE(exception.cause().has_value());
   ASSERT_TRUE(expected_cause_info == exception.cause().value());
   ASSERT_TRUE(moved_cause_info.source.empty());
   ASSERT_TRUE(moved_cause_info.file.empty());
   ASSERT_TRUE(moved_cause_info.highlighting.empty());
}
