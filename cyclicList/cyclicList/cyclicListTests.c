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
<<<<<<< HEAD:list/list/listTests.c
        deletePosition(&position);
=======
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListTests.c
        deleteList(&testList);
        return false;
    }
    const int correctOrder1[14] = { 10, 15, 7, 12, 7, 2, 20, 10, 15, 7, 12, 7, 2, 20 };
    first(testList, position);
    for (int index = 0; index < 14; index++)
    {
        if (get(testList, position) != correctOrder1[index])
        {
            deletePosition(&position);
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
            deletePosition(&position);
            deleteList(&testList);
            return false;
        }
        next(position);
    }

    first(testList, position);
    next(position);
    next(position);
    deleteItem(testList, position);
    deleteItem(testList, position);
<<<<<<< HEAD:list/list/listTests.c
    const int correctOrder3[4] = { 15, 7, 2, 20 };
    currentIndex = 0;
    for (first(testList, position); !last(position); next(position))
=======
    next(position);
    const int correctOrder3[8] = { 15, 7, 2, 20, 15, 7, 2, 20 };
    first(testList, position);
    for (int index = 0; index < 8; index++)
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListTests.c
    {
        if (get(testList, position) != correctOrder3[index])
        {
<<<<<<< HEAD:list/list/listTests.c
            deletePosition(&position);
=======
            free(position);
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListTests.c
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
<<<<<<< HEAD:list/list/listTests.c
            deletePosition(&position);
=======
            free(position);
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListTests.c
            deleteList(&testList);
            return false;
        }
        next(position);
    }
    deleteItem(testList, first(testList, position));
    deleteItem(testList, first(testList, position));
<<<<<<< HEAD:list/list/listTests.c
    if (!last(first(testList, position)))
    {
        deletePosition(&position);
        deleteList(&testList);
        return false;
    }
=======
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListTests.c

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
        || last(testList, first(testList, position)))
    {
<<<<<<< HEAD:list/list/listTests.c
        deletePosition(&position);
=======
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListTests.c
        deleteList(&testList);
        return false;
    }
    deleteList(&testList);
    deletePosition(&position);
    return testList == NULL && position == NULL;
}