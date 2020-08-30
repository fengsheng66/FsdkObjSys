#include <FsdkObj/inner/InvokerItem.h>

using namespace FsdkObj;

InvokerItem::InvokerItem(
	const char* _name, IInvoker* _invoker) : m_name(_name), m_invoker(_invoker)
{

}

MetaType InvokerItem::type() const
{
	return InvokerMeta;
}

const std::string& InvokerItem::name() const
{
	return m_name;
}

IInvoker* InvokerItem::invoker() const
{
	return m_invoker;
}