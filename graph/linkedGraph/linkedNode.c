#include "linkedNode.h"

LinkedList *createLinkedList()
{
	return ((LinkedList *)calloc(sizeof(LinkedList), 1));
}

ListNode	*createNode(ListNode element)
{
	ListNode	*newNode = calloc(1, sizeof(ListNode));

	newNode->data = element.data;
	return (newNode);
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
	int			idx = 0;
	ListNode	*newNode;
	ListNode	*posNode;
	ListNode	*prev;
	ListNode	*next;

	if (!pList || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	newNode = createNode(element);
	if (position == 0)
	{
		newNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = newNode;
	}
	else
	{
		prev = getLLElement(pList, position - 1);
		newNode->pLink = prev->pLink;
		prev->pLink = newNode;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList *pList, int position)
{
	int			idx = 0;
	ListNode	*delNode;
	ListNode	*prevNode;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	delNode = getLLElement(pList, position);
	if (position == 0)
		pList->headerNode.pLink = delNode->pLink;
	else
	{
		prevNode = getLLElement(pList, position-1);
		delNode = getLLElement(pList, position);
		prevNode->pLink = delNode->pLink;
	}
	free(delNode);
	return (TRUE);
}

ListNode *getLLElement(LinkedList *pList, int position)
{
	int			idx = 0;
	ListNode	*node;

	if (!pList || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	if (idx == 0)
		return (pList->headerNode.pLink);
	node = &pList->headerNode;
	while (idx++ < position)
		node = node->pLink;
	return (node);
}

void clearLinkedList(LinkedList *pList)
{
	ListNode	*delNode;
	ListNode	*nextNode;

	if (!pList || pList->currentElementCount == 0)
		return ;
	delNode = pList->headerNode.pLink;
	for (int i; i < pList->currentElementCount; i++)
	{
		nextNode = delNode->pLink;
		delNode->data.vertexID = 0;
		delNode->data.weight = 0;
		free(delNode);
		delNode = nextNode;
	}
}

int getLinkedListLength(LinkedList *pList)
{
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
}
