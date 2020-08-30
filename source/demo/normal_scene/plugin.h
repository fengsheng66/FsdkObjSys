#ifndef FSDK_DEMO_PLUGIN_H
#define FSDK_DEMO_PLUGIN_H

namespace pd
{
	struct IPluginDemo
	{
		virtual void print(const char* content) = 0;
	};
} // namespace pd

#endif