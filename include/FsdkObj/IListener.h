#ifndef ILISTENER_H_FSDKOBJ
#define ILISTENER_H_FSDKOBJ

#include "./ObjectDef.h"

namespace FsdkObj
{
	struct IListener
	{
		virtual void registerObj(IObject* obj) = 0;
		virtual void writeoffObj(IObject* obj) = 0;
	};
}

#endif