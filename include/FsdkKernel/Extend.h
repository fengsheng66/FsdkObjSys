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

#ifndef EXTEND_H_FSDKKERNEL
#define EXTEND_H_FSDKKERNEL

#include "./Export.h"
#include "../FsdkObj/ObjectDef.h"
#include <vector>

namespace FsdkKernel
{
	template<typename T>
	std::vector<T*> FindImplObjects(const char* _path)
	{
		std::vector<FsdkObj::IObject*> objs;
		int nums = FsdkKernel_FindObjects(_path, 0);
		if (0 >= nums) return std::vector<T*>();
		objs.resize(nums);
		FsdkKernel_FindObjects(_path, &objs[0]);
		std::vector<T*> impls;
		impls.resize(objs.size());
		int _pos = 0;
		for (int i = 0; i < objs.size(); i++)
		{
			T* impl = dynamic_cast<T*>(objs[i]);
			if (!impl)
			{
				impls.resize((int)impls.size() - 1);
				continue;
			}
			impls[_pos] = impl;
			_pos++;
		}
		return impls;
	}
}

#define FSDKKERNEL_DEFINE_EXTENDPTRS(space, type, vars) \
	std::vector<space::type*> vars = \
	FsdkKernel::FindImplObjects<space::type>(#space);

#endif