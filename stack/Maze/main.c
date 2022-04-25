/*
함수 list
{
	Stack	*createStack(); // linked stack 참조 
	t_direction	*setDirection(t_map map); // 
		t_direction	*createDirection();
		void setDirection_LR(t_direction **dir_ptr, t_map map);
		void setDirection_UD(t_direction **dir_ptr, t_map map);
	int	go(direction, map); // 가다가 실패
		while (topNode)
			int	search_left(); // 성공 여부 반환
			int	search_right(); // 성공 여부 반환
			int	search_up(); // 성공 여부 반환
			int	search_down(); // 성공 여부 반환
			free(topNode);
			topNode = popLS();
	void	display_path(); //error 포함
	void	delete_map();
	void	exception_handling(Map) // start node, end node, map이 유효한지
	MapNode	*createMapNode();
}
0 = Path
1 = Wall 
탐색 순서를 결정할 때 map의 가로 세로를 고려해서 탐색 순서를 결정해줘야한다.
flag를 처음에 지정해서 어떤 순서로 탐색할 지를 정해줘야하는데
우햐향 
우상향
좌햐향
좌상향
우향탐색 하향탐색 좌향탐색 상향탐색
우향탐색, 좌향탐색, 하향탐색, 상향탐색
Node->Link = 단일경로
Link로 오면 해당 좌표를 1로 바꿔준다. graph[x][y] == 1 이면 못 가고 0이면 진행
더 이상 갈 곳이 없으면 stack에서 하나 pop하고 다른 경로 있는지 확인하고, 없으면 반복
 */
#include "Maze.h"

int	main(void)
{
	MapNode	*startNode;
	MapNode *endNode;
	Map		*map;
	Direction	*dir;

	int	row;
	int	column;
	char	**graph;

	scanf("%d %d", &row, &column);
	graph = calloc(row, sizeof(char *));
	for (int i = 0; i < row; i++)
	{
		graph[i] = calloc(column + 1, sizeof(char));
		scanf("%s\n", graph[i]);
	}

	startNode = createMapNode();
	endNode = createMapNode();
	startNode->x = 1;
	startNode->y = 0;
	endNode->x = 4;
	endNode->y = 4;
	map = createMap(5, 5, graph, startNode, endNode);
	dir = setDirection(map);
	printf("result = %d", Go(dir, map));
}
