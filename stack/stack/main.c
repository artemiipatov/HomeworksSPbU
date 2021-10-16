#include <stdio.h>
#include "stack.h"

int main()
{
    StackElement* head = NULL;
    push(&head, 10);
    push(&head, 3);
    push(&head, 5);
    push(&head, 90);
    printf("%d", isEmpty(head));
    deleteStack(&head);
    printf("%d", isEmpty(head));
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
    printf("%d ", pop(&head));
}