#include "arraystack.h"

StackNode	*peekAS(ArrayStack *pStack)
{
	NULLCHECK(pStack);
	if (isArrayStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	return (pStack->pTopElement);
}
