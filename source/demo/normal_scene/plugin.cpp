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

#include "./plugin.h"
#include <FsdkObj/ObjectDef.h>
#include <FsdkObj/Registry.h>

namespace pd
{
	class PluginDemo : public FsdkObj::IObject, public IPluginDemo
	{
	public:
		PluginDemo()
		{
			FSDKOBJ_REGISTEROBJECT(this);
		}
		~PluginDemo()
		{
			FSDKOBJ_UNREGISTEROBJECT(this);
		}
		virtual const char* path() const
		{
			return "pd"; //return namespace name
		}
		virtual const char* name() const
		{
			return "IPluginDemo"; //return interface name
		}

		virtual void print(const char* content)
		{
			printf("PluginDemo print: %s\n", content);
		}
	};
} // namespace pd

static pd::PluginDemo pdInstance;