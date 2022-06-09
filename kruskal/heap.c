#include "./kruskal.h"

Heap *createHeap(size_t size, HeapType type)
{
	Heap *newHeap = calloc(1, sizeof(Heap));

	if (!newHeap)
		return (NULL);
	newHeap->pElement = calloc(size + 1, sizeof(Edge));
	if (!newHeap->pElement)
	{
		free(newHeap);
		return (NULL);
	}
	newHeap->maxElementCount = size;
	newHeap->type = type;
	return (newHeap);
}

int insertMinHeap(Edge edge, Heap *heap)
{
	int index;
	int	parent_idx;

	if (!heap || heap->type == MAX_HEAP)
		return (ERR);
	if (heap->currentElementCount == heap->maxElementCount)
	{
		printf("Array is full Now\n");
		return (FALSE);
	}
	heap->currentElementCount++;
	index = heap->currentElementCount;
	parent_idx = index / 2;
	while (index > 1 && edge.weight <= heap->pElement[parent_idx].weight)
	{
		heap->pElement[index] = heap->pElement[parent_idx];
		index /= 2;
		parent_idx = index / 2;
	}
	heap->pElement[index] = edge;
	return (TRUE);
}

int deleteMinHeap(Heap *heap)
{
	int	index = 1;
	int	left;
	int	right;
	int	small;
	Edge	temp;

	if (!heap || heap->type == MAX_HEAP || heap->currentElementCount == 0)
		return (ERR);
	heap->pElement[index] = heap->pElement[heap->currentElementCount];
	heap->currentElementCount--;
	while (index < heap->currentElementCount)
	{
		left = index * 2;
		right = index * 2 + 1;
		small = left;
		if (right <= heap->currentElementCount && heap->pElement[left].weight > heap->pElement[right].weight)
			small = right;
		if (heap->pElement[index].weight > heap->pElement[small].weight)
		{
			temp = heap->pElement[index];
			heap->pElement[index] = heap->pElement[small];
			heap->pElement[small] = temp;
		}
		index = small;
	}
	return (TRUE);
}

Edge	*getMinHeapEdge(Heap *heap)
{
	int			index;
	int			left;
	int			right;
	int			small;
	Edge		tmp;
	Edge		*rootNode;

	if (heap == NULL || heap->currentElementCount == 0)
		return (NULL);
	index = 1;
	rootNode = calloc(1, sizeof(Edge));
	*rootNode = heap->pElement[index];
	heap->pElement[index] = heap->pElement[heap->currentElementCount];
	heap->currentElementCount--;
	while (index < heap->currentElementCount)
	{
		left = index * 2;
		right = index * 2 + 1;
		small = left;
		if (right <= heap->currentElementCount && heap->pElement[left].weight > heap->pElement[right].weight)
			small = right;
		if (heap->pElement[index].weight > heap->pElement[small].weight)
		{
			tmp = heap->pElement[index];
			heap->pElement[index] = heap->pElement[small];
			heap->pElement[small] = tmp;
		}
		index = small;
	}
	printf("rootNode->vertexA = %d\n", rootNode->vertexA);
	printf("rootNode->vertexB = %d\n", rootNode->vertexB);
	printf("rootNode->weight = %d\n", rootNode->weight);
	return (rootNode);
}


void displayMinHeap(Heap *heap)
{
	for (int i = 1; i <= heap->currentElementCount; i++)
		printf("%d %d %d \n", heap->pElement[i].vertexA, heap->pElement[i].vertexB, heap->pElement[i].weight);
}
