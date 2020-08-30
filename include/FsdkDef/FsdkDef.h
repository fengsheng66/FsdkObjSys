#ifndef FSDKDEF_H
#define FSDKDEF_H

//< export macro
#define FSDK_EXPORT __declspec(dllexport)
//< import macro
#define FSDK_IMPORT __declspec(dllimport)

//< assert macro
#ifdef NDEBUG
#undef NDEBUG
#include <assert.h>
#define FSDK_ASSERT(_Expression)	assert(_Expression)
#define NDEBUG
#else
#include <assert.h>
#define FSDK_ASSERT(_Expression)	assert(_Expression)
#endif

#endif