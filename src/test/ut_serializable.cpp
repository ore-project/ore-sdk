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
#include <ore/sdk/serializable.h>

struct serializer : ore::sdk::serializable {
   virtual ~serializer() = default;

   virtual std::string serialize() const override;
   virtual void        deserialize(const std::string& source) override;
   virtual void        deserialize(std::string&& source) override;
};

std::string serializer::serialize() const
{
   return ore::sdk::serializable::serialize();
}

void serializer::deserialize(const std::string& source)
{
   ore::sdk::serializable::deserialize(source);
}

void serializer::deserialize(std::string&& source)
{
   ore::sdk::serializable::deserialize(std::move(source));
}

TEST(ut_serializable, serialize)
{
   serializer object;

   EXPECT_NO_THROW({ object.serialize(); });
   EXPECT_TRUE(object.serialize().empty());
}

TEST(ut_serializable, deserialize)
{
   serializer object;

   EXPECT_NO_THROW({ object.deserialize(""); });
}
