#ifndef VARIANT_H_FSDKOBJ
#define VARIANT_H_FSDKOBJ

#include "./Releasable.h"
#include "./VariantDef.h"

namespace FsdkObj
{
	template <typename T>
	class VarImpl : public IVariant, public Releasable
	{
	public:
		VarImpl(const T& value) : m_value(value)
		{

		}
		virtual ~VarImpl(){}
		virtual IVariant* clone() const
		{
			return new VarImpl<T>(m_value);
		}
		T value() const
		{
			return m_value;
		}

	private:
		T m_value;
	};
}

#endif