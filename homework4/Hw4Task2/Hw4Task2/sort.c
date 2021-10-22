#include "sort.h"
#include <stdio.h>

void insertionSort(int sequence[], int start, int end)
{
    for (int index = start + 1; index < end; index++)
    {
        int i = index;
        while (i > start && sequence[i] < sequence[i - 1])
        {
            const int temp = sequence[i - 1];
            sequence[i - 1] = sequence[i];
            sequence[i] = temp;
            --i;
        }
    }
}

void quickSort(int start, int end, int sequence[])
{
    if (end - start + 1 < 10)
    {
        insertionSort(sequence, start, end);
        return;
    }

    const int mainElement = sequence[start];
    int numberOfSmallerElements = 0;
    for (int index = start + 1; index < end; index++)
    {
        if (sequence[index] < mainElement)
        {
            ++numberOfSmallerElements;
        }
    }
    numberOfSmallerElements = numberOfSmallerElements + start;
    sequence[start] = sequence[numberOfSmallerElements];
    sequence[numberOfSmallerElements] = mainElement;

    int previousIndex = start;
    for (int greaterIndex = numberOfSmallerElements + 1; greaterIndex < end; greaterIndex++)
    {
        if (sequence[greaterIndex] < mainElement)
        {
            for (int smallerIndex = previousIndex; previousIndex < numberOfSmallerElements; smallerIndex++)
            {
                if (sequence[smallerIndex] >= mainElement)
                {
                    const int temp = sequence[smallerIndex];
                    sequence[smallerIndex] = sequence[greaterIndex];
                    sequence[greaterIndex] = temp;
                    previousIndex = smallerIndex;
                    break;
                }
            }
        }
    }

    if (numberOfSmallerElements - start >= 2)
    {
        quickSort(start, numberOfSmallerElements, sequence);
    }
    if (end - numberOfSmallerElements - 1 >= 2)
    {
        quickSort(numberOfSmallerElements + 1, end, sequence);
    }
}