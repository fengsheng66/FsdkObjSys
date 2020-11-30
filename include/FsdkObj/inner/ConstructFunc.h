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