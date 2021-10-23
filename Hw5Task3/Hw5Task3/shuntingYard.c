#include <stdlib.h>
#include "../../stack/stack/stack.h"
#include "shuntingYard.h"

bool shuntingYard(char infixNotation[], char postfixNotation[], int length)
{
    StackElement* head = createStack();
    int currentIndex = 0;
    for (int index = 0; index < length; index++)
    {
        if (infixNotation[index] != '\n' && infixNotation[index] != '\0')
        {
            switch (infixNotation[index])
            {
                case '(':
                case '*':
                case '/':
                {
                    push(&head, infixNotation[index]);
                    break;
                }
                case ')':
                {
                    int headValue = 0;
                    bool isValueReceived = pop(&head, &headValue);
                    while (headValue != '(')
                    {
                        if (!isValueReceived)
                        {
                            deleteStack(&head);
                            return false;
                        }
                        postfixNotation[currentIndex] = headValue;
                        currentIndex++;
                        isValueReceived = pop(&head, &headValue);
                    }
                    break;
                }
                case '+':
                case '-':
                {
                    int headValue = 0;
                    while (pop(&head, &headValue))
                    {
                        if (headValue == '*' || headValue == '/' || headValue == '+' || headValue == '-')
                        {
                            postfixNotation[currentIndex] = headValue;
                            currentIndex++;
                        }
                        else
                        {
                            push(&head, headValue);
                            break;
                        }
                    }
                    push(&head, infixNotation[index]);
                    break;
                }
                default:
                {
                    postfixNotation[currentIndex] = infixNotation[index];
                    currentIndex++;
                    break;
                }
            }
        }
    }
    int headValue = 0;
    while (pop(&head, &headValue))
    {
        if (headValue == '(')
        {
            deleteStack(&head);
            return false;
        }
        postfixNotation[currentIndex] = headValue;
        currentIndex++;
    }
    deleteStack(&head);
    return true;
}