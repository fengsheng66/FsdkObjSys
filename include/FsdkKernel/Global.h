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