#include "./kruskal.h"


int main(void)
{

	Heap	*minHeap = createHeap(EDGE_NUM, MIN_HEAP);
	Edge	edge;

	edge.vertexA = 1;
	edge.vertexB = 4;
	edge.weight = 13;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 1;
	edge.vertexB = 2;
	edge.weight = 23;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 1;
	edge.vertexB = 6;
	edge.weight = 65;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 2;
	edge.vertexB = 4;
	edge.weight = 24;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 3;
	edge.vertexB = 5;
	edge.weight = 50;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 3;
	edge.vertexB = 6;
	edge.weight = 48;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 4;
	edge.vertexB = 6;
	edge.weight = 30;
	insertMinHeap(edge, minHeap);

	edge.vertexA = 5;
	edge.vertexB = 6;
	edge.weight = 33;
	insertMinHeap(edge, minHeap);

	displayMinHeap(minHeap);
	
	// VERT_NUM 개의 정점이 EDGE_NUM개의 간선으로 연결되어 있다.
	int	set[VERT_NUM + 1];
	for (int i = 0; i < VERT_NUM; i++) {
		set[i] = i;
	}
	
	printf("\n");
	int	count = minHeap->currentElementCount;
	int	sum = 0;
	Edge	*e1;
	for (int i = 0; i < count; i++) {
		e1  = getMinHeapEdge(minHeap);
		printf("\n");
		if (!isParentSame(set, e1->vertexA, e1->vertexB))
		{
			sum += e1->weight;
			unionParent(set, e1->vertexA, e1->vertexB);
		}
		free(e1);
		e1 = NULL;
	}
	
	printf("%d\n", sum);

	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result ");
	return (0);
}