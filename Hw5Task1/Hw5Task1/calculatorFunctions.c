#include <stdlib.h>
#include <stdbool.h>
#include "../../stack/stack/stack.h"
#include "calculatorFunctions.h"

bool isInputCorrect(StackElement** head)
{
    return *head != NULL && getNext(*head) != NULL;
}

 int calculate(char sequence[], bool* correctInput, int length)
{
    *correctInput = true;
    StackElement* head = createStack();
    for (int index = 0; index < length; index++)
    {
        if (sequence[index] != ' ' && sequence[index] != '\0' && sequence[index] != '\n')
        {
            switch (sequence[index])
            {
                case '*':
                case '/':
                case '-':
                case '+':
                {
                    if (!isInputCorrect(&head))
                    {
                        *correctInput = false;
                        deleteStack(&head);
                        return 0;
                    }
                    int firstOperand = 0;
                    pop(&head, &firstOperand);
                    int secondOperand = 0;
                    pop(&head, &secondOperand);
                    if (sequence[index] == '*')
                    {
                        push(&head, secondOperand * firstOperand);
                    }
                    else if (sequence[index] == '/')
                    {
                        push(&head, secondOperand / firstOperand);
                    }
                    else if (sequence[index] == '+')
                    {
                        push(&head, secondOperand + firstOperand);
                    }
                    else
                    {
                        push(&head, secondOperand - firstOperand);
                    }
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