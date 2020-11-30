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

#ifndef INVOKER_H_FSDKOBJ
#define INVOKER_H_FSDKOBJ

#include "../FsdkObjDef.h"
#include "../VarList.h"
#include "./InvokeFunc.h"
#include "./InnerDef.h"

namespace FsdkObj
{
	struct IInvoker
	{
		virtual VarProxy invoke(Releasable* obj, const VarList &argList) = 0;
	};
	template<class OBJ, typename PFUNC>
	class NotVoidInvoker : public IInvoker
	{
	public:
		NotVoidInvoker(PFUNC pFunc)
		{
			m_pFunc = pFunc;
		}
		virtual VarProxy invoke(Releasable* obj, const VarList &argList)
		{
			return CallObjNotVoidFunc(dynamic_cast<OBJ*>(obj), m_pFunc, argList);
		}

	private:
		PFUNC		m_pFunc;
	};
	template<class OBJ, typename PFUNC>
	IInvoker* BuildNotVoidInvoker(OBJ* obj, PFUNC pFunc)
	{
		return new NotVoidInvoker<OBJ, PFUNC>(pFunc);
	}

	template<class OBJ, typename PFUNC>
	class VoidInvoker : public IInvoker
	{
	public:
		VoidInvoker(PFUNC pFunc)
		{
			m_pFunc = pFunc;
		}
		virtual VarProxy invoke(Releasable* obj, const VarList &argList)
		{
			return CallObjVoidFunc(dynamic_cast<OBJ*>(obj), m_pFunc, argList);
		}

	private:
		PFUNC		m_pFunc;
	};
	template<class OBJ, typename PFUNC>
	IInvoker* BuildVoidInvoker(OBJ* obj, PFUNC pFunc)
	{
		return new VoidInvoker<OBJ, PFUNC>(pFunc);
	}

}

#endif