#include "./heap.h"

Heap *createHeap(size_t size, HeapType type)
{
	Heap *newHeap = calloc(1, sizeof(Heap));

	if (!newHeap)
		return (NULL);
	newHeap->pElement = calloc(size + 1, sizeof(int));
	if (!newHeap->pElement)
	{
		free(newHeap);
		return (NULL);
	}
	newHeap->maxElementCount = size;
	newHeap->type = type;
	return (newHeap);
}

// 마지막에 넣어놓고 부모와 비교하면서 올라온다
int insertMaxHeap(int data, Heap *heap)
{
	int index;

	if (!heap || heap->type != MAX_HEAP)
		return (ERR);
	if (heap->currentElementCount == heap->maxElementCount)
	{
		printf("Array is full Now\n");
		return (FALSE);
	}
	index = heap->currentElementCount + 1;
	while (index > 1 && heap->pElement[index / 2] < data)
	{
		heap->pElement[index] = heap->pElement[index / 2];
		index /= 2;
	}
	heap->pElement[index] = data;
	heap->currentElementCount++;
	return (TRUE);
}

int insertMinHeap(int data, Heap *heap)
{
	int index;

	if (!heap || heap->type != MAX_HEAP)
		return (ERR);
	if (heap->currentElementCount == heap->maxElementCount)
	{
		printf("Array is full Now\n");
		return (FALSE);
	}
	index = heap->currentElementCount + 1;
	heap->pElement[index] = data;
	while (index > 1 && heap->pElement[index / 2] > data)
	{
		heap->pElement[index] = heap->pElement[index / 2];
		heap->pElement[index / 2] = data;
	}
	return (TRUE);
}

int deleteMaxHeap(Heap *heap)
{
	if (!heap)
		return (ERR);
	if (!heap->currentElementCount)
	{
		printf("Array is now Empty\n");
		return (FALSE);
	}
	int	result = heap->pElement[1];
	int	temp = heap->pElement[heap->currentElementCount];
	int	parent = 1;
	int	child = 2;
	while (child <= heap->currentElementCount)
	{
		if (child < heap->currentElementCount && \
		heap->pElement[child] < heap->pElement[child + 1])
			child += 1;
		if (temp >= heap->pElement[child])
			break ;
		heap->pElement[parent] = heap->pElement[child];
		parent = child;
		child *= 2;
	}
	heap->pElement[parent] = temp;
	heap->pElement[heap->currentElementCount] = 0;
	heap->currentElementCount--;
	return (result);
}

int deleteMinHeap(Heap *heap)
{
	if (!heap)
		return (ERR);
	if (!heap->currentElementCount)
	{
		printf("Array is now Empty\n");
		return (FALSE);
	}
	int	result = heap->pElement[1];
	int	temp = heap->pElement[heap->currentElementCount];
	int	parent = 1;
	int	child = 2;
	while (child >= heap->currentElementCount)
	{
		if (child > heap->currentElementCount && \
		heap->pElement[child] < heap->pElement[child + 1])
			child += 1;
		if (temp <= heap->pElement[child])
			break ;
		heap->pElement[parent] = heap->pElement[child];
		parent = child;
		child *= 2;
	}
	heap->pElement[parent] = temp;
	heap->pElement[heap->currentElementCount] = 0;
	heap->currentElementCount--;
	return (result);
}

