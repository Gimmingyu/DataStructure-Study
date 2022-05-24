#include "arraygraph.h"

int main(void)
{
	printf("Undirection Graph Test\n");
	printf("======================================================\n");
	printf("Test for 1 to 10\n");
	ArrayGraph *graph = createArrayGraph(10);

	printf("Graph must be empty at first: %d\n", isEmptyAG(graph));
	for (int i = 0; i < 10; i++)
		addVertexAG(graph, i);
	for (int i = 0; i < 10; i++)
		printf("%d ", graph->pVertex[i]);
	printf("\n");
	printf("Add Edge...\n");
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 1, 5);
	addEdgeAG(graph, 1, 7);
	addEdgeAG(graph, 1, 9);
	addEdgeAG(graph, 3, 5);
	addEdgeAG(graph, 3, 7);
	addEdgeAG(graph, 3, 9);
	addEdgeAG(graph, 5, 7);
	addEdgeAG(graph, 5, 9);
	addEdgeAG(graph, 7, 9);
	addEdgeAG(graph, 2, 4);
	addEdgeAG(graph, 2, 6);
	addEdgeAG(graph, 2, 8);
	addEdgeAG(graph, 4, 6);
	addEdgeAG(graph, 4, 8);
	addEdgeAG(graph, 6, 8);
	printf("======================================================\n");
	printf("Display Graph\n");
	displayArrayGraph(graph);
	printf("======================================================\n");
	printf("Test for remove number\n");
	for (int i = 0; i < 5; i++)
		removeVertexAG(graph, i);
	printf("======================================================\n");
	printf("Display Graph\n");
	displayArrayGraph(graph);
	sleep(1);
	deleteArrayGraph(graph);
	system("leaks a.out > leaks_result; cat leaks_result | \
	grep leaked && rm -rf leaks_result");

	printf("Direction Graph Test\n");
	printf("======================================================\n");
	printf("Test for 1 to 10\n");
	ArrayGraph *DirectedGraph = createArrayDirectedGraph(10);

	printf("Graph must be empty at first: %d\n", isEmptyAG(DirectedGraph));
	for (int i = 0; i < 10; i++)
		addVertexAG(DirectedGraph, i);
	for (int i = 0; i < 10; i++)
		printf("%d ", DirectedGraph->pVertex[i]);
	printf("\n");
	printf("Add Edge...\n");
	addEdgeAG(DirectedGraph, 1, 3);
	addEdgeAG(DirectedGraph, 1, 5);
	addEdgeAG(DirectedGraph, 1, 7);
	addEdgeAG(DirectedGraph, 1, 9);
	addEdgeAG(DirectedGraph, 3, 1);
	addEdgeAG(DirectedGraph, 5, 1);
	addEdgeAG(DirectedGraph, 7, 1);
	addEdgeAG(DirectedGraph, 9, 1);
	addEdgeAG(DirectedGraph, 3, 5);
	addEdgeAG(DirectedGraph, 3, 7);
	addEdgeAG(DirectedGraph, 3, 9);
	addEdgeAG(DirectedGraph, 5, 7);
	addEdgeAG(DirectedGraph, 5, 9);
	addEdgeAG(DirectedGraph, 7, 9);
	addEdgeAG(DirectedGraph, 2, 4);
	addEdgeAG(DirectedGraph, 2, 6);
	addEdgeAG(DirectedGraph, 2, 8);
	addEdgeAG(DirectedGraph, 4, 6);
	addEdgeAG(DirectedGraph, 4, 8);
	addEdgeAG(DirectedGraph, 6, 8);
	printf("======================================================\n");
	printf("Display DirectedGraph\n");
	displayArrayGraph(DirectedGraph);
	printf("======================================================\n");
	printf("Test for remove number\n");
	for (int i = 0; i < 5; i++)
		removeVertexAG(DirectedGraph, i);
	printf("======================================================\n");
	printf("Display Graph\n");
	displayArrayGraph(DirectedGraph);
	sleep(1);
	deleteArrayGraph(DirectedGraph);
	system("leaks a.out > leaks_result; cat leaks_result | \
	        grep leaked && rm -rf leaks_result");
	return (0);
}