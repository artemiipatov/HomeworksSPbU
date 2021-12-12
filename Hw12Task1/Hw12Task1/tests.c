#include <stdbool.h>
#include <stdio.h>
#include "lexer.h"
#include "tests.h"

bool lexerPassedTests()
{
    FILE* file = fopen("test.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "981259");
    fclose(file);
    if (isReal("test.txt"))
    {
        return false;
    }

    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "1.3492E");
    fclose(file);
    if (isReal("test.txt"))
    {
        return false;
    }

    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "1281934E+10");
    fclose(file);
    if (isReal("test.txt"))
    {
        return false;
    }

    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "1.281934E-10");
    fclose(file);
    if (!isReal("test.txt"))
    {
        return false;
    }

    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "1.2E+549");
    fclose(file);
    return isReal("test.txt");
}