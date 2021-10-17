#include <stdlib.h>
#include "stack.h"
#include "calculatorFunctions.h"

void multiply(StackElement** head)
{
    push(head, pop(head) * pop(head));
}

void divide(StackElement** head)
{
    const int divisor = pop(head);
    const int dividend = pop(head);
    push(head, dividend / divisor);
}

void subtract(StackElement** head)
{
    const int subtrahend = pop(head);
    const int minuend = pop(head);
    push(head, minuend - subtrahend);
}

void add(StackElement** head)
{
    push(head, pop(head) + pop(head));
}

bool checkCorrectInput(StackElement** head)
{
    return ((*head) != NULL && (*head)->value != NULL && ((*head)->next) != NULL);
}

bool calculate(StackElement** head, char sequence[])
{
    for (int index = 0; index < 30; index++)
    {
        if (sequence[index] != ' ' && sequence[index] != '\0' && sequence[index] != '\n')
        {
            switch (sequence[index])
            {
                case '*':
                {
                    if (!checkCorrectInput(head))
                    {
                        return false;
                    }
                    multiply(head);
                    break;
                }
                case '/':
                {
                    if (!checkCorrectInput(head))
                    {
                        return false;
                    }
                    divide(head);
                    break;
                }
                case '-':
                {
                    if (!checkCorrectInput(head))
                    {
                        return false;
                    }
                    subtract(head);
                    break;
                }
                case '+':
                {
                    if (!checkCorrectInput(head))
                    {
                        return false;
                    }
                    add(head);
                    break;
                }
                default:
                {
                    push(head, (int)(sequence[index] - '0'));
                    break;
                }
            }
        }
    }
    return ((*head)->next) == NULL;
}