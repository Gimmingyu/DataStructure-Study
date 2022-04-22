#include "arraystack.h"

int 		isArrayStackFull(ArrayStack *pStack)
{
	NULLCHECK(pStack);
	return (pStack->currentElementCount == pStack->maxElementCount ? TRUE : FALSE);
}