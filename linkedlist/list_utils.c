#include "linkedlist.h"

void	clearLinkedList(LinkedList *pList)
{
	int	idx;

	idx = pList->currentElementCount - 1;
	while (idx > -1)
	{
		removeLLElement(pList, idx);
		idx--;
	}
}

int	getLinkedListLength(LinkedList *pList)
{
	printf("List length = %d\n", pList->currentElementCount);
	return (pList->currentElementCount);
}

void	displayLinkedList(LinkedList *pList)
{
	ListNode	*node;
	int			idx;

	if (!pList || !(pList->currentElementCount))
		return ;
	node = &(pList->headerNode);
	idx = 0;
	while (node)
	{
		printf("%d번째 data는 %d 입니다.\n", idx, node->data);
		idx++;
		node = node->pLink;
	}
}