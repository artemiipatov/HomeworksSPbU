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
    Graph* graph = readFile("input.txt");
    if (graph == NULL)
    {
        printf("An error occured while parsing");
        return -1;
    }
    if (!capture(graph))
    {
        printf("An error occured while capturing world");
        return -1;
    }
    printStates(graph);
    deleteGraph(&graph);
    return 0;
}