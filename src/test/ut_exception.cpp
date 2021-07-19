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

TEST(ut_exception, copy_initialization_constructor)
{
   const auto expected_type = ore::sdk::exception_type::deserialization;
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception{ expected_type, expected_what };

   ASSERT_TRUE(expected_type == exception.exception_type());
   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_exception, move_initialization_constructor)
{
   const auto expected_type = ore::sdk::exception_type::deserialization;
   const auto expected_what = std::string{ "xxx" };

   auto what_for_move = expected_what;

   ore::sdk::exception exception{ expected_type, std::move(what_for_move) };

   ASSERT_TRUE(expected_type == exception.exception_type());
   ASSERT_TRUE(what_for_move.empty());
   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_exception, copy_constructor)
{
   const auto expected_type = ore::sdk::exception_type::deserialization;
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception_1{ expected_type, expected_what };
   ore::sdk::exception exception_2{ exception_1 };

   ASSERT_TRUE(expected_type == exception_1.exception_type());
   ASSERT_TRUE(exception_1.exception_type() == exception_2.exception_type());
   ASSERT_STREQ(expected_what.c_str(), exception_1.what());
   ASSERT_STREQ(exception_1.what(), exception_2.what());
}

TEST(ut_exception, move_constructor)
{
   const auto expected_type = ore::sdk::exception_type::deserialization;
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception_1{ expected_type, expected_what };
   ore::sdk::exception exception_2{ std::move(exception_1) };

   ASSERT_TRUE(expected_type == exception_1.exception_type());
   ASSERT_TRUE(exception_1.exception_type() == exception_2.exception_type());
   ASSERT_TRUE(std::string{ exception_1.what() }.empty());
   ASSERT_STREQ(expected_what.c_str(), exception_2.what());
}

TEST(ut_exception, copy_assignment_operator)
{
   const auto expected_type = ore::sdk::exception_type::deserialization;
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception_1{ expected_type, expected_what };
   ore::sdk::exception exception_2{ ore::sdk::exception_type::compilation, "" };

   exception_2 = exception_1;

   ASSERT_TRUE(expected_type == exception_1.exception_type());
   ASSERT_TRUE(exception_1.exception_type() == exception_2.exception_type());
   ASSERT_STREQ(expected_what.c_str(), exception_1.what());
   ASSERT_STREQ(exception_1.what(), exception_2.what());
}

TEST(ut_exception, move_assignment_operator)
{
   const auto expected_type = ore::sdk::exception_type::deserialization;
   const auto expected_what = std::string{ "xxx" };

   ore::sdk::exception exception_1{ expected_type, expected_what };
   ore::sdk::exception exception_2{ ore::sdk::exception_type::compilation, "" };

   exception_2 = std::move(exception_1);

   ASSERT_TRUE(expected_type == exception_1.exception_type());
   ASSERT_TRUE(exception_1.exception_type() == exception_2.exception_type());
   ASSERT_TRUE(std::string{ exception_1.what() }.empty());
   ASSERT_STREQ(expected_what.c_str(), exception_2.what());
}

TEST(ut_exception, exception_type)
{
   class exception_public : public std::runtime_error {
   public:
      ore::sdk::exception_type m_exception_type;
   };

   const auto expected_type = ore::sdk::exception_type::deserialization;

   ore::sdk::exception exception{ ore::sdk::exception_type::compilation, "" };

   exception_public* exception_public_ptr = reinterpret_cast<exception_public*>(&exception);

   exception_public_ptr->m_exception_type = expected_type;

   ASSERT_TRUE(expected_type == exception.exception_type());
}
