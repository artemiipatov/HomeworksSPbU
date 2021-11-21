#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void findNumber(int sequence[], int assistantArray[], int length)
{
    int maxNumber = INT_MIN;
    int indexOfAssistantArray = 0;
    for (int index = 0; index < length; index++)
    {
        int sumOfNumberNumbers = sumOfNumbers(sequence[index]);
        if (sumOfNumberNumbers > maxNumber)
        {
            maxNumber = sumOfNumberNumbers;
            for (int iter = 0; iter < indexOfAssistantArray; iter++)
            {
                assistantArray[iter] = 0;
            }
            indexOfAssistantArray = 0;
            assistantArray[indexOfAssistantArray] = sequence[index];
        }
        else if (sumOfNumberNumbers == maxNumber)
        {
            assistantArray[index] = sequence[index];
            indexOfAssistantArray++;
        }
    }
    return;
}

int sumOfNumbers(int number)
{
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

bool testCorrectResult()
{
    // One element array test
    int testArray1[1] = { 5 };
    int testAssistantArray1[1] = { 0 };
    findNumber(testArray1, testAssistantArray1, 1);
    if (testAssistantArray1[0] != 5)
    {
        return false;
    }

    // identical elements test
    int testArray2[12] = { 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234, 234 };
    int testAssistantArray2[12] = { 0 };
    findNumber(testArray2, testAssistantArray2, 12);
    for (int index = 0; index < 12; index++)
    {
        if (testAssistantArray2[index] != 234)
        {
            return false;
        }
    }

    // usual array test
    int testArray3[11] = { 152, 523, 4521, 1432, 95999234, 4322, 8, 439, 23, 423413, 98965 };
    int testAssistantArray3[11] = { 0 };
    findNumber(testArray3, testAssistantArray3, 11);
    if (testAssistantArray3[0] != 95999234)
    {
        return false;
    }

    return true;
}

int main()
{
    if (!testCorrectResult())
    {
        printf("tests failed");
        return -1;
    }
    int length = 0;
    printf("Enter lengeht of array: ");
    scanf("%d", &length);
    int* sequence = (int*)calloc(length, sizeof(int));
    int* assistantArray = (int*)calloc(length, sizeof(int));
    if (sequence == NULL || assistantArray == NULL)
    {
        printf("Allocation failure");
        return -1;
    }
    srand((unsigned)time(NULL));
    for (int index = 0; index < length; index++)
    {
        sequence[index] = rand();
    }
    if (length < 200)
    {
        for (int index = 0; index < length; index++)
        {
            printf("%d ", sequence[index]);
        }
    }
    findNumber(sequence, assistantArray, length);
    printf("\nNumbers with max sum of numbers they consist of:\n");
    for (int index = 0; index <= length; index++)
    {
        if (assistantArray[index] > 0 || (assistantArray[0] == 0 && assistantArray[index] == 0))
        {
            printf("%d\n", assistantArray[index]);
        }
    }
}