#include "linkedlist.h"

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode	*node;
	int			idx;

	if (!pList || !(&element) || position < 0)
	{
		printf("Invalid Input\n");
		return (FALSE);
	}
	node = &(pList->headerNode);
	idx = 0;
	while (node->pLink && idx++ < position - 1)
		node = node->pLink;
	node->pLink = &element;
	return (TRUE);
}

int removeLLElement(LinkedList *pList, int position)
{
	ListNode	*node;
	ListNode	*nxt;
	ListNode	*prev;
	int			idx;

	if (pList->currentElementCount < position || !pList)
	{
		printf("Invalid Input\n");
		return (FALSE);
	}
	node = &(pList->headerNode);
	idx = 0;
	while (idx++ <= position && node)
	{
		prev = node;
		nxt = node->pLink;
		node = nxt;
	}
	if (idx == position)
	{
		free(node);
		node = NULL;
		prev->pLink = nxt;
		return (TRUE);
	}
	return (FALSE);
}

ListNode    *getLLelement(LinkedList *pList)
{

}

