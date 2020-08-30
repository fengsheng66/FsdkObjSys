#ifndef METACONTEXT_H_FSDKOBJ
#define METACONTEXT_H_FSDKOBJ

#include <map>
#include "./MetaSpace.h"

namespace FsdkObj
{
	class FSDKOBJ_API MetaContext
	{
	public:
		static MetaContext& getSingleton();
		~MetaContext();

		const MetaSpace* space(const std::string& name) const;

		bool registerClass(IMetaClass* metaClass);
		void writeoffClass(IMetaClass* metaClass);

	private:
		MetaContext();

	private:
		std::map<std::string, MetaSpace*> m_spaces;

	};
}

#endif