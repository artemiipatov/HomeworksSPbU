#include <stdio.h>
#include "stack.h"
#include "stackTests.h"
#include "calculatorFunctions.h"
#include "calculatorTests.h"

int main()
{
    if (!(stackTestingMaster() && testCalculator()))
    {
        printf("Tests failed");
        return -1;
    }
    StackElement* head = NULL;
    char sequence[30] = { '\0' };
    printf("Print postfix expression: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);
    for (int index = 0; index < 30; index++)
    {
        if (sequence[index] != ' ' && sequence[index] != '\0' && sequence[index] != '\n')
        {
            switch (sequence[index])
            {
                case '*':
                {
                    multiply(&head);
                    break;
                }
                case '/':
                {
                    divide(&head);
                    break;
                }
                case '-':
                {
                    subtract(&head);
                    break;
                }
                case '+':
                {
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
    printf("%d", pop(&head));
    deleteStack(&head);
    return 0;
}