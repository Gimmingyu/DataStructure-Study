#include "doublylist.h"

void	clearDoublyList(DoublyList *pList)
{
    DoublyListNode  *buf;
    DoublyListNode  *next;
	DoublyListNode	empty;

    buf = pList->headerNode.pRLink;
    while (UPPER_ZERO(pList->currentElementCount))
    {
        next = buf->pRLink;
        buf->data = 0x00;
        buf->pLLink = NULL;
        buf->pRLink = NULL;
        free(buf);
		pList->currentElementCount--;
        buf = next;
    }
	pList->headerNode.pRLink = NULL;
	pList->headerNode.pLLink = NULL;
	empty.pLLink = NULL;
	empty.pRLink = NULL;
	pList->headerNode = empty;
	buf = NULL;
	next = NULL;
	pList->currentElementCount = 0;
}
