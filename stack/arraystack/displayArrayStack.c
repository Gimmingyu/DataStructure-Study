#include "arraystack.h"

void	displayArrayStack(ArrayStack *pStack)
{
	int	idx = pStack->currentElementCount;
	StackNode	*topNode = pStack->pElement;

	while (idx-- && topNode)
		printf("topNode->data = '%c'\n", topNode[idx].data);
}