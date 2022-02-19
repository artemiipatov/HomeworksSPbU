#include <stdlib.h>
#include "graphTests.h"
#include "states.h"

bool testCapturing(void)
{
    States* states = readFile("inputTest.txt");
    if (states == NULL)
    {
        return false;
    }
    if (!capture(states))
    {
        deleteStates(&states);
        return false;
    }
    List** arrayOfStates = getCapitals(states);
    int numberOfCapitals = getNumberOfCapitals(states);
    int correctStates[3][4] = { { 6, 3, 0, 7 }, { 4, 5 }, { 2, 1 } };
    for (int i = 0; i < numberOfCapitals; i++)
    {
        Position* position = createPosition();
        if (position == NULL)
        {
            deleteStates(&states);
            return false;
        }
        first(arrayOfStates[i], &position);
        int column = 0;
        while (!isNull(position))
        {
            if (getPositionValue(position) != correctStates[i][column])
            {
                deletePosition(&position);
                deleteStates(&states);
                return false;
            }
            next(&position);
            ++column;
        }
        deletePosition(&position);
    }
    deleteStates(&states);
    return states == NULL;
}

bool testParsing(void)
{
    States* states = readFile("inputTest.txt");
    if (states == NULL)
    {
        return false;
    }
    int matrix[NUMBER_OF_NODES][NUMBER_OF_NODES] = { 0 };
    getMatrix(getGraph(states), matrix);
    if (!(getNumberOfCities(states) == 8 && getNumberOfCapitals(states) == 3))
    {
        deleteStates(&states);
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
        deleteStates(&states);
        return false;
    }
    deleteStates(&states);
    return states == NULL;
}

bool graphPassedTests(void)
{
    return testParsing() && testCapturing();
}