#include "testMostFrequentElement.h"
#include "sort.h"
#include "mostFrequentElementSearch.h"
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