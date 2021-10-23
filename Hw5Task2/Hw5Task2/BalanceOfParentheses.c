#include <stdbool.h>
#include "../../stack/stack/stack.h"
#include "BalanceOfParentheses.h"

// checks previous bracket to find out if balance between previous bracket and current one is kept
bool checkPreviousBracket(StackElement** head, char currentBracket)
{
    char previousBracket = getValue(*head);
    if (   (currentBracket == ')' && previousBracket == '(')
        || (currentBracket == '}' && previousBracket == '{')
        || (currentBracket == ']' && previousBracket == '[')   )
    {
        int buffer = 0;
        pop(head, &buffer);
        return true;
    }
    else
    {
        return false;
    }
}

bool checkBalance(char sequence[], int length)
{
    StackElement* head = createStack();
    push(&head, sequence[0]);
    for (int index = 1; index < length; index++)
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
            case '(':
            case '[':
            case '{':
            {
                push(&head, sequence[index]);
            }
        }
    }
    bool checkEmpty = isEmpty(head);
    deleteStack(&head);
    return checkEmpty;
}