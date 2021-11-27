#include <stdio.h>
#include <stdbool.h>
#include "../../stack/stack/stackTests.h"
#include "shuntingYard.h"
#include "testsShuntingYard.h"
#define LENGTH 30

int main()
{
    if (!testsStack() || !testsPassed())
    {
        printf("Tests failed");
        return -1;
    }
    char input[LENGTH] = { '\0' };
    printf("Print infix expression: ");
    fgets(input, (unsigned)sizeof(input), stdin);
    char output[LENGTH] = { '\0' };
    bool isInputCorrect = shuntingYard(input, output, LENGTH);

    if (!isInputCorrect)
    {
        printf("Incorrect input");
        return -1;
    }
    printf("Postfix expresson: ");
    for (int index = 0; index < LENGTH; index++)
    {
        if (output[index] != '\0' && output[index] != '\n')
        {
            printf("%c ", output[index]);
        }
    }
    return 0;
}