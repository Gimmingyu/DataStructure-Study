#include "arraystack.h"

int	pushAS(ArrayStack *pStack, StackNode element)
{
	StackNode	*stack;
	int			i = 0;

	if (NULLCHECK(pStack))
		return (ERROR);
	if (isArrayStackFull(pStack))
		return (ERROR);
	stack = pStack->pElement;
	stack[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}