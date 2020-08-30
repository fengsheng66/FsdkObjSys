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