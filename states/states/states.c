#include <limits.h>
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

void capture(Graph* graph)
{
    int numberOfCapitals = getNumberOfCapitals(graph);
    int numberOfCities = getNumberOfCities(graph);
    int numberOfCapturedCities = numberOfCapitals;
    List** states = getCapitals(graph);
    while (numberOfCapturedCities < numberOfCities)
    {
        int index = numberOfCapturedCities % numberOfCapitals;
        List* state = states[index];
        int stateSize = getLength(state);
        int shortestWay = INT_MAX;
        int nearestCity = 0;
        Position* position = createPosition();
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
        addAtTail(state, nearestCity);
        deleteColumn(graph, nearestCity);
        deletePosition(&position);
        ++numberOfCapturedCities;
    }
}