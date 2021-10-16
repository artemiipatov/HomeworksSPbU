#include "stack.h"
#include "calculatorFunctions.h"

void multiply(StackElement** head)
{
    push(head, pop(head) * pop(head));
}

void divide(StackElement** head)
{
    const int divisor = pop(head);
    const int dividend = pop(head);
    push(head, dividend / divisor);

}

void subtract(StackElement** head)
{
    const int subtrahend = pop(head);
    const int minuend = pop(head);
    push(head, minuend - subtrahend);
}

void add(StackElement** head)
{
    push(head, pop(head) + pop(head));
}