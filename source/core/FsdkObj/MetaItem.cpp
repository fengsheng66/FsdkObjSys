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