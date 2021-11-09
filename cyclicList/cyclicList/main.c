#include <stdio.h>
#include "cyclicListFunctions.h"
#include "cyclicListTests.h"

int main()
{
    if (!cyclicListPassedTests())
    {
        printf("Tests failed");
        return -1;
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
    first(myList, position);
    for (int index = 0; index < 8; index++)
    {
        printf("%d\n", get(myList, position));
        next(position);
    }
    deleteList(&myList);
    deletePosition(&position);
}