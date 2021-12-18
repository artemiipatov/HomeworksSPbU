#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

int main(int argc, char argv[])
{
    if (!testsStack())
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
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
    deleteStack(&head);
    return 0;
}