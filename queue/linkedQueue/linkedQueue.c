#include "linkedQueue.h"


LinkedQueue	*createLinkedQueue()
{
	LinkedQueue	*newQueue = calloc(1, sizeof(LinkedQueue));

	if (NULLCHECK(newQueue))
		return (NULL);
	return (newQueue);
}

int 		insertFrontLQ(LinkedQueue* pQueue, QueueNode element)
{
	QueueNode	*newNode;

	if (NULLCHECK(pQueue))
		return (ERR);
	newNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
	if (isLinkedQueueEmpty(pQueue))
	{
		pQueue->pFrontNode = newNode;
		pQueue->pRearNode = newNode;
	}
	else
	{
		newNode->pRLink = pQueue->pFrontNode;
		pQueue->pFrontNode = newNode;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

int 		insertRearLQ(LinkedQueue* pQueue, QueueNode element)
{
	QueueNode	*newNode;

	if (NULLCHECK(pQueue))
		return (ERR);
	newNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
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

QueueNode	*deleteFrontLQ(LinkedQueue* pQueue)
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

QueueNode	*deleteRearLQ(LinkedQueue* pQueue)
{
	QueueNode	*rearNode;
	QueueNode	*delNode;
	int			idx;

	if (NULLCHECK(pQueue))
		return (NULL);
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("Queue is now empty\n");
		return (NULL);
	}
	// 1인경우
	// 큐의 레어노드는 프론트노드와 같음.
	// 큐의 양쪽 노드 초기화 해주고 리턴.
	// 2인경우
	// idx = 1이므로 rearNode는 frontNode가 되어야한다.
	if (pQueue->currentElementCount == 1)
	{
		delNode = pQueue->pRearNode;
		pQueue->pFrontNode = NULL;
		pQueue->pRearNode = NULL;
	}
	else
	{
		rearNode = pQueue->pFrontNode;
		idx = pQueue->currentElementCount - 1;
		while (idx - 1 > 0)
			rearNode = rearNode->pRLink;
		delNode = rearNode->pRLink;
		pQueue->pRearNode = rearNode;
		rearNode->pRLink = NULL;
	}
	pQueue->currentElementCount--;
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

void 		deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode	*delNode;
	QueueNode	*nextNode;

	if (NULLCHECK(pQueue))
		return ;
	if (isLinkedQueueEmpty(pQueue))
		return ;

	delNode = pQueue->pFrontNode;
	while (pQueue->currentElementCount--)
	{
		nextNode = delNode->pRLink;
		free(delNode);
		delNode = nextNode;
	}
	free(pQueue);
}

int 		isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

void	displayLinkedQueue(LinkedQueue	*q)
{
	QueueNode	*node;
	QueueNode	*nextNode;

	node = q->pFrontNode;
	while (node)
	{
		nextNode = node->pRLink;
		printf("node.data = %c\n", node->data);
		node = nextNode;
	}
}

int	main(void)
{
	LinkedQueue	*lst = createLinkedQueue();

	QueueNode	node1;
	node1.data = 'A';
	insertFrontLQ(lst, node1);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node2;
	node2.data = 'B';
	insertRearLQ(lst, node2);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node3;
	node3.data = 'C';
	insertFrontLQ(lst, node3);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node4;
	node4.data = 'D';
	insertRearLQ(lst, node4);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node5;
	node5.data = 'E';
	insertRearLQ(lst, node5);
	displayLinkedQueue(lst);
	printf("================================================\n");

	printf("now delete!!\n");
	deleteRearLQ(lst);
	displayLinkedQueue(lst);
	printf("================================================\n");

	deleteRearLQ(lst);
	displayLinkedQueue(lst);
	printf("================================================\n");

	deleteFrontLQ(lst);
	displayLinkedQueue(lst);
	printf("================================================\n");


	deleteLinkedQueue(lst);
	
	system("leaks a.out");
	return (0);
}