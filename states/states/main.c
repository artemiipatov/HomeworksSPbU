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
    capture(graph);
    printStates(graph);
    deleteGraph(&graph);
}