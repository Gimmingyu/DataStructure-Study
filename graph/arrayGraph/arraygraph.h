#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERROR = -1,
} t_flag;

typedef enum e_type
{
	DirectedGraph,
	UnDirectedGraph	
} t_type;

typedef struct ArrayGraphType
{
	int maxVertexCount;
	int currentVertexCount;
	int graphType;
	int **ppAdjEdge;
	int *pVertex;
} ArrayGraph;

ArrayGraph *createArrayGraph(int maxVertexCount);
ArrayGraph *createArrayDirectedGraph(int maxVertexCount);

void deleteArrayGraph(ArrayGraph *pGraph);

int isEmptyAG(ArrayGraph *pGraph);

int addVertexAG(ArrayGraph *pGraph, int vertexID);

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(ArrayGraph *pGraph, int vertexID);

int removeVertexAG(ArrayGraph *pGraph, int vertexID);

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);

void displayArrayGraph(ArrayGraph *pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2
#endif
