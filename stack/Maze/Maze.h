#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct DirectionType
{
	void	*first;
	void	*second;
	void	*third;
	void	*fourth;
} Direction;

typedef struct NodeType
{
	int				x;
	int				y;
	struct NodeType *next;
} MapNode;

typedef struct StackType
{
	int 	currentElementCount;
	MapNode	*pTopElement;
} Stack;

typedef struct MapType
{
	int	row;
	int	column;
	MapNode	*startNode;
	MapNode	*endNode;
	char	**graph;
} Map;

typedef	int(*t_func)(MapNode *, Stack *, Map *);

Stack		*createStack();
int			isStackEmpty(Stack *stack);
int			pushLS(Stack *stack, MapNode node);
MapNode		*popLS(Stack *stack);
Map			*createMap(int row, int column, char **graph, MapNode *startNode, MapNode *endNode);
MapNode	*createMapNode();
Direction	*createDirection();
int	Go(Direction *dir, Map *map);
Direction	*setDirection(Map *map);
void	deleteLS(Stack *stack);
int			searchLeft(MapNode *node, Stack *stack, Map *map);
int			searchRight(MapNode *node, Stack *stack, Map *map);
int			searchUp(MapNode *node, Stack *stack, Map *map);
int			searchDown(MapNode *node,Stack *stack,  Map *map);
int	exceptionHandling(Map *map);
void		assignFunc(Direction **Dir, Map *map);
void	deleteMap(Map *map);
void	displayPATH(MapNode	*topNode);
int			NULLCHECK(void *ptr);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif