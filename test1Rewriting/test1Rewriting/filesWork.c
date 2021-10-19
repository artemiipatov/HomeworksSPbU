#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "filesWork.h"

int readDataFromFile(const char fileName[], int array[])
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("File not found");
        return -1;
    }
    int linesRead = 0;

    while (!feof(file))
    {
        int readNumber = 0;
        const int readBytes = fscanf(file, "%d", &readNumber);
        if (readBytes < 0)
        {
            break;
        }
        array[linesRead] = readNumber;
        ++linesRead;
    }
    fclose(file);
    return linesRead;
}

void writeDataToFile(const char fileName[], int array[], int length)
{
    FILE* file = fopen(fileName, "w");
    for (int index = 0; index < length; index++)
    {
        fprintf(file, "%d\n", array[index]);
    }
    fclose(file);
}

void findLessNumbers(const char filename[], int array[], int length, int number)
{
    int* newArray = calloc(length, sizeof(int));
    if (newArray == NULL)
    {
        printf("Allocation failure");
        return;
    }
    int currentIndex = 0;
    for (int index = 0; index < length; index++)
    {
        if (array[index] < number)
        {
            newArray[currentIndex] = array[index];
            currentIndex++;
        }
    }
    writeDataToFile(filename, newArray, currentIndex);
    free(newArray);
}