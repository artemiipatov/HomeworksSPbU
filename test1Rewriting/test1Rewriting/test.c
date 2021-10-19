#include <stdbool.h>
#include <stdio.h>
#include "filesWork.h"

bool testWorkWithFiles()
{
    int* testArray[100] = { 0 };
    int length = readDataFromFile("testf.txt", testArray);
    int* testNumber[1] = { 0 };
    readDataFromFile("testg.txt", testNumber);
    findLessNumbers("testh.txt", testArray, length, testNumber[0]);

    int* newArray[10] = { 0 };
    int newArrayLength = readDataFromFile("testh.txt", newArray);
    int correctArray[4] = { 23, 6, 7, 4 };
    for (int index = 0; index < newArrayLength; index++)
    {
        if (newArray[index] != correctArray[index])
        {
            return false;
        }
    }
}