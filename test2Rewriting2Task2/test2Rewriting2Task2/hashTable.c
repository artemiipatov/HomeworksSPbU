#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "list.h"

typedef struct HashTable
{
    List** array;
    int numberOfElements;
    int arraySize;
} HashTable;

HashTable* createHashTable()
{
    HashTable* hashTable = calloc(1, sizeof(HashTable));
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

void deleteArray(List*** array, int arraySize)
{
    if ((*array) == NULL)
    {
        return;
    }
    for (int index = 0; index < arraySize; index++)
    {
        deleteList(&(*array)[index]);
    }
    free(*array);
    (*array) = NULL;
}

void deleteHashTable(HashTable** hashTable)
{
    const int arraySize = (*hashTable)->arraySize;
    deleteArray(&((*hashTable)->array), (*hashTable)->arraySize);
    free(*hashTable);
    *hashTable = NULL;
}

int hashFunction(const char word[], int arraySize)
{
    const int length = (int)strlen(word);
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = (hash * 3 + word[i] + arraySize) % arraySize;
    }
    return hash % arraySize;
}

bool resize(HashTable* hashTable);

bool addItemToHashTable(HashTable* hashTable, const char word[])
{
    const int hash = hashFunction(word, hashTable->arraySize);
    if (!addItemToList(&(hashTable->array[hash]), word))
    {
        return false;
    }
    ++hashTable->numberOfElements;
    if (getLoadFactor(hashTable) > 1.0)
    {
        if (!resize(hashTable))
        {
            return false;
        }
    }
    return true;
}

bool resize(HashTable* hashTable)
{
    const int oldSize = hashTable->arraySize;
    List** newArray = calloc(oldSize * 2, sizeof(List*));
    if (newArray == NULL)
    {
        return false;
    }
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
                deleteArray(&newArray, oldSize * 2);
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
    deleteArray(&oldArray, oldSize);
    hashTable->array = newArray;
    hashTable->arraySize = oldSize * 2;
    return true;
}

bool readFile(HashTable* hashTable, List* list)
{
    int length = getLength(list);
    Position* position = createPosition();
    if (position == NULL)
    {
        return false;
    }
    first(list, &position);
    for (int i = 0; i < length; i++)
    {
        if (!addItemToHashTable(hashTable, getValue(position)))
        {
            return false;
        }
        next(&position);
    }
    return true;
}

double getLoadFactor(HashTable* hashTable)
{
    return (double)hashTable->numberOfElements / (double)hashTable->arraySize;
}

int getNumberOfElements(HashTable* hashTable)
{
    return hashTable->numberOfElements;
}

List* getValues(HashTable* hashTable)
{
    List* list = createList();
    if (list == NULL)
    {
        return NULL;
    }
    for (int index = 0; index < hashTable->arraySize; index++)
    {
        if (hashTable->array[index] != NULL)
        {
            Position* position = createPosition();
            if (position == NULL)
            {
                deleteList(&list);
                return NULL;
            }
            first(hashTable->array[index], &position);
            while (!isNull(position))
            {
                addItemToList(&list, getValue(position));
                next(&position);
            }
            deletePosition(&position);
        }
    }
    return list;
}

List* deleteDuplicates(char* fileName)
{
    List* list = readFileToList(fileName);
    if (list == NULL)
    {
        return NULL;
    }
    HashTable* hashTable = createHashTable();
    if (hashTable == NULL)
    {
        return NULL;
    }
    if (!readFile(hashTable, list))
    {
        deleteHashTable(&hashTable);
        return NULL;
    }
    list = getValues(hashTable);
    deleteHashTable(&hashTable);
    return list;
}