#ifndef CONSTRUCTFUNC_H_FSDKOBJ
#define CONSTRUCTFUNC_H_FSDKOBJ

#include "../MetaDef.h"
#include "../VarList.h"

namespace FsdkObj
{
	typedef Releasable* (*LPCONSTRUCTFUNC)(const VarList &);
	//none params
	template<class OBJ>
	Releasable* CallConstructFunc(const VarList &argList)
	{
		return new OBJ;
	}
	//one params
	template<class OBJ, typename ARG_1>
	Releasable* CallConstructFunc(const VarList &argList)
	{
		return new OBJ(argList.getValue<ARG_1>(0));
	}
	//two params
	template<class OBJ, typename ARG_1, typename ARG_2>
	Releasable* CallConstructFunc(const VarList &argList)
	{
		return new OBJ(argList.getValue<ARG_1>(0), argList.getValue<ARG_2>(1));
	}
}

#endif