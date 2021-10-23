#include <stdbool.h>
#include <stdlib.h>
#include "calculatorTests.h"
#include "calculatorFunctions.h"
#include "../../stack/stack/stack.h"

bool calculatorTests()
{
    int length = 30;

    // tests calculator with correct input 
    char testSequence1[30] = "7 4 - 8 9 + * 3 / 9 9 9 + + -";
    int result = 0;
    bool correctInput = true;
    int result1 = calculate(testSequence1, &correctInput, length);
    if (!(correctInput && result1 == -10))
    {
        return false;
    }

    // tests calculator with incorrect input
    // case 1, more than one number in a stack after finishing calculations
    char testSequence2[30] = "6 4 + 2 - 8 / 5 * 9";
    correctInput = true;
    int result2 = calculate(testSequence2, &correctInput, length);
    if (correctInput)
    {
        return false;
    }

    //case 2, lack of numbers to finish all calculations with input operands
    char testSequence3[30] = "7 8 + 3 / 9 * -";
    correctInput = true;
    int result3 = calculate(testSequence3, &correctInput, length);
    if (correctInput)
    {
        return false;
    }

    // case 3, only operand given
    char testSequence4[30] = "+";
    correctInput = true;
    int result4 = calculate(testSequence4, &correctInput, length);
    return !correctInput;
}