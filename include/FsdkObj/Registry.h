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

#ifndef REGISTRY_H_FSDKOBJ
#define REGISTRY_H_FSDKOBJ

#include "./inner/Invoker.h"
#include "./inner/ConstructFunc.h"
#include "./inner/ImplClass.h"

#define FSDKOBJ_REGISTERCLASS_BEGIN(classname, spacename) \
	std::string FsdkObj::ImplClass<classname>::_implSpaceName = #spacename; \
	std::string FsdkObj::ImplClass<classname>::_implClassName = #classname; \
	std::vector<FsdkObj::LPCONSTRUCTFUNC> FsdkObj::ImplClass<classname>::_constructors; \
	std::vector<FsdkObj::ImplClass<classname>::SuperPair> FsdkObj::ImplClass<classname>::_supers; \
	std::map<std::string, FsdkObj::IInvoker*> FsdkObj::ImplClass<classname>::_invokers; \
	static FsdkObj::MetaItem fsdkobj_implclass_##classname##_meta[] = {

#define FSDKOBJ_REGISTERCLASS_CONSTRUCTOR(classname, ...) \
	new FsdkObj::ConstructItem(FsdkObj::CallConstructFunc<classname, __VA_ARGS__>),

#define FSDKOBJ_REGISTERCLASS_SUPER(supername, superspace) \
	new FsdkObj::SuperItem(#supername, #superspace),

#define FSDKOBJ_REGISTERCLASS_VOIDFUNC(classname, funcname, func) \
	new FsdkObj::InvokerItem(#funcname, BuildVoidInvoker((classname*)(0), &func)),

#define FSDKOBJ_REGISTERCLASS_NOTVOIDFUNC(classname, funcname, func) \
	new FsdkObj::InvokerItem(#funcname, BuildNotVoidInvoker((classname*)(0), &func)),
	
#define FSDKOBJ_REGISTERCLASS_END(classname) \
	(FsdkObj::IMetaItem*)0 }; \
	static bool fsdkobj_implclass_##classname##_inited = \
	FsdkObj::ImplClass<classname>::InitStaticMetas(fsdkobj_implclass_##classname##_meta); \
	static FsdkObj::ImplClass<classname> fsdkobj_implclass##classname##_instance;

#include "./ObjContext.h"

#define FSDKOBJ_REGISTEROBJECT(objptr) \
	FsdkObj::ObjContext::getSingleton().registerObj(objptr)

#define FSDKOBJ_UNREGISTEROBJECT(objptr) \
	FsdkObj::ObjContext::getSingleton().writeoffObj(objptr)

#define FSDKOBJ_LISTENOBJS(lookptr) \
	FsdkObj::ObjContext::getSingleton().listen(lookptr)

#define FSDKOBJ_IGNOREOBJS(lookptr) \
	FsdkObj::ObjContext::getSingleton().ignore(lookptr)

#endif