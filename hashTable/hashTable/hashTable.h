#pragma once
#include <stdbool.h>

typedef struct hashTable hashTable;

hashTable* createHashTable();

void deleteHashTable(hashTable** hashTable);

bool parse(hashTable* hashTable, char* fileName);

int hashFunction(const char word[]);

int getCounter(hashTable* hashTable, const char word[]);

void printHashTable(hashTable* hashTable);