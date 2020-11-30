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

#include <FsdkObj/MetaDef.h>
#include <FsdkObj/inner/Invoker.h>
#include <FsdkObj/Registry.h>
#include "FsdkObj/MetaContext.h"
#include "FsdkObj/MetaSpace.h"
#include <FsdkObj/Releasable.h>

class ObjTest : public FsdkObj::Releasable
{
public:
	ObjTest(){}
	ObjTest(int a, char b)
	{

	}
	~ObjTest()
	{

	}

	virtual FsdkObj::IMetaClass* meta() const
	{
		return FsdkObj::MetaContext::getSingleton().space("::")->getClass("ObjTest");
	}
	virtual const char* name() const
	{
		return 0;
	}
};

FSDKOBJ_REGISTERCLASS_BEGIN(ObjTest, ::)
FSDKOBJ_REGISTERCLASS_CONSTRUCTOR(ObjTest)
FSDKOBJ_REGISTERCLASS_CONSTRUCTOR(ObjTest, int, char)
FSDKOBJ_REGISTERCLASS_END(ObjTest)