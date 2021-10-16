#include <stdbool.h>
#include <stdlib.h>
#include "stackTests.h"
#include "stack.h"

bool testPush(StackElement** testHead)
{
    push(testHead, 10);
    push(testHead, 25);
    return ((*testHead)->value) == 25 && (((*testHead)->next)->value) == 10;
}

bool testPop(StackElement** testHead)
{
    return pop(testHead) == 25 && pop(testHead) == 10 && pop(testHead) == -1;
}

bool testIsEmpty(StackElement** testHead)
{
    return isEmpty(*testHead);
}

bool testDeleteStack(StackElement** testHead)
{
    deleteStack(testHead);
    return (*testHead) == NULL;
}

bool testMaster()
{
    StackElement* testHead = NULL;
    return testPush(&testHead) && testPop(&testHead) && testIsEmpty(&testHead) && testDeleteStack(&testHead) && testIsEmpty(&testHead);
    //testPush(&testHead);
    //testPop(&testHead);
    //testIsEmpty(&testHead);
    //testDeleteStack(&testHead);
    //testIsEmpty(&testHead);
}