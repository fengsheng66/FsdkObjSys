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