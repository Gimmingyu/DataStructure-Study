#include "simulation.h"

void	insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	SimCustomer	*newCustomer;
	QueueNode	*newNode;

	if (NULLCHECK(pQueue))
		return ;

	newCustomer = calloc(1, sizeof(SimCustomer));
	if (!newCustomer)
		return ;
	newNode = calloc(1, sizeof(QueueNode));
	if (!newNode)
	{
		free(newCustomer);
		return ;
	}
	newCustomer->arrivalTime = arrivalTime;
	newCustomer->serviceTime = processTime;
	newCustomer->status = arrival;
	newNode->customerData = newCustomer;
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
}

void	processArrival(int currentTime, LinkedQueue *pArrivalQueue, \ 
LinkedQueue *pWaitQueue)
{
	QueueNode	*frontNode;

	if (!pArrivalQueue || !pWaitQueue || isLinkedQueueEmpty(pArrivalQueue))
		return ;
	while (pArrivalQueue->pFrontNode->customerData->arrivalTime == currentTime)
	{
		frontNode = deleteLQ(pArrivalQueue);
		insertLQ(pWaitQueue, *frontNode);
		free(frontNode);
		if (isLinkedQueueEmpty(pArrivalQueue))
			break ;
	}
}

QueueNode	*processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode	*frontNode;
	SimCustomer	*customer;

	if (!pWaitQueue || isLinkedQueueEmpty(pWaitQueue))
		return (NULL);
	if (currentTime > pWaitQueue->pFrontNode->customerData->arrivalTime)
		return (NULL);
	frontNode = pWaitQueue->pFrontNode;
	customer = frontNode->customerData;
	customer->startTime = currentTime;
	customer->endTime = customer->startTime + customer->serviceTime;
	customer->status = start;
	pWaitQueue->pFrontNode = frontNode->pRLink;
	return (frontNode);
}

QueueNode	*processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, \
int *pServiceUserCount, int *pTotalWaitTime)
{
	QueueNode	*frontNode;
	SimCustomer	*customer;

	if (!pServiceNode)
		return (NULL);
	customer = pServiceNode->customerData;
	if (currentTime == customer->endTime)
	{
		*pServiceUserCount++;
		*pTotalWaitTime += customer->serviceTime;
		customer->status = end;
		return (pServiceNode);
	}
	return (NULL);
}

