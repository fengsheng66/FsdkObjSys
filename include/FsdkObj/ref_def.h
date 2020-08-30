#ifndef REF_DEF_H_FSDKOBJ
#define REF_DEF_H_FSDKOBJ

#include "./Releasable.h"

namespace FsdkObj
{
	struct IRefrence 
	{
		virtual Releasable& asReleasable() = 0;
		virtual int ref() const = 0;
		virtual int unref() const = 0;
	};
}

#endif