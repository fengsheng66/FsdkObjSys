#include <FsdkObj/Refrence.h>

using namespace FsdkObj;

Releasable& Refrence::asReleasable()
{
	return *this;
}

int Refrence::ref() const
{
	return ++m_refCount;
}

int Refrence::unref() const
{
	return (0 < m_refCount) ? --m_refCount : 0;
}