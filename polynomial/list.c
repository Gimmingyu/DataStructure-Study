#include "linkedlist.h"

LinkedList	*createLinkedList()
{
	LinkedList	*linked_list;

	linked_list = malloc(sizeof(LinkedList));
	linked_list->currentElementCount = 0;
	linked_list->headerNode.data = 0;
	linked_list->headerNode.pLink = NULL;
	return (linked_list);
}

void	deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}
