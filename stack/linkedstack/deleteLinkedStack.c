#include "linkedstack.h"

void	deleteLinkedStack(LinkedStack *pStack)
{
	int			idx;
	StackNode	*delNode;
	StackNode	*nextNode;

	if (NULLCHECK(pStack))
		return ;
	idx = pStack->currentElementCount;
	delNode = pStack->pTopElement;
	while (idx-- && delNode)
	{
		nextNode = delNode->pLink;
		free(delNode);
		delNode = nextNode;
	}
	free(pStack);
}
