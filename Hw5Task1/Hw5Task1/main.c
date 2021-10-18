#include <stdio.h>
#include "../../stack/stack/stack.h"
#include "../../stack/stack/stackTests.h"
#include "calculatorFunctions.h"
#include "calculatorTests.h"

int main()
{
    if (!(stackTestingMaster() && calculatorTests()))
    {
        printf("Tests failed");
        return -1;
    }
    StackElement* head = NULL;
    char sequence[30] = { '\0' };
    printf("Print postfix expression: ");
    fgets(sequence, (unsigned)sizeof(sequence), stdin);

    if (!calculate(&head, sequence))
    {
        printf("Incorrect input");
        return -1;
    }
    printf("%d", pop(&head));
    return 0;
}