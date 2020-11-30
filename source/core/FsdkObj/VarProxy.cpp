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

#include <FsdkObj/VarProxy.h>

using namespace FsdkObj;

VarProxy::VarProxy() :m_impl(0)
{

}

VarProxy::VarProxy(const VarProxy& other)
{
	m_impl =
		(other.m_impl ? other.m_impl->clone() : 0);
}

VarProxy::~VarProxy()
{
	if (m_impl)
	{
		delete m_impl;
	}
}

VarProxy& VarProxy::operator=(const VarProxy& other)
{
	if (this == &other)
	{
		return *this;
	}
	if (m_impl)
	{
		delete m_impl;
	}
	m_impl =
		(other.m_impl ? other.m_impl->clone() : 0);
	return *this;
}

bool VarProxy::isNull() const
{
	return 0 == m_impl;
}

IVariant* VarProxy::clone() const
{
	VarProxy* proxy = new VarProxy;
	if (proxy && m_impl)
		proxy->m_impl = m_impl->clone();
	return proxy;
}