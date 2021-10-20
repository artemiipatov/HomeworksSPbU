#include <stdio.h>
#include "../../stack/stack/stack.h"
#include "../../stack/stack/stackTests.h"
#include "calculatorFunctions.h"
#include "calculatorTests.h"

int main()
{
    if (!(testsStack() && calculatorTests()))
    {
        printf("Tests failed");
        return -1;
    }
    StackElement* head = createStack();
    char sequence[30] = { '\0' };
    printf("Print postfix expression: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);

    if (!calculate(&head, sequence))
    {
        printf("Incorrect input");
        deleteStack(&head);
        return -1;
    }
    int result = 0;
    pop(&head, &result);
    printf("%d", result);
    return 0;
}