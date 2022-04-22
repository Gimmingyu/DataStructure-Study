#include "arraystack.h"

int 		pushAS(ArrayStack *pStack, StackNode element)
{
	StackNode	*newNode = calloc(1, sizeof(StackNode));

	NULLCHECK(pStack);
	NULLCHECK(newNode);
	if (isArrayStackFull(pStack))
	{
		free(newNode);
		newNode = NULL;
		return (FALSE);
	}
	newNode->data = element.data;
	newNode->pLink = pStack->pTopElement;
	pStack->pTopElement = newNode;
	pStack->currentElementCount++;
	return (TRUE);
}