#pragma once
#include <stdbool.h>

// converts infix notation to postfix and returns true if user input is correct false if it is incorrect
bool shuntingYard(const char infixNotation[], char postfixNotation[], const int length);