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