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

int	Go(Map *map)
{
	MapNode		*topNode;
	Stack		*stack;
	Direction	*dir;

	stack = createStack();
	dir = setDirection(map);
	topNode = map->startNode;
	topNode->func = &FIRST;
	map->endNode->dist = 2147483647;
	// stack이 비게되면 topNode는 NULL이 된다.
	while (topNode)
	{
		// endNode 도착하면 거리를 갱신해주어야 한다.
		if (topNode->x == map->endNode->x && topNode->y == map->endNode->y)
		{
			pushLS(stack, *topNode);
			free(topNode);
			topNode = popLS(stack);
			break ;
		}
		// 함수 pointer가 NULL이다 == 이미 지나간 노드이고, 4방향 전부 진행했다.
		// 따라서 pop해준다.
		if (NULLCHECK(topNode->func))
		{
			free(topNode);
			topNode = popLS(stack);
			continue ;
		}
		// printf("a\n");
		// node의 함수 포인터 실행 -> (FSTF) -> (FSTF는 DIR의 fstf를 각각 실행)
		// true이면 이동에 성공 및 거리 증가
		// false이면 이동에 실패 --> 다음 함수 혹은 pop으로 가야한다. 
		if ((*(t_order)topNode->func)(map, &topNode, stack, dir))
			topNode->func = &FIRST;
	}
	displayPATH(topNode);
	free(topNode);
	free(dir);
	deleteLS(stack);
	deleteMap(map);
	return (TRUE);
}