#include <limits.h>
#include <stdio.h>
#include "list.h"
#include "states.h"

int getNearestCity(Graph* graph, int start, int* length)
{
    int cities[NUMBER_OF_CITIES] = { 0 };
    getRelatedCities(graph, start, &cities);
    int nearestCity = 0;
    for (int index = 0; index < NUMBER_OF_CITIES; index++)
    {
        int edge = getEdge(graph, start, index);
        if (edge != 0 && edge < *length)
        {
            *length = edge;
            nearestCity = index;
        }
    }
    return nearestCity;
}

void removeRoadsToCapitals(Graph* graph)
{
    List** capitals = getCapitals(graph);
    int numberOfCapitals = getNumberOfCapitals(graph);
    for (int i = 0; i < numberOfCapitals; i++)
    {
        deleteColumn(graph, getHeadNumber(capitals[i]));
    }
}

bool capture(Graph* graph)
{
    removeRoadsToCapitals(graph);
    int numberOfCapitals = getNumberOfCapitals(graph);
    int numberOfCities = getNumberOfCities(graph);
    int numberOfCapturedCities = numberOfCapitals;
    List** states = getCapitals(graph);
    int index = 0;
    while (numberOfCapturedCities < numberOfCities)
    {
        List* state = states[index % numberOfCapitals];
        int stateSize = getLength(state);
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
            int stateNumber = getCityIndex(position);
            int length = INT_MAX;
            int currentNearestCity = getNearestCity(graph, getPositionValue(position), &length);
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
            deleteColumn(graph, nearestCity);
        }
        ++index;
        deletePosition(&position);
    }
    return true;
}

void printStates(Graph* graph)
{
    int numberOfCapitals = getNumberOfCapitals(graph);
    List** capitals = getCapitals(graph);
    for (int i = 0; i < numberOfCapitals; i++)
    {
        printf("state %d\n", getHeadNumber(capitals[i]));
        printList(capitals[i]);
        printf("\n");
    }
}