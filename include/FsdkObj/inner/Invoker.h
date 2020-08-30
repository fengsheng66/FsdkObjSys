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