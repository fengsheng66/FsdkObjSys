#ifndef INVOKERITEM_H_FSDKOBJ
#define INVOKERITEM_H_FSDKOBJ

#include "./MetaItem.h"
#include "../FsdkObjDef.h"
#include <string>

namespace FsdkObj
{
	struct IInvoker;

	class FSDKOBJ_API InvokerItem : public IMetaItem
	{
	public:
		InvokerItem(const char* _name, IInvoker* _invoker);
		virtual MetaType type() const;

		const std::string& name() const;
		IInvoker* invoker() const;

	private:
		const std::string	m_name;
		IInvoker*			m_invoker;
	};
}

#endif