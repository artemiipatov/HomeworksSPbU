#pragma once
#include <stdbool.h>

// list structure
typedef struct List List;

// position structure
typedef struct Position Position;

// allocates memory for list
List* createList();

// checks if list is empty
bool isEmpty(List* list);

// deletes all list elements and list
void deleteList(List** list);

// returns length of the list
int getLength(List* list);

// adds new value at the tail of the list. Name size should be less than 20 elements
bool addItemToList(List** list, const char* name);

// returns word frequency
int getCounterFromList(List* list, const char word[]);

// prints list in console
void printList(List* list);