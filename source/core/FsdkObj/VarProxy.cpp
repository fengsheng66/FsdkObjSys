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