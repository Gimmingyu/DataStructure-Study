#ifndef _KRUSKAL_
#define _KRUSKAL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct EdgeType
{
	int	vertexA;
	int	vertexB;
	int	weight;
} Edge;


typedef enum HeapType
{
	MAX_HEAP,
	MIN_HEAP
} HeapType;

typedef enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
} t_flag;

typedef struct HeapArray
{
	int 		currentElementCount;
	int			maxElementCount;
	Edge 		*pElement;
	HeapType	type;
} Heap;

// 문제 설정 
// 정점 6개에 간선 8개 존재
#define EDGE_NUM 8
#define VERT_NUM 6

int parent[VERT_NUM]; // 각 정점의 부모노드
int num[VERT_NUM]; // 각 집합의 크기 


Heap	*createHeap(size_t size, HeapType type);

int 	insertMaxHeap(int data, Heap *heap);
int 	insertMinHeap(Edge data, Heap *heap);

int		deleteMaxHeap(Heap *heap);
int		deleteMinHeap(Heap *heap);

// utils
void displayMinHeap(Heap *heap);
Edge	*getMinHeapEdge(Heap *heap);

int getParent(int parent[], int x);
void	unionParent(int parent[], int a, int b);
int isParentSame(int parent[], int a, int b);
#endif