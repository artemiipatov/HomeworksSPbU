#include <stdio.h>
#include "lexer.h"
#include "tests.h"

int main()
{
    if (!lexerPassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    isCorrect("data.txt") ? printf("Correct!") : printf("Incorrect");
}