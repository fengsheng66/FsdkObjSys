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