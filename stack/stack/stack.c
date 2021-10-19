#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include "stackTests.h"

typedef struct StackElement 
{
    int value;
    struct StackElement* next;
} StackElement;

int getValue(StackElement* head)
{
    return head->value;
}

StackElement* getNext(StackElement* head)
{
    return head->next;
}

StackElement* createStack()
{
    StackElement* stack = NULL;
    return stack;
}

void push(StackElement** head, int number)
{
    StackElement* newElement = malloc(sizeof(StackElement));
    if (newElement == NULL)
    {
        return;
    }
    newElement->value = number;
    newElement->next = *head;
    *head = newElement;
}

bool pop(StackElement** head, int* number)
{
    if (*head == NULL || head == NULL)
    {
        return false;
    }
    StackElement* temp = (*head)->next;
    *number = (*head)->value;
    free(*head);
    *head = temp;
    return true;
}

bool isEmpty(StackElement* head)
{
    return head == NULL;
}

void deleteStack(StackElement** head)
{
    while (!isEmpty(*head))
    {
        int number = 0;
        pop(head, &number);
    }
}