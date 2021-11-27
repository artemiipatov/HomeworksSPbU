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

// deletes all list elements and list
void deleteList(List** list);

// frees memory allocated for position
void deletePosition(Position** position);

// adds element to list
bool add(List* list, Position* position, int value);

// copies adress from the first position and pastes it to the second position
void copyPosition(Position* copyFromHere, Position* pasteHere);

// compares two positions
bool comparePositions(Position* position1, Position* position2);

// frees memory allocated for list element and deletes element from the list
void deleteItem(List* list, Position* position);

// returns position of the first element of list
Position* first(List* list, Position* position);

// puts in position next position, returns true if next is not NULL, false if next is NULL
bool next(Position* position);

// returns length of the list
int getLength(List* list);

// returns true if currentElement is the last one in the list, false if it is not last
bool last(List* list, Position* position);

// returns value of the list element on the current position
int get(List* list, Position* position);