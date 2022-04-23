#include "linkedstack.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("null pointer exception\n");	
		return (1);
	}
	return (0);
}

int	SAME(int x, int y)
{
	return (x == y ? TRUE : FALSE);
}

int	ZERO(int x)
{
	return (x == 0 ? TRUE : FALSE);
}