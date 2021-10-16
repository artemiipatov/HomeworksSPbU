#pragma once
#include <stdbool.h>

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

void push(StackElement** head, int number);

int pop(StackElement** head);

bool isEmpty(StackElement* head);

void deleteStack(StackElement** head);