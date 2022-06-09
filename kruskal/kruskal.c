#include "./kruskal.h"

// 부모 노드 탐색
int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent, parent[x]);
}

// 부모 노드 합치기
void	unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

// 같은 부모인지 확인
int isParentSame(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b)
		return TRUE;
	return FALSE;
}


