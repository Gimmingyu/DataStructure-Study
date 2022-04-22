#include "linkedstack.h"

LinkedStack	*createLinkedStack()
{
	LinkedStack	*stack;

	stack = calloc(1, sizeof(LinkedStack));
	NULLCHECK(stack);
	return (stack);
}