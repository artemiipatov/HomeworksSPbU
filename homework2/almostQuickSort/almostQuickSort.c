#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void repositionElements(int length, int sequence[])
{
    const int mainElement = sequence[0];
    int numberOfSmallerElements = 0;
    for (int index = 1; index < length; index++)
    {
        if (sequence[index] < mainElement)
        {
            ++numberOfSmallerElements;
        }
    }
    sequence[0] = sequence[numberOfSmallerElements];
    sequence[numberOfSmallerElements] = mainElement;
    const int numberOfGreaterElements = length - numberOfSmallerElements - 1;

    int previousIndex = 0;
    for (int greaterIndex = numberOfSmallerElements + 1; greaterIndex < length; greaterIndex++)
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
}

bool testCorrectExecution()
{
    int testArray[9] = { 6, 8, 1, 7, 2, 5, 6, 4, -10 };
    const int length = 9;
    const int mainElement = testArray[0];
    repositionElements(length, testArray);

    for (int index = 0; index < 5; index++)
    {
        if (testArray[index] >= mainElement)
        {
            return false;
        }
    }
    for (int index = 5; index < length; index++)
    {
        if (testArray[index] < mainElement)
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
        printf("Tests failed");
        return -1;
    }

    int length = 0;
    printf("Length: ");
    scanf("%d", &length);
    int* sequence = (int*)calloc(length + 1, sizeof(int));
    if (sequence == NULL)
    {
        printf("Allocation error");
        return -1;
    }

    srand(time(NULL));
    for (int index = 0; index < length; index++)
    {
        sequence[index] = rand() % 100;
    }
    printf("First elements: %d\n", sequence[0]);

    repositionElements(length, sequence);

    if (length > 100)
    {
        printf("Program was executed successfully, but there are too many elements in the array, so it is pointless to print them.");
    }
    else
    {
        for (int index = 0; index < length; index++)
        {
            printf("%d ", sequence[index]);
        }
    }
    free(sequence);
    return 0;
}