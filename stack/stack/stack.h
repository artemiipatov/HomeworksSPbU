#pragma once
#include <stdbool.h>

// stack structure
typedef struct StackElement StackElement;

// returns head value
int getValue(StackElement* head);

// returns head next
StackElement* getNext(StackElement* head);

// creates stack
StackElement* createStack();

// adds new element to stack head
void push(StackElement** head, int number);

// fills variable number with head value and returns false if stack equals NULL, true if value has been received
bool pop(StackElement** head, int* number);

// checks if stack is empty, returns true if it is
bool isEmpty(StackElement* head);

// cleans whole stack
void deleteStack(StackElement** head);