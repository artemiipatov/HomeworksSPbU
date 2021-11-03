#include <stdbool.h>
#include "BalanceOfParentheses.h"

bool testsBalance()
{
    const int length = 30;
    // test 1, checkBalance() must return false;
    char sequence1[30] = "(()";
    if (checkBalance(sequence1, length))
    {
        return false;
    }

    // test 2, checkBalance() must return false;
    char sequence2[30] = "[]]";
    if (checkBalance(sequence2, length))
    {
        return false;
    }

    // test 3, checkBalance() must return false;
    char sequence3[30] = "{";
    if (checkBalance(sequence3, length))
    {
        return false;
    }

    // test 4, checkBalance() must return false;
    char sequence4[30] = ")";
    if (checkBalance(sequence4, length))
    {
        return false;
    }

    // test 5, checkBalance() must return true;
    char sequence5[30] = "(){[()[[[]]]{}]}";
    if (!checkBalance(sequence5, length))
    {
        return false;
    }

    // test 6, checkBalance() must return false;
    char sequence6[30] = "{[({})}}";
    return !checkBalance(sequence6, length);
}