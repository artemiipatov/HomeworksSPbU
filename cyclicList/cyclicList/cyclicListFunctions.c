#include <stdbool.h>
#include <stdlib.h>
#include "cyclicListFunctions.h"

typedef struct ListElement
{
    int value;
    struct ListElement* next;
    struct ListElement* previous;
} ListElement;

typedef struct List
{
    int length;
    ListElement* head;
} List;

typedef struct Position
{
    ListElement* previousPosition;
    ListElement* currentPosition;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

Position* createPosition()
{
    return calloc(1, sizeof(Position));
}

void deleteList(List** list)
{
    if ((*list)->length == 0)
    {
        free(*list);
        *list = NULL;
        return;
    }
    while ((*list)->head->next != (*list)->head)
    {
        ListElement* temp = (*list)->head->next->next;
        free((*list)->head->next);
        (*list)->head->next = temp;
    }
    free((*list)->head);
    free(*list);
    *list = NULL;
}

void deletePosition(Position** position)
{
    free(*position);
    *position = NULL;
}

bool add(List* list, Position* position, int value)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    list->length++;
    newElement->value = value;
    list->length++;
    if (position == NULL)
    {
        newElement->previous = list->head->previous;
        list->head->previous->next = newElement;
        newElement->next = list->head;
        list->head->previous = newElement;
        list->head = newElement;
        return true;
    }
    if (position->currentPosition == NULL)
    {
        list->head = newElement;
        newElement->previous = newElement;
        newElement->next = newElement;
        return true;
    }
<<<<<<< HEAD
    newElement->next = position->currentPosition->next;
    position->currentPosition->next = newElement;
=======
    newElement->previous = position->position;
    newElement->next = position->position->next;
    position->position->next->previous = newElement;
    position->position->next = newElement;
>>>>>>> cyclicList
    return true;
}

void copyPosition(Position* copyFromHere, Position* pasteHere)
{
    pasteHere->currentPosition = copyFromHere->currentPosition;
    pasteHere->previousPosition = copyFromHere->previousPosition;
}

bool comparePositions(Position* position1, Position* position2)
{
<<<<<<< HEAD
    return position1->currentPosition == position2->currentPosition;
=======
    return position1->position == position2->position;
>>>>>>> cyclicList
}

void deleteItem(List* list, Position* position)
{
    list->length--;
<<<<<<< HEAD
<<<<<<< HEAD:list/list/list.c
    if (position->currentPosition == list->head)
=======
    if (position->position == list->head)
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListFunctions.c
=======
    position->position->previous->next = position->position->next;
    position->position->next->previous = position->position->previous;
    ListElement* temp = position->position->next;
    bool isHead = position->position == list->head;
    free(position->position);
    if (isHead)
>>>>>>> cyclicList
    {
        list->head = temp;
    }
<<<<<<< HEAD
    ListElement* temp = position->currentPosition->next;
    free(position->previousPosition->next);
    position->previousPosition->next = temp;
    position->currentPosition = temp;
=======
    position->position = temp;
>>>>>>> cyclicList
}

Position* first(List* list, Position* position)
{
    position->previousPosition = NULL;
    position->currentPosition = list->head;
    return position;
}

bool next(Position* currentIndex)
{
    if (currentIndex->currentPosition == NULL)
    {
        return false;
    }
    currentIndex->previousPosition = currentIndex->currentPosition;
    currentIndex->currentPosition = currentIndex->currentPosition->next;
    return true;
}

int getLength(List* list)
{
    return list->length;
}

int getLength(List* list)
{
    return list->length;
}

bool last(List* list, Position* position)
{
<<<<<<< HEAD:list/list/list.c
    return position->currentPosition == NULL;
=======
    return position->position->next == list->head;
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListFunctions.c
}

int get(List* list, Position* position)
{
    return position->currentPosition->value;
}