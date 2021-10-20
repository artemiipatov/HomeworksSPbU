#pragma once
#include <stdbool.h>
#include "../../stack/stack/stack.h"

// checks previous bracket to decide if balance between previous bracket and current one is kept
bool checkPreviousBracket(StackElement** head, char currentBracket);

// main function, pushes elements to stack and calls checkPreviousBracket() function, returns true if balance is kept, false if it is not
bool checkBalance(StackElement* head, char* array);