#include "linkedstack.h"

void 		deleteLinkedStack(LinkedStack *pStack)
{
	int			idx;
	StackNode	*delNode;
	StackNode	*nextNode;

	NULLCHECK(pStack);
	if (isLinkedStackEmpty(pStack))
	{
		pStack->pTopElement = NULL;
		free(pStack);
		pStack = NULL;
	}
	else
	{
		idx = pStack->currentElementCount;
		delNode = pStack->pTopElement;
		while (idx-- && delNode)
		{
			nextNode = delNode->pLink;
			delNode->pLink = NULL;
			delNode->data = 0x00;
			free(delNode);
			delNode = nextNode;
		}
		pStack->pTopElement = NULL;
		free(delNode);
		free(pStack);
		free(nextNode);
		nextNode = NULL;
		delNode = NULL;
		pStack = NULL;
	}
}