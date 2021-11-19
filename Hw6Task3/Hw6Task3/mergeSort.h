#pragma once
#include "list.h"

// enumeration for pointing objects by which user wants to sort the list
typedef enum SortBy
{
    names,
    numbers
} SortBy;

// merge sort for list
List* mergeSort(List* mainList, SortBy flag);