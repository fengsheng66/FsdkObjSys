#ifndef VARLIST_H_FSDKOBJ
#define VARLIST_H_FSDKOBJ

#include <vector>
#include "./FsdkObjDef.h"
#include "./Variant.h"

namespace FsdkObj
{
	class FSDKOBJ_API VarList
	{
	public:
		inline VarList(){ }
		VarList(const VarList& other);
		virtual ~VarList();
		const VarList& operator=(const VarList& other);

		int size() const;
		void resize(int _size);
		void clear();

		template <typename T>
		void setValue(const T& var, int index = -1)
		{
			if (index >= 0 && index < m_vars.size())
			{
				if (m_vars[index])
				{
					Releasable* ra =
						dynamic_cast<Releasable*>(m_vars[index]);
					if (!ra)
						throw "canot release var";
					else
						delete ra;
				}
				m_vars[index] = new VarImpl<T>(var);
			}
			else
			{
				m_vars.push_back(new VarImpl<T>(var));
			}
		}
		template <typename T>
		T getValue(int index) const
		{
			if (index < 0 || index >= m_vars.size())
				throw "not find!";
			const VarImpl<T>* var_impl
				= dynamic_cast<const VarImpl<T>*>(m_vars[index]);
			if (var_impl != NULL)
			{
				return var_impl->value();
			}
			else
			{
				throw "type error!";
			}
		}

	private:
		std::vector<IVariant*> m_vars;
	};

}



#endif