#include "simulation.h"

LinkedQueue	*createLinkedQueue()
{
	LinkedQueue	*newQueue = calloc(1, sizeof(LinkedQueue));

	if (!newQueue)
		return  (NULL);
	return (newQueue);
}

int	insertLQ(LinkedQueue* pQueue, QueueNode element)
{
	QueueNode	*newNode;

	if (NULLCHECK(pQueue))
		return (ERR);
	newNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->customerData = element.customerData;
	if (isLinkedQueueEmpty(pQueue))
	{
		pQueue->pFrontNode = newNode;
		pQueue->pRearNode = newNode;
	}
	else
	{
		pQueue->pRearNode->pRLink = newNode;
		pQueue->pRearNode = newNode;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode	*deleteLQ(LinkedQueue* pQueue)
{
	QueueNode	*delNode;

	if (NULLCHECK(pQueue))
		return (NULL);
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("Queue is now empty\n");
		return (NULL);
	}
	delNode = pQueue->pFrontNode;
	pQueue->pFrontNode = delNode->pRLink;
	return (delNode);
}

QueueNode	*peekFrontLQ(LinkedQueue* pQueue)
{
	return (pQueue->pFrontNode);
}

QueueNode	*peekRearLQ(LinkedQueue* pQueue)
{
	return (pQueue->pRearNode);
}

void	deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode	*delNode;
	QueueNode	*nextNode;

	if (NULLCHECK(pQueue))
		return ;
	if (isLinkedQueueEmpty(pQueue))
		return ;

	delNode = pQueue->pFrontNode;
	while (delNode && pQueue->currentElementCount--)
	{
		nextNode = delNode->pRLink;
		free(delNode->customerData);
		free(delNode);
		delNode = nextNode;
	}
	free(pQueue);
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}