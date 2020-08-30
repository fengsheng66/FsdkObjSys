#ifndef VARPROXY_H_FSDKOBJ
#define VARPROXY_H_FSDKOBJ

#include "./Variant.h"
#include "./FsdkObjDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API VarProxy : public IVariant
	{
	public:
		VarProxy();
		VarProxy(const VarProxy& other);
		~VarProxy();
		VarProxy& operator=(const VarProxy& other);
		bool isNull() const;

		virtual IVariant* clone() const;

		template <typename T>
		void setVar(T var)
		{
			if (m_impl)
			{
				delete m_impl;
			}
			m_impl = new VarImpl<T>(var);
		}
		template <typename T>
		T getVar() const
		{
			VarImpl<T>* impl
				= dynamic_cast<VarImpl<T>*>(m_impl);
			if (impl != NULL)
			{
				return impl->value();
			}
			else
			{
				throw "not find!";
			}
		}
	private:
		IVariant* m_impl;
	};
}

#endif