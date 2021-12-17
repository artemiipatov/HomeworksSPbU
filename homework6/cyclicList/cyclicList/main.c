#include <stdio.h>
#include "cyclicListFunctions.h"
#include "cyclicListTests.h"

int main(int argc, char argv[])
{
    if (!cyclicListPassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    List* myList = createList();
    if (myList == NULL)
    {
        return -1;
    }
    Position* position = createPosition();
    if (position == NULL)
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