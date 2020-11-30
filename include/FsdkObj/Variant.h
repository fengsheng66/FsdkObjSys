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