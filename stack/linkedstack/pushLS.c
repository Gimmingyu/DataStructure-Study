#include "linkedstack.h"

int 		pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*newNode;

	if (NULLCHECK(pStack))
		return (ERROR);
	newNode = calloc(1, sizeof(StackNode));
	if (NULLCHECK(newNode))
		return (ERROR);
	newNode->data = element.data;
	newNode->pLink = pStack->pTopElement;
	pStack->pTopElement = newNode;
	pStack->currentElementCount++;
	return (TRUE);
}