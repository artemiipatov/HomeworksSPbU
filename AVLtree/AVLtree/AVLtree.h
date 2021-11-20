#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Dictionary structure.
typedef struct Dict Dict;

// creates dictionary.
Dict* createDictionary();

// Deletes dictionary.
void deleteDictionary(Dict** dict);

// Inserts new node or replaces existing value with new one. Returns true if insertion is successful, false if it failed.
bool insert(Dict* dict, const int key, const char* value);

// Deletes node.
void deleteNode(Dict** dict, int key);

// Returns value by given key.
char* getValue(Dict* dict, const int key);

// Checks if given key is in the dictionary.
bool inDictionary(Dict* dict, const int key);