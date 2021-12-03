#pragma once
#include "list.h"
#define NUMBER_OF_CITIES 20

typedef struct Graph Graph;

typedef struct Node Node;

Graph* createGraph(void);

Node* addNode(Graph* graph, int value);

int getEdge(Graph* graph, int firstNode, int secondNode);

void setEdge(Graph* graph, int firstNode, int secondNode, int weight);

Graph* parse(char* fileName);

void deleteColumn(Graph* graph, int column);

int getNumberOfCapitals(Graph* graph);

int getNumberOfCities(Graph* graph);

List** getCapitals(Graph* graph);

void getRelatedCities(Graph* graph, int city, int* cities[]);