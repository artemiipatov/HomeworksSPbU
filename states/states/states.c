#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdlib.h>
#include "states.h"

typedef struct States
{
    List** capitals;
    int numberOfCapitals;
    Graph* graph;
} States;

States* createStates(void)
{
    States* states = calloc(1, sizeof(States));
    if (states == NULL)
    {
        return NULL;
    }
    states->capitals = calloc(NUMBER_OF_NODES, sizeof(List*));
    return states->capitals == NULL ? NULL : states;
}

void deleteStates(States** states)
{
    deleteGraph(&((*states)->graph));
    const int numberOfCapitals = (*states)->numberOfCapitals;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        deleteList(&((*states)->capitals[i]));
    }
    free((*states)->capitals);
    (*states)->capitals = NULL;
    free(*states);
    *states = NULL;
}

States* readFile(const char* fileName)
{
    States* states = createStates();
    if (states == NULL)
    {
        return NULL;
    }
    FILE* input = fopen(fileName, "r");
    if (input == NULL)
    {
        return NULL;
    }
    states->graph = buildGraph(input);
    if (states->graph == NULL)
    {
        deleteStates(&states);
        fclose(input);
        return NULL;
    }
    int numberOfCapitals = 0;
    fscanf_s(input, "%d", &numberOfCapitals);
    states->numberOfCapitals = numberOfCapitals;
    for (int index = 0; index < numberOfCapitals; index++)
    {
        int capitalIndex = 0;
        fscanf_s(input, "%d", &capitalIndex);
        states->capitals[index] = createList();
        if (!addAtTail(states->capitals[index], capitalIndex))
        {
            deleteStates(&states);
            fclose(input);
            return NULL;
        }
    }
    fclose(input);
    return states;
}

List** getCapitals(States* states)
{
    return states->capitals;
}

int getNearestCity(States* states, int start, int* length)
{
    int nearestCity = 0;
    for (int index = 0; index < NUMBER_OF_NODES; index++)
    {
        int edge = getEdge(states->graph, start, index);
        if (edge != 0 && edge < *length)
        {
            *length = edge;
            nearestCity = index;
        }
    }
    return nearestCity;
}

void removeRoadsToCapitals(States* states)
{
    List** capitals = getCapitals(states);
    const int numberOfCapitals = states->numberOfCapitals;
    for (int i = 0; i < numberOfCapitals; i++)
    {
        deleteColumn(states->graph, getHeadNumber(capitals[i]));
    }
}

bool capture(States* states)
{
    removeRoadsToCapitals(states);
    const int numberOfCapitals = states->numberOfCapitals;
    const int numberOfCities = getNumberOfNodes(states->graph);
    int numberOfCapturedCities = numberOfCapitals;
    List** arrayOfStates = getCapitals(states);
    int index = 0;
    while (numberOfCapturedCities < numberOfCities)
    {
        List* state = arrayOfStates[index % numberOfCapitals];
        const int stateSize = getLength(state);
        int shortestWay = INT_MAX;
        int nearestCity = -1;
        Position* position = createPosition();
        if (position == NULL)
        {
            return false;
        }
        first(state, &position);
        for (int i = 0; i < stateSize; i++)
        {
            int stateNumber = getPositionValue(position);
            int length = INT_MAX;
            int currentNearestCity = getNearestCity(states, getPositionValue(position), &length);
            if (length < shortestWay)
            {
                shortestWay = length;
                nearestCity = currentNearestCity;
            }
            next(&position);
        }
        if (nearestCity != -1)
        {
            addAtTail(state, nearestCity);
            ++numberOfCapturedCities;
            deleteColumn(states->graph, nearestCity);
        }
        ++index;
        deletePosition(&position);
    }
    return true;
}

Graph* getGraph(States* states)
{
    return states->graph;
}

int getNumberOfCapitals(States* states)
{
    return states->numberOfCapitals;
}

int getNumberOfCities(States* states)
{
    return getNumberOfNodes(states->graph);
}

void printStates(States* states)
{
    const int numberOfCapitals = states->numberOfCapitals;
    List** capitals = getCapitals(states);
    for (int i = 0; i < numberOfCapitals; i++)
    {
        printf("state %d\n", getHeadNumber(capitals[i]));
        printList(capitals[i]);
        printf("\n");
    }
}