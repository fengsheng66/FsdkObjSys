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