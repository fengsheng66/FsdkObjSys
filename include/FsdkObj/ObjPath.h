// Copyright (c) 2020 FengSheng.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//    http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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