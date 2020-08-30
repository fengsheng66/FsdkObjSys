#include "./meta.h"
#include <FsdkObj/MetaContext.h>

int main(int argc, char* argv[])
{
	//construct object
	const FsdkObj::MetaSpace *space =
		FsdkObj::MetaContext::getSingleton().space("md");
	if (!space)
	{
		printf("load meta space fault!\n");
		return -1;
	}
	FsdkObj::IMetaClass* mc = space->getClass("MetaDemo"); 
	if (!mc)
	{
		printf("load meta class fault!\n");
		return -1;
	}
	FsdkObj::VarList params;
	params.resize(1);
	typedef const char* CSTR;
	params.setValue<CSTR>("666", 0);
	FsdkObj::Releasable *obj = mc->construct(params, 0);
	if (!obj)
	{
		printf("construct meta object fault!\n");
		return -1;
	}

	//invoke method
	FsdkObj::VarList args;
	FsdkObj::VarProxy ret1;
	if (!mc->invoke("print", obj, args, ret1))
	{
		printf("invoke print fault!\n");
		return -1;
	}
	args.resize(1);
	args.setValue<CSTR>("888", 0);
	FsdkObj::VarProxy ret2;
	if (!mc->invoke("output", obj, args, ret2))
	{
		printf("invoke output fault!\n");
		return -1;
	}
	int ivRetNum = ret2.getVar<int>();
	printf("invoke output return %d!\n", ivRetNum);

	//call static type
	md::MetaDemo* mdImpl = dynamic_cast<md::MetaDemo*>(obj);
	if (!mdImpl)
	{
		printf("convert meta object to impl fault!\n");
		return -1;
	}
	mdImpl->print();
	int retNum = mdImpl->output("555");
	printf("call output return %d!\n", retNum);
	delete mdImpl;

	while (true) { }

	return 0;
}