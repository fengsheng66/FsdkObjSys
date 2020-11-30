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

#ifndef GLOBAL_H_FSDKKERNEL
#define GLOBAL_H_FSDKKERNEL

#include "./Export.h"
#include "../FsdkObj/ObjectDef.h"

namespace FsdkKernel
{
	template<typename T>
	T* FindImplObject(const char* _name, const char* _path)
	{
		return dynamic_cast<T*>(FsdkKernel_FindObject(_name, _path));
	}
}

#define FSDKKERNEL_DEFINE_GLOBALPTR(space, type, var) \
	space::type* var = \
	FsdkKernel::FindImplObject<space::type>(#type, #space);

#endif