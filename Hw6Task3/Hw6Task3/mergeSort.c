#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "mergeSort.h"
#define NAME_SIZE 20

bool popAndAdd(List* popFrom, List* addTo)
{
    char name[NAME_SIZE] = { '\0' };
    int number = 0;
    popHead(popFrom, name, &number);
    if (!addAtTail(addTo, name, number))
    {
        return false;
    }
    return true;
}

bool mergeLists(List* mainList, List* leftBuffer, List* rightBuffer, SortBy flag)
{
    while (!(isEmpty(leftBuffer) && isEmpty(rightBuffer)))
    {
        if (isEmpty(leftBuffer))
        {
            if (!popAndAdd(rightBuffer, mainList))
            {
                return false;
            }
            continue;
        }
        if (isEmpty(rightBuffer))
        {
            if (!popAndAdd(leftBuffer, mainList))
            {
                return false;
            }
            continue;
        }

        if (flag == names)
        {
            char* leftValue = getHeadName(leftBuffer);
            char* rightValue = getHeadName(rightBuffer);
            if (strcmp(leftValue, rightValue) <= 0)
            {
                if (!popAndAdd(leftBuffer, mainList))
                {
                    return false;
                }
            }
            else
            {
                if (!popAndAdd(rightBuffer, mainList))
                {
                    return false;
                }
            }
        }
        else
        {
            int leftValue = getHeadNumber(leftBuffer);
            int rightValue = getHeadNumber(rightBuffer);
            if (leftValue <= rightValue)
            {
                if (!popAndAdd(leftBuffer, mainList))
                {
                    return false;
                }
            }
            else
            {
                if (!popAndAdd(rightBuffer, mainList))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

List* mergeSort(List* mainList, SortBy flag)
{
    const int length = getLength(mainList);
    if (length == 1)
    {
        return mainList;
    }
    List* leftList = createList();
    if (leftList == NULL)
    {
        return NULL;
    }
    List* rightList = createList();
    if (rightList == NULL)
    {
        deleteList(&leftList);
        return NULL;
    }
    const int halfLength = length / 2;
    for (int index = 0; index < halfLength; index++)
    {
        if (!popAndAdd(mainList, leftList))
        {
            deleteList(&leftList);
            deleteList(&rightList);
            return NULL;
        }
    }
    for (int index = halfLength; index < length; index++)
    {
        if (!popAndAdd(mainList, rightList))
        {
            deleteList(&leftList);
            deleteList(&rightList);
            return NULL;
        }
    }
    
    List* leftBuffer = mergeSort(leftList, flag);
    if (leftBuffer == NULL)
    {
        deleteList(&leftList);
        deleteList(&rightList);
        return NULL;
    }
    List* rightBuffer = mergeSort(rightList, flag);
    if (rightBuffer == NULL)
    {
        deleteList(&leftList);
        deleteList(&rightList);
        return NULL;
    }

    if (!mergeLists(mainList, leftBuffer, rightBuffer, flag))
    {
        deleteList(&leftList);
        deleteList(&rightList);
        return NULL;
    }

    free(leftList);
    free(rightList);
    return mainList;
}