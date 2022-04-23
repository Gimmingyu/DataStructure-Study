#include "arraystack.h"

void	displayArrayStack(ArrayStack *pStack)
{
	int	idx;
	StackNode	*topNode;

	if (NULLCHECK(pStack))
		return ;
	idx = pStack->currentElementCount;
	topNode = pStack->pElement;
	while (idx-- && topNode)
		printf("topNode->data = '%c'\n", topNode[idx].data);
}