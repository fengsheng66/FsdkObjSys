// Copyright (c) 2020 FengSheng.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//    http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <FsdkObj/inner/SuperItem.h>

using namespace FsdkObj;

SuperItem::SuperItem(
	const char* _super, const char* _space) : m_super(_super), m_space(_space)
{

}

MetaType SuperItem::type() const
{
	return SuperMeta;
}

const std::string& SuperItem::super() const
{
	return m_super;
}

const std::string& SuperItem::space() const
{
	return m_space;
}