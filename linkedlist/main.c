#include "linkedlist.h"
#include <time.h>

int	main(void)
{
	clock_t start, end;
	LinkedList	*lst;
	ListNode	*elem;

	start = clock();
	lst = createLinkedList();
	for (int i=0; i < 100000; i++)
	{
		// printf("i = %d\n", i);
		elem = (ListNode *)malloc(sizeof(ListNode));
		elem->data = i;
		elem->pLink = NULL;
		addLLElement(lst, i, *elem);
		free(elem);
		elem = NULL;
		// displayLinkedList(lst);
	}
	for (int i=99999; i > -1; i--)
	{
		// printf("i = %d\n", i);
		// getLinkedListLength(lst);
		removeLLElement(lst, i);
		// displayLinkedList(lst);
	}
	displayLinkedList(lst);
	end = clock();
	printf("[time : %f]\n", (float)(end - start)/CLOCKS_PER_SEC);
	printf("-------------------------\n");
	// elem = (ListNode *)malloc(sizeof(ListNode));
	// elem->data = 9999;
	// elem->pLink = NULL;
	// addLLElement(lst, 0, *elem);
	// free(elem);
	// elem = NULL;
	// displayLinkedList(lst);
	// printf("-------------------------\n");
	// elem = (ListNode *)malloc(sizeof(ListNode));
	// elem->data = 7777;
	// elem->pLink = NULL;
	// addLLElement(lst, 1, *elem);
	// free(elem);
	// elem = NULL;
	// displayLinkedList(lst);
	// printf("-------------------------\n");
	// elem = (ListNode *)malloc(sizeof(ListNode));
	// elem->data = 1111;
	// elem->pLink = NULL;
	// addLLElement(lst, 0, *elem);
	// free(elem);
	// elem = NULL;
	// displayLinkedList(lst);
	// printf("-------------------------\n");
	// elem = (ListNode *)malloc(sizeof(ListNode));
	// elem->data = 5000;
	// elem->pLink = NULL;
	// addLLElement(lst, 0, *elem);
	// free(elem);
	// elem = NULL;
	// displayLinkedList(lst);
	// printf("-------------------------\n");
	deleteLinkedList(lst);


	lst = NULL;
	elem = NULL;
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}
