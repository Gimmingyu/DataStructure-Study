#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef	enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
} t_flag;

typedef struct QueueNodeType
{
	char 					data;
	struct QueueNodeType	*pRLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int 		currentElementCount;
	QueueNode	*pFrontNode;
	QueueNode	*pRearNode;
} LinkedQueue;

LinkedQueue	*createLinkedQueue();

int 		insertFrontLD(LinkedQueue* pQueue, QueueNode element);
int 		insertRearLD(LinkedQueue* pQueue, QueueNode element);

QueueNode	*deleteFrontLD(LinkedQueue* pQueue);
QueueNode	*deleteRearLD(LinkedQueue* pQueue);
QueueNode	*peekFrontLD(LinkedQueue* pQueue);
QueueNode	*peekRearLD(LinkedQueue* pQueue);

void 		deleteLinkedQueue(LinkedQueue* pQueue);

int 		isLinkedQueueEmpty(LinkedQueue* pQueue);


//additional
int	NULLCHECK(void *ptr);

#endif
