#ifndef OBJCONTEXT_H_FSDKOBJ
#define OBJCONTEXT_H_FSDKOBJ

#include <map>
#include <set>
#include "./IListener.h"
#include "./ObjPath.h"

namespace FsdkObj
{
	class FSDKOBJ_API ObjContext
	{
	public:
		static ObjContext& getSingleton();
		~ObjContext();

		const ObjPath* path(const std::string& name) const;

		bool registerObj(IObject* obj);
		void writeoffObj(IObject* obj);

		bool listen(IListener* _listenner);
		void ignore(IListener* _listenner);

	private:
		ObjContext();

	private:
		std::map<std::string, ObjPath*> m_paths;
		std::set<IListener*>			m_looks;
	};
}

#endif