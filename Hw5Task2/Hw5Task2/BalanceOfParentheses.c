#include <stdbool.h>
#include "../../stack/stack/stack.h"
#include "BalanceOfParentheses.h"

// checks previous bracket to find out if balance between previous bracket and current one is kept
bool checkPreviousBracket(StackElement** head, char currentBracket)
{
    switch (currentBracket)
    {
        case ')':
        {
            switch (getValue(*head))
            {
                case '(':
                {
                    int buffer = 0;
                    pop(head, &buffer);
                    return true;
                }
                case '}':
                case ']':
                {
                    return true;
                }
                default:
                {
                    return false;
                }
            }
        }
        case '}':
        {
            switch (getValue(*head))
            {
                case '{':
                {
                    int buffer = 0;
                    pop(head, &buffer);
                    return true;
                }
                case ')':
                case ']':
                {
                    return true;
                }
                default:
                {
                    return false;
                }
            }
        }
        case ']':
        {
            switch (getValue(*head))
            {
                case '[':
                {
                    int buffer = 0;
                    pop(head, &buffer);
                    return true;
                }
                case '}':
                case ')':
                {
                    return true;
                }
                default:
                {
                    return false;
                }
            }
        }
        default:
        {
            return false;
        }
    }
}

bool checkBalance(char* sequence)
{
    StackElement* head = createStack();
    push(&head, sequence[0]);
    for (int index = 1; index < 30; index++)
    {
        if (!(sequence[index] == '\0' || sequence[index] == '\n'))
        {
            switch (sequence[index])
            {
                case ')':
                case ']':
                case '}':
                {
                    if (isEmpty(head) || !checkPreviousBracket(&head, sequence[index]))
                    {
                        return false;
                    }
                    break;
                }
                default:
                {
                    push(&head, sequence[index]);
                }
            }
        }
    }
    bool checkEmpty = isEmpty(head);
    deleteStack(&head);
    return checkEmpty;
}