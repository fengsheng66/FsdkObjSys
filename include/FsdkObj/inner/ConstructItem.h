#ifndef CONSTRUCTITEM_H_FSDKOBJ
#define CONSTRUCTITEM_H_FSDKOBJ

#include "./MetaItem.h"
#include "./ConstructFunc.h"
#include "../FsdkObjDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API ConstructItem : public IMetaItem
	{
	public:
		inline ConstructItem(LPCONSTRUCTFUNC func) : m_func(func){}
		virtual MetaType type() const;
		LPCONSTRUCTFUNC constructor() const;

	private:
		mutable LPCONSTRUCTFUNC		m_func;
	};
}

#endif