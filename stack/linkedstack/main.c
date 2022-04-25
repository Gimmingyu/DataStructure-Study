#include "linkedstack.h"

// int	main(void)
// {
// 	LinkedStack	*stack = createLinkedStack(10);
// 	StackNode	*node1 = calloc(1, sizeof(StackNode));
// 	StackNode	*node2 = calloc(1, sizeof(StackNode));
// 	StackNode	*node3 = calloc(1, sizeof(StackNode));
// 	StackNode	*node4 = calloc(1, sizeof(StackNode));
// 	StackNode	*node5 = calloc(1, sizeof(StackNode));
// 	StackNode	*node6 = calloc(1, sizeof(StackNode));
// 	StackNode	*node7 = calloc(1, sizeof(StackNode));

// 	node1->data = 'm';
// 	node2->data = 'i';
// 	node3->data = 'n';
// 	node4->data = 'g';
// 	node5->data = 'k';
// 	node6->data = 'i';
// 	node7->data = 'm';
// 	pushLS(stack, *node1);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	pushLS(stack, *node2);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	pushLS(stack, *node3);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	pushLS(stack, *node4);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	pushLS(stack, *node5);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	pushLS(stack, *node6);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	pushLS(stack, *node7);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	printf("***********now peek & pop*****************\n");
// 	printf("***********now peek & pop*****************\n");
// 	printf("***********now peek & pop*****************\n");

// 	StackNode	*temp;
// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");
	
// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");

// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");
// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");
// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");
// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");
// 	temp = peekLS(stack);
// 	printf("peek : %c\n", temp->data);
// 	temp = popLS(stack);
// 	free(temp);
// 	displayLinkedStack(stack);
// 	printf("====================================================\n");
// 	// temp = peekLS(stack);
// 	// printf("peek : %c\n", temp->data);
// 	// temp = popLS(stack);
// 	// displayLinkedStack(stack);
// 	printf("====================================================\n");
// 	deleteLinkedStack(stack);
// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	free(node4);
// 	free(node5);
// 	free(node6);
// 	free(node7);
// 	node1 = NULL;
// 	node2 = NULL;
// 	node3 = NULL;
// 	node4 = NULL;
// 	node5 = NULL;
// 	node6 = NULL;
// 	node7 = NULL;
// 	// printf("Is stack empty ? : %d\n", isLinkedStackEmpty(stack));
// 	system("leaks a.out > leaks_result; cat leaks_result | \
//         grep leaked && rm -rf leaks_result");
// 	return (0);
// }

int	INT(char c)
{
	return ('0' <= c && c <= '9' ? TRUE : FALSE);
}


int	isOperator(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int	operate_stack(LinkedStack *stack, char c)
{
	int	rtn;
	int	a;
	int	b;

	b = (popLS(stack))->data;
	a = (popLS(stack))->data; // 순서 주의 나눗셈할때
	if (c == '+')
		rtn = a + b;
	else if (c == '-')
		rtn = a - b;
	else if (c == '*')
		rtn = a * b;
	else if (c == '/')
		rtn = a / b;
	return (rtn);
}

// topOper가 우선순위가 높다 == False
// Oper가 우선순위가 낮거나 같다. == True
int	checkPriority(char topOper, char Oper)
{
	if (topOper == '*' || topOper == '/')
	{
		if (Oper == '*' || Oper == '/')
			return (TRUE);
		else
			return (FALSE);
	}
	else if (topOper == '-' || topOper == '+')
	{
		if (Oper == '*' || Oper == '/')
			return (FALSE);
		else
			return (TRUE);
	}
	return (ERROR);
}

int	checkBracketMatching(char *arr)
{
	LinkedStack	*stack;
	StackNode	node;
	int	rtn;
	int	num;

	if (NULLCHECK(arr))
		return (ERROR);
	stack = createLinkedStack();
	if (NULLCHECK(stack))
		return (ERROR);
	rtn = ERROR;
	while (*arr)
	{
		if ('0' <= *arr && *arr <= '9') //숫자일 경우
		{
			node.data = *arr - '0';
			for (; '0' <= *(arr + 1) && *(arr + 1) <= '9';)
			{
				arr++;
				node.data *= 10;
				node.data += *arr - '0';
			}
			pushLS(stack, node);
		}
		else if (isOperator(*arr)) //연산자일 경우
		{
			if (stack->currentElementCount < 2) //최소 2개가 있어야 연산가능
				break;
			node.data = operate_stack(stack, *arr);
			pushLS(stack, node);
		}
		else if (*arr != ' ')
			break;
		arr++;
	}
	if (*arr == '\0' && stack->currentElementCount == 1) //마지막 저장된 결과값 1개 일때
		rtn = (popLS(stack))->data;
	deleteLinkedStack(stack);
	return (rtn);
}

// 중위에서 후위로 변경해서 출력
// 계산도 해줄 것이면 checkBracketMatching 호출?
int	fromPostToInfix(char *arr)
{
	LinkedStack	*NumStack;
	LinkedStack	*OperStack;
	StackNode	NumNode;
	StackNode	OperNode;
	StackNode	*topNode;
	int			ret;

	if (NULLCHECK(arr))
		return (ERROR);
	ret = checkBracketMatching(arr);
	// if (ret == ERROR)
	// 	return (ERROR);
	OperStack = createLinkedStack();
	if (NULLCHECK(NumStack))
		return (ERROR);
	while (*arr)
	{
		// 숫자이면 
		if (INT(*arr))
		{
			// 숫자인 동안에 합쳐서 출력 
			while (INT(*arr))
			{
				NumNode.data *= 10;
				NumNode.data += *arr - '0';
				arr++;
			}
			// 출력만 ? 
			printf("%d ", NumNode.data);
			NumNode.data = 0;
		}
		// 연산자면 
		else if (isOperator(*arr))
		{
			OperNode.data = *arr;
			if (isLinkedStackEmpty(OperStack))
				pushLS(OperStack, OperNode);
			else
			{
				topNode = popLS(OperStack);
				if (checkPriority(topNode->data, OperNode.data))
				{
					printf("%c ", topNode->data);
					pushLS(OperStack, OperNode);
				}
				else
				{
					pushLS(OperStack, *topNode);
					pushLS(OperStack, OperNode);
				}
			}
		}
		else if (*arr != ' ')
			break ;
		arr++;
	}
	while (OperStack->currentElementCount)
	{
		topNode = popLS(OperStack);
		printf("%c ", topNode->data);
	}
	// printf("= %d\n", ret);
	printf("\n");
	return (ret);
}

int	main(void)
{
	char	arr1[] = "2 2 3 + 4 * - 2 /"; // (2 - (2 + 3) * 4 )/ 2 = -9
	char	arr2[] = "2 3 + 4"; // 문자가 많을때 
	char	arr3[] = "2 3 + -"; // 연산자가 많을때
	char	arr4[] = "2 3 +a -"; // 잘못된 문자가 들어 있을때
	char	arr5[] = "1"; // 숫자 하나일때
	char	arr6[] = "20 + 30 * 90 / 70";

	printf("result %d\n", checkBracketMatching(arr1));
	printf("result %d\n", checkBracketMatching(arr2));
	printf("result %d\n", checkBracketMatching(arr3));
	printf("result %d\n", checkBracketMatching(arr4));
	printf("result %d\n", checkBracketMatching(arr5));
	fromPostToInfix(arr6);
	return (0);
}