#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "list.h"

typedef struct hashTable
{
    List** array;
    int numberOfElements;
    int arraySize;
} hashTable;

hashTable* createHashTable()
{
    hashTable* hashTable = calloc(1, sizeof(hashTable));
    if (hashTable == NULL)
    {
        return NULL;
    }
    hashTable->arraySize = 15;
    hashTable->array = calloc(15, sizeof(List*));
    if (hashTable->array == NULL)
    {
        return NULL;
    }
    hashTable->numberOfElements = 0;
    return hashTable;
}

void deleteArray(List** array, int arraySize)
{
    if (array == NULL)
    {
        return;
    }
    for (int index = 0; index < arraySize; index++)
    {
        deleteList(&array[index]);
    }
}

void deleteHashTable(hashTable** hashTable) 
{
    int arraySize = (*hashTable)->arraySize;
    for (int index = 0; index < arraySize; index++)
    {
        deleteList(&((*hashTable)->array[index]));
    }
    free(*((*hashTable)->array));
    free(*hashTable);
    *hashTable = NULL;
}

bool addItemToHashTable(hashTable* hashTable, const char word[])
{
    int hash = hashFunction(word, hashTable->arraySize);
    ++hashTable->numberOfElements;
    if (!addItemToList(&(hashTable->array[hash]), word))
    {
        return false;
    }
    return true;
}

bool resize(hashTable* hashTable)
{
    int oldSize = hashTable->arraySize;
    List** newArray = calloc(oldSize * 2, sizeof(List*));
    hashTable->arraySize = oldSize * 2;
    List** oldArray = hashTable->array;
    hashTable->array = newArray;
    hashTable->numberOfElements = 0;
    for (int index = 0; index < oldSize; index++)
    {
        if (oldArray[index] != NULL)
        {
            Position* position = createPosition();
            if (position == NULL)
            {
                deleteArray(newArray, oldSize * 2);
                return false;
            }
            first(oldArray[index], &position);
            while (!isNull(position))
            {
                addItemToHashTable(hashTable, getValue(position));
                next(&position);
            }
            deletePosition(&position);
        }
    }
    deleteArray(oldArray, oldSize);
    hashTable->array = newArray;
    hashTable->arraySize = oldSize * 2;
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
        if (getLoadFactor(hashTable) > 1.0)
        {
            resize(hashTable);
        }
    }
    fclose(file);
    return true;
}

int hashFunction(const char word[], int arraySize)
{
    int length = (int)strlen(word);
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = (hash * 3 + word[i]) % arraySize;
    }
    return hash % arraySize;
}

int getCounter(hashTable* hashTable, const char word[])
{
    int hash = hashFunction(word, hashTable->arraySize);
    List* list = hashTable->array[hash];
    return getCounterFromList(list, word);
}

void printHashTable(hashTable* hashTable)
{
    int arraySize = hashTable->arraySize;
    for (int arrayIndex = 0; arrayIndex < arraySize; arrayIndex++)
    {
        printList(hashTable->array[arrayIndex]);
    }
}

int getMaxLength(hashTable* hashTable)
{
    int maxLength = 0;
    int arraySize = hashTable->arraySize;
    for (int index = 0; index < arraySize; index++)
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
    int arraySize = hashTable->arraySize;
    for (int index = 0; index < arraySize; index++)
    {
        if (hashTable->array[index] != NULL)
        {
            sumOfLengths += getLength(hashTable->array[index]);
        }
    }
    return sumOfLengths / arraySize;
}

double getLoadFactor(hashTable* hashTable)
{
    return (double)hashTable->numberOfElements / (double)hashTable->arraySize;
}

int getNumberOfElements(hashTable* hashTable)
{
    return hashTable->numberOfElements;
}