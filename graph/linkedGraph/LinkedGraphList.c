#include "./LinkedGraphList.h"

LinkedGraph *createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*newGraph = calloc(1, sizeof(LinkedGraph));

	newGraph->maxVertexCount = maxVertexCount;
	newGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	newGraph->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
	newGraph->graphType = UNDIRECTED;
	for (int i = 0; i < maxVertexCount; i++)
		newGraph->ppAdjEdge[i] = createLinkedList();
	return (newGraph);
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*newGraph = calloc(1, sizeof(LinkedGraph));

	newGraph->maxVertexCount = maxVertexCount;
	newGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	newGraph->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
	newGraph->graphType = DIRECTED;
	for (int i = 0; i < maxVertexCount; i++)
		newGraph->ppAdjEdge[i] = createLinkedList();
	return (newGraph);
}

void deleteLinkedGraph(LinkedGraph *pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyLG(LinkedGraph *pGraph)
{
	return (pGraph->currentVertexCount == 0 ? TRUE : FALSE);
}

int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
	if (pGraph->maxVertexCount <= vertexID || checkVertexValid(pGraph, vertexID))
		return (FALSE);
	pGraph->pVertex[vertexID] = 1;
	pGraph->currentVertexCount++;
	return (TRUE);
}

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1));
}

int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	toNode;
	LinkedList	*fromList;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	toNode.data.vertexID = toVertexID;
	toNode.data.weight = weight;
	fromList = pGraph->ppAdjEdge[fromVertexID];
	addLLElement(fromList, fromList->currentElementCount, toNode);
	if (pGraph->graphType == UNDIRECTED)
	{
		ListNode	fromNode;
		LinkedList	*toList = pGraph->ppAdjEdge[toVertexID];

		fromNode.data.vertexID = fromVertexID;
		fromNode.data.weight = weight;
		addLLElement(toList, toList->currentElementCount, fromNode);
	}
	return (TRUE);
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
	return (pGraph->pVertex[vertexID] == 1 ? TRUE : FALSE);
}

int	findById(LinkedList *pList, int vertexID)
{
	int	i = 0;
	ListNode	*temp;

	temp = pList->headerNode.pLink;
	while(temp)
	{
		if (temp->data.vertexID == vertexID)
			break ;
		temp = temp->pLink;
		i++;
	}
	return i;
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
	LinkedList	*list;

	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	list = pGraph->ppAdjEdge[vertexID];
	for (int i=0; i < pGraph->maxVertexCount; i++)
	{
		removeEdgeLG(pGraph, i, vertexID);
		if (pGraph->graphType == 1)
			removeEdgeLG(pGraph, vertexID, i);
	}
	pGraph->pVertex[vertexID] = 0;
	pGraph->currentVertexCount--;
	return (TRUE);
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	removeLLElement(pGraph->ppAdjEdge[fromVertexID], findById(pGraph->ppAdjEdge[fromVertexID], toVertexID));
	if (pGraph->graphType == UNDIRECTED)
		removeLLElement(pGraph->ppAdjEdge[toVertexID], findById(pGraph->ppAdjEdge[toVertexID], fromVertexID));
	return (TRUE);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	LinkedList	*temp;
	ListNode	*buf;

	for (int i = 0; i < pGraph->currentVertexCount; i++)
	{
		temp = pGraph->ppAdjEdge[i];
		buf = temp->headerNode.pLink;
		for(int j = 0; j < temp->currentElementCount; j++)
		{
			printf("from : %d to : %d \n", i, buf->data.vertexID);
			buf = buf->pLink;
		}
	}
}
