#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct ListElement
{
    int city;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    int length;
    ListElement* tail;
    ListElement* capital;
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

bool isEmpty(List* list)
{
    return list == NULL || list->capital == NULL;
}

void deleteList(List** list)
{
    ListElement* position = (*list)->capital;
    while (position != NULL)
    {
        (*list)->capital = (*list)->capital->next;
        free(position);
        position = (*list)->capital;
    }
    free(*list);
    *list = NULL;
}

void deletePosition(Position** position)
{
    free(*position);
    *position = NULL;
}

int getLength(List* list)
{
    return list->length;
}

void popHead(List* list, int* city)
{
    *city = list->capital->city;
    list->length--;
    ListElement* temp = list->capital->next;
    free(list->capital);
    list->capital = temp;
}

bool addAtTail(List* list, const int city)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    list->length++;
    newElement->city = city;
    if (list->capital == NULL)
    {
        list->capital = newElement;
        list->tail = list->capital;
        return true;
    }
    list->tail->next = newElement;
    list->tail = newElement;
    return true;
}

int getHeadNumber(List* list)
{
    return list->capital->city;
}

void first(List* list, Position** position)
{
    (*position)->position = list->capital;
}

void next(Position** position)
{
    (*position)->position = (*position)->position->next;
}

int getCityIndex(Position* position)
{
    return position->position->city;
}

int getPositionValue(Position* position)
{
    return position->position->city;
}