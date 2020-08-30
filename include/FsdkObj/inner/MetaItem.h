#ifndef METAITEM_H_FSDKOBJ
#define METAITEM_H_FSDKOBJ

#include "./InnerDef.h"
#include "../Releasable.h"
#include "../FsdkObjDef.h"

namespace FsdkObj
{
	struct IMetaItem : public Releasable
	{
		virtual MetaType type() const = 0;
	};
	class FSDKOBJ_API MetaItem : public IMetaItem
	{
	public:
		MetaItem(IMetaItem* _impl);
		
		virtual ~MetaItem();
		virtual MetaType type() const;
		const IMetaItem* impl() const;

	protected:
		inline MetaItem(const MetaItem& other){}
		inline MetaItem& operator=(const MetaItem& other)
		{ return *this; }
	private:
		mutable IMetaItem*		m_impl;
	};
}

#endif