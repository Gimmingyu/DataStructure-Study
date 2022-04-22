#include "linkedstack.h"

StackNode	*peekLS(LinkedStack* pStack)
{
	NULLCHECK(pStack);
	if (isLinkedStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	return (pStack->pTopElement);
}