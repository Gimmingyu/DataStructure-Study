#include "linkedlist.h"

LinkedList	*createLinkedList()
{
	LinkedList	*linked_list;

	linked_list = malloc(sizeof(LinkedList));
	if (!linked_list)
	{
		printf("failed malloc in createLinkedList\n");
		return (NULL);
	}
	linked_list->currentElementCount = 0;
	return (linked_list);
}

void	deleteLinkedList(LinkedList *pList)
{
	ListNode	*node;
	ListNode	*next;

	if (!pList)
		return ;
	node = &(pList->headerNode);
	while (node)
	{
		next = &(node->pLink);
		free(node);
		node = next;
	}
	node = NULL;
	next = NULL;
	free(pList);
	pList = NULL;
}