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
	// for (int i=9; i > -1; i--)
	// {
	// 	printf("i = %d\n", i);
	// 	getLinkedListLength(lst);
	// 	removeLLElement(lst, i);
	// 	displayLinkedList(lst);
	// }
	printf("-------------------------\n");
	elem = (ListNode *)malloc(sizeof(ListNode));
	elem->data = 9999;
	elem->pLink = NULL;
	addLLElement(lst, 0, *elem);
	free(elem);
	elem = NULL;
	displayLinkedList(lst);
	printf("-------------------------\n");
	elem = (ListNode *)malloc(sizeof(ListNode));
	elem->data = 7777;
	elem->pLink = NULL;
	addLLElement(lst, 10, *elem);
	free(elem);
	elem = NULL;
	displayLinkedList(lst);
	printf("-------------------------\n");
	elem = (ListNode *)malloc(sizeof(ListNode));
	elem->data = 1111;
	elem->pLink = NULL;
	addLLElement(lst, 8, *elem);
	free(elem);
	elem = NULL;
	displayLinkedList(lst);
	printf("-------------------------\n");
	elem = (ListNode *)malloc(sizeof(ListNode));
	elem->data = 5000;
	elem->pLink = NULL;
	addLLElement(lst, 0, *elem);
	free(elem);
	elem = NULL;
	displayLinkedList(lst);
	printf("-------------------------\n");
	deleteLinkedList(lst);


	lst = NULL;
	elem = NULL;
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}
