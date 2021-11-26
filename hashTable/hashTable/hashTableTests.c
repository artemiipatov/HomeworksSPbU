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
    deleteHashTable(&hashTable);
    return true;
}