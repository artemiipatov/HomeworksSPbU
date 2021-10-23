#include <stdio.h>
#include <stdbool.h>
#include "../../stack/stack/stackTests.h"
#include "shuntingYard.h"
#include "testsShuntingYard.h"

int main()
{
    if (!testsStack() && !testsPassed())
    {
        printf("Tests failed");
        return -1;
    }
    char input[30] = { '\0' };
    printf("Print infix expression: ");
    fgets(input, (unsigned)sizeof(input), stdin);
    char output[30] = { '\0' };
    bool isInputCorrect = shuntingYard(input, output, 30);

    if (!isInputCorrect)
    {
        printf("Incorrect input");
        return -1;
    }
    for (int index = 0; index < 30; index++)
    {
        if (output[index] != '\0' && output[index] != '\n')
        {
            printf("%c ", output[index]);
        }
    }
    return 0;
}