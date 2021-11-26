#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int main()
{
    if (!hashTablePassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    hashTable* myHashTable = createHashTable();
    if (myHashTable == NULL)
    {
        printf("Allocation error");
        return -1;
    }
    if (!parse(myHashTable, "data.txt"))
    {
        printf("An error occured while parsing");
        return -1;
    }
    printHashTable(myHashTable);
    deleteHashTable(&myHashTable);
}