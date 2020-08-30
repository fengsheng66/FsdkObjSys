#ifndef OBJECTDEF_H_FSDK
#define OBJECTDEF_H_FSDK

namespace FsdkObj
{
	struct IObject
	{
		virtual const char* path() const = 0;
		virtual const char* name() const = 0;
	};
}

#endif