#include "arraystack.h"

StackNode	*popAS(ArrayStack *pStack)
{
	StackNode	*popNode;
	StackNode	*delNode;

	if (NULLCHECK(pStack))
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	popNode = calloc(1, sizeof(StackNode));
	if (NULLCHECK(popNode))
		return (NULL);
	delNode = &(pStack->pElement[pStack->currentElementCount - 1]);
	popNode->data = delNode->data;
	delNode->data = 0;
	pStack->currentElementCount--;
	return (popNode);
}
