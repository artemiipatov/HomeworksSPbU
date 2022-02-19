#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lexer.h"
#include "tests.h"

// tests incorrect input
bool testCorrectInput()
{
    FILE* file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "00.B04-mm");
    fclose(file);
    if (!isCorrect("testFile.txt"))
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "10.M40-mm");
    fclose(file);
    if (!isCorrect("testFile.txt"))
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "10.S21-mm");
    fclose(file);
    return isCorrect("testFile.txt");
}

// tests incorrect input
bool testIncorrectInput()
{
    FILE* file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "matmex");
    fclose(file);
    if (isCorrect("test.txt"))
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "10S21mm");
    fclose(file);
    if (isCorrect("testFile.txt"))
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "10.B21-phys");
    fclose(file);
    return !isCorrect("testFile.txt");
}

bool lexerPassedTests()
{
    return testCorrectInput() && testCorrectInput();
}