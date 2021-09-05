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
#include <ore/sdk/exception/exception.h>

TEST(ut_exception, string_initialization_constructor)
{
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception{ expected_what };

   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_exception, cstring_initialization_constructor)
{
   const auto expected_what = "xxx";

   ore::sdk::exception exception{ expected_what };

   ASSERT_STREQ(expected_what, exception.what());
}

TEST(ut_exception, copy_constructor)
{
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception_1{ expected_what };
   ore::sdk::exception exception_2{ exception_1 };

   ASSERT_STREQ(exception_1.what(), exception_2.what());
}

TEST(ut_exception, assignment_operator)
{
   const auto expected_what     = std::string{ "xxx" };
   const auto not_expected_what = std::string{ "yyy" };

   ore::sdk::exception exception_1{ expected_what };
   ore::sdk::exception exception_2{ not_expected_what };

   exception_2 = exception_1;

   ASSERT_STREQ(exception_1.what(), exception_2.what());
}
