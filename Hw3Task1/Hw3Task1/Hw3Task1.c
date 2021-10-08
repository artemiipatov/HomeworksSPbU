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

int main()
{
    if (!testQSortCorrectExecution())
    {
        printf("Test failed");
        return -1;
    }
    int length = 0;

    // Memory allocation
    printf("Length of main array: ");
    scanf("%d", &length);
    int* sequence = (int*)calloc(length, sizeof(int));
    if (sequence == NULL)
    {
        printf("Allocation failure");
        return -1;
    }

    // Array generating
    srand((unsigned)time(NULL));
    for (int index = 0; index < length; index++)
    {
        sequence[index] = rand() % 100;
    }

    // Not sorted array
    printf("Original array: ");
    for (int index = 0; index < length; index++)
    {
        printf("%d ", sequence[index]);
    }

    // Sorted array
    quickSort(0, length, sequence);
    printf("\nsorted array: ");
    for (int index = 0; index < length; index++)
    {
        printf("%d ", sequence[index]);
    }
    return 0;
}