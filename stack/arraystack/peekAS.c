#include "arraystack.h"

StackNode	*peekAS(ArrayStack *pStack)
{
	StackNode	*topNode;

	NULLCHECK(pStack);
	topNode = calloc(1, sizeof(StackNode));
	NULLCHECK(topNode);
	if (isArrayStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	topNode->data = pStack->pElement[pStack->currentElementCount - 1].data;
	return (topNode);
}