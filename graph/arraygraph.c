#include "./arraygraph.h"

// 무방향 그래프
ArrayGraph	*createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*newGraph = calloc(1, sizeof(ArrayGraph));
	size_t		idx = 0;

	newGraph->maxVertexCount = maxVertexCount;
	newGraph->pVertex = calloc(sizeof(int) , maxVertexCount);
	newGraph->ppAdjEdge = calloc(sizeof(int *), maxVertexCount);
	while (idx < maxVertexCount)
		newGraph->ppAdjEdge[idx++] = (int *)calloc(maxVertexCount, sizeof(int));
	newGraph->graphType = UnDirectedGraph;
	return (newGraph);
}

// 방향그래프
ArrayGraph	*createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*newGraph = calloc(1, sizeof(ArrayGraph));
	size_t		idx = 0;

	newGraph->maxVertexCount = maxVertexCount;
	newGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	newGraph->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
	while (idx < maxVertexCount)
		(newGraph->ppAdjEdge)[idx++] = calloc(maxVertexCount, sizeof(int));
	newGraph->graphType = DirectedGraph;
	return (newGraph);
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
	size_t	idx = 0;

	if (!pGraph || !(pGraph->pVertex) || !pGraph->ppAdjEdge)
		return ;
	free(pGraph->pVertex);
	while (idx < pGraph->maxVertexCount)
		free(pGraph->ppAdjEdge[idx++]);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

int isEmptyAG(ArrayGraph *pGraph)
{
	return (pGraph->currentVertexCount == 0 ? TRUE : FALSE);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	int	*ptr;

	if (!pGraph || pGraph->currentVertexCount >= pGraph->maxVertexCount)
		return (FALSE);
	pGraph->pVertex[pGraph->currentVertexCount] = vertexID;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	int	fromPosition;
	int	toPositon;

	if (!pGraph)
		return (FALSE);
	fromPosition = checkVertexValid(pGraph, fromVertexID);
	toPositon = checkVertexValid(pGraph, toVertexID);
	pGraph->ppAdjEdge[fromPosition][toPositon] = USED;
	return (TRUE);
}

int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	size_t	fromPosition = checkVertexValid(pGraph, fromVertexID);
	size_t	toPosition = checkVertexValid(pGraph, toVertexID);

	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	return (TRUE);
}

// 존재 유무확인? vs 연결된 간선이 있는지?
int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	size_t	idx = 0;

	if (!pGraph)
		return (FALSE);
	while (idx < pGraph->currentVertexCount)
	{
		if (pGraph->pVertex[idx] == vertexID)
			return (idx);
		idx++;
	}
	return (ERROR);
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	int	position;
	size_t	idx = 0;

	if (!pGraph || (position = checkVertexValid(pGraph, vertexID)) == ERROR)
		return (FALSE);
	pGraph->pVertex[position] = NOT_USED;
	while (idx < pGraph->maxVertexCount)
	{
		pGraph->ppAdjEdge[position][idx] = NOT_USED;
		pGraph->ppAdjEdge[idx][position] = NOT_USED;
		idx++;
	}
	return (TRUE);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	size_t	fromPosition = checkVertexValid(pGraph, fromPosition);
	size_t	toPosition = checkVertexValid(pGraph, toPosition);

	pGraph->ppAdjEdge[fromPosition][toPosition] = NOT_USED;
	return (TRUE);
}

void displayArrayGraph(ArrayGraph *pGraph)
{
	size_t	c = 0;
	size_t	r = 0;

	while (r < pGraph->maxVertexCount)
	{
		while (c < pGraph->maxVertexCount)
		{
			if (c == pGraph->maxVertexCount - 1)
				printf("%d", pGraph->ppAdjEdge[r][c]);
			else
				printf("%d ", pGraph->ppAdjEdge[r][c]);
			c++;
		}
		printf("\n");
		c = 0;
		r++;
	}
}
