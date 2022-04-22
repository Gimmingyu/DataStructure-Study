#include "bracket.h"

void	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("null pointer exception\n");
		system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
		exit(1);
	}
	return ;
}

Stack	*createStack()
{
	Stack	*newStack = calloc(1, sizeof(Stack));

	NULLCHECK(newStack);
	return (newStack);
}

int		isStackEmpty(Stack *pStack)
{
	NULLCHECK(pStack);
	return (pStack->currentElementCount == 0 ? TRUE : FALSE);
}

t_type	verify_type(Bracket bracket)
{
	if (bracket.type == SMALL_LEFT)
		return (SMALL_RIGHT);

	else if (bracket.type == SMALL_RIGHT)
		return (SMALL_LEFT);

	else if (bracket.type == MIDDLE_LEFT)
		return (MIDDLE_RIGHT);

	else if (bracket.type == MIDDLE_RIGHT)
		return (MIDDLE_LEFT);

	else if (bracket.type == BIG_LEFT)
		return (BIG_RIGHT);

	else if (bracket.type == BIG_RIGHT)
		return (BIG_LEFT);
	else
	{
		printf("Invalid Input\n");
		exit(1);
	}
	return (bracket.type);
}

int	find_bracket_pair(Stack *pStack, t_type type)
{
	if (!pStack->topNode)
		return (FALSE);
	return (pStack->topNode->type == type ? TRUE : FALSE);
}

int	pushBracket(Stack *pStack, Bracket bracket)
{
	t_type	type;
	Bracket	*topNode;
	Bracket	*newNode;

	NULLCHECK(pStack);
	// type이 괄호가 아니라면 exit
	type = verify_type(bracket);
	// 맨 위에 있던 괄호와 일치하는 경우 
	if (find_bracket_pair(pStack, type))
	{
		// 맨위의 노드를 지우고 return True
		topNode = pStack->topNode;
		pStack->topNode = topNode->Link;
		free(topNode);
		topNode = NULL;
		pStack->currentElementCount--;
	}
	else
	{
		// 복사해줄 새로운 노드 
		newNode = calloc(1, sizeof(Bracket));
		NULLCHECK(newNode);
		newNode->type = bracket.type;
		newNode->Link = pStack->topNode;
		pStack->topNode = newNode;
		pStack->currentElementCount++;
	}
	return (TRUE);
}

Bracket	*peekBracket(Stack *pStack)
{
	NULLCHECK(pStack);
	if (isStackEmpty(pStack))
	{
		printf("STACK IS NOW EMPTY\n");
		return (NULL);
	}
	return (pStack->topNode);
}

Bracket	*popBracket(Stack *pStack)
{
	Bracket	*popNode;
	Bracket	*delNode;

	NULLCHECK(pStack);
	// is empty
	if (isStackEmpty(pStack))
		return (NULL);
	popNode = calloc(1, sizeof(Bracket));
	NULLCHECK(popNode);
	delNode = pStack->topNode;
	if (pStack->currentElementCount == 1)
	{
		popNode->type = delNode->type;
		popNode->Link = delNode->Link;
		free(delNode);
		delNode = NULL;
		pStack->topNode = NULL;
	}
	else
	{
		popNode->type = delNode->type;
		popNode->Link = delNode->Link;
		pStack->topNode = delNode->Link;
		free(delNode);
		delNode = NULL;
	}
	pStack->currentElementCount--;
	return (popNode);
}

void	displayStack(Stack *pStack)
{
	int		idx = pStack->currentElementCount;
	Bracket	*topNode = pStack->topNode;

	while (idx-- && topNode)
	{
		printf("topNode->type = '%c'\n", topNode->type);
		topNode = topNode->Link;
	}
}

void	deleteStack(Stack *pStack)
{
	int			idx;
	Bracket		*delNode;
	Bracket		*nextNode;

	NULLCHECK(pStack);
	if (isStackEmpty(pStack))
	{
		pStack->topNode = NULL;
		free(pStack);
		pStack = NULL;
	}
	else
	{
		idx = pStack->currentElementCount;
		delNode = pStack->topNode;
		while (idx-- && delNode)
		{
			nextNode = delNode->Link;
			delNode->Link = NULL;
			delNode->type = 0x00;
			free(delNode);
			delNode = nextNode;
		}
		pStack->topNode = NULL;
		free(delNode);
		free(pStack);
		free(nextNode);
		nextNode = NULL;
		delNode = NULL;
		pStack = NULL;
	}
}

int	main(void)
{
	Stack	*stack = createStack();
	Bracket	*node1 = calloc(1, sizeof(Bracket));
	Bracket	*node2 = calloc(1, sizeof(Bracket));
	Bracket	*node3 = calloc(1, sizeof(Bracket));
	Bracket	*node4 = calloc(1, sizeof(Bracket));
	Bracket	*node5 = calloc(1, sizeof(Bracket));
	Bracket	*node6 = calloc(1, sizeof(Bracket));
	Bracket	*node7 = calloc(1, sizeof(Bracket));

	node1->type = '(';
	node2->type = '[';
	node3->type = '[';
	node4->type = ']';
	node5->type = '}';
	node6->type = ')';
	pushBracket(stack, *node1);
	displayStack(stack);
	printf("====================================================\n");

	pushBracket(stack, *node2);
	displayStack(stack);
	printf("====================================================\n");

	pushBracket(stack, *node3);
	displayStack(stack);
	printf("====================================================\n");

	pushBracket(stack, *node4);
	displayStack(stack);
	printf("====================================================\n");

	pushBracket(stack, *node5);
	displayStack(stack);
	printf("====================================================\n");

	pushBracket(stack, *node6);
	displayStack(stack);
	printf("====================================================\n");

	// pushBracket(stack, *node7);
	// displayStack(stack);
	// printf("====================================================\n");

	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");

	// Bracket	*temp;
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");
	
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");

	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// free(temp);
	// displayStack(stack);
	// printf("====================================================\n");
	// temp = peekBracket(stack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(stack);
	// displayStack(stack);
	printf("====================================================\n");
	deleteStack(stack);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}
