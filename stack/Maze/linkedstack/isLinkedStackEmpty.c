#include "linkedstack.h"

int	isLinkedStackEmpty(LinkedStack* pStack)
{
	if (NULLCHECK(pStack))
		return (ERROR);
	return (pStack->currentElementCount == 0 ? TRUE : FALSE);
}