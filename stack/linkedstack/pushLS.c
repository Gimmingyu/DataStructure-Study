#include "linkedstack.h"

int 		pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*newNode = calloc(1, sizeof(StackNode));

	NULLCHECK(pStack);
	NULLCHECK(newNode);
	newNode->data = element.data;
	newNode->pLink = pStack->pTopElement;
	pStack->pTopElement = newNode;
	pStack->currentElementCount++;
	return (TRUE);
}