#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

typedef struct ListElement
{
    char word[50];
    int counter;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    int length;
    ListElement* head;
    ListElement* tail;
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
    if (*list == NULL)
    {
        return;
    }
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

ListElement* createElement(const char* word)
{
    ListElement* newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL)
    {
        return NULL;
    }
    ++newElement->counter;
    strcpy(newElement->word, word);
    return newElement;
}

bool addItemToList(List** list, const char* word)
{
    if (*list == NULL)
    {
        *list = createList();
    }
    if ((*list)->head == NULL)
    {
        ListElement* newElement = createElement(word);
        if (newElement == NULL)
        {
            return false;
        }
        (*list)->length++;
        (*list)->head = newElement;
        (*list)->tail = newElement;
    }
    else
    {
        ListElement* currentElement = (*list)->head;
        while (currentElement != NULL)
        {
            if (strcmp(currentElement->word, word) == 0)
            {
                ++currentElement->counter;
                return true;
            }
            currentElement = currentElement->next;
        }
        ListElement* newElement = createElement(word);
        if (newElement == NULL)
        {
            return false;
        }
        ++(*list)->length;
        (*list)->tail->next = newElement;
        (*list)->tail = (*list)->tail->next;
    }
    return true;
}

int getCounterFromList(List* list, const char word[])
{
    if (list == NULL)
    {
        return 0;
    }
    ListElement* currentElement = list->head;
    while (strcmp(currentElement->word, word) != 0)
    {
        if (currentElement->next == NULL)
        {
            return 0;
        }
        currentElement = currentElement->next;
    }
    return currentElement->counter;
}

void printList(List* list)
{
    if (list == NULL)
    {
        return;
    }
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("\n%50.50s", currentElement->word);
        printf("%5d", currentElement->counter);
        currentElement = currentElement->next;
    }
}