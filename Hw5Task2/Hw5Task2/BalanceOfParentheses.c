#include <stdbool.h>
#include "../../stack/stack/stack.h"
#include "BalanceOfParentheses.h"

bool checkPreviousBracket(StackElement** head, char currentBracket)
{
    switch (currentBracket)
    {
        case ')':
        {
            char previousBracket = getValue(*head);
            if (previousBracket == '(')
            {
                int buffer = 0;
                pop(head, &buffer);
                return true;
            }
            else if (previousBracket == '{' || previousBracket == '[')
            {
                return false;
            }
            else if (previousBracket == '}' || previousBracket == ']')
            {
                return true;
            }
            return false;
        }
        case '}':
        {
            char previousBracket = getValue(*head);
            if (previousBracket == '{')
            {
                int buffer = 0;
                pop(head, &buffer);
                return true;
            }
            else if (previousBracket == '(' || previousBracket == '[')
            {
                return false;
            }
            else if (previousBracket == ')' || previousBracket == ']')
            {
                return true;
            }
            return false;
        }
        case ']':
        {
            char previousBracket = getValue(*head);
            if (previousBracket == '[')
            {
                int buffer = 0;
                pop(head, &buffer);
                return true;
            }
            else if (previousBracket == '(' || previousBracket == '{')
            {
                return false;
            }
            else if (previousBracket == '}' || previousBracket == ')')
            {
                return true;
            }
            return false;
        }
        default:
        {
            return false;
        }
    }
}

bool checkBalance(StackElement* head, char* sequence)
{
    push(&head, sequence[0]);
    for (int index = 1; index < 30; index++)
    {
        if (!(sequence[index] == '\0' || sequence[index] == '\n'))
        {
            if (sequence[index] == ')' || sequence[index] == ']' || sequence[index] == '}')
            {
                if (isEmpty(head) || !checkPreviousBracket(&head, sequence[index]))
                {
                    return false;
                }
            }
            else
            {
                push(&head, sequence[index]);
            }
        }
    }
    return isEmpty(head);
}