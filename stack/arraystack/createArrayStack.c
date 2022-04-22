#include "arraystack.h"

ArrayStack	*createArrayStack(int maxElementCount)
{
	ArrayStack	*array;

	array = calloc(1, sizeof(ArrayStack));
	NULLCHECK(array);
	array->maxElementCount = maxElementCount;
	return (array);
}