#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

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

    // Counting smaller elements
    const int mainElement = sequence[start];
    int numberOfSmallerElements = 0;
    for (int index = start + 1; index < end; index++)
    {
        if (sequence[index] < mainElement)
        {
            ++numberOfSmallerElements;
        }
    }

    // put first elements on correct position
    numberOfSmallerElements = numberOfSmallerElements + start;
    sequence[start] = sequence[numberOfSmallerElements];
    sequence[numberOfSmallerElements] = mainElement;

    // repositioning 
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

    // Quicksort
    if (numberOfSmallerElements - start >= 2)
    {
        quickSort(start, numberOfSmallerElements, sequence);
    }
    if (end - numberOfSmallerElements - 1 >= 2)
    {
        quickSort(numberOfSmallerElements + 1, end, sequence);
    }
}

int binarySearch(const int wantedElement, int sequence[], const int left, const int right)
{
    if (right - left < 2)
    {
        return false;
    }
    const int medium = (right + left) / 2;
    if (wantedElement == sequence[medium])
    {
        return true;
    }
    else if (wantedElement < sequence[medium])
    {
        binarySearch(wantedElement, sequence, left, medium);
    }
    else
    {
        binarySearch(wantedElement, sequence, medium, right);
    }
}

bool testQSortCorrectExecution()
{
    // One element array test
    int testArray[1] = { 5 };
    quickSort(0, 1, testArray);
    if (!(testArray[0] == 5))
    {   
        return false;
    }

    // identical elements test
    int testArray1[12] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    quickSort(0, 12, testArray1);
    for (int index = 0; index < 12; index++)
    {
        if (testArray1[index] != 5)
        {
            return false;
        }
    }

    // random elements tests
    srand(4);
    for (int number = 0; number < 4; number++)
    {
        int testArray2[30] = { 0 };
        for (int index = 0; index < 30; index++)
        {
            testArray2[index] = rand() % 10;
        }
        quickSort(0, 30, testArray2);
        for (int index = 1; index < 30; index++)
        {
            if (testArray2[index - 1] > testArray2[index])
            {
                return false;
            }
        }
    }
    return true;
}

bool testBinSearchCorrectExecution()
{
    const int testMainArray[11] = { 0, 5, 2, 0, 0, 1, 6, 3, 5, 2, 3 };
    const int toSearch[8] = { 5, 0, 2, 3, 10, 8, 9, 2 };
    const int foundElements[5] = { 5, 0, 2, 3, 2 };
    quickSort(0, 11, testMainArray);
    int counter = 0;

    for (int index = 0; index < 8; index++)
    {
        if (binarySearch(toSearch[index], testMainArray, 0, 8))
        {
            if (foundElements[counter] == toSearch[index])
            {
                ++counter;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // Test
    if (!testQSortCorrectExecution() && !testBinSearchCorrectExecution())
    {
        printf("Test failed");
        return -1;
    }
    int length = 0;

    // Memory allocation
    printf("Length or main array: ");
    scanf("%d", &length);
    int* sequence = (int*)calloc((length + 1), sizeof(int));
    if (sequence == NULL)
    {
        printf("Allocation failure");
        return -1;
    }

    // number of to-search elements 
    int numberOfWantedNumbers = 0;
    printf("Length of array with wanted numbers: ");
    scanf("%d", &numberOfWantedNumbers);

    // Array generating
    srand((unsigned)time(NULL));
    for (int index = 0; index < length; index++)
    {
        sequence[index] = rand() % 100;
    }

    // printing not sorted array
    printf("Main array: ");
    for (int index = 0; index < length; index++)
    {
        printf("%d ", sequence[index]);
    }

    quickSort(0, length, sequence);

    // Generating to-search elements
    int* wantedNumbers = (int*)calloc((numberOfWantedNumbers + 1), sizeof(int));
    if (wantedNumbers == NULL)
    {
        printf("Allocation failure");
        free(sequence);
        return -1;
    }
    for (int index = 0; index < numberOfWantedNumbers; index++)
    {
        wantedNumbers[index] = rand() % 100;
    }

    printf("\nTo search: ");
    for (int index = 0; index < numberOfWantedNumbers; index++)
    {
        printf("%d ", wantedNumbers[index]);
    }

    printf("\nFound items: ");
    for (int index = 0; index < numberOfWantedNumbers; index++)
    {
        if (binarySearch(wantedNumbers[index], sequence, 0, length))
        {
            printf("%d ", wantedNumbers[index]);
        }
    }
    free(sequence);
    free(wantedNumbers);
    return 0;
}