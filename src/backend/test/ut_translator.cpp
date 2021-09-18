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

#include <ore/sdk/backend.h>
#include <ore/sdk/exception/translation_error.h>

TEST(ut_translator, translate_with_error)
{
   // Temporary representation of an invalid OPR object
   const ore::sdk::opr* invalid_object = nullptr;
   EXPECT_THROW(ore::sdk::translate(*invalid_object), ore::sdk::translation_error);
}

TEST(ut_translator, translate_with_success)
{
   EXPECT_NO_THROW({ ore::sdk::translate({}); });
}
