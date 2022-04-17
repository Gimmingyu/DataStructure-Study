#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (!pList || position < 0)
	{
		printf("Invalid Input\n");
		return (NULL);
	}
	else if (position > pList->currentElementCount - 1)
	{
		printf("Empty node\n");
		return (NULL);
	}
	return (&(pList->pElement)[position]);
}

int	removeALElement(ArrayList *pList, int position)
{
	ArrayListNode	*temp;
	int				i;

	if (!pList || position > pList->currentElementCount || position < 0)
	{
		printf("Invalid Input\n");
		return (FALSE);
	}
	temp = pList->pElement;
	i = (pList->currentElementCount) - 1;
	while (position <= i)
	{
		temp[i] = temp[i + 1];
		position++;
	}
	return (TRUE);
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	ArrayListNode	*temp;
	int				i;

	if (!pList || isArrayListFull(pList) || position > pList->currentElementCount || \
			position < 0)
	{
		printf("Invalid Input\n");
		return (FALSE);
	}
	temp = pList->pElement;
	i = (pList->currentElementCount) - 1;
	while (position < i)
	{
		temp[i + 1] = temp[i];
		i--;
	}
	temp[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}
