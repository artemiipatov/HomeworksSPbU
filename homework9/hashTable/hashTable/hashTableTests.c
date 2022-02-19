#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "hashTable.h"
#include "list.h"

bool hashTablePassedTests()
{
    HashTable* hashTable = createHashTable();
    if (hashTable == NULL)
    {
        return false;
    }
    if (!readFile(hashTable, "testData.txt"))
    {
        deleteHashTable(&hashTable);
        return false;
    }
    if (!(getCounter(hashTable, "wqlr") == 2
        && getCounter(hashTable, "bhkdfbhgk") == 2
        && getCounter(hashTable, "mrou") == 1
        && getCounter(hashTable, "jengjklqngnqignqeiorgrn") == 0))
    {
        deleteHashTable(&hashTable);
        return false;
    }
    int averageLength = getAverageLength(hashTable);
    int maximumLength = getMaxLength(hashTable);
    double loadFactor = -getLoadFactor(hashTable);
    int numberOfElements = getNumberOfElements(hashTable);
    deleteHashTable(&hashTable);
    return hashTable == NULL && averageLength == 0 && maximumLength == 2 && loadFactor < 1 && numberOfElements == 24;
}