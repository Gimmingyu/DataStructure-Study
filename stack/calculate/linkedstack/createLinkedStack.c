#include "linkedstack.h"

LinkedStack	*createLinkedStack()
{
	LinkedStack	*stack;

	stack = calloc(1, sizeof(LinkedStack));
	if (NULLCHECK(stack))
		return (NULL);
	return (stack);
}