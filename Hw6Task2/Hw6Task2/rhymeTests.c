#include <stdbool.h>
#include "rhyme.h"
#include "rhymeTests.h"

bool rhymePassedTests()
{
    return (countPosition(37, 4) == 34 && countPosition(20, 3) == 20 
        && countPosition(41, 7) == 31 && countPosition(41, 1) == 41
        && countPosition(1, 1) == 1);
}