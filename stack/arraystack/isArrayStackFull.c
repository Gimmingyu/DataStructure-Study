#include "arraystack.h"

int 		isArrayStackFull(ArrayStack *pStack)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	return (pStack->currentElementCount == pStack->maxElementCount ? TRUE : FALSE);
}