#include "bracket.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("null pointer exception\n");
		return (TRUE);
	}
	return (FALSE);
}

BracketStack	*createBracketStack()
{
	BracketStack	*newBracketStack = calloc(1, sizeof(BracketStack));

	if (NULLCHECK(newBracketStack))
		return (NULL);
	return (newBracketStack);
}

int		isBracketStackEmpty(BracketStack *pBracketStack)
{
	if (NULLCHECK(pBracketStack))
		return (ERROR);
	return (pBracketStack->currentElementCount == 0 ? TRUE : FALSE);
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
		return (ERROR);
	}
	return (bracket.type);
}

int	find_bracket_pair(BracketStack *pBracketStack, t_type type)
{
	if (!pBracketStack->topNode)
		return (FALSE);
	return (pBracketStack->topNode->type == type ? TRUE : FALSE);
}

int	pushBracket(BracketStack *pBracketStack, Bracket bracket)
{
	t_type	type;
	Bracket	*topNode;
	Bracket	*newNode;

	if (NULLCHECK(pBracketStack))
		return (ERROR);
	// type이 괄호가 아니라면 exit
	if ((type = verify_type(bracket)) == ERROR)
		return (ERROR);
	// 맨 위에 있던 괄호와 일치하는 경우 
	if (find_bracket_pair(pBracketStack, type))
	{
		// 맨위의 노드를 지우고 return True
		topNode = pBracketStack->topNode;
		pBracketStack->topNode = topNode->Link;
		free(topNode);
		topNode = NULL;
		pBracketStack->currentElementCount--;
	}
	else
	{
		// 복사해줄 새로운 노드 
		newNode = calloc(1, sizeof(Bracket));
		NULLCHECK(newNode);
		newNode->type = bracket.type;
		newNode->Link = pBracketStack->topNode;
		pBracketStack->topNode = newNode;
		pBracketStack->currentElementCount++;
	}
	return (TRUE);
}

Bracket	*peekBracket(BracketStack *pBracketStack)
{
	if (NULLCHECK(pBracketStack))
		return (NULL);
	if (isBracketStackEmpty(pBracketStack))
	{
		printf("BracketStack IS NOW EMPTY\n");
		return (NULL);
	}
	return (pBracketStack->topNode);
}

Bracket	*popBracket(BracketStack *pBracketStack)
{
	Bracket	*popNode;
	Bracket	*delNode;

	if (NULLCHECK(pBracketStack))
		return (NULL);
	// is empty
	if (isBracketStackEmpty(pBracketStack))
		return (NULL);
	popNode = calloc(1, sizeof(Bracket));
	if (NULLCHECK(popNode))
		return (NULL);
	delNode = pBracketStack->topNode;
	if (pBracketStack->currentElementCount == 1)
	{
		popNode->type = delNode->type;
		popNode->Link = delNode->Link;
		free(delNode);
		delNode = NULL;
		pBracketStack->topNode = NULL;
	}
	else
	{
		popNode->type = delNode->type;
		popNode->Link = delNode->Link;
		pBracketStack->topNode = delNode->Link;
		free(delNode);
		delNode = NULL;
	}
	pBracketStack->currentElementCount--;
	return (popNode);
}

void	displayBracketStack(BracketStack *pBracketStack)
{
	int		idx = pBracketStack->currentElementCount;
	Bracket	*topNode = pBracketStack->topNode;

	while (idx-- && topNode)
	{
		printf("topNode->type = '%c'\n", topNode->type);
		topNode = topNode->Link;
	}
}

void	deleteBracketStack(BracketStack *pBracketStack)
{
	int			idx;
	Bracket		*delNode;
	Bracket		*nextNode;

	if (NULLCHECK(pBracketStack))
		return ;

	idx = pBracketStack->currentElementCount;
	delNode = pBracketStack->topNode;
	while (idx-- && delNode)
	{
		nextNode = delNode->Link;
		delNode->Link = NULL;
		delNode->type = 0x00;
		free(delNode);
		delNode = nextNode;
	}
	pBracketStack->topNode = NULL;
	free(pBracketStack);
}

int	main(void)
{
	BracketStack	*BracketStack = createBracketStack();
	Bracket	*node1 = calloc(1, sizeof(Bracket));
	Bracket	*node2 = calloc(1, sizeof(Bracket));
	Bracket	*node3 = calloc(1, sizeof(Bracket));
	Bracket	*node4 = calloc(1, sizeof(Bracket));
	Bracket	*node5 = calloc(1, sizeof(Bracket));
	Bracket	*node6 = calloc(1, sizeof(Bracket));
	Bracket	*node7 = calloc(1, sizeof(Bracket));

	node1->type = '(';
	node2->type = '[';
	node3->type = '{';
	node4->type = '}';
	node5->type = ']';
	node6->type = ')';
	pushBracket(BracketStack, *node1);
	displayBracketStack(BracketStack);
	printf("====================================================\n");

	pushBracket(BracketStack, *node2);
	displayBracketStack(BracketStack);
	printf("====================================================\n");

	pushBracket(BracketStack, *node3);
	displayBracketStack(BracketStack);
	printf("====================================================\n");

	pushBracket(BracketStack, *node4);
	displayBracketStack(BracketStack);
	printf("====================================================\n");

	pushBracket(BracketStack, *node5);
	displayBracketStack(BracketStack);
	printf("====================================================\n");

	pushBracket(BracketStack, *node6);
	displayBracketStack(BracketStack);
	printf("====================================================\n");

	// pushBracket(BracketStack, *node7);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");

	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");
	printf("***********now peek & pop*****************\n");

	// Bracket	*temp;
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");
	
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");

	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// free(temp);
	// displayBracketStack(BracketStack);
	// printf("====================================================\n");
	// temp = peekBracket(BracketStack);
	// printf("peek : %c\n", temp->type);
	// temp = popBracket(BracketStack);
	// displayBracketStack(BracketStack);
	printf("====================================================\n");
	deleteBracketStack(BracketStack);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}
