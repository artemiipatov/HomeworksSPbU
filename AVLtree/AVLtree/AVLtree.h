#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dict Dict;

Dict* createDictionary();

void deleteDictionary(Dict** dict);

bool insert(Dict* dict, const int key, const char* value);

void deleteNode(Dict* dict, int key);

char* getValue(Dict* dict, const int key);

bool inDictionary(Dict* dict, const int key);