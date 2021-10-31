#pragma once
#include <stdbool.h>

// list structure
typedef struct List List;

// position structure
typedef struct Position Position;

// allocates memory for list
bool createList(List** list);

// allocates memory for position
bool createPosition(Position** position);

// deletes all list elements and list
void deleteList(List** list);

// frees memory allocated for position
void deletePosition(Position** position);

// adds element to list
bool add(List* list, Position* position, int value);

// copies adress from the first position and pastes it to the second position
void copyPosition(Position* copyFromHere, Position* pasteHere);

// returns previous position
bool getPreviousPosition(List* list, Position* position);

// compares two positions
bool comparePositions(Position* position1, Position* position2);

// frees memory allocated for list element and deletes element from the list
void deleteItem(List* list, Position* position);

// returns position of the first element of list
Position* first(List* list, Position* position);

// puts in position next position, returns true if next is not NULL, false if next is NULL
bool next(Position* position);

// puts in position last element of the list and returns true if function did it successfully, false if it failed
void lastElement(List* list, Position* index);

// returns true if currentElement is the last one in the list, false if it is not last
bool last(List* list, Position* position);

// returns value of the list element on the current position
int get(List* list, Position* position);