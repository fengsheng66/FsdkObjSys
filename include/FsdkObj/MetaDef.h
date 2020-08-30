#ifndef METADEF_H_FSDKOBJ
#define METADEF_H_FSDKOBJ

#include <string>
#include "VarProxy.h"
#include "VarList.h"

namespace FsdkObj
{
	class Releasable;

	struct IMetaClass
	{
		virtual const char* spacename() const = 0;
		virtual const char* classname() const = 0;
		virtual Releasable* construct(const VarList &argList, int index) = 0;
		virtual bool invoke(const std::string& funcName, Releasable* obj, const VarList &argList, VarProxy& out) = 0;
		virtual bool destroy(Releasable* obj) = 0;
	};
}

#endif
