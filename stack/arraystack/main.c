#include "arraystack.h"

int	main(void)
{
	ArrayStack	*stack = createArrayStack(10);
	StackNode	*node1 = calloc(1, sizeof(StackNode));
	StackNode	*node2 = calloc(1, sizeof(StackNode));
	StackNode	*node3 = calloc(1, sizeof(StackNode));
	StackNode	*node4 = calloc(1, sizeof(StackNode));
	StackNode	*node5 = calloc(1, sizeof(StackNode));
	StackNode	*node6 = calloc(1, sizeof(StackNode));
	StackNode	*node7 = calloc(1, sizeof(StackNode));
	StackNode	*temp;
	
	node1->data = 'm';
	node2->data = 'i';
	node3->data = 'n';
	node4->data = 'g';
	node5->data = 'k';
	node6->data = 'i';
	node7->data = 'm';
	pushAS(stack, *node1);
	displayArrayStack(stack);
	printf("====================================================\n");

	pushAS(stack, *node2);
	displayArrayStack(stack);
	printf("====================================================\n");

	pushAS(stack, *node3);
	displayArrayStack(stack);
	printf("====================================================\n");

	pushAS(stack, *node4);
	displayArrayStack(stack);
	printf("====================================================\n");

	pushAS(stack, *node5);
	displayArrayStack(stack);
	printf("====================================================\n");

	pushAS(stack, *node6);
	displayArrayStack(stack);
	printf("====================================================\n");

	pushAS(stack, *node7);
	displayArrayStack(stack);
	printf("====================================================\n");

	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	temp = peekAS(stack);
	printf("peek : %c\n", temp->data);
	free(temp);
	temp = popAS(stack);
	free(temp);
	displayArrayStack(stack);
	printf("====================================================\n");

	// temp = peekAS(stack);
	// printf("peek : %c\n", temp->data);
	// free(temp);
	// temp = popAS(stack);
	// free(temp);
	temp = NULL;
	displayArrayStack(stack);
	printf("====================================================\n");

	deleteArrayStack(stack);
	// node1->data = 0;
	// node2->data = 0;
	// node3->data = 0;
	// node4->data = 0;
	// node5->data = 0;
	// node6->data = 0;
	// node7->data = 0;
	// free(node1);
	// free(node2);
	// free(node3);
	// free(node4);
	// free(node5);
	// free(node6);
	// free(node7);
	// printf("Is stack empty ? : %d\n", isLinkedStackEmpty(stack));
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}