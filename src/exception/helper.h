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

template<class P, class C>
concept derived = std::is_base_of<C, P>::value;

template<class P, derived<P> C>
void parrent_assign_operator(C* invokator, const C& other)
{
   auto&       parrent_ref = *dynamic_cast<P*>(invokator);
   const auto& other_ref   = *dynamic_cast<const P*>(&other);

   parrent_ref = other_ref;
}
