#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../list/list/list.h"
#include "sortedListFunctions.h"

bool addItemToSortedList(List* list, int value)
{
    Position* firstItem = NULL;
    if (!createPosition(&firstItem))
    {
        return false;
    }
    Position* currentIndex = NULL;
    if (!createPosition(&currentIndex))
    {
        free(firstItem);
        return false;
    }
    Position* iterator = NULL;
    if (!createPosition(&iterator))
    {
        free(firstItem);
        free(currentIndex);
        return false;
    }
    for (first(list, iterator); !last(iterator); next(iterator))
    {
        if (get(list, iterator) < value)
        {
            copyPosition(iterator, currentIndex);
            continue;
        }
        if (comparePositions(iterator, first(list, firstItem)))
        {
            add(list, NULL, value);
        }
        else
        {
            add(list, currentIndex, value);
        }
        deletePosition(&firstItem);
        deletePosition(&currentIndex);
        deletePosition(&iterator);
        return true;
    }
    if (first(list, firstItem) == NULL)
    {
        add(list, firstItem, value);
    }
    else
    {
        add(list, currentIndex, value);
    }
    deletePosition(&firstItem);
    deletePosition(&currentIndex);
    deletePosition(&iterator);
    return true;
}

bool deleteItemByIndex(List* list, int itemIndex)
{
    int currentIndex = 0;
    Position* iterator = NULL;
    if (!createPosition(&iterator))
    {
        return false;
    }
    for (first(list, iterator); !last(iterator) || currentIndex > itemIndex; next(iterator))
    {
        if (currentIndex == itemIndex)
        {
            deleteItem(list, iterator);
            deletePosition(&iterator);
            return true;
        }
        currentIndex++;
    }
    deletePosition(&iterator);
    return false;
}

bool printList(List* list)
{
    Position* iterator = NULL;
    if (!createPosition(&iterator))
    {
        return false;
    }
    for (first(list, iterator); !last(iterator); next(iterator))
    {
        printf("%d ", get(list, iterator));
    }
    deletePosition(&iterator);
    return true;
}