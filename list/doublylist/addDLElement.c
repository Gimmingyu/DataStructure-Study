#include "doublylist.h"

int addDLElement(DoublyList	*pList, int position, DoublyListNode element)
{
	DoublyListNode *buf;
	DoublyListNode *new;

	new = calloc(1, sizeof(DoublyListNode));
	NULLCHECK(new);
	new->data = element.data;
	// pList->headerNode.pRLink --> 0번 index
	// 현재 원소가 없는 경우 
	if (ZERO(pList->currentElementCount))
	{
		pList->headerNode.pRLink = new;
		new->pLLink = new;
		new->pRLink = new;
	}
	else
	{
		buf = getDLElement(pList, position - 1);
		new->pLLink = buf;
		new->pRLink = buf->pRLink;
		buf->pRLink->pLLink = new;
		buf->pRLink = new;
	}
	pList->currentElementCount += 1;
	return (TRUE);
}
