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