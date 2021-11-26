#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "list.h"
#define ARRAY_SIZE 500

typedef struct hashTable
{
    List* array[ARRAY_SIZE];
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
        //fscanf_s(file, "%[^ ]%*c", &word, 50);
        fscanf_s(file, "%s%*c", &word, 50);
        //if (strcmp(word, "") == 0)
        //{
        //    return 
        //}
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