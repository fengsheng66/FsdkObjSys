#ifndef FSDKOBJDEF_H_FSDKOBJ
#define FSDKOBJDEF_H_FSDKOBJ

#include "../FsdkDef/FsdkDef.h"

///�궨��
#ifdef FSDKOBJ_LIB
#define FSDKOBJ_API FSDK_EXPORT
#else
#define FSDKOBJ_API FSDK_IMPORT
#endif

#endif