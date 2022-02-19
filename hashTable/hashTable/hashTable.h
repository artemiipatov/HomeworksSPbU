#pragma once
#include <stdbool.h>

// hash table struct
typedef struct HashTable HashTable;

// creates hash table
HashTable* createHashTable();

// deletes hash table
void deleteHashTable(HashTable** hashTable);

// parses file
bool readFile(HashTable* hashTable, const char* fileName);

// returns word frequency
int getCounter(HashTable* hashTable, const char word[]);

// prints all words from hash table and their frequency in console
void printHashTable(HashTable* hashTable);

// returns max length of hash table lists
int getMaxLength(HashTable* hashTable);

// returns average length of hash table lists
int getAverageLength(HashTable* hashTable);

// returns load factor of hash table
double getLoadFactor(HashTable* hashTable);

// returns number of elements in hash table
int getNumberOfElements(HashTable* hashTable);