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

#include <FsdkObj/MetaSpace.h>

using namespace FsdkObj;

MetaSpace::MetaSpace(
	const std::string& _space) : m_space(_space)
{

}

MetaSpace::~MetaSpace()
{

}

bool MetaSpace::registerClass(IMetaClass* metaClass)
{
	ClassMap::iterator iter = 
		m_classMap.find(metaClass->classname());
	if (iter != m_classMap.end())
	{
		return false;
	}
	else
	{
		m_classMap[metaClass->classname()] = metaClass;
		return true;
	}
}

void MetaSpace::writeoffClass(const std::string& name)
{
	ClassMap::iterator iter = m_classMap.find(name);
	if (iter != m_classMap.end())
	{
		m_classMap.erase(iter);
	}
}

const std::string& MetaSpace::space() const
{
	return m_space;
}

std::vector<IMetaClass*> MetaSpace::allClass() const
{
	std::vector<IMetaClass*> classVec;
	classVec.resize(m_classMap.size(), 0);
	ClassMap::const_iterator iter = m_classMap.begin();
	for (int i = 0; iter != m_classMap.end(); iter++, i++)
	{
		classVec[i] = iter->second;
	}
	return classVec;
}

int MetaSpace::getClassNum() const
{
	return m_classMap.size();
}

IMetaClass* MetaSpace::getClass(const std::string& name) const
{
	ClassMap::const_iterator iter = m_classMap.find(name);
	if (iter != m_classMap.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}
