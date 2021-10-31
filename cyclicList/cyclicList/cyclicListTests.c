#include <stdbool.h>
#include <stdlib.h>
#include "cyclicListFunctions.h"
#include "cyclicListTests.h"

bool cyclicListPassedTests()
{
    List* testList = NULL;
    if (!createList(&testList) || testList == NULL)
    {
        return false;
    }
    Position* position = NULL;
    if (!createPosition(&position))
    {
        free(testList);
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
        return false;
    }
    const int correctOrder1[14] = { 10, 15, 7, 12, 7, 2, 20, 10, 15, 7, 12, 7, 2, 20 };
    first(testList, position);
    for (int index = 0; index < 14; index++)
    {
        if (get(testList, position) != correctOrder1[index])
        {
            free(position);
            deleteList(&testList);
            return false;
        }
        next(position);
    }

    first(testList, position);
    deleteItem(testList, position);
    const int correctOrder2[12] = { 15, 7, 12, 7, 2, 20, 15, 7, 12, 7, 2, 20 };
    first(testList, position);
    for (int index = 0; index < 12; index++)
    {
        if (get(testList, position) != correctOrder2[index])
        {
            free(position);
            deleteList(&testList);
            return false;
        }
        next(position);
    }

    first(testList, position);
    next(position);
    next(position);
    deleteItem(testList, position);
    next(position);
    deleteItem(testList, position);
    next(position);
    const int correctOrder3[8] = { 15, 7, 2, 20, 15, 7, 2, 20 };
    first(testList, position);
    for (int index = 0; index < 8; index++)
    {
        if (get(testList, position) != correctOrder3[index])
        {
            free(position);
            deleteList(&testList);
            return false;
        }
        next(position);
    }

    deleteItem(testList, first(testList, position));
    first(testList, position);
    next(position);
    next(position);
    deleteItem(testList, position);
    const int correctOrder4[6] = { 7, 2, 7, 2, 7, 2 };
    first(testList, position);
    for (int index = 0; index < 6; index++)
    {
        if (get(testList, position) != correctOrder4[index])
        {
            free(position);
            deleteList(&testList);
            return false;
        }
        next(position);
    }
    deleteItem(testList, first(testList, position));
    deleteItem(testList, first(testList, position));

    // deleteList() testing
    deleteList(&testList);
    if (!createList(&testList))
    {
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
        || last(testList, first(testList, position)))
    {
        return false;
    }
    deleteList(&testList);
    deletePosition(&position);
    return testList == NULL && position == NULL;
}