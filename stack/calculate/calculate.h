#ifndef _CALCULATE_
#define _CALCULATE_


#include <stdio.h>
#include <stdlib.h>

typedef	enum e_operator 
{
	MULTIPLY = '*',
	DIVIDE = '/',
	PLUS = '+',
	MINUS = '-',
} t_operator;

typedef	enum e_bracket 
{
	SMALL_LEFT = '(',
	SMALL_RIGHT = ')',
	MIDDLE_LEFT = '{',
	MIDDLE_RIGHT = '}',
	BIG_LEFT = '[',
	BIG_RIGHT = ']',
} t_bracket;

typedef struct StackNodeType
{
	size_t					size;
	int						data;
	struct StackNodeType	*Link;
} Node;

typedef struct FormulaType
{
	int			currentStackCount;
	Node	*topNode;
} Formula;

Formula	*createStack();
Formula *copyFormula(Formula *Stack);

int		verifyType(Node elem);
int		isFormulaEmpty(Formula *Stack);
int		calcFormula(Formula *Stack);

int		addNodeinFormula(Formula *Stack, Node elem);
Node	*peekNodeinFormula(Formula *Stack);
Node	*combineNodeByOper(Formula *Stack);
void	deleteFormula(Formula *Stack);
// additional
int		NULLCHECK(void *ptr);
int		SAME(int x, int y);
int		ZERO(int x);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#define CHARSIZE	1
#define INTSIZE		4
#endif