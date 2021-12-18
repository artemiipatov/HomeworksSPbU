#include <stdio.h>
#include "filesWork.h"
#include "test.h"

int main()
{
    if (!testWorkWithFiles())
    {
        printf("Tests failed");
        return -1;
    }
    int array[100] = { 0 };
    int length = readDataFromFile("f.txt", array);
    int number[1] = { 0 };
    readDataFromFile("g.txt", number);
    findLessNumbers("h.txt", array, length, number[0]);
}