#include <stdbool.h>

// list structure
typedef struct List List;

// position structure
typedef struct Position Position;

// allocates memory for list
bool createList(List** list);

// checks if list is empty
bool isEmpty(List* list);

// deletes all list elements and list
void deleteList(List** list);

// returns length of the list
int getLength(List* list);

// returns head name and number and deletes head item
void popHead(List* list, char** name, int* number);

// adds new value at the tail of the list
bool addAtTail(List* list, char* name, const int number);

// returns name of the first element of the list
char* getHeadName(List* list);

// returns number of the first element of the list
int getHeadNumber(List* list);