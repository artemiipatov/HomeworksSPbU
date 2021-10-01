#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

void printResult(double time1, double time2)
{
    printf("Bubble sort time: %f\n", time1);
    printf("Counting sort time: %f", time2);
}

double bubbleSort(int quantity, int sequence[])
{
    const clock_t start = clock();

    while (quantity > 1)
    {
        for (int iter = 1; iter < quantity; iter++)
        {
            if (sequence[iter - 1] > sequence[iter])
            {
                const int temp = sequence[iter];
                sequence[iter] = sequence[iter - 1];
                sequence[iter - 1] = temp;
            }
        }
        --quantity;
    }
    const clock_t end = clock();
    return (end - start);
}

double countingSort(int quantity, int sequence[])
{
    const start = clock();
    int maxElement = INT_MIN;
    int minElement = INT_MAX;
    for (int index = 0; index < quantity; index++)
    {
        const int element = sequence[index];
        if (element > maxElement)
        {
            maxElement = element;
        }
        else if (element < minElement)
        {
            minElement = element;
        }
    }

    int* counters = (int*)calloc((maxElement - minElement + 1), sizeof(int));
    if (counters == NULL)
    {
        printf("Allocation failure.");
        return -1;
    }
    for (int index = 0; index < quantity; index++)
    {
        ++counters[sequence[index] - minElement];
    }

    int counter = 0;
    for (int index = 0; index <= maxElement - minElement + 1; index++)
    {
        while (counters[index] > 0)
        {
            sequence[counter] = index + minElement;
            --counters[index];
            ++counter;
        }
    }
    free(counters);

    const clock_t end = clock();
    return (end - start);
}

bool testCorrectSorting()
{
    const int quantity = 20;
    int testSequence1[100] = { 0 };
    int testSequence2[100] = { 0 };
    for (int index = 0; index < quantity; index++)
    {
        const int randNumber = rand() % 100 - 100;
        testSequence1[index] = randNumber;
        testSequence2[index] = randNumber;
    }

    bubbleSort(quantity, testSequence1);
    countingSort(quantity, testSequence2);

    for (int index = 1; index < quantity; index++)
    {
        if (testSequence1[index] < testSequence1[index - 1] || testSequence2[index] < testSequence2[index - 1])
        {
            return false;
        }
    }
    return true;
}

void main()
{
    srand(time(NULL));
    if (!testCorrectSorting())
    {
        printf("Tests failed");
        return;
    }
    const int quantity = 100000;
    printf("Number of elements: 100000\n");

    int sequence1[100100] = { 0 };
    int sequence2[100100] = { 0 };
    for (int index = 0; index < quantity; index++)
    {
        const int randNumber = rand();
        sequence1[index] = randNumber;
        sequence2[index] = randNumber;
    }
    printResult(bubbleSort(quantity, sequence1), countingSort(quantity, sequence2));
}