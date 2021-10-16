#pragma once
#include <stdbool.h>
#include "stack.h"

// tests push function
bool testPush(StackElement** testHead);

// tests pop function
bool testPop(StackElement** testHead);

// test isEmpty function
bool testIsEmpty(StackElement** testHead);

// tests DeleteStack function
bool testDeleteStack(StackElement** testHead);

// unite all stack testing functions
bool testMaster();