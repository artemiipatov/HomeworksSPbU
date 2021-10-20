#include <stdbool.h>
#include "../../stack/stack/stack.h"
#include "BalanceOfParentheses.h"

bool testsBalance()
{
    // test 1, checkBalance() must return false;
    StackElement* testHead1 = createStack();
    char sequence1[30] = "(()";
    if (checkBalance(testHead1, sequence1))
    {
        deleteStack(&testHead1);
        return false;
    }
    // test 2, checkBalance() must return false;
    StackElement* testHead2 = createStack();
    char sequence2[30] = "[]]";
    if (checkBalance(testHead2, sequence2))
    {
        deleteStack(&testHead2);
        return false;
    }
    // test 3, checkBalance() must return false;
    StackElement* testHead3 = createStack();
    char sequence3[30] = "{";
    if (checkBalance(testHead3, sequence3))
    {
        deleteStack(&testHead3);
        return false;
    }
    // test 4, checkBalance() must return false;
    StackElement* testHead4 = createStack();
    char sequence4[30] = ")";
    if (checkBalance(testHead4, sequence4))
    {
        deleteStack(&testHead4);
        return false;
    }
    // test 5, checkBalance() must return true;
    StackElement* testHead5 = createStack();
    char sequence5[30] = "(){[(){}]}";
    if (!checkBalance(testHead5, sequence5))
    {
        deleteStack(&testHead5);
        return false;
    }
    // test 6, checkBalance() must return false;
    StackElement* testHead6 = createStack();
    char sequence6[30] = "{[({})}}";
    if (checkBalance(testHead6, sequence6))
    {
        deleteStack(&testHead6);
        return false;
    }
    return true;
}