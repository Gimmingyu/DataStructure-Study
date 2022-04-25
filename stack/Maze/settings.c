#include "Maze.h"


Direction	*createDirection()
{
	Direction	*newDir;

	newDir = calloc(1, sizeof(Direction));
	if (NULLCHECK(newDir))
		return (NULL);
	return (newDir);
}

void	assignFunc(Direction **Dir, Map *map)
{
	if (NULLCHECK(Dir) || NULLCHECK(map))
		return ;
	// 0이상이면 왼쪽먼저, 아니면 오른쪽 먼저
	if ((map->startNode->x) - (map->endNode->x) >= 0)
	{
		(*Dir)->first = searchLeft;
		(*Dir)->third = searchRight;
	}
	else
	{
		(*Dir)->first = searchRight;
		(*Dir)->third = searchLeft;
	}
	// 0이상이면 상향먼저, 아니면 하향먼저
	if ((map->startNode->y) - (map->endNode->y) >= 0)
	{
		(*Dir)->second = searchUp;
		(*Dir)->fourth = searchDown;
	}
	else
	{
		(*Dir)->second = searchDown;
		(*Dir)->fourth = searchUp;
	}
}

Direction	*setDirection(Map *map)
{
	Direction	*newDir;

	if (NULLCHECK(map))
		return (NULL);
	newDir = createDirection();
	if (NULLCHECK(newDir))
		return (NULL);
	assignFunc(&newDir, map);
	return (newDir);
}