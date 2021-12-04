#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

typedef struct Graph
{
    List** capitals;
    int numberOfCapitals;
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

void deleteGraph(Graph** graph)
{
    int numberOfCapitals = (*graph)->numberOfCapitals;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        deleteList(&((*graph)->capitals[i]));
    }
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

Graph* parse(char* fileName)
{
    Graph* graph = createGraph();
    FILE* input = fopen(fileName, "r");
    int numberOfCities = 0;
    int numberOfRoads = 0;
    fscanf_s(input, "%d%*c", &numberOfCities);
    graph->numberOfCities = numberOfCities;
    fscanf_s(input, "%d%*c", &numberOfRoads);
    for (int index = 0; index < numberOfRoads; index++)
    {
        int cityIndex1 = 0;
        int cityIndex2 = 0;
        int roadLength = 0;
        fscanf_s(input, "%d%*c", &cityIndex1);
        fscanf_s(input, "%d%*c", &cityIndex2);
        fscanf_s(input, "%d%*c", &roadLength);
        if (cityIndex1 >= NUMBER_OF_CITIES || cityIndex2 >= NUMBER_OF_CITIES)
        {
            printf("City index should be less than %d", NUMBER_OF_CITIES);
            fclose(input);
            return NULL;
        }
        setEdge(graph, cityIndex1, cityIndex2, roadLength);
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
    fclose(input);
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

void getRelatedCities(Graph* graph, int city, int* cities[NUMBER_OF_CITIES])
{
    *cities = graph->matrix[city];
}

void getMatrix(Graph* graph, int matrix[NUMBER_OF_CITIES][NUMBER_OF_CITIES])
{
    for (int row = 0; row < NUMBER_OF_CITIES; row++)
    {
        for (int column = 0; column < NUMBER_OF_CITIES; column++)
        {
            matrix[row][column] = graph->matrix[row][column];
        }
    }
}