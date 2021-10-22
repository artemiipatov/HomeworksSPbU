#pragma once
#include <stdbool.h>

// main function, pushes elements to stack and calls checkPreviousBracket() function, returns true if balance is kept, false if it is not
bool checkBalance(char* array);