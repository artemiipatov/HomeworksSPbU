#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int insertionSort(int sequence[], int start, int end)
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

int quickSort(int start, int end, int sequence[])
{
    if (end - start + 1 < 10)
    {
        insertionSort(sequence, start, end);
        return 0;
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
    int testArray[40] = { 0 };

    srand((unsigned)time(NULL));
    for (int index = 0; index < 40; index++)
    {
        testArray[index] = rand() % 1000;
    }

    quickSort(0, 40, testArray);

    for (int index = 1; index < 40; index++)
    {
        if (testArray[index - 1] > testArray[index])
        {
            return false;
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
    int* sequence = (int*)calloc((length + 1), sizeof(int));
    if (sequence == NULL)
    {
        printf("Allocation failure");
    }

    // Array generating
    srand((unsigned)time(NULL));
    for (int index = 0; index < length; index++)
    {
        sequence[index] = rand() % 1000;
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