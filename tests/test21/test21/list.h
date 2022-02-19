#pragma once
#include <stdbool.h>

#pragma once
#include <stdbool.h>

// list structure
typedef struct List List;

// position structure
typedef struct Position Position;

Position* createPosition();

void first(List* list, Position* position);

// checks if list is empty
bool isEmpty(List* list);

int getLength(list);

// deletes all list elements and list
void deleteList(List** list);

// adds new value at the tail of the list. Name size should be less than 20 elements
bool addAtTail(List* list, const int value);

List* readFile(const char* fileName);

void reverse(List* list);

// returns number of the first element of the list
int getHeadNumber(List* list);

void printList(List* list);

void next(Position* position);

int getPositionValue(Position* position);