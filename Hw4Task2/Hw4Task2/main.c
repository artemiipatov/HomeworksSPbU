#include "sort.h"
#include "mostFrequentElementSearch.h"
#include "testMostFrequentElement.h"
#include "testQuickSort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    if (!testQSortCorrectExecution() || !testMostFrequentElement())
    {
        printf("Test failed");
        return -1;
    }

    // Reading data from file 
    FILE* inputData = fopen("input.txt", "r");
    if (inputData == NULL)
    {
        printf("File not found");
        return -1;
    }
    int length = 0;
    if (!feof(inputData))
    {
        fscanf(inputData, "%d", &length);
    }

    // Memory allocation
    int* sequence = (int*)calloc((length + 1), sizeof(int));
    if (sequence == NULL)
    {
        fclose(inputData);
        printf("Allocation failure");
        return -1;
    }

    int index = 0;
    while (!feof(inputData))
    {
        fscanf(inputData, "%d", &sequence[index]);
        ++index;
    }
    fclose(inputData);

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

    free(sequence);
    return 0;
}