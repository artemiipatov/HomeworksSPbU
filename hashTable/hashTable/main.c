#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "hashTable.h"
#include "hashTableTests.h"

int main()
{
    setlocale(LC_ALL, "");
    if (!hashTablePassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    HashTable* myHashTable = createHashTable();
    if (myHashTable == NULL)
    {
        printf("Allocation error");
        return -1;
    }
    if (!readFile(myHashTable, "data.txt"))
    {
        printf("An error occured while reading file");
        deleteHashTable(&myHashTable);
        return -1;
    }
    printHashTable(myHashTable);
    printf("\nAverage list length: %d", getAverageLength(myHashTable));
    printf("\nMaximum list length: %d", getMaxLength(myHashTable));
    printf("\nLoad factor: %f", getLoadFactor(myHashTable));
    deleteHashTable(&myHashTable);
    return 0;
}