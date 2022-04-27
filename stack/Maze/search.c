#include "Maze.h"

int	searchLeft(MapNode *node, Stack *stack, Map *map)
{
	if (NULLCHECK(node) || NULLCHECK(map))
		return (FALSE);
	if (node->x - 1 >= 0 && map->graph[node->y][node->x - 1] == '0')
	{
		pushLS(stack, *node);
		map->graph[node->y][node->x - 1] = '1';
		node->x--;
		node->dist++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	searchRight(MapNode *node, Stack *stack, Map *map)
{
	if (NULLCHECK(node) || NULLCHECK(map))
		return (FALSE);
	if (node->x + 1 < map->column && map->graph[node->y][node->x + 1] == '0')
	{
		pushLS(stack, *node);
		map->graph[node->y][node->x + 1] = '1';
		node->x++;
		node->dist++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	searchUp(MapNode *node, Stack *stack, Map *map)
{
	if (NULLCHECK(node) || NULLCHECK(map))
		return (FALSE);
	if (node->y - 1 >= 0 && map->graph[node->y - 1][node->x] == '0')
	{
		pushLS(stack, *node);
		map->graph[node->y - 1][node->x] = '1';
		node->y--;
		node->dist++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	searchDown(MapNode *node, Stack *stack, Map *map)
{
	if (NULLCHECK(node) || NULLCHECK(map))
		return (FALSE);
	if (node->y + 1 < map->row && map->graph[node->y + 1][node->x] == '0')
	{
		pushLS(stack, *node);
		map->graph[node->y + 1][node->x] = '1';
		node->y++;
		node->dist++;
	}
	else
		return (FALSE);
	return (TRUE);
}
