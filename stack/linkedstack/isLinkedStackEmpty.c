#include "linkedstack.h"

int	isLinkedStackEmpty(LinkedStack* pStack)
{
	NULLCHECK(pStack);
	return (pStack->currentElementCount == 0 ? TRUE : FALSE);
}