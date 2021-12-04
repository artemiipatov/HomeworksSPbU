#include <stdlib.h>
#include "graphTests.h"
#include "graph.h"
#include "states.h"

bool testCapturing(void)
{
    Graph* graph = parse("inputTest.txt");
    if (graph == NULL)
    {
        return false;
    }
    if (!capture(graph))
    {
        return false;
    }
    List** states = getCapitals(graph);
    int numberOfCapitals = getNumberOfCapitals(graph);
    int correctStates[3][4] = { { 6, 3, 0, 7 }, { 4, 5 }, { 2, 1 } };
    for (int i = 0; i < numberOfCapitals; i++)
    {
        Position* position = createPosition();
        if (position == NULL)
        {
            deleteGraph(&graph);
            return false;
        }
        first(states[i], &position);
        int column = 0;
        while (!isNull(position))
        {
            if (getPositionValue(position) != correctStates[i][column])
            {
                deletePosition(&position);
                deleteGraph(&graph);
                return false;
            }
            next(&position);
            ++column;
        }
        deletePosition(&position);
    }
    deleteGraph(&graph);
    return graph == NULL;
}

bool testParsing(void)
{
    Graph* graph = parse("inputTest.txt");
    if (graph == NULL)
    {
        return false;
    }
    int matrix[NUMBER_OF_CITIES][NUMBER_OF_CITIES] = { 0 };
    getMatrix(graph, matrix);
    if (!(getNumberOfCities(graph) == 8 && getNumberOfCapitals(graph) == 3))
    {
        deleteGraph(&graph);
        return false;
    }
    if (!(matrix[0][1] == matrix[1][0] && matrix[0][1] == 7
        && matrix[1][2] == matrix[2][1] && matrix[1][2] == 5
        && matrix[2][3] == matrix[3][2] && matrix[2][3] == 8
        && matrix[3][4] == matrix[4][3] && matrix[3][4] == 21
        && matrix[4][5] == matrix[5][4] && matrix[4][5] == 1
        && matrix[4][0] == matrix[0][4] && matrix[4][0] == 2
        && matrix[5][6] == matrix[6][5] && matrix[5][6] == 9
        && matrix[6][0] == matrix[0][6] && matrix[6][0] == 3
        && matrix[6][1] == matrix[1][6] && matrix[6][1] == 10
        && matrix[6][2] == matrix[2][6] && matrix[6][2] == 13
        && matrix[6][3] == matrix[3][6] && matrix[6][3] == 1
        && matrix[6][4] == matrix[4][6] && matrix[6][4] == 6
        && matrix[6][7] == matrix[7][6] && matrix[6][7] == 34))
    {
        deleteGraph(&graph);
        return false;
    }
    deleteGraph(&graph);
    return graph == NULL;
}

bool graphPassedTests(void)
{
    return testParsing() && testCapturing();
}