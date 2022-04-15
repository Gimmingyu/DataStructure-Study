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
	return (array);
}

void deleteArrayList(ArrayList *pList)
{
	clearArrayList(pList);
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
	pList = NULL;
}

