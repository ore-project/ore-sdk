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

#include <ore/sdk/serializer.h>

class Object {
public:
   Object() = default;
   Object(int data)
   : m_data{ data }
   {
   }

   bool operator==(const Object& other) const
   {
      return m_data == other.m_data;
   }

   friend std::istream& operator>>(std::istream& istream, Object& object);
   friend std::ostream& operator<<(std::ostream& ostream, const Object& object);

private:
   int m_data;
};

std::istream& operator>>(std::istream& istream, Object& object)
{
   istream >> object.m_data;
   return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Object& object)
{
   ostream << object.m_data;
   return ostream;
}

class SerializationErrorObject {
public:
   friend std::ostream& operator<<(std::ostream&, const SerializationErrorObject&);
};

std::ostream& operator<<(std::ostream&, const SerializationErrorObject&)
{
   throw std::exception();
}

class DeserializationErrorObject {
public:
   friend std::istream& operator>>(std::istream&, DeserializationErrorObject&);
};

std::istream& operator>>(std::istream&, DeserializationErrorObject&)
{
   throw std::exception();
}

TEST(ut_serializer, serialize)
{
   const auto input_data    = "data";
   const auto expected_data = std::vector<std::byte>{ static_cast<std::byte>('d'),
                                                      static_cast<std::byte>('a'),
                                                      static_cast<std::byte>('t'),
                                                      static_cast<std::byte>('a') };

   std::vector<std::byte> serialized_data;

   EXPECT_NO_THROW({ serialized_data = ore::sdk::serialize(input_data); });
   EXPECT_EQ(serialized_data, expected_data);
}

TEST(ut_serializer, serialize_object)
{
   const auto input_data    = Object{ 117 };
   const auto expected_data = std::vector<std::byte>{ static_cast<std::byte>('1'),
                                                      static_cast<std::byte>('1'),
                                                      static_cast<std::byte>('7') };

   std::vector<std::byte> serialized_data;

   EXPECT_NO_THROW({ serialized_data = ore::sdk::serialize(input_data); });
   EXPECT_EQ(serialized_data, expected_data);
}

TEST(ut_serializer, serialize_error)
{
   SerializationErrorObject test_object;

   EXPECT_THROW(ore::sdk::serialize(test_object), ore::sdk::serialization_error);
}

TEST(ut_serializer, deserialize)
{
   const auto input_data = std::vector<std::byte>{ static_cast<std::byte>('d'),
                                                   static_cast<std::byte>('a'),
                                                   static_cast<std::byte>('t'),
                                                   static_cast<std::byte>('a') };
   const auto expected_data = "data";

   std::string deserialized_data;

   EXPECT_NO_THROW({ deserialized_data = ore::sdk::deserialize(input_data); });
   EXPECT_EQ(deserialized_data, expected_data);
}

TEST(ut_serializer, deserialize_object)
{
   const auto input_data = std::vector<std::byte>{ static_cast<std::byte>('1'),
                                                   static_cast<std::byte>('1'),
                                                   static_cast<std::byte>('7') };
   const auto expected_data = Object{ 117 };

   Object deserialized_data;

   EXPECT_NO_THROW(
      { deserialized_data = ore::sdk::deserialize<Object>(input_data); });
   EXPECT_EQ(deserialized_data, expected_data);
}

TEST(ut_serializer, deserialize_error)
{
   EXPECT_THROW(ore::sdk::deserialize<DeserializationErrorObject>({}),
                ore::sdk::deserialization_error);
}
