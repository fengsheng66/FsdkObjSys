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

#include <FsdkKernel/Export.h>
#include <FsdkObj/MetaContext.h>
#include <FsdkObj/ObjContext.h>
#include <vector>

FSDKKERNEL_API FsdkObj::IObject* __stdcall FsdkKernel_FindObject(const char* _name, const char* _path)
{
	std::string stdPath = (_path ? _path : "");
	const FsdkObj::ObjPath *oPath =
		FsdkObj::ObjContext::getSingleton().path(stdPath);
	if (!oPath) return 0;
	std::string stdName = (_name ? _name : 0);
	return oPath->getObj(stdName);
}

FSDKKERNEL_API int __stdcall FsdkKernel_FindObjects(const char* _path, FsdkObj::IObject* objs[])
{
	std::string stdPath = (_path ? _path : "");
	const FsdkObj::ObjPath *oPath =
		FsdkObj::ObjContext::getSingleton().path(stdPath);
	if (!oPath) return 0;
	if (!objs) return oPath->getObjectNum();
	std::vector<FsdkObj::IObject*> ptrs = oPath->allObj();
	for (int i = 0; i < ptrs.size(); i++)
	{
		*(objs + i) = ptrs[i];
	}
	return ptrs.size();
}

FSDKKERNEL_API FsdkObj::IMetaClass* __stdcall FsdkKernel_FindMeta(const char* _name, const char* _space)
{
	std::string stdSpace = (_space ? _space : "");
	const FsdkObj::MetaSpace *space =
		FsdkObj::MetaContext::getSingleton().space(stdSpace);
	if (!space) return 0;
	std::string stdName = (_name ? _name : 0);
	return space->getClass(stdName);
}

FSDKKERNEL_API int __stdcall FsdkKernel_FindMetas(const char* _space, FsdkObj::IMetaClass* metas[])
{
	std::string stdSpace = (_space ? _space : "");
	const FsdkObj::MetaSpace *space =
		FsdkObj::MetaContext::getSingleton().space(stdSpace);
	if (!space) return 0;
	if (!metas) return space->getClassNum();
	std::vector<FsdkObj::IMetaClass*> ptrs = space->allClass();
	for (int i = 0; i < ptrs.size(); i++)
	{
		*(metas + i) = ptrs[i];
	}
	return ptrs.size();
}