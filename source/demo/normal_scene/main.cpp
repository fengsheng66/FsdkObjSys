#include "./meta.h"
#include <FsdkObj/MetaContext.h>

int main(int argc, char* argv[])
{ 
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
	md::MetaDemo* mdImpl = dynamic_cast<md::MetaDemo*>(obj);
	if (!mdImpl)
	{
		printf("convert meta object to impl fault!\n");
		return -1;
	}
	mdImpl->print();
	bool stat = mdImpl->output();
	printf("output return %s!\n", stat ? "true" : "false");
	delete mdImpl;
	while (true) { }
	return 0;
}