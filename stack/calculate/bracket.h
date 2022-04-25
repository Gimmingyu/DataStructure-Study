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

typedef	struct BracketStackType
{
	int		currentElementCount;
	Bracket	*topNode;
} BracketStack;

BracketStack	*createBracketStack();

Bracket	*popBracket(BracketStack *pBracketStack);
Bracket *peekBracket(BracketStack *pBracketStack);

t_type	verify_type(Bracket bracket);

int		isBracketStackEmpty(BracketStack *pBracketStack);
int		pushBracket(BracketStack *pBracketStack, Bracket bracket);

int		find_bracket_pair(BracketStack *pBracketStack, t_type type);
void	displayBracketStack(BracketStack *pBracketStack);
void	deleteBracketStack(BracketStack *pBracketStack);
// additional
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