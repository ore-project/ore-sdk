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

TEST(ut_compiler, compiler_empty_input)
{
   EXPECT_THROW(ore::sdk::compile({}), ore::sdk::compilation_error);
}

TEST(ut_compiler, compile_with_error)
{
   EXPECT_THROW(ore::sdk::compile({ {}, {} }), ore::sdk::compilation_error);
}

TEST(ut_compiler, compile_with_success)
{
   EXPECT_NO_THROW({ ore::sdk::compile({ {} }); });
}

TEST(ut_compiler, link_empty_input)
{
   EXPECT_THROW(ore::sdk::link({}), ore::sdk::link_error);
}

TEST(ut_compiler, link_with_error)
{
   EXPECT_THROW(ore::sdk::link({ {}, {} }), ore::sdk::link_error);
}

TEST(ut_compiler, link_with_success)
{
   EXPECT_NO_THROW({ ore::sdk::link({ {} }); });
}
