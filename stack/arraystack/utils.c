#include "arraystack.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("null pointer exception\n");
		return (TRUE);
	}
	return (FALSE);
}

int	SAME(int x, int y)
{
	return (x == y ? TRUE : FALSE);
}

int	ZERO(int x)
{
	return (x == 0 ? TRUE : FALSE);
}