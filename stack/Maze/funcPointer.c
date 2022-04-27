#include "Maze.h"

int	FIRST(Map *map, MapNode **node, Stack *stack, Direction *dir)
{
	(*node)->func = &SECOND;
	return ((*(t_func)dir->first)(*node, stack, map));
}

int	SECOND(Map *map, MapNode **node, Stack *stack, Direction *dir)
{
	(*node)->func = &THIRD;
	return ((*(t_func)dir->second)(*node, stack, map));
}

int	THIRD(Map *map, MapNode **node, Stack *stack, Direction	*dir)
{
	(*node)->func = &FOURTH;
	return ((*(t_func)dir->third)(*node, stack, map));
}

int	FOURTH(Map *map, MapNode **node, Stack *stack, Direction *dir)
{
	(*node)->func = NULL;
	return ((*(t_func)dir->fourth)(*node, stack, map));
}
