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
#include <ore/sdk/compilation_exception.h>

using highlight  = ore::sdk::compilation_exception::highlight;
using cause_info = ore::sdk::compilation_exception::cause_info;

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
};

TEST(ut_compilation_exception, copy_initialization_constructor)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   ore::sdk::compilation_exception exception{ expected_type, expected_what, expected_cause };

   ASSERT_TRUE(expected_parrent_type == exception.exception_type());
   ASSERT_TRUE(expected_type == exception.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception.cause());
   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_compilation_exception, move_initialization_constructor_overload_1)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   auto what_for_move = expected_what;

   ore::sdk::compilation_exception exception{ expected_type, std::move(what_for_move), expected_cause };

   ASSERT_TRUE(expected_parrent_type == exception.exception_type());
   ASSERT_TRUE(expected_type == exception.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception.cause());
   ASSERT_TRUE(what_for_move.empty());
   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_compilation_exception, move_initialization_constructor_overload_2)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   auto cause_for_move = expected_cause;

   ore::sdk::compilation_exception exception{ expected_type,
                                              expected_what,
                                              std::move(cause_for_move) };

   ASSERT_TRUE(expected_parrent_type == exception.exception_type());
   ASSERT_TRUE(expected_type == exception.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception.cause());
   ASSERT_TRUE(cause_for_move.source.empty());
   ASSERT_TRUE(cause_for_move.file.empty());
   ASSERT_TRUE(cause_for_move.highlighting.empty());
   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_compilation_exception, move_initialization_constructor_overload_3)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   auto what_for_move  = expected_what;
   auto cause_for_move = expected_cause;

   ore::sdk::compilation_exception exception{ expected_type,
                                              std::move(what_for_move),
                                              std::move(cause_for_move) };

   ASSERT_TRUE(expected_parrent_type == exception.exception_type());
   ASSERT_TRUE(expected_type == exception.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception.cause());
   ASSERT_TRUE(what_for_move.empty());
   ASSERT_TRUE(cause_for_move.source.empty());
   ASSERT_TRUE(cause_for_move.file.empty());
   ASSERT_TRUE(cause_for_move.highlighting.empty());
   ASSERT_STREQ(expected_what.c_str(), exception.what());
}

TEST(ut_compilation_exception, copy_constructor)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   ore::sdk::compilation_exception exception_1{ expected_type, expected_what, expected_cause };
   ore::sdk::compilation_exception exception_2{ exception_1 };

   ASSERT_TRUE(expected_parrent_type == exception_1.exception_type());
   ASSERT_TRUE(exception_1.exception_type() == exception_2.exception_type());
   ASSERT_TRUE(expected_type == exception_1.compilation_exception_type());
   ASSERT_TRUE(exception_1.compilation_exception_type()
               == exception_2.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception_1.cause());
   ASSERT_TRUE(exception_1.cause() == exception_2.cause());
   ASSERT_STREQ(expected_what.c_str(), exception_1.what());
   ASSERT_TRUE(exception_1.what() == exception_2.what());
}

TEST(ut_compilation_exception, move_constructor)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   ore::sdk::compilation_exception exception_1{ expected_type, expected_what, expected_cause };
   ore::sdk::compilation_exception exception_2{ std::move(exception_1) };

   ASSERT_TRUE(std::string{ exception_1.what() }.empty());
   ASSERT_TRUE(exception_1.cause().source.empty());
   ASSERT_TRUE(exception_1.cause().file.empty());
   ASSERT_TRUE(exception_1.cause().highlighting.empty());
   ASSERT_TRUE(expected_parrent_type == exception_2.exception_type());
   ASSERT_TRUE(expected_type == exception_2.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception_2.cause());
   ASSERT_STREQ(expected_what.c_str(), exception_2.what());
}

TEST(ut_compilation_exception, copy_assignment_operator)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   ore::sdk::compilation_exception exception_1{ expected_type, expected_what, expected_cause };
   ore::sdk::compilation_exception exception_2{ ore::sdk::compilation_exception_type::parse,
                                                "",
                                                {} };

   exception_2 = exception_1;

   ASSERT_TRUE(expected_parrent_type == exception_1.exception_type());
   ASSERT_TRUE(exception_1.exception_type() == exception_2.exception_type());
   ASSERT_TRUE(expected_type == exception_1.compilation_exception_type());
   ASSERT_TRUE(exception_1.compilation_exception_type()
               == exception_2.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception_1.cause());
   ASSERT_TRUE(exception_1.cause() == exception_2.cause());
   ASSERT_STREQ(expected_what.c_str(), exception_1.what());
   ASSERT_TRUE(exception_1.what() == exception_2.what());
}

TEST(ut_compilation_exception, move_assignment_operator)
{
   const auto expected_type = ore::sdk::compilation_exception_type::compile;
   const auto expected_parrent_type = ore::sdk::exception_type::compilation;
   const auto expected_what         = std::string{ "xxx" };
   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   ore::sdk::compilation_exception exception_1{ expected_type, expected_what, expected_cause };
   ore::sdk::compilation_exception exception_2{ ore::sdk::compilation_exception_type::parse,
                                                "",
                                                {} };

   exception_2 = std::move(exception_1);

   ASSERT_TRUE(std::string{ exception_1.what() }.empty());
   ASSERT_TRUE(exception_1.cause().source.empty());
   ASSERT_TRUE(exception_1.cause().file.empty());
   ASSERT_TRUE(exception_1.cause().highlighting.empty());
   ASSERT_TRUE(expected_parrent_type == exception_2.exception_type());
   ASSERT_TRUE(expected_type == exception_2.compilation_exception_type());
   ASSERT_TRUE(expected_cause == exception_2.cause());
   ASSERT_STREQ(expected_what.c_str(), exception_2.what());
}

TEST(ut_exception, compilation_exception_type)
{
   class compilation_exception_public : public ore::sdk::exception {
   public:
      ore::sdk::compilation_exception_type m_compilation_exception_type;
      cause_info                           m_cause_info;
   };

   const auto expected_type = ore::sdk::compilation_exception_type::compile;

   ore::sdk::compilation_exception exception{ ore::sdk::compilation_exception_type::parse,
                                              "",
                                              {} };

   compilation_exception_public* exception_public_ptr =
      reinterpret_cast<compilation_exception_public*>(&exception);

   exception_public_ptr->m_compilation_exception_type = expected_type;

   ASSERT_TRUE(expected_type == exception.compilation_exception_type());
}

TEST(ut_exception, cause)
{
   class compilation_exception_public : public ore::sdk::exception {
   public:
      ore::sdk::compilation_exception_type m_compilation_exception_type;
      cause_info                           m_cause_info;
   };

   const auto expected_cause =
      cause_info{ .source       = "xxx",
                  .file         = "yyy",
                  .line         = 10,
                  .highlighting = { highlight{ 1, 2 }, highlight{ 3, 4 } } };

   ore::sdk::compilation_exception exception{ ore::sdk::compilation_exception_type::parse,
                                              "",
                                              {} };

   compilation_exception_public* exception_public_ptr =
      reinterpret_cast<compilation_exception_public*>(&exception);

   exception_public_ptr->m_cause_info = expected_cause;

   ASSERT_TRUE(expected_cause == exception.cause());
}
