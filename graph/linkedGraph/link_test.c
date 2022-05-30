#include "LinkedGraphList.h"

int main()
{
	LinkedGraph	*graph = createLinkedGraph(10);
	ListNode	node;

	printf("======================UNDIRECTED LinkedGraph TEST======================\n");

	printf("======================PUSH 0 to 9======================\n");
	addVertexLG(graph, 0);
	addVertexLG(graph, 1);
	addVertexLG(graph, 2);
	addVertexLG(graph, 3);
	addVertexLG(graph, 4);
	addVertexLG(graph, 5);
	addVertexLG(graph, 6);
	addVertexLG(graph, 7);
	addVertexLG(graph, 8);
	addVertexLG(graph, 9);

	printf("Now, Vertex Count = %d\n", graph->currentVertexCount);
	printf("======================MAKE EDGE TEST======================\n");
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 0, 4);
	addEdgeLG(graph, 0, 6);
	addEdgeLG(graph, 0, 8);
	addEdgeLG(graph, 1, 3);
	addEdgeLG(graph, 1, 5);
	addEdgeLG(graph, 1, 7);
	addEdgeLG(graph, 1, 9);
	addEdgeLG(graph, 2, 4);

	printf("======================DISPLAY======================\n");
	displayLinkedGraph(graph);
	return (0);
}