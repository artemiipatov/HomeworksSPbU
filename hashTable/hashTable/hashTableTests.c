#include <stdbool.h>
#include <stdlib.h>
#include "hashTable.h"
#include "list.h"

bool hashTablePassedTests()
{
    hashTable* hashTable = createHashTable();
    if (hashTable == NULL)
    {
        return false;
    }
    if (!parse(hashTable, "testData.txt"))
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
    int loadFactor = getLoadFactor(hashTable);
    int numberOfElements = getNumberOfElements(hashTable);
    deleteHashTable(&hashTable);
    return hashTable == NULL && averageLength == 0 && maximumLength == 2 && loadFactor == 0 && numberOfElements == 24;
}