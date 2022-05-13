#include "./heap.h"

int main()
{
	size_t size = 7;
	size_t idx = 0;
	Heap *heap = createHeap(size, MAX_HEAP);

	while (idx++ < size)
	{
		insertMaxHeap(idx, heap);
		for (int i = 0; i <= idx; i++)
			printf("heap->pElement[%d] = %d\n", i, heap->pElement[i]);
			printf("========================================\n");
	}
	printf("----------------now delete----------------\n");
	while (idx)
	{
		deleteMaxHeap(heap);
		for (int i = 0; i < idx; i++)
			printf("heap->pElement[%d] = %d\n", i, heap->pElement[i]);
			printf("========================================\n");
		idx--;
	}
	free(heap->pElement);
	free(heap);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}