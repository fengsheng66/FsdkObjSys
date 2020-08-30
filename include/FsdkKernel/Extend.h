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