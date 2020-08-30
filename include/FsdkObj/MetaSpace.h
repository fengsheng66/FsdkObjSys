#ifndef METASPACE_H_FSDKOBJ
#define METASPACE_H_FSDKOBJ

#include <string>
#include <map>
#include "./FsdkObjDef.h"
#include "./MetaDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API MetaSpace
	{
	public:
		const std::string& space() const;
		~MetaSpace();

		std::vector<IMetaClass*> allClass() const;
		int getClassNum() const;
		IMetaClass* getClass(const std::string& name) const;

	private:
		MetaSpace(const std::string& _space);

		bool registerClass(IMetaClass* metaClass);
		void writeoffClass(const std::string& name);

	private:
		typedef std::map<std::string, IMetaClass*>	ClassMap;
		const std::string		m_space;
		ClassMap				m_classMap;

		friend class MetaContext;
	};
}

#endif