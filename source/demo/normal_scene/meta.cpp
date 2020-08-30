#include "./meta.h"
#include "./plugin.h"
#include <FsdkKernel/Global.h>
#include <FsdkObj/Registry.h>

using namespace md;

//must define "using namespace md" in before;
FSDKOBJ_REGISTERCLASS_BEGIN(MetaDemo, md)
FSDKOBJ_REGISTERCLASS_CONSTRUCTOR(MetaDemo, const char*)
FSDKOBJ_REGISTERCLASS_VOIDFUNC(MetaDemo, print, MetaDemo::print)
FSDKOBJ_REGISTERCLASS_NOTVOIDFUNC(MetaDemo, output, MetaDemo::output)
FSDKOBJ_REGISTERCLASS_END(MetaDemo)

void MetaDemo::print()
{
	FSDKKERNEL_DEFINE_GLOBALPTR(pd, IPluginDemo, ipd);
	if (!ipd)
	{
		printf("load plugin interface falut!\n");
		return;
	}
	std::string content = m_outStr;
	content += " called in MetaDemo::print";
	ipd->print(content.c_str());
}
int MetaDemo::output(const char* tag)
{
	FSDKKERNEL_DEFINE_GLOBALPTR(pd, IPluginDemo, ipd);
	if (!ipd)
	{
		printf("load plugin interface falut!\n");
		return -1;
	}
	std::string content = tag;
	content += " called in MetaDemo::output";
	ipd->print(content.c_str());
	static int gCallNum = 0;
	gCallNum++;
	return gCallNum;
}