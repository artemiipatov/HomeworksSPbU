#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

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
    ListElement* position = (*list)->head;
    while (position != NULL)
    {
        (*list)->head = (*list)->head->next;
        free(position);
        position = (*list)->head;
    }
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
    if (position->currentPosition == list->head)
    {
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

bool last(Position* position)
{
    return position->currentPosition == NULL;
}

int get(List* list, Position* position)
{
    return position->currentPosition->value;
}