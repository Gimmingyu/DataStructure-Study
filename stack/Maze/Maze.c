#include "Maze.h"

// 들어온 map을 받아줄 함수
Map	*createMap(int row, int column, char **graph, MapNode *startNode, MapNode *endNode)
{
	Map		*newMap;
	newMap = calloc(1, sizeof(Map));
	newMap->row = row;
	newMap->column = column;
	newMap->graph = graph;
	newMap->startNode = startNode;
	newMap->endNode = endNode;
	return (newMap);
}


MapNode	*createMapNode()
{
	MapNode	*newNode;

	newNode = calloc(1, sizeof(MapNode));
	if (NULLCHECK(newNode))
		return (NULL);
	return (newNode);
}

int	Go(Direction *dir, Map *map)
{
	MapNode		*topNode;
	Stack		*stack;

	stack = createStack();
	topNode = map->startNode;
	pushLS(stack, *topNode);
	while (topNode)
	{
		// first가 우향일 때, 갈 수 있으면 first안에서 
		// topNode 가 이동하고 TRUE
		if (topNode->x == map->endNode->x && topNode->y == map->endNode->y)
		{
			pushLS(stack, *topNode);
			free(topNode);
			displayPATH(stack->pTopElement);
			return (TRUE);
		}
		if ((*(t_func)dir->first)(topNode, stack, map))
			continue ;
		if ((*(t_func)dir->second)(topNode, stack, map))
			continue ;
		if ((*(t_func)dir->third)(topNode, stack, map))
			continue ;
		if ((*(t_func)dir->fourth)(topNode, stack, map))
			continue ;
		printf("===========================\n");
		free(topNode);
		topNode = popLS(stack);
	}
	return (FALSE);
}