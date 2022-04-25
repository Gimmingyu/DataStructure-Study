#include "Maze.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("NULL pointer exception\n");
		return (TRUE);
	}
	return (FALSE);
}

void	displayPATH(MapNode *topNode)
{
	if (topNode->next)
		displayPATH(topNode->next);
	printf("(%d, %d) ", topNode->y, topNode->x);
}

void	deleteMap(Map *map)
{
	if (NULLCHECK(map))
		return ;
	free(map->startNode);
	free(map->endNode);
	map->graph = NULL;
	free(map);
}

int	exceptionHandling(Map *map)
{
	size_t	i = 0;
	size_t	j;
	int	ret = TRUE;

	if (NULLCHECK(map))
		return (FALSE);
	if (map->startNode->x > map->column || map->startNode->x < 0)
		ret = FALSE;
	else if (map->startNode->y > map->row || map->startNode->y < 0)
		ret = FALSE;
	else if (map->endNode->x > map->column || map->endNode->x < 0)
		ret = FALSE;
	else if (map->endNode->y > map->row || map->endNode->y < 0)
		ret = FALSE;
	while (map->graph[i])
	{
		j = 0;
		while (map->graph[i][j])
			j++;
		// graph[i]의 길이가 가로 길이와 맞지 않음
		if (j != map->column)
		{
			ret = FALSE;
			break ;
		}
		i++;
	}
	// graph내의 배열의 개수가 세로 길이와 맞지 않음
	if (i != map->row)
		ret = FALSE;
	return (ret);
}