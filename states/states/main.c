#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "states.h"

//bool nodeIsVisited(Node* node, Node* visitedNodes[], int length)
//{
//    for (int i = 0; i < length; i++)
//    {
//        if (node == visitedNodes[i])
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//void depthRecursive(Node* node, Node* result[], int* length)
//{
//    result[*length] = node;
//    (*length)++;
//    int nearNodesCount = 0;
//    Node** nearNodes = getNearNodes(node, &nearNodesCount);
//    for (int i = 0; i < nearNodesCount; i++)
//    {
//        if (!nodeIsVisited(nearNodes[i], result, *length))
//        {
//            depthRecursive(nearNodes[i], result, length);
//        }
//    }
//}
//
//Node** depthFirstSearch(Graph* graph, Node* startNode, int nodesCount)
//{
//    Node** result = calloc(nodesCount, sizeof(Node*));
//    int resultLength = 0;
//    depthRecursive(startNode, result, &resultLength);
//    return result;
//}

int main(void)
{
    Graph* graph = parse("input.txt");
    if (graph == NULL)
    {
        printf("An error occured while parsing");
        return -1;
    }
    capture(graph);
}