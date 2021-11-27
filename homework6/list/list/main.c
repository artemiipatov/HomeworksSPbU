#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listTests.h"

int main(int argc, char argv[])
{
    if (!listTestsPassed())
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    List* myList = NULL;
    if (!createList(&myList))
    {
        return -1;
    }
    Position* position = NULL;
    if (!createPosition(&position))
    {
        deleteList(&myList);
        return -1;
    }
    add(myList, first(myList, position), 1);
    add(myList, first(myList, position), 2);
    next(position);
    add(myList, position, 3);
    next(position);
    add(myList, position, 4);
    for (first(myList, position); !last(position); next(position))
    {
        printf("%d ", get(myList, position));
    }
    deleteList(&myList);
    deletePosition(&position);
}