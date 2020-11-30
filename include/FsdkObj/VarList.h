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