#ifndef _LINKED_STACK_
#define _LINKED_STACK_


#include <stdio.h>
#include <stdlib.h>

typedef struct StackNodeType
{
	char data;
	struct StackNodeType	*pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode	*pTopElement;
} LinkedStack;

void 		deleteLinkedStack(LinkedStack* pStack);
LinkedStack	*createLinkedStack();

StackNode	*peekLS(LinkedStack* pStack);
StackNode	*popLS(LinkedStack* pStack);
int 		pushLS(LinkedStack* pStack, StackNode element);

int 		isLinkedStackEmpty(LinkedStack* pStack);

// additional
void		displayLinkedStack(LinkedStack *pStack);
int			NULLCHECK(void *ptr);
int			SAME(int x, int y);
int			ZERO(int x);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif