#pragma once
#include <stdbool.h>

// Tree element structure
typedef struct Node Node;

// creates dictionary, returns root
Node* createDictionary();

// deletes whole dictionary
void deleteDictionary(Node** root);

// adds new dictionary item with input key and value, returns root
Node* addNode(Node* root, const int key, const char* value);

// deletes dictionary item with given key, returns root
Node* deleteNode(Node* root, const int key);

// returns value of the item with input key
char* getValue(Node** root, const int key);

// returns true if item with given key is in the dictionary, false if it is not in the dictionary
bool inDictionary(Node** root, const int key);