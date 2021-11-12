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
    ListElement* position;
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
    if (position == NULL)
    {
        newElement->previous = list->head->previous;
        list->head->previous->next = newElement;
        newElement->next = list->head;
        list->head->previous = newElement;
        list->head = newElement;
        return true;
    }
    if (position->position == NULL)
    {
        list->head = newElement;
        newElement->previous = newElement;
        newElement->next = newElement;
        return true;
    }
    newElement->previous = position->position;
    newElement->next = position->position->next;
    position->position->next->previous = newElement;
    position->position->next = newElement;
    return true;
}

void copyPosition(Position* copyFromHere, Position* pasteHere)
{
    pasteHere->position = copyFromHere->position;
}

bool comparePositions(Position* position1, Position* position2)
{
    return position1->position == position2->position;
}

void deleteItem(List* list, Position* position)
{
    list->length--;
    position->position->previous->next = position->position->next;
    position->position->next->previous = position->position->previous;
    ListElement* temp = position->position->next;
    bool isHead = position->position == list->head;
    free(position->position);
    if (isHead)
    {
        list->head = temp;
    }
    position->position = temp;
}

Position* first(List* list, Position* position)
{
    position->position = list->head;
    return position;
}

bool next(Position* currentIndex)
{
    if (currentIndex->position == NULL)
    {
        return false;
    }
    currentIndex->position = currentIndex->position->next;
    return currentIndex;
}

int getLength(List* list)
{
    return list->length;
}

bool last(List* list, Position* position)
{
    return position->position->next == list->head;
}

int get(List* list, Position* position)
{
    return position->position->value;
}