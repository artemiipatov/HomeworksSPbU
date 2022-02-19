#pragma once
#define NUMBER_OF_NODES 20

// graph structure
typedef struct Graph Graph;

// deletes graph
void deleteGraph(Graph** graph);

// returns length of edge between two cities
int getEdge(Graph* graph, int firstNode, int secondNode);

Graph* readFile(char* fileName);

// deletes whole column
void deleteColumn(Graph* graph, int column);

// fills array with cities which have edge with given city
void getRelatedCities(Graph* graph, int city, int* cities[NUMBER_OF_NODES]);

// copies adjacency matrix to two 2d array
void getMatrix(Graph* graph, int matrix[NUMBER_OF_NODES][NUMBER_OF_NODES]);

void componentSearch(Graph* graph, int components[]);