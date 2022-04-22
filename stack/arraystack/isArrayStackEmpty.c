#include "arraystack.h"

int 		isArrayStackEmpty(ArrayStack* pStack)
{
	NULLCHECK(pStack);
	return (pStack->currentElementCount == 0 ? TRUE : FALSE);
}