
typedef struct NodeType
{
	int x;
	int	y; // 0, 1
	struct NodeType *Link;
} MapNode;

typedef struct Direction
{
	void	*first;
	void	*second;
	void	*third;
	void	*fourth;
} t_direction;



// nodef를 linked로 했을때 -> 움직이기 편해진다. 노드가 무거워진다.
// stack 쓸 이유가 잇나요? 

char	*graph[] = {"00000", "00000", "00000", "00000", "00000"};

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
typedef struct map
{
	int		row;
	int		column;
	MapNode	*startNode;
	MapNode	*endNode;
	char	*graph[];
} t_map;

int	main(void)
{
	char	*graph[] = {"00000", "00000", "00000", "00000", "00000"};


}