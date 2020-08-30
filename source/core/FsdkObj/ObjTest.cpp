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