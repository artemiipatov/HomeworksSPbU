#include "tests.h"
#include "stringSearch.h"

bool stringSearchPassedTests()
{
    int s1 = findFirstOccurence("testData.txt", "data");
    int s2 = findFirstOccurence("testData.txt", "l");
    int s3 = findFirstOccurence("testData.txt", "associative array abstract data type");
    int s4 = findFirstOccurence("testData.txt", "qweasdzxc");
    int s5 = findFirstOccurence("testData.txt", "lues");
    return s1 == 44 && s2 == 25 && s3 == 78 && s4 == -1 && s5 == 151;
}