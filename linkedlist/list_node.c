#include "linkedlist.h"

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode	*node;
	ListNode	*prev;
	int			idx;

	if (position > pList->currentElementCount || position < 0 || !pList)
	{
		printf("Invalied Input\n");
		return (FALSE);
	}
	node = malloc(sizeof(ListNode));
	if (!node)
	{
		printf("malloc failed in addLLElement\n");
		return (FALSE);
	}
	if (!(pList->currentElementCount))
	{
		pList->headerNode = element;
		pList->currentElementCount++;
		return (TRUE);
	}
	*node = element;
	node->pLink = NULL;
	prev = &(pList->headerNode);
	idx = 0;
	while (idx++ < position - 1)
		prev = prev->pLink;
	node->pLink = prev->pLink;
	prev->pLink = node;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList *pList, int position)
{
	ListNode	*node;
	ListNode	*temp;
	int			idx;

	if (!pList || pList->currentElementCount < position || position < 0)
	{
		printf("Invalid Input\n");
		return (FALSE);
	}
	node = &(pList->headerNode);
	idx = 0;
	while (idx++ < position -1 && node)
		node = node->pLink;
	if (!(node->pLink))
	{
		temp = node->pLink;
		node->pLink = NULL;
		free(temp);	
		temp = NULL;
	}
	else
	{
		temp = node->pLink;
		node->pLink = temp->pLink;
		free(temp);
		temp = NULL;
	}
	pList->currentElementCount--;
	return (FALSE);
}

ListNode	*getLLElement(LinkedList *pList, int position)
{
	int	idx;
	ListNode	*node;

	if (position > pList->currentElementCount || position < 0)
	{
		printf("Index out of range\n");
		return (NULL);
	}
	node = &(pList->headerNode);
	idx = 0;
	while (idx++ <= position)
		node = node->pLink;
	printf("node->data = %d\n", node->data);
	return (node);
}
