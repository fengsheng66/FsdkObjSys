#ifndef INVOKEFUNC_H_FSDKOBJ
#define INVOKEFUNC_H_FSDKOBJ

#include "../VarList.h"
#include "../VarProxy.h"

namespace FsdkObj
{
	//none params
	template<class OBJ, typename RES>
	VarProxy CallObjNotVoidFunc(OBJ * pObj, RES(OBJ::*pFunc)(), const VarList &argList)
	{
		VarProxy var;
		var.setVar<RES>((pObj->*pFunc)());
		return var;
	}
	template<class OBJ>
	VarProxy CallObjVoidFunc(OBJ * pObj, void(OBJ::*pFunc)(), const VarList &argList)
	{
		VarProxy var;
		(pObj->*pFunc)();
		return var;
	}
	//one params
	template<class OBJ, typename RES, typename ARG_1>
	VarProxy CallObjNotVoidFunc(OBJ * pObj, RES(OBJ::*pFunc)(ARG_1), const VarList &argList)
	{
		VarProxy var;
		var.setVar<RES>((pObj->*pFunc)(argList.getValue<ARG_1>(0)));
		return var;
	}
	template<class OBJ, typename ARG_1>
	VarProxy CallObjVoidFunc(OBJ * pObj, void(OBJ::*pFunc)(ARG_1), const VarList &argList)
	{
		VarProxy var;
		(pObj->*pFunc)(argList.getValue<ARG_1>(0));
		return var;
	}
	//two params
	template<class OBJ, typename RES, typename ARG_1, typename ARG_2>
	VarProxy CallObjNotVoidFunc(OBJ * pObj, RES(OBJ::*pFunc)(ARG_1, ARG_2), const VarList &argList)
	{
		VarProxy var;
		var.setVar<RES>((pObj->*pFunc)(argList.getValue<ARG_1>(0), argList.getValue<ARG_1>(0)));
		return var;
	}
	template<class OBJ, typename ARG_1, typename ARG_2>
	VarProxy CallObjVoidFunc(OBJ * pObj, void(OBJ::*pFunc)(ARG_1, ARG_2), const VarList &argList)
	{
		VarProxy var;
		(pObj->*pFunc)(argList.getValue<ARG_1>(0), argList.getValue<ARG_1>(0));
		return var;
	}
}

#endif