#include <stdbool.h>
#include "shuntingYard.h"
#include "testsShuntingYard.h"
#define LENGTH 30

bool testIncorrectInput()
{
    char input1[LENGTH] = "2+3+4*(9+(2-8/(6-5)))*7)";
    char output1[LENGTH] = { '\0' };
    char input2[LENGTH] = "2+3+4*(9+((2-8/(6-5))*7)";
    char output2[LENGTH] = { '\0' };
    if (shuntingYard(input1, output1, LENGTH) || shuntingYard(input2, output2, LENGTH))
    {
        return false;
    }
    return true;
}

bool testCorrectInput()
{
    char input1[LENGTH] = "2+3+4*(9+(2-8/(6-5))*7)+1";
    char output1[LENGTH] = { '\0' };
    const char correctOutput1[20] = "23+492865-/-7*+*+1+";
    bool isInputCorrect = shuntingYard(input1, output1, LENGTH);
    if (!isInputCorrect)
    {
        return false;
    }
    for (int index = 0; index < 20; index++)
    {
        if (correctOutput1[index] != output1[index])
        {
            return false;
        }
    }

    char input2[LENGTH] = "(6+7)*5+3*(5+4)-8/(8+(3+9)*7)";
    char output2[LENGTH] = { '\0' };
    const char correctOutput2[LENGTH] = "67+5*354+*+8839+7*+/-";
    if (!shuntingYard(input2, output2, LENGTH))
    {
        return false;
    }
    for (int index = 0; index < LENGTH; index++)
    {
        if (correctOutput2[index] != output2[index])
        {
            return false;
        }
    }
    return true;
}

bool testsPassed()
{
    return testCorrectInput() && testIncorrectInput();
}