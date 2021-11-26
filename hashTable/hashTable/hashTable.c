#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "list.h"
#define ARRAY_SIZE 2000

typedef struct hashTable
{
    List* array[ARRAY_SIZE];
    int numberOfElements;
} hashTable;

hashTable* createHashTable()
{
    return calloc(1, sizeof(hashTable));
}

void deleteHashTable(hashTable** hashTable) 
{
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        deleteList(&((*hashTable)->array[index]));
    }
    free(*hashTable);
    *hashTable = NULL;
}

bool addItemToHashTable(hashTable* hashTable, char word[])
{
    int hash = hashFunction(word);
    ++hashTable->numberOfElements;
    if (!addItemToList(&(hashTable->array[hash]), word))
    {
        return false;
    }
    return true;
}

bool parse(hashTable* hashTable, char* fileName)
{
    FILE* file = fopen(fileName, "r");
    while (!feof(file))
    {
        char word[50] = {'\0'};
        fscanf_s(file, "%s%*c", &word, 50);
        if (!addItemToHashTable(hashTable, word))
        {
            fclose(file);
            return false;
        }
    }
    fclose(file);
    return true;
}

int hashFunction(const char word[])
{
    int length = (int)strlen(word);
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash += word[i];
    }
    return hash % ARRAY_SIZE;
}

int getCounter(hashTable* hashTable, const char word[])
{
    int hash = hashFunction(word);
    List* list = hashTable->array[hash];
    return getCounterFromList(list, word);
}

void printHashTable(hashTable* hashTable)
{
    for (int arrayIndex = 0; arrayIndex < ARRAY_SIZE; arrayIndex++)
    {
        printList(hashTable->array[arrayIndex]);
    }
}

int getMaxLength(hashTable* hashTable)
{
    int maxLength = 0;
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        if (hashTable->array[index] != NULL)
        {
            int length = getLength(hashTable->array[index]);
            if (length > maxLength)
            {
                maxLength = length;
            }
        }
    }
    return maxLength;
}

int getAverageLength(hashTable* hashTable)
{
    int sumOfLengths = 0;
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        if (hashTable->array[index] != NULL)
        {
            sumOfLengths += getLength(hashTable->array[index]);
        }
    }
    return sumOfLengths / ARRAY_SIZE;
}

int getLoadFactor(hashTable* hashTable)
{
    return hashTable->numberOfElements / ARRAY_SIZE;
}

int getNumberOfElements(hashTable* hashTable)
{
    return hashTable->numberOfElements;
}