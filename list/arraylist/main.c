#include "arraylist.h"
#include <time.h>

int	main(void)
{
	ArrayList		*array;
	ArrayListNode	*elem;
	clock_t	start, end;


	array = createArrayList(100000);
	start = clock();
	for (int i=0; i < 100000; i++)
	{
		// printf("i = %d\n", i);
		elem = malloc(sizeof(ArrayListNode));
		elem->data = i;
		addALElement(array, i, *elem);
		free(elem);
		// displayArrayList(array);
	}
	for (int i=99999; i > -1; i--)
	{
		printf("i = %d\n", i);
		// getArrayListLength(array);
		removeALElement(array, i);
		// displayArrayList(array);
	}
	displayArrayList(array);
	end = clock();
	printf("[time : %f]\n", (float)(end - start)/CLOCKS_PER_SEC);
	clearArrayList(array);
	deleteArrayList(array);
	array = NULL;
	elem = NULL;
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}