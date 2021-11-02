#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct ListElement
{
    char name[20];
    int number;
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
    if (*list == NULL)
    {
        return false;
    }
    return true;
}

bool isEmpty(List* list)
{
    if (list->head == NULL)
    {
        return true;
    }
    return false;
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
    (*list) = NULL;
}

int getLength(List* list)
{
    return list->length;
}

void popHead(List* list, char** name, int* number)
{
    strcpy(*name, list->head->name);
    *number = list->head->number;
    list->length--;
    ListElement* temp = list->head->next;
    free(list->head);
    list->head = temp;
}

bool addAtTail(List* list, char* name, int number)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    strcpy(newElement->name, name);
    newElement->number = number;
    list->length++;
    if (list->head == NULL)
    {
        list->head = newElement;
        return true;
    }
    ListElement* currentElement = list->head;
    while (currentElement->next != NULL)
    {
        currentElement = currentElement->next;
    }
    currentElement->next = newElement;
    return true;
}

char* getHeadName(List* list)
{
    return list->head->name;
}

int getHeadNumber(List* list)
{
    return list->head->number;
}