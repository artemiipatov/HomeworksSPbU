#pragma once
#include <stdbool.h>

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

// adds new element to stack head
void push(StackElement** head, int number);

// returns stack head element and removes it from stack
int pop(StackElement** head);

// checks if stack is empty, returns true if it is
bool isEmpty(StackElement* head);

// cleans whole stack
void deleteStack(StackElement** head);