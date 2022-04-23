#ifndef _CALCULATE_
#define _CALCULATE_


#include <stdio.h>
#include <stdlib.h>

typedef	enum e_flag 
{
	MULTIPLY = '*',
	DIVIDE = '/',
	PLUS = '+',
	MINUS = '-',
	INT = 'i',
} t_flag;

typedef struct FormulaType
{
	int					data;
	t_flag				flag;
	struct FormulaType	*Link;
} Formula;

typedef	struct StackType
{
	int				currentElementCount;
	struct Formula	*topNode;
} Stack;

Stack	*createStack();

t_flag	verify_element(Formula element);

int		addElement(Stack pStack, Formula element);
// additional
void		NULLCHECK(void *ptr);
int			SAME(int x, int y);
int			ZERO(int x);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#endif