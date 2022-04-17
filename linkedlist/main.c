#include "linkedlist.h"

int	main(void)
{
	LinkedList	*lst;
	ListNode	*elem;

	lst = createLinkedList();
	for (int i=0; i < 10; i++)
	{
		printf("i = %d\n", i);
		elem = (ListNode *)malloc(sizeof(ListNode));
		elem->data = i;
		elem->pLink = NULL;
		addLLElement(lst, i, *elem);
		free(elem);
		elem = NULL;
		displayLinkedList(lst);
	}
	for (int i=9; i > -1; i--)
	{
		printf("i = %d\n", i);
		getLinkedListLength(lst);
		removeLLElement(lst, i);
		displayLinkedList(lst);
	}
	printf("lst->headerNode.data = %d\n", lst->headerNode.data);
	getLinkedListLength(lst);
	deleteLinkedList(lst);
	displayLinkedList(lst);
	lst = NULL;
	elem = NULL;
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
}
