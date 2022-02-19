#pragma once
#include <stdbool.h>
#include "list.h"

// hash table struct
typedef struct HashTable HashTable;

// creates hash table
HashTable* createHashTable();

// deletes hash table
void deleteHashTable(HashTable** hashTable);

// parses file
bool readFile(HashTable* hashTable, List* list);

// returns load factor of hash table
double getLoadFactor(HashTable* hashTable);

// returns number of elements in hash table
int getNumberOfElements(HashTable* hashTable);

// deletes elements with equal values
List* deleteDuplicates(char* fileName);