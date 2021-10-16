#include <stdbool.h>
#include <stdlib.h>
#include "calculatorTests.h"
#include "calculatorFunctions.h"

bool testCalculator()
{
    StackElement* testHead = NULL;
    const char testSequence[30] = "7 4 - 8 9 + * 3 / 9 9 9 + + -";
    for (int index = 0; index < 30; index++)
    {
        if (testSequence[index] != ' ' && testSequence[index] != '\0')
        {
            switch (testSequence[index])
            {
                case '*':
                {
                    multiply(&testHead);
                    break;
                }
                case '/':
                {
                    divide(&testHead);
                    break;
                }
                case '-':
                {
                    subtract(&testHead);
                    break;
                }
                case '+':
                {
                    add(&testHead);
                    break;
                }
                default:
                {
                    push(&testHead, (int)(testSequence[index] - '0'));
                    break;
                }
            }
        }
    }
    return pop(&testHead) == -10;
}