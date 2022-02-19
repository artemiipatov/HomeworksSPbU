#pragma once
#include <stdio.h>
#include "list.h"
#define NUMBER_OF_NODES 20

// graph structure
typedef struct Graph Graph;

// deletes graph
void deleteGraph(Graph** graph);

// returns length of edge between two cities
int getEdge(Graph* graph, const int start, const int end);

// parses file
Graph* buildGraph(FILE* input);

// deletes whole column
void deleteColumn(Graph* graph, const int column);

// returns number of graph nodes
int getNumberOfNodes(Graph* graph);

// copies adjacency matrix to 2d array
void getMatrix(Graph* graph, int matrix[NUMBER_OF_NODES][NUMBER_OF_NODES]);