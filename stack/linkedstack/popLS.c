#include "linkedstack.h"

StackNode	*popLS(LinkedStack* pStack)
{
	StackNode	*delNode;

	if (NULLCHECK(pStack))
		return (NULL);
	// is empty
	if (isLinkedStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	delNode = pStack->pTopElement;
	pStack->pTopElement = delNode->pLink;
	pStack->currentElementCount--;
	return (delNode);
}