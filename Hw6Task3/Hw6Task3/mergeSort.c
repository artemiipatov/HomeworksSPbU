#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "mergeSort.h"
#define NAME_SIZE 20

bool popAndAdd(List* popFrom, List* addTo)
{
    char* name = calloc(NAME_SIZE, sizeof(char));
    if (name == NULL)
    {
        return false;
    }
    int number = 0;
    popHead(popFrom, &name, &number);
    if (!addAtTail(addTo, name, number))
    {
        free(name);
        return false;
    }
    free(name);
    return true;
}

List* mergeSort(List* mainList, SortBy flag)
{
    int length = getLength(mainList);
    if (length == 1)
    {
        return mainList;
    }
    List* leftList = NULL;
    if (!createList(&leftList))
    {
        return NULL;
    }
    List* rightList = NULL;
    if (!createList(&rightList))
    {
        free(leftList);
        return NULL;
    }

    int halfLength = length / 2;
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

    while (!(isEmpty(leftBuffer) && isEmpty(rightBuffer)))
    {
        if (isEmpty(leftBuffer))
        {
            if (!popAndAdd(rightBuffer, mainList))
            {
                deleteList(&leftList);
                deleteList(&rightList);
                return NULL;
            }
            continue;
        }
        if (isEmpty(rightBuffer))
        {
            if (!popAndAdd(leftBuffer, mainList))
            {
                deleteList(&leftList);
                deleteList(&rightList);
                return NULL;
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
                    deleteList(&leftList);
                    deleteList(&rightList);
                    return NULL;
                }
            }
            else
            {
                if (!popAndAdd(rightBuffer, mainList))
                {
                    deleteList(&leftList);
                    deleteList(&rightList);
                    return NULL;
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
                    deleteList(&leftList);
                    deleteList(&rightList);
                    return NULL;
                }
            }
            else
            {
                if (!popAndAdd(rightBuffer, mainList))
                {
                    deleteList(&leftList);
                    deleteList(&rightList);
                    return NULL;
                }
            }
        }
        
    }
    free(leftList);
    free(rightList);
    return mainList;
}