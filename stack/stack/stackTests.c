#include <stdbool.h>
#include <stdlib.h>
#include "stackTests.h"
#include "stack.h"

bool testsStack()
{
    StackElement* testHead = NULL;
    push(&testHead, 10);
    push(&testHead, 25);
    push(&testHead, 90);
    if (!(((testHead)->value) == 90 && (((testHead)->next)->value) == 25))
    {
        return false;
    }
    if (isEmpty(testHead))
    {
        return false;
    }
    if (!(pop(&testHead) == 90 && pop(&testHead) == 25))
    {
        return false;
    }
    deleteStack(&testHead);
    return isEmpty(testHead) && pop(&testHead) == -1;
}