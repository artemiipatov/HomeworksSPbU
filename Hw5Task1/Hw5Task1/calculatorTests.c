#include <stdbool.h>
#include <stdlib.h>
#include "calculatorTests.h"
#include "calculatorFunctions.h"
#include "stack.h"

bool calculatorTests()
{
    // tests calculator with correct input 
    StackElement* testHead1 = NULL;
    char testSequence1[30] = "7 4 - 8 9 + * 3 / 9 9 9 + + -";
    if (!calculate(&testHead1, testSequence1) || pop(&testHead1) != -10)
    {
        return false;
    }

    // tests calculator with incorrect input
    // case 1, more than one number in a stack after finishing calculations
    StackElement* testHead2 = NULL;
    char testSequence2[30] = "6 4 + 2 - 8 / 5 * 9";
    if (calculate(&testHead2, testSequence2) != false)
    {
        return false;
    }
    deleteStack(&testHead2);
    //case 2, lack of numbers to finish all calculations with input operands
    StackElement* testHead3 = NULL;
    char testSequence3[30] = "7 8 + 3 / 9 * -";
    if (calculate(&testHead3, testSequence3) != false)
    {
        return false;
    }
    // case 3, only operand given
    StackElement* testHead4 = NULL;
    char testSequence4[30] = "+";
    return calculate(&testHead4, testSequence4) == false;
}