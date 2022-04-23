#include "arraystack.h"

ArrayStack	*createArrayStack(int maxElementCount)
{
	ArrayStack	*array;

	array = calloc(1, sizeof(ArrayStack));
	if (NULLCHECK(array))
		return (NULL);
	array->pElement = calloc(maxElementCount, sizeof(StackNode));
	if (NULLCHECK(array->pElement))
		return (NULL);
	array->maxElementCount = maxElementCount;
	return (array);
}