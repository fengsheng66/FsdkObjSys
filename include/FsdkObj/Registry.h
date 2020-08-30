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