#include "linkedlist.h"

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode	*node;
	ListNode	*prev;
	int			idx;

	// 예외처리
	if (position > pList->currentElementCount || position < 0 || !pList)
	{
		printf("Invalied Input\n");
		return (FALSE);
	}
	else if (!(pList->currentElementCount)) // 빈 리스트일 때
	{
		pList->headerNode = element;
		pList->headerNode.pLink = NULL;
		pList->currentElementCount++;
		return (TRUE);
	}
	prev = &(pList->headerNode);
	node = malloc(sizeof(ListNode));
	if (!position)
	{
		node->data = prev->data;
		node->pLink = prev->pLink;
		element.pLink = node;
		pList->headerNode = element;
		pList->currentElementCount++;
		return (TRUE);
	}
	*node = element;
	node->pLink = NULL;
	idx = 0;
	while (idx++ < position - 1 && prev)
		prev = prev->pLink;
	if (idx == position)
	{
		if ((prev->pLink))
			node->pLink = prev->pLink;
		prev->pLink = node;
		pList->currentElementCount++;
		return (TRUE);
	}
	return (FALSE);
}

int removeLLElement(LinkedList *pList, int position)
{
	ListNode	*node;
	ListNode	*temp;
	int			idx;

	// 예외처리
	if (!pList || pList->currentElementCount < position || position < 0)
	{
		printf("Invalid Input\n");
		return (FALSE);
	}
	node = &(pList->headerNode);
	if (!position)
	{
		if (!(node->pLink))
		{
			node->data = 0x00;
			node = NULL;
		}
		else
		{
			temp = node->pLink;
			pList->headerNode = *temp;
			node->data = 0x00;
			node->pLink = NULL;
			free(node);
			node = NULL;
			temp = NULL;
		}
		pList->currentElementCount--;
		return (TRUE);
	}
	idx = 0;
	while (idx++ < position - 1 && node)
		node = node->pLink;
	if (idx == position && node)
	{
		temp = node->pLink;
		node->pLink = temp->pLink;
		temp->data = 0x00;
		temp->pLink = NULL;
		free(temp);
		temp = NULL;
		pList->currentElementCount--;
		return (TRUE);
	}
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
