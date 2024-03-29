#include "arraystack.h"

void	deleteArrayStack(ArrayStack *pStack)
{
	StackNode	*bottomNode;
	int	idx = 0;

	if (NULLCHECK(pStack))
		return ;
	bottomNode = pStack->pElement;
	while (idx < pStack->maxElementCount)
		bottomNode[idx++].data = 0;
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
	pStack = NULL;
}