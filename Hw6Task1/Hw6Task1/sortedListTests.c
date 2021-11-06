#include <stdbool.h>
#include <stdlib.h>
#include "../../list/list/list.h"
#include "sortedListFunctions.h"
#include "sortedListTests.h"

bool sortedListTestsPassed()
{
    List* list = NULL;
    if (!createList(&list))
    {
        return false;
    }
    if (!addItemToSortedList(list, 7))
    {
        deleteList(&list);
        return false;
    }
    if (!addItemToSortedList(list, 10))
    {
        deleteList(&list);
        return false;
    }
    if (!addItemToSortedList(list, 3))
    {
        deleteList(&list);
        return false;
    }
    if (!addItemToSortedList(list, 8))
    {
        deleteList(&list);
        return false;
    }
    if (!addItemToSortedList(list, 5))
    {
        deleteList(&list);
        return false;
    }
    if (!addItemToSortedList(list, 6))
    {
        deleteList(&list);
        return false;
    }
    const int correctSortedArray1[6] = { 3, 5, 6, 7, 8, 10 };
    int currentIndex = 0;
    Position* index = NULL;
    if (!createPosition(&index))
    {
        deleteList(&list);
        return false;
    }
    for (first(list, index); !last(index); next(index))
    {
        if (get(list, index) != correctSortedArray1[currentIndex])
        {
            deletePosition(&index);
            deleteList(&list);
            return false;
        }
        currentIndex++;
    }
    deleteItemByIndex(list, 3);
    const int correctSortedArray2[5] = { 3, 5, 6, 8, 10 };
    currentIndex = 0;
    for (first(list, index); !last(index); next(index))
    {
        if (get(list, index) != correctSortedArray2[currentIndex])
        {
            deletePosition(&index);
            deleteList(&list);
            return false;
        }
        currentIndex++;
    }
    deleteItemByIndex(list, 4);
    const int correctSortedArray3[4] = { 3, 5, 6, 8 };
    currentIndex = 0;
    for (first(list, index); !last(index); next(index))
    {
        if (get(list, index) != correctSortedArray3[currentIndex])
        {
            deletePosition(&index);
            deleteList(&list);
            return false;
        }
        currentIndex++;
    }
    addItemToSortedList(list, 7);
    const int correctSortedArray4[5] = { 3, 5, 6, 7, 8 };
    currentIndex = 0;
    for (first(list, index); !last(index); next(index))
    {
        if (get(list, index) != correctSortedArray4[currentIndex])
        {
            deletePosition(&index);
            deleteList(&list);
            return false;
        }
        currentIndex++;
    }
    deleteItemByIndex(list, 3);
    deleteItemByIndex(list, 0);
    const int correctSortedArray5[3] = { 5, 6, 8 };
    currentIndex = 0;
    for (first(list, index); !last(index); next(index))
    {
        if (get(list, index) != correctSortedArray5[currentIndex])
        {
            deletePosition(&index);
            deleteList(&list);
            return false;
        }
        currentIndex++;
    }
    deleteItemByIndex(list, 2);
    const int correctSortedArray6[2] = { 5, 6 };
    currentIndex = 0;
    for (first(list, index); !last(index); next(index))
    {
        if (get(list, index) != correctSortedArray6[currentIndex])
        {
            deletePosition(&index);
            deleteList(&list);
            return false;
        }
        currentIndex++;
    }
    deleteItemByIndex(list, 1);
    if (get(list, first(list, index)) != 5)
    {
        deletePosition(&index);
        deleteList(&list);
        return false;
    }
    deleteItemByIndex(list, 0);
    bool isEmpty = last(first(list, index));
    deleteList(&list);
    return isEmpty;
}