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