#pragma once
#include <stdbool.h>

// hash table struct
typedef struct hashTable hashTable;

// creates hash table
hashTable* createHashTable();

// deletes hash table
void deleteHashTable(hashTable** hashTable);

// parses file
bool parse(hashTable* hashTable, char* fileName);

// counts hash for given word
int hashFunction(const char word[], int arraySize);

// returns word frequency
int getCounter(hashTable* hashTable, const char word[]);

// prints all words from hash table and their frequency in console
void printHashTable(hashTable* hashTable);

// returns max length of hash table lists
int getMaxLength(hashTable* hashTable);

// returns average length of hash table lists
int getAverageLength(hashTable* hashTable);

// returns load factor of hash table
double getLoadFactor(hashTable* hashTable);

// returns number of elements in hash table
int getNumberOfElements(hashTable* hashTable);