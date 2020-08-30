#include <FsdkObj/inner/ConstructItem.h>

using namespace FsdkObj;

MetaType ConstructItem::type() const
{
	return ConstructorMeta;
}

LPCONSTRUCTFUNC ConstructItem::constructor() const
{
	return m_func;
}