#include "linkedstack.h"

void	displayLinkedStack(LinkedStack *pStack)
{
	int	idx = pStack->currentElementCount;
	StackNode	*topNode = pStack->pTopElement;

	while (idx-- && topNode)
	{
		printf("topNode->data = '%c'\n", topNode->data);
		topNode = topNode->pLink;
	}
}
