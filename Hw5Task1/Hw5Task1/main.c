#include <stdio.h>
#include "stack.h"
#include "stackTests.h"

int main()
{
    if (!testMaster())
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
                    push(&head, pop(&head) * pop(&head));
                    break;
                }
                case '/':
                {
                    const int divisor = pop(&head);
                    const int dividend = pop(&head);
                    push(&head, dividend / divisor);
                    break;
                }
                case '-':
                {
                    const int subtrahend = pop(&head);
                    const int minuend = pop(&head);
                    push(&head, minuend - subtrahend);
                    break;
                }
                case '+':
                {
                    push(&head, pop(&head) + pop(&head));
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