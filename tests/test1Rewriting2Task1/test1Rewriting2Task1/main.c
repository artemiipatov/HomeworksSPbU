#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// reads array from file
int* readFile(char* fileName, int* numberOfElements)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return NULL;
    }
    fscanf(file, "%d%*c", numberOfElements);
    int* array = (int*)calloc(*numberOfElements, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < (*numberOfElements); i++)
    {
        fscanf(file, "%d%*c", &array[i]);
    }
    return array;
}

// sorts elementst on even indexes
void sortEvenIndexes(int* array, int numberOfElements)
{
    for (int j = numberOfElements; j >= 0; j--)
    {
        bool swapped = false;
        for (int i = 0; i < numberOfElements - 2; i += 2)
        {
            if (array[i] > array[i + 2])
            {
                const int temp = array[i];
                array[i] = array[i + 2];
                array[i + 2] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

// tests for sorting
bool sortPassedTests()
{
    FILE* file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "5\n");
    fprintf(file, "5 4 3 2 1");
    fclose(file);
    const int numberOfElements1 = 0;
    int* array = readFile("testFile.txt", &numberOfElements1);
    if (array == NULL)
    {
        return false;
    }
    sortEvenIndexes(array, numberOfElements1);
    const int correctArray1[5] = { 1, 4, 3, 2, 5 };
    for (int i = 0; i < numberOfElements1; i++)
    {
        if (array[i] != correctArray1[i])
        {
            return false;
        }
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "8\n");
    fprintf(file, "0 0 0 0 0 0 0 0");
    fclose(file);
    const int numberOfElements2 = 0;
    array = readFile("testFile.txt", &numberOfElements2);
    if (array == NULL)
    {
        return false;
    }
    sortEvenIndexes(array, numberOfElements2);
    const int correctArray2[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < numberOfElements2; i++)
    {
        if (array[i] != correctArray2[i])
        {
            return false;
        }
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "6\n");
    fprintf(file, "6 5 4 3 2 1");
    fclose(file);
    const int numberOfElements3 = 0;
    array = readFile("testFile.txt", &numberOfElements3);
    if (array == NULL)
    {
        return false;
    }
    sortEvenIndexes(array, numberOfElements3);
    const int correctArray3[6] = { 2, 5, 4, 3, 6, 1 };
    for (int i = 0; i < numberOfElements3; i++)
    {
        if (array[i] != correctArray3[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!sortPassedTests())
    {
        printf("tests failed");
        return -1;
    }
    int numberOfElements = 0;
    int* array = readFile("data.txt", &numberOfElements);
    sortEvenIndexes(array, numberOfElements);
    printf("Sorted array: ");
    for (int index = 0; index < numberOfElements; index++)
    {
        printf("%d ", array[index]);
    }
    free(array);
}