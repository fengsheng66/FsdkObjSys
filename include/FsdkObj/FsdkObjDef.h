#ifndef FSDKOBJDEF_H_FSDKOBJ
#define FSDKOBJDEF_H_FSDKOBJ

#include "../FsdkDef/FsdkDef.h"

///∫Í∂®“Â
#ifdef FSDKOBJ_LIB
#define FSDKOBJ_API FSDK_EXPORT
#else
#define FSDKOBJ_API FSDK_IMPORT
#endif

#endif