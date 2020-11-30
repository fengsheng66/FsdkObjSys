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

#ifndef EXPORT_H_FSDKKERNEL
#define EXPORT_H_FSDKKERNEL

#include "../FsdkDef/FsdkDef.h"

///∫Í∂®“Â
#ifdef FSDKKERNEL_LIB
#define FSDKKERNEL_API FSDK_EXPORT
#else
#define FSDKKERNEL_API FSDK_IMPORT
#endif

namespace FsdkObj
{
	struct IMetaClass;
	struct IObject;
}

extern "C"
{
	FSDKKERNEL_API 
		FsdkObj::IObject* 
		__stdcall 
		FsdkKernel_FindObject(
		const char* _name, 
		const char* _path
		);
	FSDKKERNEL_API 
		int
		__stdcall
		FsdkKernel_FindObjects(
		const char* _path,
		FsdkObj::IObject* objs[]
		);
	FSDKKERNEL_API 
		FsdkObj::IMetaClass* 
		__stdcall
		FsdkKernel_FindMeta(
		const char* _name, 
		const char* _space
		);
	FSDKKERNEL_API
		int
		__stdcall
		FsdkKernel_FindMetas(
		const char* _space,
		FsdkObj::IMetaClass* metas[]
		);
};

#endif