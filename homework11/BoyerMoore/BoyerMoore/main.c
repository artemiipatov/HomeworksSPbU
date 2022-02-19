#include <stdio.h>
#include "stringSearch.h"
#include "tests.h"

int main(int argc, char argv[])
{
    if (!stringSearchPassedTests())
    {
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    char string[50] = {'\0'};
    printf("substring: ");
    gets_s(string, 50);
    int value = findFirstOccurence("data.txt", string);
    value == -1 ? printf("%s was not found in the text", string) : printf("%s first occurence: %d", string, value);
    return 0;
}