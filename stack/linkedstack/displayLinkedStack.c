#include "linkedstack.h"

void	displayLinkedStack(LinkedStack *pStack)
{
	int	idx;
	StackNode	*topNode;

	if (NULLCHECK(pStack))
		return ;
	idx = pStack->currentElementCount;
	topNode = pStack->pTopElement;
	while (idx-- && topNode)
	{
		printf("topNode->data = '%c'\n", topNode->data);
		topNode = topNode->pLink;
	}
}
