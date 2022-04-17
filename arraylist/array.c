#include "arraylist.h"

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList		*array;

	if (maxElementCount <= 0)
	{
		printf("Invalid Input in createArrayList\n");
		return (NULL);
	}
	array = malloc(sizeof(ArrayList));
	if (!array)
	{
		printf("malloc failed in createArrayList\n");
		return (NULL);
	}
	array->maxElementCount = maxElementCount;
	array->currentElementCount = 0;
	array->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode));
	if (!array->pElement)
	{
		printf("malloc failed in createArrayList\n");
		return (NULL);
	}
	return (array);
}

void	deleteArrayList(ArrayList *pList)
{
	clearArrayList(pList);
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
	pList = NULL;
}

void	setArray(ArrayList *pList)
{
	ArrayListNode	node;
	int				i;

	i = 0;
	node.data = 0;
	while (i < pList->maxElementCount)
		(pList->pElement)[i++] = node;
}
