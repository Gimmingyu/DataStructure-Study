#include "calculate.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("null pointer exception\n");
		return (TRUE);
	}
	return (FALSE);
}

int	SAME(int x, int y)
{
	return (x == y ? TRUE : FALSE);
}

int ZERO(int x)
{
	return (x == 0 ? TRUE : FALSE);
}

Formula	*createStack()
{
	Formula	*newStack = calloc(1, sizeof(Formula));

	if (NULLCHECK(newStack))
		return (NULL);
	return (newStack);
}

// Formula *copyFormula(Formula *Stack)
// {
// 	Formula	*newFormula;
// 	Node	*topNode;
// 	int		idx;

// 	if (NULLCHECK(Stack))
// 		return (NULL);
// 	newFormula = calloc(1, sizeof(Formula));
// 	if (NULLCHECK(newFormula))
// 		return (NULL);
// 	topNode = Stack->topNode;
// 	idx = Stack->currentStackCount;
// 	while (idx-- && topNode)
// 	{
// 		addNodeinFormula(newFormula, *topNode);
// 		topNode = topNode->Link;
// 	}
// 	return (newFormula);
// }

int		isFormulaEmpty(Formula *Stack)
{
	if (NULLCHECK(Stack))
		return (ERROR);
	return (Stack->currentStackCount == 0 ? TRUE : FALSE);
}

int	verifyType(Node elem)
{
	if (elem.data == SMALL_LEFT || elem.data == SMALL_RIGHT || \
		elem.data == MIDDLE_LEFT || elem.data == MIDDLE_RIGHT || \
		elem.data == BIG_LEFT || elem.data == BIG_RIGHT || \
		elem.data == MULTIPLY || elem.data == DIVIDE || \
		elem.data == PLUS || elem.data == MINUS)
		return (TRUE);
	return (FALSE);
}

t_operator	verifyOperator(Node *elem)
{
	if (elem->data == PLUS)
		return (PLUS);
	if (elem->data == MINUS)
		return (MINUS);
	if (elem->data == MULTIPLY)
		return (MULTIPLY);
	if (elem->data == DIVIDE)
		return (DIVIDE);
	return (ERROR);
}

t_bracket	verifyBracket(Node *elem)
{
	if (elem->data == SMALL_LEFT)
		return (SMALL_RIGHT);

	else if (elem->data == SMALL_RIGHT)
		return (SMALL_LEFT);

	else if (elem->data == MIDDLE_LEFT)
		return (MIDDLE_RIGHT);

	else if (elem->data == MIDDLE_RIGHT)
		return (MIDDLE_LEFT);

	else if (elem->data == BIG_LEFT)
		return (BIG_RIGHT);

	else if (elem->data == BIG_RIGHT)
		return (BIG_LEFT);
	printf("Invalid Input\n");
	return (ERROR);
}

int	addNodeinFormula(Formula *Stack, Node elem)
{
	Node	*newNode;

	if (NULLCHECK(Stack))
		return (ERROR);
	newNode = calloc(1, sizeof(Node));
	if (NULLCHECK(newNode))
		return (ERROR);
	if (elem.size == 1 && verifyType(elem) == FALSE)
		return (ERROR);
	newNode->size = elem.size;
	newNode->data = elem.data;
	if (Stack->topNode)
	{
		newNode->Link = Stack->topNode;
		printf("%d\n", Stack->topNode->data);
	}
	Stack->topNode = newNode;
	printf("%d\n", Stack->topNode->data);
	Stack->currentStackCount++;
	return (TRUE);
}

Node	*peekNodeinFormula(Formula *Stack)
{
	if (NULLCHECK(Stack))
		return (NULL);
	if (isFormulaEmpty(Stack))
	{
		printf("EMPTY FORMULA\n");
		return (NULL);
	}
	return (Stack->topNode);
}

void	deleteFormula(Formula *Stack)
{
	Node	*topNode;
	Node	*nextNode;
	int		idx;

	if (NULLCHECK(Stack))
		return ;
	topNode = Stack->topNode;
	idx = Stack->currentStackCount;
	while (idx-- && topNode)
	{
		nextNode = topNode->Link;
		free(topNode);
		topNode = nextNode;
	}
	free(Stack);
}

Node	*combineNodeByOper(Formula *Stack)
{
	Node		*topNode;
	Node		*aNode;
	Node		*bNode;
	Node		*newNode;
	t_operator	oper;

	if (NULLCHECK(Stack))
		return (NULL);
	topNode = Stack->topNode;
	aNode = topNode->Link;
	bNode = aNode->Link;
	newNode = calloc(1, sizeof(Node));
	if (NULLCHECK(newNode))
		return (NULL);
	oper = verifyOperator(topNode);
	if (oper == PLUS)
		newNode->data = aNode->data + bNode->data;
	else if (oper == MINUS)
		newNode->data = aNode->data - bNode->data;
	else if (oper == MULTIPLY)
		newNode->data = aNode->data * bNode->data;
	else
		newNode->data = aNode->data / bNode->data;
	newNode->size = INTSIZE;
	newNode->Link = bNode->Link;
	Stack->topNode = newNode;
	Stack->currentStackCount -= 2;
	return (newNode);
}

int	calcFormula(Formula *Stack)
{
	int			idx;
	t_operator	otype;
	t_operator	prev_otype = 0x00;
	t_bracket	btype;
	t_bracket	prev_btype = 0x00;
	Node		*topNode;

	if (NULLCHECK(Stack))
		return (ERROR);
	idx = Stack->currentStackCount;
	topNode = Stack->topNode;
	while (idx-- && topNode)
	{
		// 괄호가 나왔을 때
		if (topNode->size == CHARSIZE && (btype = verifyBracket(topNode)) != ERROR)
		{
			// 이전 괄호와 비교해서 잘못된 괄호가 들어오면 터짐
			if (prev_btype != btype)
			{
				deleteFormula(Stack);
				printf("Invalid Formula\n");
				return (ERROR);
			}
			// 맞는 괄호가 들어오면 괄호 초기화
			btype = 0x00;
			prev_btype = 0x00;
		}
		// 연산자가 나왔을 때
		else if (topNode->size == CHARSIZE && (otype = verifyOperator(topNode)) != ERROR)
		{
			// 후위연산이므로 이전에 숫자 두개가 반드시 있어야함
			if (Stack->currentStackCount < 3 || topNode->Link->size != 4 || \
			topNode->Link->Link->size != 4)
			{
				deleteFormula(Stack);
				printf("Invalid Formula\n");
				return (ERROR);
			}
			if (NULLCHECK(combineNodeByOper(Stack)))
			{
				deleteFormula(Stack);
				printf("Invalid Formula\n");
				return (ERROR);
			}
		}
		// 숫자가 나왔을 때 
		topNode = topNode->Link;
	}
	if (Stack->currentStackCount != 1)
	{
		deleteFormula(Stack);
		printf("Invalid Formula\n");
		return (ERROR);
	}
	return (topNode->data);
}

int	main(void)
{
	Formula	*Stack = createStack();
	Node	*node1 = calloc(1, sizeof(Node));
	Node	*node2 = calloc(1, sizeof(Node));
	Node	*node3 = calloc(1, sizeof(Node));
	Node	*node4 = calloc(1, sizeof(Node));
	Node	*node5 = calloc(1, sizeof(Node));
	Node	*node6 = calloc(1, sizeof(Node));
	Node	*node7 = calloc(1, sizeof(Node));
	Node	*node8 = calloc(1, sizeof(Node));
	Node	*node9 = calloc(1, sizeof(Node));
	Node	*node10 = calloc(1, sizeof(Node));
	Node	*temp;

	node1->data = '(';
	node1->size = 1;
	addNodeinFormula(Stack, *node1);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node2->data = 4;
	node2->size = 4;
	addNodeinFormula(Stack, *node2);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node3->data = 5;
	node3->size = 4;
	addNodeinFormula(Stack, *node3);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node4->data = '+';
	node4->size = 1;
	addNodeinFormula(Stack, *node4);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node5->data = ')';
	node5->size = 1;
	addNodeinFormula(Stack, *node5);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node6->data = 2;
	node6->size = 4;
	addNodeinFormula(Stack, *node6);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node7->data = 6;
	node7->size = 4;
	addNodeinFormula(Stack, *node7);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node8->data = '*';
	node8->size = 1;
	addNodeinFormula(Stack, *node8);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node9->data = '-';
	node9->size = 1;
	addNodeinFormula(Stack, *node9);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	node10->data = 42;
	node10->size = 4;
	addNodeinFormula(Stack, *node10);
	temp = peekNodeinFormula(Stack);
	printf("now topNode->data = %d\ntopNode->size = %td\n", temp->data, temp->size);
	free(temp);
	printf("======================================================\n");

	int ret = calcFormula(Stack);
	printf("ret = %d\n", ret);
	deleteFormula(Stack);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}