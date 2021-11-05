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
    ListElement* position;
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
    if (position->position == NULL)
    {
        list->head = newElement;
        return true;
    }
    newElement->next = position->position->next;
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

bool getPreviousPosition(List* list, Position* position)
{
    if (list->head == position->position || list->head == NULL)
    {
        position->position = NULL;
        return true;
    }
    Position* assistantIterator = NULL;
    if (!createPosition(&assistantIterator))
    {
        return false;
    }
    assistantIterator->position = list->head;
    while (assistantIterator->position->next != position->position)
    {
        next(assistantIterator);
    }
    position->position = assistantIterator->position;
    free(assistantIterator);
    return true;
}

void deleteItem(List* list, Position* position)
{
    list->length--;
    if (position->position == list->head)
    {
        ListElement* temp = list->head->next;
        free(list->head);
        list->head = temp;
        return;
    }
    getPreviousPosition(list, position);
    ListElement* temp = position->position->next->next;
    free(position->position->next);
    position->position->next = temp;
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

bool last(Position* position)
{
    return position->position == NULL;
}

int get(List* list, Position* position)
{
    return position->position->value;
}