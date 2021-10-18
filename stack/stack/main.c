#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "stackTests.h"

int main()
{
    if (!stackTestingMaster())
    {
        printf("Tests failed");
        return -1;
    }
    StackElement* head = NULL;
    push(&head, 10);
    push(&head, 3);
    push(&head, 90);
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
}