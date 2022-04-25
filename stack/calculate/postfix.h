#ifndef _CALCULATE_
#define _CALCULATE_

#include "linkedstack/linkedstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// additional
int		NULLCHECK(void *ptr);
int		SAME(int x, int y);
int		ZERO(int x);
#endif
