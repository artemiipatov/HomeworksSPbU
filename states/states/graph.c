#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

typedef struct Node
{
    int index;
    Graph* graph;
} Node;

typedef struct Graph
{
    List** capitals;
    int numberOfCapitals;
    Node* cities[NUMBER_OF_CITIES]; 
    int numberOfCities;
    int matrix[NUMBER_OF_CITIES][NUMBER_OF_CITIES];
} Graph;

Graph* createGraph(void)
{
    Graph* graph = calloc(1, sizeof(Graph));
    graph->capitals = calloc(NUMBER_OF_CITIES, sizeof(List*));
    graph->numberOfCities = 0;
    return graph;
}

Node* addNode(Graph* graph, int index)
{
    Node* node = calloc(1, sizeof(Node));
    node->index = index;
    node->graph = graph;
    graph->cities[graph->numberOfCities] = node;
    ++graph->numberOfCities;
    return node;
}

int getEdge(Graph* graph, int start, int end)
{
    return graph->matrix[start][end];
}

void setEdge(Graph* graph, int firstNode, int secondNode, int weight)
{
    graph->matrix[firstNode][secondNode] = weight;
    graph->matrix[secondNode][firstNode] = weight;
}

Graph* parse(char* fileName)
{
    Graph* graph = createGraph();
    FILE* input = fopen(fileName, "r");
    int numberOfCities = 0;
    int numberOfRoads = 0;
    fscanf_s(input, "%d%*c", &numberOfCities);
    fscanf_s(input, "%d%*c", &numberOfRoads);
    for (int index = 0; index < numberOfRoads; index++)
    {
        int nodeIndex1 = 0;
        int nodeIndex2 = 0;
        int roadLength = 0;
        fscanf_s(input, "%d%*c", &nodeIndex1);
        fscanf_s(input, "%d%*c", &nodeIndex2);
        fscanf_s(input, "%d%*c", &roadLength);
        Node* node1 = addNode(graph, nodeIndex1);
        if (node1 == NULL)
        {
            return NULL;
        }
        Node* node2 = addNode(graph, nodeIndex2);
        if (node2 == NULL)
        {
            return NULL;
        }
        setEdge(graph, nodeIndex1, nodeIndex2, roadLength);
    }
    int numberOfCapitals = 0;
    fscanf_s(input, "%d%*c", &numberOfCapitals);
    graph->numberOfCapitals = numberOfCapitals;
    for (int index = 0; index < numberOfCapitals; index++)
    {
        int capitalIndex = 0;
        fscanf_s(input, "%d%*c", &capitalIndex);
        graph->capitals[index] = createList();
        addAtTail(graph->capitals[index], capitalIndex);
    }
    return graph;
}

void deleteColumn(Graph* graph, int column)
{
    for (int index = 0; index < NUMBER_OF_CITIES; index++)
    {
        graph->matrix[index][column] = 0;
    }
}

int getNumberOfCapitals(Graph* graph)
{
    return graph->numberOfCapitals;
}

int getNumberOfCities(Graph* graph)
{
    return graph->numberOfCities;
}

List** getCapitals(Graph* graph)
{
    return graph->capitals;
}

void getRelatedCities(Graph* graph, int city, int* cities[])
{
    *cities = graph->matrix[city];
}