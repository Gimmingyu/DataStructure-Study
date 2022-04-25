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

int	operateStack(LinkedStack *stack, char c)
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

// Oper가 우선순위가 높다 == False == Oper를 스택에 넣는다 
// Oper가 우선순위가 낮거나 같다. == True == topOper를 출력하고 Oper스택에 넣는다 ? 
int	checkPriority(char topOper, char Oper)
{
	if (topOper == '*' || topOper == '/')
	{
		if ((Oper == '-' || Oper == '+') || (Oper == '*' || Oper == '/'))
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
			node.data = operateStack(stack, *arr);
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
	StackNode	OperNode;
	StackNode	*topNode;
	int			ret;
	char		*newArr;
	int			idx = 0;

	newArr = calloc(strlen(arr), sizeof(char));
	if (NULLCHECK(arr))
		return (ERROR);
	OperStack = createLinkedStack();
	if (NULLCHECK(OperStack))
		return (ERROR);
	while (*arr)
	{
		if (INT(*arr))
		{
			while (INT(*arr))
			{
				newArr[idx++] = *arr;
				arr++;
			}
			newArr[idx++] = ' ';
		}
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
					newArr[idx++] = topNode->data;
					newArr[idx++] = ' ';
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
		newArr[idx++] = topNode->data;
		newArr[idx++] = ' ';
	}
	newArr[idx] = 0x00;
	ret = checkBracketMatching(newArr);
	printf("%s= %d\n", newArr, ret);
	return (ret);
}

// 2700
int	main(void)
{
	char	arr1[] = "2 2 3 + 4 * - 2 /"; // (2 - (2 + 3) * 4 )/ 2 = -9
	char	arr2[] = "2 3 + 4"; // 문자가 많을때 
	char	arr3[] = "2 3 + -"; // 연산자가 많을때
	char	arr4[] = "2 3 +a -"; // 잘못된 문자가 들어 있을때
	char	arr5[] = "1"; // 숫자 하나일때
	char	arr6[] = "2 + 3 * 9 / 7"; // 5 
	// 20 + ((30 * 90) / 70)
	// 20 30 90
	// +  * /

	printf("result %d\n", checkBracketMatching(arr1));
	printf("result %d\n", checkBracketMatching(arr2));
	printf("result %d\n", checkBracketMatching(arr3));
	printf("result %d\n", checkBracketMatching(arr4));
	printf("result %d\n", checkBracketMatching(arr5));
	printf("result %d\n", fromInfixToPost(arr6));
	return (0);
}