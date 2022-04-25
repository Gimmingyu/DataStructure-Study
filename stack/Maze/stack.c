#include "Maze.h"

Stack	*createStack()
{
	Stack	*newStack;

	newStack = calloc(1, sizeof(Stack));
	if (NULLCHECK(newStack))
		return (NULL);
	newStack->pTopElement = NULL;
	newStack->currentElementCount = 0;
	return (newStack);
}

int	isStackEmpty(Stack *stack)
{
	return (stack->currentElementCount == 0 ? TRUE : FALSE);
}

int	pushLS(Stack *stack, MapNode node)
{
	MapNode	*newNode;

	newNode = calloc(1, sizeof(MapNode));
	if (NULLCHECK(newNode))
		return (ERROR);
	newNode->x = node.x;
	newNode->y = node.y;
	newNode->next = stack->pTopElement;
	if (stack->currentElementCount == 0)
		newNode->next = NULL;
	stack->pTopElement = newNode;
	stack->currentElementCount++;
	return (TRUE);
}

MapNode	*popLS(Stack *stack)
{
	MapNode *delNode;

	if (NULLCHECK(stack))
		return (NULL);
	if (stack->currentElementCount == 0)
		return (NULL);
	delNode = stack->pTopElement;
	stack->pTopElement = delNode->next;
	stack->currentElementCount--;
	if (stack->currentElementCount == 0)
		delNode->next = NULL;
	return (delNode);
}

void	deleteLS(Stack *stack)
{
	int		idx;
	MapNode	*delNode;
	MapNode	*nextNode;

	if (NULLCHECK(stack))
		return ;
	idx = stack->currentElementCount;
	delNode = stack->pTopElement;
	while (idx-- && delNode)
	{
		nextNode = delNode->next;
		free(delNode);
		delNode = nextNode;
	}
	free(stack);
}