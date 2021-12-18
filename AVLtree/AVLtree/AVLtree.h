#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

// Dictionary structure.
typedef struct Dict Dict;

// creates dictionary.
Dict* createDictionary();

// Deletes dictionary.
void deleteDictionary(Dict** dict);

// Inserts new node or replaces existing value with new one. Returns true if insertion is successful, false if it failed.
bool insert(Dict* dict, const char* key, const char* value);

// Deletes node.
void deleteNode(Dict** dict, const char* key);

// Returns value by given key.
const char* getValue(Dict* dict, const char* key);

// Checks if given key is in the dictionary.
bool inDictionary(Dict* dict, const char* key);

// Returns balance factor of item with given key
int getBalanceByKey(Dict* dict, const char* key);