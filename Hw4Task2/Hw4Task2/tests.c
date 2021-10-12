#include "tests.h"
#include <stdbool.h>

bool testMostFrequentElement()
{
    // One element array test
    int testArray1[1] = { 5 };
    quickSort(0, 1, testArray1);
    if (findMostFrequent(testArray1, 1) != 5)
    {
        return false;
    }

    // identical elements test
    int testArray2[12] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    quickSort(0, 12, testArray2);
    if (findMostFrequent(testArray2, 12) != 5)
    {
        return false;
    }

    // usual array test
    int testArray3[11] = { 1, 0, 4, 1, 9, 2, 8, 9, 2, 4, 9 };
    quickSort(0, 11, testArray3);
    return 9 == findMostFrequent(testArray3, 11);
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