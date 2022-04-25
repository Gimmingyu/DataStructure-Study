#include "postfix.h"

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

// Oper가 우선순위가 높거나 같다 == False
// Oper가 우선순위가 낮다. == True
int	checkPriority(char topOper, char Oper)
{
	if (topOper == '*' || topOper == '/')
	{
		if (Oper == '-' || Oper == '+')
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
int	fromInfixToPost(char *arr)
{
	LinkedStack	*OperStack;
	StackNode	NumNode;
	StackNode	OperNode;
	StackNode	*topNode;
	int			ret;

	if (NULLCHECK(arr))
		return (ERROR);
	OperStack = createLinkedStack();
	if (NULLCHECK(OperStack))
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
			// 비어있으면 그냥 push
			if (isLinkedStackEmpty(OperStack))
				pushLS(OperStack, OperNode);
			else
			{
				// 맨위의 연산자와 우선순위 비교 
				topNode = popLS(OperStack);
				// True == 현재 들어온 연산자가 우선순위가 낮거나 같다. 
				if (checkPriority(topNode->data, OperNode.data))
				{
					printf("%c ", topNode->data);
					pushLS(OperStack, OperNode);
				}
				// False == 현재 들어온 연산자가 우선순위가 높다 
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
	ret = checkBracketMatching(arr);
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
	fromInfixToPost(arr6);
	return (0);
}