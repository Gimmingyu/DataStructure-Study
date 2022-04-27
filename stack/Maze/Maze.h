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
	int				dist;
	void			*func;
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
typedef int(*t_order)(Map *, MapNode **, Stack *, Direction *);

Stack		*createStack();
int			isStackEmpty(Stack *stack);
int			pushLS(Stack *stack, MapNode node);
MapNode		*popLS(Stack *stack);
void		deleteLS(Stack *stack);

Map			*createMap(int row, int column, char **graph, MapNode *startNode, MapNode *endNode);
MapNode		*createMapNode();
Direction	*createDirection();

int			Go(Map *map);

Direction	*setDirection(Map *map);
void		assignFunc(Direction **Dir, Map *map);

int	FIRST(Map *map, MapNode **node, Stack *stack, Direction *dir);
int	SECOND(Map *map, MapNode **node, Stack *stack, Direction *dir);
int	THIRD(Map *map, MapNode **node, Stack *stack, Direction	*dir);
int	FOURTH(Map *map, MapNode **node, Stack *stack, Direction *dir);

int			searchLeft(MapNode *node, Stack *stack, Map *map);
int			searchRight(MapNode *node, Stack *stack, Map *map);
int			searchUp(MapNode *node, Stack *stack, Map *map);
int			searchDown(MapNode *node,Stack *stack,  Map *map);


void		deleteMap(Map *map);
void		displayPATH(MapNode	*topNode);

int			exceptionHandling(Map *map);
int			NULLCHECK(void *ptr);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#endif