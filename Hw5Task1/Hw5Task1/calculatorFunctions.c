#include <stdlib.h>
#include <stdbool.h>
#include "../../stack/stack/stack.h"
#include "calculatorFunctions.h"

void multiply(StackElement** head)
{
    int firstFactor = 0;
    pop(head, &firstFactor);
    int secondFactor = 0;
    pop(head, &secondFactor);
    push(head, firstFactor * secondFactor);
}

void divide(StackElement** head)
{
    int divisor = 0;
    pop(head, &divisor);
    int dividend = 0;
    pop(head, &dividend);
    push(head, dividend / divisor);
}

void subtract(StackElement** head)
{
    int subtrahend = 0;
    pop(head, &subtrahend);
    int minuend = 0;
    pop(head, &minuend);
    push(head, minuend - subtrahend);
}

void add(StackElement** head)
{
    int firstSummand = 0;
    pop(head, &firstSummand);
    int secondSummand = 0;
    pop(head, &secondSummand);
    push(head, firstSummand + secondSummand);
}

bool checkCorrectInput(StackElement** head)
{
    return ((*head) != NULL && getNext(*head) != NULL);
}

 int calculate(char sequence[], bool* correctInput, int length)
{
    StackElement* head = createStack();
    for (int index = 0; index < length; index++)
    {
        if (sequence[index] != ' ' && sequence[index] != '\0' && sequence[index] != '\n')
        {
            switch (sequence[index])
            {
                case '*':
                {
                    if (!checkCorrectInput(&head))
                    {
                        *correctInput = false;
                        deleteStack(&head);
                        return 0;
                    }
                    multiply(&head);
                    break;
                }
                case '/':
                {
                    if (!checkCorrectInput(&head))
                    {
                        *correctInput = false;
                        deleteStack(&head);
                        return 0;
                    }
                    divide(&head);
                    break;
                }
                case '-':
                {
                    if (!checkCorrectInput(&head))
                    {
                        *correctInput = false;
                        deleteStack(&head);
                        return 0;
                    }
                    subtract(&head);
                    break;
                }
                case '+':
                {
                    if (!checkCorrectInput(&head))
                    {
                        *correctInput = false;
                        deleteStack(&head);
                        return 0;
                    }
                    add(&head);
                    break;
                }
                default:
                {
                    push(&head, (int)(sequence[index] - '0'));
                    break;
                }
            }
        }
    }
    int result = 0;
    pop(&head, &result);
    if (!isEmpty(head))
    {
        deleteStack(&head);
        *correctInput = false;
        return 0;
    }
    deleteStack(&head);
    return result;
}