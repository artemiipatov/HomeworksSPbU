#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

typedef struct Graph
{
    int matrix[NUMBER_OF_NODES][NUMBER_OF_NODES];
    int rank;
} Graph;

Graph* createGraph(void)
{
    return calloc(1, sizeof(Graph));
}

void deleteGraph(Graph** graph)
{
    free(*graph);
    *graph = NULL;
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

Graph* readFile(char* fileName)
{
    Graph* graph = createGraph();
    if (graph == NULL)
    {
        return NULL;
    }
    FILE* inputFile = fopen(fileName, "r");
    if (inputFile == NULL)
    {
        return NULL;
    }
    int rank = 0;
    fscanf_s(inputFile, "%d%*c", &rank);
    graph->rank = rank;
    for (int raw = 0; raw < rank; raw++)
    {
        for (int col = 0; col < rank; col++)
        {
            fscanf_s(inputFile, "%d%*c", &(graph->matrix[raw][col]));
        }
    }
    fclose(inputFile);
    return graph;
}

void deleteColumn(Graph* graph, int column)
{
    for (int index = 0; index < NUMBER_OF_NODES; index++)
    {
        graph->matrix[index][column] = 0;
    }
}

void getRelatedCities(Graph* graph, int city, int* cities[NUMBER_OF_NODES])
{
    *cities = graph->matrix[city];
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

int getRank(Graph* graph)
{
    return graph->rank;
}

void dfs(Graph* graph, int nodeRaw, int componentNumber, bool used[], int components[])
{
    used[nodeRaw] = true;
    components[nodeRaw] = componentNumber;
    int rank = graph->rank;
    for (int col = 0; col < rank; col++)
    {
        if (!used[col])
        {
            dfs(graph, col, componentNumber, used, components);
        }
    }
}

void componentSearch(Graph* graph, int components[])
{
    bool used[20] = { false };
    int rank = graph->rank;
    int componentNumber = 1;
    for (int raw = 0; raw < rank; raw++)
    {
        if (!used[raw])
        {
            dfs(graph, raw, componentNumber, used, components);
            ++componentNumber;
        }
    }
}