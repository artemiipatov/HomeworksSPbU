#pragma once
#include <stdbool.h>

// list structure
typedef struct List List;

// position structure
typedef struct Position Position;

// allocates memory for list
List* createList();

Position* createPosition();

// checks if list is empty
bool isEmpty(List* list);

// deletes all list elements and list
void deleteList(List** list);

void deletePosition(Position** position);

// returns length of the list
int getLength(List* list);

// returns head name and number and deletes head item
void popHead(List* list, int* city);

// adds new value at the tail of the list. Name size should be less than 20 elements
bool addAtTail(List* list, const int city);

// returns number of the first element of the list
int getHeadNumber(List* list);

void first(List* list, Position** position);

void next(Position** position);

int getCityIndex(Position* position);

int getPositionValue(Position* position);