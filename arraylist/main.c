#include "arraylist.h"

int	main(void)
{
	ArrayList		*array;
	ArrayListNode	*elem;

	array = createArrayList(10);
	for (int i=0; i < 10; i++)
	{
		printf("i = %d\n", i);
		elem = malloc(sizeof(ArrayListNode));
		elem->data = i;
		addALElement(array, i, *elem);
		free(elem);
		displayArrayList(array);
	}
	clearArrayList(array);
	deleteArrayList(array);
	array = NULL;
	elem = NULL;
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}