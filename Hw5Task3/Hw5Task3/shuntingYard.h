#pragma once
#include <stdbool.h>

// converts infix notation to postfix and returns true if user input is correct false if it is incorrect
bool shuntingYard(char infixNotation[], char postfixNotation[], int length);