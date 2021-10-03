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

// Function for searching most frequent element
int findMostFrequent(int sequence[], int length)
{
    int counter = 1;
    int maxNumber = INT_MIN;
    int mostFrequentElement = sequence[0];
    for (int index = 1; index < length; index++)
    {
        if (sequence[index] == sequence[index - 1])
        {
            counter++;
        }
        if (counter > maxNumber)
        {
            maxNumber = counter;
            mostFrequentElement = sequence[index - 1];
        }
        if (sequence[index] != sequence[index-1])
        {
            counter = 1;
        }
    }
    return mostFrequentElement;
}

bool testMostFrequentElement()
{
    // One element array test
    int testArray2[1] = { 5 };
    quickSort(0, 1, testArray2);
    if (findMostFrequent(testArray2, 1) != 5)
    {
        return false;
    }

    // identical elements test
    int testArray1[12] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    quickSort(0, 12, testArray1);
    if (findMostFrequent(testArray1, 12) != 5)
    {
        return false;
    }

    // usual array test
    int testArray3[11] = { 1, 0, 4, 1, 9, 2, 8, 9, 2, 4, 9 };
    quickSort(0, 11, testArray3);
    if (9 == findMostFrequent(testArray2, 11))
    {
        return false;
    }

    return true;
}

bool testQSortCorrectExecution()
{
    // One element array test
    int testArray[1] = { 5 };
    if (quickSort(0, 1, testArray) != 0 || !(testArray[0] == 5))
    {
        return false;
    }

    // identical elements test
    int testArray1[12] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    if (quickSort(0, 12, testArray1) != 0)
    {
        return false;
    }
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
    if (!testQSortCorrectExecution() || !testMostFrequentElement())
    {
        printf("Test failed");
        return -1;
    }

    int length = 0;
    printf("Length of main array: ");
    scanf("%d", &length);

    // Memory allocation
    int* sequence = (int*)calloc((length + 1), sizeof(int));
    if (sequence == NULL)
    {
        printf("Allocation failure");
    }

    // Array generating
    srand((unsigned)time(NULL));
    for (int index = 0; index < length; index++)
    {
        sequence[index] = rand() % 100;
    }

    // Sorted array
    printf("Sorted array: ");
    quickSort(0, length, sequence);
    if (length <= 200)
    {
        for (int index = 0; index < length; index++)
        {
            printf("%d ", sequence[index]);
        }
    }

    // Printing answer
    const int answer = findMostFrequent(sequence, length);
    printf("\nMost frequent element: %d", answer);
}