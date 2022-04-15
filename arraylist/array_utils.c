#include "arraylist.h"

int isArrayListFull(ArrayList* pList)
{
	int	maxElementCount;
	int	currentElementCount;

	maxElementCount = pList->maxElementCount;
	currentElementCount = pList->currentElementCount;
	if (maxElementCount == currentElementCount)
		return (TRUE);
	return (FALSE);
}

void displayArrayList(ArrayList *pList)
{
	ArrayList		*array;
	ArrayListNode	*temp;
	size_t		idx;
	size_t		size;

	array = pList;
	idx = 0;
	size = array->currentElementCount - 1;
	temp = array->pElement;
	while (temp && idx <= size)
	{
		printf("node[%td] = %d\n", idx, temp++->data);
		idx++;
	}
	temp = NULL;
}

void clearArrayList(ArrayList* pList)
{
	ArrayListNode	node;
	int				i;

	node.data = 0;
	i = 0;
	while (i < pList->currentElementCount)
		pList->pElement[i++] = node;
}

int getArrayListLength(ArrayList* pList)
{
	printf("ArrayList Length is %d\n", pList->currentElementCount);
	return (pList->currentElementCount);
}