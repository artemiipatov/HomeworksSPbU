#pragma once
#include "list.h"
#define NUMBER_OF_CITIES 20

// graph structure
typedef struct Graph Graph;

// deletes graph
void deleteGraph(Graph** graph);

// returns length of edge between two cities
int getEdge(Graph* graph, int firstNode, int secondNode);

// parses file
Graph* readFile(char* fileName);

// deletes whole column
void deleteColumn(Graph* graph, int column);

// returns number of capitals
int getNumberOfCapitals(Graph* graph);

// returns number of cities (graph nodes)
int getNumberOfCities(Graph* graph);

// returns array of lists with capitals
List** getCapitals(Graph* graph);

// fills array with cities which have edge with given city
void getRelatedCities(Graph* graph, int city, int* cities[NUMBER_OF_CITIES]);

// copies adjacency matrix to two 2d array
void getMatrix(Graph* graph, int matrix[NUMBER_OF_CITIES][NUMBER_OF_CITIES]);