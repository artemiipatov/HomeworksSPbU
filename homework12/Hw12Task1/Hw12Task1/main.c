#include <stdio.h>
#include "lexer.h"
#include "tests.h"

int main(int argc, char* argv[])
{
    if (!lexerPassedTests())
    {
        printf("Tests failed.");
        return -1;
    }
    if (argc != 1)
    {
        return 0;
    }
    bool numberIsReal = isReal("data.txt");
    printf("%d", numberIsReal);
    return 0;
}