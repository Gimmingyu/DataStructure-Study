#include "arraystack.h"

StackNode	*peekAS(ArrayStack *pStack)
{
	StackNode	*topNode;

	if (NULLCHECK(pStack))
		return (NULL);
	topNode = calloc(1, sizeof(StackNode));
	if (NULLCHECK(topNode))
		return (NULL);
	if (isArrayStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	topNode->data = pStack->pElement[pStack->currentElementCount - 1].data;
	return (topNode);
}