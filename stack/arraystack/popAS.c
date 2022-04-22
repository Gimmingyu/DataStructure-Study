#include "arraystack.h"

StackNode	*popAS(ArrayStack *pStack)
{
	StackNode	*popNode;
	StackNode	*delNode;

	NULLCHECK(pStack);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	popNode = calloc(1, sizeof(StackNode));
	NULLCHECK(popNode);
	delNode = &(pStack->pElement[pStack->currentElementCount - 1]);
	popNode->data = delNode->data;
	delNode = NULL;
	pStack->currentElementCount--;
	return (popNode);
}