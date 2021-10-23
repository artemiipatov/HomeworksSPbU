#include <stdio.h>
#include "../../stack/stack/stackTests.h"
#include "calculatorFunctions.h"
#include "calculatorTests.h"

int main()
{
    if (!(testsStack() && calculatorTests()))
    {
        printf("Tests failed");
        return -1;
    }
    char sequence[30] = { '\0' };
    printf("Print postfix expression: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);

    bool correctInput = true;
    int result = calculate(sequence, &correctInput);
    if (!correctInput)
    {
        printf("Incorrect input");
        return -1;
    }
    printf("%d", result);
    return 0;
}