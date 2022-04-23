#include "linkedstack.h"

StackNode	*peekLS(LinkedStack* pStack)
{
	if (NULLCHECK(pStack))
		return (NULL);
	if (isLinkedStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	return (pStack->pTopElement);
}