#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int selectionSort(int sequence[], int length)
{
    for (int index = 0; index < length; index++)
    {
        int minElement = sequence[index];
        int minElementIndex = 0;
        for (int indexForSearchingMin = index; indexForSearchingMin < length; indexForSearchingMin++)
        {
            if (sequence[indexForSearchingMin] <= minElement)
            {
                minElement = sequence[indexForSearchingMin];
                minElementIndex = indexForSearchingMin;
            }
        }
        const int temp = sequence[index];
        sequence[index] = minElement;
        sequence[minElementIndex] = temp;
    }
}

bool testCorrectExecution()
{
    // One element array test
    int testArray[1] = { 5 };
    if (!(testArray[0] == 5))
    {
        return false;
    }

    // identical elements test
    int testArray1[12] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    for (int index = 0; index < 12; index++)
    {
        if (testArray1[index] != 5)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!testCorrectExecution())
    {
        printf("Test failed");
        return -1;
    }
    int sequence[10] = { 0 };
    for (int index = 0; index < 10; index++)
    {
        scanf("%d", &sequence[index]);
    }

    selectionSort(sequence, 10);
    printf("Sorted array:");
    for (int index = 0; index < 10; index++)
    {
        printf("%d ", sequence[index]);
    }
}