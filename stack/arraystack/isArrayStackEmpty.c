#include "arraystack.h"

int 		isArrayStackEmpty(ArrayStack* pStack)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	return (pStack->currentElementCount == 0 ? TRUE : FALSE);
}