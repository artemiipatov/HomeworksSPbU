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
    ListElement* tail;
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

bool isEmpty(List* list)
{
    return list == NULL || list->head == NULL;
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

int getLength(List* list)
{
    return list->length;
}

void copyString(char** destination, char* source, int length)
{
    for (int index = 0; index < length; index++)
    {
        *destination[index] = source[index];
    }
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
    list->length++;
    strcpy(newElement->name, name);
    newElement->number = number;
    if (list->head == NULL)
    {
        list->head = newElement;
        list->tail = list->head;
        return true;
    }
    list->tail->next = newElement;
    list->tail = newElement;
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