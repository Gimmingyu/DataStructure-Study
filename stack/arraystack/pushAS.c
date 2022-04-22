#include "arraystack.h"

int	pushAS(ArrayStack *pStack, StackNode element)
{
	StackNode	*stack;
	int			i = 0;

	NULLCHECK(pStack);
	if (isArrayStackFull(pStack))
		return (FALSE);
	stack = pStack->pElement;
	stack[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}