#ifndef REFRENCE_H_FSDKOBJ
#define REFRENCE_H_FSDKOBJ

#include "./ref_def.h"
#include "./FsdkObjDef.h"

namespace FsdkObj
{
	class FSDKOBJ_API Refrence : public IRefrence, public Releasable
	{
	public:
		virtual ~Refrence(){}
		virtual Releasable& asReleasable();
		virtual int ref() const;
		virtual int unref() const;

	protected:
		inline Refrence() : m_refCount(0) {}

	private:
		mutable int		m_refCount;
	};
}

#endif