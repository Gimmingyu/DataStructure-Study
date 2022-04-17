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
	if (!pList)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}
