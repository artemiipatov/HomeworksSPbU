#include <stdbool.h>
#include <stdlib.h>
#include "cyclicListFunctions.h"

typedef struct ListElement
{
    int value;
    struct ListElement* next;
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

bool createList(List** list)
{
    *list = calloc(1, sizeof(List));
    return *list != NULL;
}

bool createPosition(Position** position)
{
    *position = calloc(1, sizeof(Position));
    return *position != NULL;
}

void deleteList(List** list)
{
    if ((*list)->length == 0)
    {
        (*list) = NULL;
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
        newElement->next = list->head;
        list->head = newElement;
        return true;
    }
    if (position->currentPosition == NULL)
    {
        newElement->next = newElement;
        list->head = newElement;
        return true;
    }
    newElement->next = position->currentPosition->next;
    position->currentPosition->next = newElement;
    return true;
}

void copyPosition(Position* copyFromHere, Position* pasteHere)
{
    pasteHere->currentPosition = copyFromHere->currentPosition;
    pasteHere->previousPosition = copyFromHere->previousPosition;
}

bool comparePositions(Position* position1, Position* position2)
{
    return position1->currentPosition == position2->currentPosition;
}

void deleteItem(List* list, Position* position)
{
    list->length--;
<<<<<<< HEAD:list/list/list.c
    if (position->currentPosition == list->head)
=======
    if (position->position == list->head)
>>>>>>> 08b9a35d3337b52d8799024ba3ee1e34eb0637c8:cyclicList/cyclicList/cyclicListFunctions.c
    {
        lastElement(list, position);
        position->position->next = list->head->next;
        ListElement* temp = list->head->next;
        free(list->head);
        list->head = temp;
        return;
    }
    ListElement* temp = position->currentPosition->next;
    free(position->previousPosition->next);
    position->previousPosition->next = temp;
    position->currentPosition = temp;
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

void lastElement(List* list, Position* index)
{
    first(list, index);
    while (!(index->position->next == list->head))
    {
        next(index);
    }
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