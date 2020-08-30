#ifndef OBJPATH_H_FSDKOBJ
#define OBJPATH_H_FSDKOBJ


#include <string>
#include <map>
#include <vector>
#include "./FsdkObjDef.h"
#include "./ObjectDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API ObjPath
	{
	public:
		const std::string& path() const;
		~ObjPath();

		std::vector<IObject*> allObj() const;
		int getObjectNum() const;
		IObject* getObj(const std::string& name) const;

	private:
		ObjPath(const std::string& _path);

		bool registerObj(IObject* obj);
		bool writeoffObj(const std::string& name);

	private:
		typedef std::map<std::string, IObject*>	ObjectMap;
		const std::string		m_path;
		ObjectMap				m_objects;

		friend class ObjContext;
	};
}

#endif