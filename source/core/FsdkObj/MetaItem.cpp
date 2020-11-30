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

#include <FsdkObj/inner/MetaItem.h>

using namespace FsdkObj;

MetaItem::MetaItem(IMetaItem* _impl) : m_impl(_impl)
{

}

MetaItem::~MetaItem()
{
	if (m_impl)
	{
		delete m_impl;
	}
}

MetaType MetaItem::type() const
{
	return m_impl ? m_impl->type() : InvlidMeta;
}

const IMetaItem* MetaItem::impl() const 
{
	return m_impl;
}