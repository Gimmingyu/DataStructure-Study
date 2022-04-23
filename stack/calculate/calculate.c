#include "calculate.h"

Stack	*createStack()
{
	Stack	*newStack = calloc(1, sizeof(Stack));

	NULLCHECK(newStack);
	return (newStack);
}

t_flag	verify_element(Formula element)
{
	if (element.flag == PLUS)
		return (PLUS);
	if (element.flag == MINUS)
		return (MINUS);
	if (element.flag == MULTIPLY)
		return (MULTIPLY);
	if (element.flag == DIVIDE)
		return (DIVIDE);
	if (element.flag == INT)
		return (INT);
}

int	addElement(Stack *pStack, Formula element)
{
	Formula	*newNode;

	NULLCHECK(pStack);
	newNode = calloc(1, sizeof(Formula));
	NULLCHECK(newNode);
	newNode->flag = verify_element(element);
	if (newNode->flag == INT)
		newNode->data = element.data;
	newNode->Link = pStack->topNode;
	pStack->topNode = newNode;
	pStack->currentElementCount++;
	return (TRUE);
}

int	isInvalidFormula(Stack *pStack)
{
	return (FALSE);
}

int	isStackEmpty(Stack *pStack)
{
	return (pStack->currentElementCount == 0 ? TRUE : FALSE)
}
int	calculate_stack(Stack *pStack)
{
	Formula	*topNode;

	NULLCHECK(pStack);
	if (isStackEmpty(pStack))
		return (FALSE);
	topNode = pStack->topNode;
}