#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

int main()
{
    if (!testsStack())
    {
        printf("Tests failed");
        return -1;
    }
    StackElement* head = createStack();
    push(&head, 10);
    push(&head, 3);
    push(&head, 90);
    int value = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("%d", pop(&head, &value));
        printf(", %d\n", value);
    }
    printf("%d\n", pop(&head, &value));
}