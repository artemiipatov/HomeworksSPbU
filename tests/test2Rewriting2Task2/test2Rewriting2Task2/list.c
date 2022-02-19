#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

typedef struct ListElement
{
    char word[50];
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

void deletePosition(Position** position)
{
    free(*position);
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
    }
    else
    {
        ListElement* currentElement = (*list)->head;
        while (currentElement->next != NULL)
        {
            if (strcmp(currentElement->word, word) == 0)
            {
                return true;
            }
            currentElement = currentElement->next;
        }
        if (strcmp(currentElement->word, word) == 0)
        {
            return true;
        }
        ListElement* newElement = createElement(word);
        if (newElement == NULL)
        {
            return false;
        }
        ++(*list)->length;
        currentElement->next = newElement;
    }
    return true;
}

List* readFileToList(char* fileName)
{
    FILE* file = fopen(fileName, "r");
    List* list = createList();
    if (list == NULL)
    {
        fclose(file);
        return NULL;
    }
    while (!feof(file))
    {
        char word[50] = { '\0' };
        fscanf_s(file, "%s%*c", &word, 50);
        if (!addItemToList(&list, word))
        {
            fclose(file);
            return NULL;
        }
    }
    fclose(file);
    return list;
}

void first(List* list, Position** position)
{
    (*position)->position = list->head;
}

char* getValue(Position* position)
{
    return position->position->word;
}

void next(Position** position)
{
    (*position)->position = (*position)->position->next;
}

bool isNull(Position* position)
{
    return position->position == NULL;
}