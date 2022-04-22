#ifndef _BRACKET_
#define _BRACKET_


#include <stdio.h>
#include <stdlib.h>
typedef	enum e_type 
{
	SMALL_LEFT = '(',
	SMALL_RIGHT = ')',
	MIDDLE_LEFT = '{',
	MIDDLE_RIGHT = '}',
	BIG_LEFT = '[',
	BIG_RIGHT = ']',
} t_type;

typedef	struct BracketType
{
	t_type			type;
	struct BracketType	*Link;
} Bracket;

typedef	struct StackType
{
	int		currentElementCount;
	Bracket	*topNode;
} Stack;

Stack	*createStack();

Bracket	*popBracket(Stack *pStack);
Bracket *peekBracket(Stack *pStack);

t_type	verify_type(Bracket bracket);

int		isStackEmpty(Stack *pStack);
int		pushBracket(Stack *pStack, Bracket bracket);

int		find_bracket_pair(Stack *pStack, t_type type);
void	displayStack(Stack *pStack);
void	deleteStack(Stack *pStack);
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