#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "states.h"
#include"graphTests.h"

int main(int argc, char argv[])
{
    if (!graphPassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    States* states = readFile("input.txt");
    if (states == NULL)
    {
        printf("An error occured while reading file");
        return -1;
    }
    if (!capture(states))
    {
        printf("An error occured while capturing world");
        return -1;
    }
    printStates(states);
    deleteStates(&states);
    return 0;
}