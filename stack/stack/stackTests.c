#include <stdbool.h>
#include <stdlib.h>
#include "stackTests.h"
#include "stack.h"

bool testsStack()
{
    StackElement* testHead = createStack();
    push(&testHead, 10);
    push(&testHead, 25);
    push(&testHead, 90);
    if (!(getValue(testHead) == 90 && getValue(getNext(testHead))) == 25)
    {
        return false;
    }
    if (isEmpty(testHead))
    {
        return false;
    }
    int value = 0;
    bool checkError1 = pop(&testHead, &value);
    if (!(checkError1 && value == 90))
    {
        return false;
    }
    deleteStack(&testHead);
    bool checkError2 = pop(&testHead, &value);
    if (checkError2)
    {
        return false;
    }
    return isEmpty(testHead);
}