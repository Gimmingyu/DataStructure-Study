#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	ArrayListNode	*temp;
	size_t			p;

	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("Index out of range in getALElement\n");
		return (FALSE);
	}
	p = (size_t)position;
	temp = pList->pElement;
	printf("pElement[%td] = %d\n", p, temp[p].data);
	return (temp + p);
}

int removeALElement(ArrayList *pList, int position)
{
	ArrayListNode	*pElem;
	ArrayListNode	*temp;
	size_t			idx;
	size_t			size;
	size_t			p;

	size = pList->currentElementCount - 1;
	if (position >= (pList->maxElementCount) || position < 0)
	{
		printf("Index out of range in removeALElement\n");
		return (FALSE);
	}
	pElem = calloc(size, sizeof(ArrayListNode));
	if (!(pElem))
	{
		printf("malloc failed in removeALElement\n");
		return (FALSE);
	}
	idx = 0;
	p = (size_t)position;
	temp = pList->pElement;
	while (temp && idx <= size)
	{
		if (idx == p)
			temp++;
		else
			pElem[idx++] = *temp++;
	}
	temp = NULL;
	free(pList->pElement);
	pList->pElement = pElem;
	return (TRUE);
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	ArrayListNode	*pElem;
	ArrayListNode	*temp;
	size_t			idx;
	size_t			size;
	size_t			p;

	idx = 0;
	size = pList->currentElementCount + 1;
	if (position > (pList->maxElementCount) - 1 || 
	(pList->currentElementCount) + 1 > (pList->maxElementCount) || 
	position < 0)
	{
		printf("Index out of range in addALElement\n");
		return (FALSE);
	}
	pElem = calloc(size, sizeof(ArrayListNode));
	if (!(pElem))
	{
		printf("malloc failed in addALElement\n");
		return (FALSE);
	}
	temp = pList->pElement;
	p = (size_t)position;
	while (temp && idx <= size)
	{
		if (idx == p)
			pElem[idx++] = element;
		else
			pElem[idx++] = *temp++;
	}
	temp = NULL;
	free(pList->pElement);
	pList->pElement = pElem;
	pList->currentElementCount = size;
	return (TRUE);
}
