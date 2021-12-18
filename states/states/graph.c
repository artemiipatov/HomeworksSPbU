#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include "graph.h"

typedef struct Graph
{
    int numberOfNodes;
    int matrix[NUMBER_OF_NODES][NUMBER_OF_NODES];
} Graph;

void deleteGraph(Graph** graph)
{
    free(*graph);
    *graph = NULL;
}

int getEdge(Graph* graph, const int start, const int end)
{
    return graph->matrix[start][end];
}

void setEdge(Graph* graph, const int firstNode, const int secondNode, const int weight)
{
    graph->matrix[firstNode][secondNode] = weight;
    graph->matrix[secondNode][firstNode] = weight;
}

Graph* buildGraph(FILE* input)
{
    Graph* graph = calloc(1, sizeof(Graph));
    if (graph == NULL)
    {
        return NULL;
    }
    graph->numberOfNodes = 0;
    int numberOfNodes = 0;
    int numberOfRoads = 0;
    fscanf_s(input, "%d%*c", &numberOfNodes);
    graph->numberOfNodes = numberOfNodes;
    fscanf_s(input, "%d%*c", &numberOfRoads);
    for (int index = 0; index < numberOfRoads; index++)
    {
        int nodeIndex1 = 0;
        int nodeIndex2 = 0;
        int roadLength = 0;
        fscanf_s(input, "%d%*c", &nodeIndex1);
        fscanf_s(input, "%d%*c", &nodeIndex2);
        fscanf_s(input, "%d%*c", &roadLength);
        if (nodeIndex1 >= NUMBER_OF_NODES || nodeIndex2 >= NUMBER_OF_NODES)
        {
            printf("City index should be less than %d", NUMBER_OF_NODES);
            deleteGraph(&graph);
            return NULL;
        }
        setEdge(graph, nodeIndex1, nodeIndex2, roadLength);
    }
    return graph;
}

void deleteColumn(Graph* graph, const int column)
{
    for (int index = 0; index < NUMBER_OF_NODES; index++)
    {
        graph->matrix[index][column] = 0;
    }
}

int getNumberOfNodes(Graph* graph)
{
    return graph->numberOfNodes;
}

void getMatrix(Graph* graph, int matrix[NUMBER_OF_NODES][NUMBER_OF_NODES])
{
    for (int row = 0; row < NUMBER_OF_NODES; row++)
    {
        for (int column = 0; column < NUMBER_OF_NODES; column++)
        {
            matrix[row][column] = graph->matrix[row][column];
        }
    }
}