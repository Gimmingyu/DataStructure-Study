#ifndef _HEAP_
#define _HEAP_

#include <stdio.h>
#include <stdlib.h>

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
	int 		*pElement;
	HeapType	type;
} Heap;

Heap	*createHeap(size_t size, HeapType type);

int 	insertMaxHeap(int data, Heap *heap);
int 	insertMinHeap(int data, Heap *heap);

int		deleteMaxHeap(Heap *heap);
int		deleteMinHeap(Heap *heap);

// utils
int 	*reallocArray(Heap *heap);

#endif