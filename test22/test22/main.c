#include <stdio.h>
#include "graph.h"

int main()
{
    Graph* graph = readFile("input.txt");
    if (graph == NULL)
    {
        printf("An error occured while reading file");
        return -1;
    }
    int components[100] = { 0 };
    componentSearch(graph, components);
    int rank = getRank(graph);
    for (int i = 0; i < rank; i++)
    {
        printf("node %d %d\n", i, components[i]);
    }
    return 0;
}