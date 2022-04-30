
# Queue

<img src="https://velog.velcdn.com/images%2Fawesomeo184%2Fpost%2Fc1d73c47-1103-4c47-94cd-8563e85b6542%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202020-10-07%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2010.25.31.png" width = "600" height = "300" />

### image 출처 : https://velog.io/@awesomeo184/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%ED%81%90Queue

<br />

***
### Queue는 선입선출의 구조를 따른다고 한다. 

### Enqueue 명령에서는 새로 들어온 원소가 꼬리쪽에 붙는다.

### Dequeue 명령에서는 가장 먼저 들어온 원소가(오래된 원소) 먼저 나간다. 

### Stack이 후입선출의 구조였던 것에 반해, queue는 처음 원소와 끝의 원소를 잘 다뤄줘야한다.

### ArrayQueue와 LinkedQueue의 형태로 만들면 되는데, ArrayQueue에서는 고민해봐야 하는 지점이 있다.

### ArrayQueue에서는 

### [0, 1, 2, 3] 의 큐에서 0이 빠져나간 경우.

### [-, 1, 2, 3] 의 형태가 되어서 빈 자리가 있음에도 그 다음 원소가 들어오지 못할 수 있다.

### 이러한 경우 circularArrayQueue의 형태로 만들면 해결이 가능하다. 

### 현재 끝 번호 (ex: 4)를 maxElementCount로 나눈 나머지(ex: 4 % 4 = 0)를  index로 쓰는 방법이다.

### 그렇게 되면 [4, 1, 2, 3]의 형태로 계속해서 채워나갈 수 있다. 이 때 front와 rear를 적절히 이동시켜주는 것이 핵심이다. 

***

## LinkedQueue.c
``` C

#include "linkedQueue.h"

LinkedQueue	*createLinkedQueue()
{
	LinkedQueue	*newQueue = calloc(1, sizeof(LinkedQueue));

	if (NULLCHECK(newQueue))
		return (NULL);
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
		free(delNode);
		delNode = nextNode;
	}
	free(pQueue);
}

int	isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}
```

## ArrayQueue
```C
#include "Arrayqueue.h"

ArrayQueue	*createArrayQueue(int maxElementCount)
{
	ArrayQueue	*q;

	q = calloc(1, sizeof(ArrayQueue));
	if (!q)
		return (NULL);
	q->pElement = calloc(maxElementCount, sizeof(char));
	if (!(q->pElement))
	{
		free(q);
		return (NULL);
	}
	q->maxElementCount = maxElementCount;
	return (q);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		return (ERR);
	if (isArrayQueueFull(pQueue))
		return (FALSE);
	if (pQueue->pElement[pQueue->maxElementCount - 1].data)
		return (FALSE);
	pQueue->pElement[pQueue->currentElementCount].data = element.data;
	pQueue->currentElementCount++;
	pQueue->rear++;
	return (TRUE);
}

ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*retNode;

	if (!pQueue)
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
		return (NULL);
	retNode = calloc(1, sizeof(ArrayQueueNode));
	if (!retNode)
		return (NULL);
	retNode->data = pQueue->pElement[pQueue->front].data;
	pQueue->pElement[pQueue->front].data = 0;
	pQueue->front++;
	pQueue->currentElementCount--;
	return (retNode);
}

ArrayQueueNode	*peekAQ(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (NULL);
	return (&pQueue->pElement[pQueue->front]);
}

void	deleteArrayQueue(ArrayQueue* pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount ? TRUE : FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

```

## circularArrayQueue 

```C
#include "circularArrayQueue.h"

ArrayQueue	*createArrayQueue(int maxElementCount)
{
	ArrayQueue	*newAQ;

	newAQ = calloc(1, sizeof(ArrayQueue));
	if (NULLCHECK(newAQ))
		return (NULL);
	newAQ->pElement = calloc(maxElementCount, sizeof(ArrayQueueNode));
	if (NULLCHECK(newAQ->pElement))
	{
		free(newAQ);
		return (NULL);
	}
	newAQ->maxElementCount = maxElementCount;
	return (newAQ);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (NULLCHECK(pQueue))
		return (ERR);
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount ? TRUE : FALSE);
}

// 원소 추가 가능 여부 판단해서 가능하면 추가하고, rear와 count 증가
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	int	idx;

	if (NULLCHECK(pQueue))
		return (ERR);
	else if (isArrayQueueFull(pQueue))
	{
		printf("ArrayQueue is Full Now.\n");
		return (FALSE);
	}
	if (isArrayQueueEmpty(pQueue))
		idx = 0;
	else
		idx = pQueue->rear + 1 % pQueue->maxElementCount;
	pQueue->pElement[idx] = element;
	pQueue->rear = idx;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode	*peekAQ(ArrayQueue* pQueue)
{
	if (NULLCHECK(pQueue))
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
	{
		printf("ArrayQueue is Empty Now.\n");
		return (NULL);
	}
	if (pQueue->rear > pQueue->maxElementCount)
		return (&(pQueue->pElement[pQueue->front % pQueue->maxElementCount]));
	return (&(pQueue->pElement[0]));
}

ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*retNode;

	if (NULLCHECK(pQueue))
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
	{
		printf("ArrayQueue is Empty Now.\n");
		return (NULL);
	}
	retNode = calloc(1, sizeof(ArrayQueueNode));
	retNode->data = pQueue->pElement[pQueue->front % pQueue->maxElementCount].data;
	pQueue->pElement[pQueue->front % pQueue->maxElementCount].data = 0;
	pQueue->front++;
	pQueue->currentElementCount--;
	return (retNode);
}

void	deleteArrayQueue(ArrayQueue	*pQueue)
{
	if (NULLCHECK(pQueue))
		return ;
	free(pQueue->pElement);
	free(pQueue);
}

```

## doublyLinkedDeque

```C
#include "doublyLinkedDeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*newLQ;

	newLQ = calloc(1, sizeof(LinkedDeque));
	if (NULLCHECK(newLQ))
		return (NULL);
	return (newLQ);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*newNode;

	if (NULLCHECK(pDeque))
		return (ERR);
	newNode = calloc(1, sizeof(DequeNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else
	{
		newNode->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = newNode;
		pDeque->pFrontNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*newNode;

	if (NULLCHECK(pDeque))
		return (ERR);
	newNode = calloc(1, sizeof(DequeNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else
	{
		newNode->pLLink = pDeque->pRearNode;
		pDeque->pRearNode->pRLink = newNode;
		pDeque->pRearNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode	*deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*delNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	delNode = pDeque->pFrontNode;
	pDeque->pFrontNode = delNode->pRLink;
	pDeque->pFrontNode->pLLink = NULL;
	return (delNode);
}

DequeNode	*deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*delNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	delNode = pDeque->pRearNode;
	pDeque->pRearNode = delNode->pLLink;
	pDeque->pRearNode->pRLink = NULL;
	return (delNode);
}
DequeNode	*peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*retNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	return (pDeque->pFrontNode);
}

DequeNode	*peekRearLD(LinkedDeque* pDeque)
{
	DequeNode	*retNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	return (pDeque->pRearNode);
}

void	deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*frontNode;
	DequeNode	*nextNode;

	if (NULLCHECK(pDeque))
		return ;
	frontNode = pDeque->pFrontNode;
	while (frontNode)
	{
		nextNode = frontNode->pRLink;
		free(frontNode);
		frontNode = nextNode;
	}
	free(pDeque);
}

int	isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (NULLCHECK(pDeque))
		return (ERR);
	return (pDeque->currentElementCount == 0 ? TRUE : FALSE);
}
```