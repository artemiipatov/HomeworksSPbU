#include <stdbool.h>
#include "shuntingYard.h"
#include "testsShuntingYard.h"

bool testIncorrectInput()
{
    char input[30] = "2+3+4*(9+(2-8/(6-5)))*7)";
    char output[30] = { '\0' };
    bool isInputCorrect = shuntingYard(input, output, 30);
    if (isInputCorrect)
    {
        return false;
    }
    return true;
}

bool testCorrectInput()
{
    char input[30] = "2+3+4*(9+(2-8/(6-5))*7)+1";
    char output[30] = { '\0' };
    char correctOutput[20] = "23+492865-/-7*+*+1+";
    bool isInputCorrect = shuntingYard(input, output, 30);
    if (!isInputCorrect)
    {
        return false;
    }
    for (int index = 0; index < 20; index++)
    {
        if (correctOutput[index] != output[index])
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