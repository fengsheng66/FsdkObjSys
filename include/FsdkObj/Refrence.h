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

#ifndef REFRENCE_H_FSDKOBJ
#define REFRENCE_H_FSDKOBJ

#include "./ref_def.h"
#include "./FsdkObjDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API Refrence : public IRefrence, public Releasable
	{
	public:
		virtual ~Refrence(){}
		virtual Releasable& asReleasable();
		virtual int ref() const;
		virtual int unref() const;

	protected:
		inline Refrence() : m_refCount(0) {}

	private:
		mutable int		m_refCount;
	};
}

#endif