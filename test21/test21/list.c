#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct ListElement
{
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

Position* createPosition()
{
    return calloc(1, sizeof(Position));
}

void first(List* list, Position* position)
{
    position->position = list->head;
}

void deletePosition(Position** position)
{
    free(*position);
    *position = NULL;
}

List* createList()
{
    return calloc(1, sizeof(List));
}

bool isEmpty(List* list)
{
    return list == NULL || list->head == NULL;
}

int getLength(List* list)
{
    return list->length;
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

bool addAtTail(List* list, const int value)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return false;
    }
    list->length++;
    newElement->number = value;
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

List* readFile(const char* fileName)
{
    List* list = createList();
    if (list == NULL)
    {
        return NULL;
    }
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return NULL;
        deleteList(&list);
    }
    while (!feof(file))
    {
        int value = 0;
        fscanf(file, "%d", &value);
        if (!addAtTail(list, value))
        {
            deleteList(&list);
            fclose(file);
            return NULL;
        }
    }
    fclose(file);
    return list;
}

void reverse(List* list)
{
    ListElement* firstElement = list->head;
    ListElement* currentElement = list->head;
    ListElement* lastElement = list->tail;

    while (true)
    {
        while (currentElement->next != lastElement && currentElement != lastElement)
        {
            currentElement = currentElement->next;
        }
        if (currentElement == firstElement)
        {
            if (list->length % 2 == 0)
            {
                const int temp = firstElement->number;
                firstElement->number = lastElement->number;
                lastElement->number = temp;
            }
            break;
        }
        const int temp = firstElement->number;
        firstElement->number = currentElement->next->number;
        currentElement->next->number = temp;
        lastElement = currentElement;
        firstElement = firstElement->next;
        currentElement = firstElement;
    }
}

int getHeadNumber(List* list)
{
    return list->head->number;
}

void printList(List* list)
{
    int length = list->length;
    ListElement* currentPosition = list->head;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", currentPosition->number);
        currentPosition = currentPosition->next;
    }
}

int* getListValues(List* list, int* array)
{
    int length = list->length;
    //int* array = calloc(length, sizeof(int));
    ListElement* currentPosition = list->head;
    for (int i = 0; i < length; i++)
    {
        array[i] = currentPosition->number;
        currentPosition = currentPosition->next;
    }
    return array;
}

void next(Position* position)
{
    position->position = position->position->next;
}

int getPositionValue(Position* position)
{
    return position->position->number;
}