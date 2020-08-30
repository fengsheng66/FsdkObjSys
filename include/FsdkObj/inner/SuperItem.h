#ifndef SUPERITEM_H_FSDKOBJ
#define SUPERITEM_H_FSDKOBJ

#include "./MetaItem.h"
#include "../FsdkObjDef.h"
#include <string>

namespace FsdkObj
{
	class FSDKOBJ_API SuperItem : public IMetaItem
	{
	public:
		SuperItem(const char* _super, const char* _space);
		virtual MetaType type() const;

		const std::string& super() const;
		const std::string& space() const;

	private:
		std::string		m_super;
		std::string		m_space;
	};
}

#endif