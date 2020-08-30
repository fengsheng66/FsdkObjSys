#ifndef VARIANTDEF_H_FSDKOBJ
#define VARIANTDEF_H_FSDKOBJ

namespace FsdkObj
{
	struct IVariant
	{
		virtual IVariant* clone() const = 0;
	};
}

#endif