#include <stdio.h>
#include "../../stack/stack/stackTests.h"
#include "calculatorFunctions.h"
#include "calculatorTests.h"

int main(int argc, char argv[])
{
    if (!(testsStack() && calculatorTests()))
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    char sequence[30] = { '\0' };
    printf("Print postfix expression: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);

    bool correctInput = true;
    int result = calculate(sequence, &correctInput, 30);
    if (!correctInput)
    {
        printf("Incorrect input");
        return -1;
    }
    printf("%d", result);
    return 0;
}