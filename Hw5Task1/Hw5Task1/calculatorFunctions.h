#pragma once
#include "../../stack/stack/stack.h"

// multiplies two values
void multiply(StackElement** head);

// divides (*head)->next value by *head value
void divide(StackElement** head);

// substracts *head value from (*head)->next value
void subtract(StackElement** head);

// adds two values
void add(StackElement** head);

// checks if user input is correct
bool checkCorrectInput(StackElement** head);

// gets expression and calculates it using operation functions. Returns true if user input is correct, false if it is incorrect
int calculate(char sequence[], bool* correctInput);