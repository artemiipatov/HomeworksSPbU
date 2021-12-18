#pragma once
#include "graph.h"
#include <stdbool.h>

// states structure
typedef struct States States;

// deletes states
void deleteStates(States** states);

// creates states structure and reads data from file
States* readFile(const char* fileName);

// returns array of capitals
List** getCapitals(States* states);

// captures city 
bool capture(States* states);

// returns graph of cities and roads
Graph* getGraph(States* states);

// returns number of capitals
int getNumberOfCapitals(States* states);

// returns number of cities
int getNumberOfCities(States* states);

// prints states with capital and captured cities
void printStates(States* states);