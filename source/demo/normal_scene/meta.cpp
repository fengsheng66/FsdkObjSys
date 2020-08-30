#include "./meta.h"
#include "./plugin.h"
#include <FsdkKernel/Global.h>
#include <FsdkObj/Registry.h>

using namespace md;

void MetaDemo::print()
{
	FSDKKERNEL_DEFINE_GLOBALPTR(pd, IPluginDemo, ipd);
	if (!ipd)
	{
		printf("load plugin interface falut!\n");
		return;
	}
	std::string content = m_outStr;
	content += "called in MetaDemo::print";
	ipd->print(content.c_str());
}
bool MetaDemo::output()
{
	FSDKKERNEL_DEFINE_GLOBALPTR(pd, IPluginDemo, ipd);
	if (!ipd)
	{
		printf("load plugin interface falut!\n");
		return false;
	}
	std::string content = m_outStr;
	content += "called in MetaDemo::output";
	ipd->print(content.c_str());
	return true;
}

//必须在前面声明 using namespace md;
FSDKOBJ_REGISTERCLASS_BEGIN(MetaDemo, md)
FSDKOBJ_REGISTERCLASS_CONSTRUCTOR(MetaDemo, const char*)
FSDKOBJ_REGISTERCLASS_VOIDFUNC(MetaDemo, print, MetaDemo::print)
FSDKOBJ_REGISTERCLASS_NOTVOIDFUNC(MetaDemo, output, MetaDemo::output)
FSDKOBJ_REGISTERCLASS_END(MetaDemo)