#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "listTests.h"

bool listTestsPassed()
{
    List* testList = NULL;
    if (!createList(&testList) || testList == NULL)
    {
        return false;
    }
    Position* position = NULL;
    if (!createPosition(&position))
    {
        deleteList(&testList);
        return false;
    }

    // testing all functions
    first(testList, position);
    if (!add(testList, position, 10)
        || !add(testList, first(testList, position), 15)
        || !next(position)
        || !add(testList, position, 7)
        || !next(position)
        || !add(testList, position, 12)
        || !next(position)
        || !add(testList, position, 7)
        || !next(position)
        || !add(testList, position, 2)
        || !next(position)
        || !add(testList, position, 20))
    {
        deletePosition(&position);
        deleteList(&testList);
        return false;
    }
    const int correctOrder1[7] = { 10, 15, 7, 12, 7, 2, 20 };
    int currentIndex = 0;
    for (first(testList, position); !last(position); next(position))
    {
        if (get(testList, position) != correctOrder1[currentIndex])
        {
            deletePosition(&position);
            deleteList(&testList);
            return false;
        }
        currentIndex++;
    }
    first(testList, position);
    deleteItem(testList, position);
    const int correctOrder2[6] = { 15, 7, 12, 7, 2, 20 };
    currentIndex = 0;
    for (first(testList, position); !last(position); next(position))
    {
        if (get(testList, position) != correctOrder2[currentIndex])
        {
            deletePosition(&position);
            deleteList(&testList);
            return false;
        }
        currentIndex++;
    }
    first(testList, position);
    next(position);
    next(position);
    deleteItem(testList, position);
    deleteItem(testList, position);
    const int correctOrder3[4] = { 15, 7, 2, 20 };
    currentIndex = 0;
    for (first(testList, position); !last(position); next(position))
    {
        if (get(testList, position) != correctOrder3[currentIndex])
        {
            deletePosition(&position);
            deleteList(&testList);
            return false;
        }
        currentIndex++;
    }
    deleteItem(testList, first(testList, position));
    first(testList, position);
    next(position);
    next(position);
    deleteItem(testList, position);
    const int correctOrder4[2] = { 7, 2 };
    currentIndex = 0;
    for (first(testList, position); !last(position); next(position))
    {
        if (get(testList, position) != correctOrder4[currentIndex])
        {
            deletePosition(&position);
            deleteList(&testList);
            return false;
        }
        currentIndex++;
    }
    deleteItem(testList, first(testList, position));
    deleteItem(testList, first(testList, position));
    if (!last(first(testList, position)))
    {
        deletePosition(&position);
        deleteList(&testList);
        return false;
    }

    // deleteList() testing
    deleteList(&testList);
    if (!createList(&testList))
    {
        deletePosition(&position);
        return false;
    }
    first(testList, position);
    if (!add(testList, position, 10)
        || !add(testList, first(testList, position), 15)
        || !next(position)
        || !add(testList, position, 7)
        || !next(position)
        || !add(testList, position, 12)
        || !next(position)
        || !add(testList, position, 7)
        || !next(position)
        || !add(testList, position, 2)
        || !next(position)
        || !add(testList, position, 20)
        || last(first(testList, position)))
    {
        deletePosition(&position);
        deleteList(&testList);
        return false;
    }
    deleteList(&testList);
    deletePosition(&position);
    return testList == NULL && position == NULL;
}