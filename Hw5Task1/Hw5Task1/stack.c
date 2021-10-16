#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

void push(StackElement** head, const int number)
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

int pop(StackElement** head)
{
    if (*head == NULL || head == NULL)
    {
        return -1;
    }
    StackElement* temp = (*head)->next;
    const int value = (*head)->value;
    free(*head);
    *head = temp;
    return value;
}

bool isEmpty(StackElement* head)
{
    return head == NULL;
}

void deleteStack(StackElement** head)
{
    while (!isEmpty(*head))
    {
        pop(head);
    }
}