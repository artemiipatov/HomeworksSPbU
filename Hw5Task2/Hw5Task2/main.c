#include <stdio.h>
#include <stdlib.h>
#include "../../stack/stack/stackTests.h"
#include "BalanceOfParentheses.h"
#include "testsBalance.h"

int main()
{
    if (!(testsStack() && testsBalance()))
    {
        printf("Tests failed");
        return -1;
    }
    
    char sequence[30] = { '\0' };
    printf("Parentheses sequence: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);
    if (checkBalance(sequence) == 1)
    {
        printf("Balance is kept");
    }
    else
    {
        printf("There is no balance at all");
    }
}