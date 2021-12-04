#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "states.h"
#include"graphTests.h"

int main(void)
{
    if (!graphPassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    Graph* graph = parse("input.txt");
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
}