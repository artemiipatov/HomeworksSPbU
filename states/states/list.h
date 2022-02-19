#pragma once
#include <stdbool.h>

// list structure
typedef struct List List;

// position structure
typedef struct Position Position;

// allocates memory for list
List* createList();

// allocates memory for position
Position* createPosition();

// checks if list is empty
bool isEmpty(List* list);

// deletes all list elements and list
void deleteList(List** list);

// deletest position
void deletePosition(Position** position);

// returns length of the list
int getLength(List* list);

// returns head name and number and deletes head item
void popHead(List* list, int* city);

// adds new value at the tail of the list. Name size should be less than 20 elements
bool addAtTail(List* list, const int city);

// returns number of the first element of the list
int getHeadNumber(List* list);

// fills position with first element of the list
void first(List* list, Position** position);

// fills position with the next element of the list
void next(Position** position);

// returns position value
int getPositionValue(Position* position);

// returns true if position is null, false if position is not null
bool isNull(Position* position);

// prints list elements in console
void printList(List* list);