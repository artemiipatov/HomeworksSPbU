#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// translate a number from file from binary notation to decimal
int binaryToDecimal(char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -1;
    }
    int decimal = 0;
    while (true)
    {
        char digit = fgetc(file);
        if (digit == EOF)
        {
            break;
        }
        decimal = decimal * 2 + ((int)digit - '0');
    }
    fclose(file);
    return decimal;
}

// tests
bool programPassedTests()
{
    FILE* file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "10011101");
    fclose(file);
    if (binaryToDecimal("testFile.txt") != 157)
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "1");
    fclose(file);
    if (binaryToDecimal("testFile.txt") != 1)
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "0");
    fclose(file);
    if (binaryToDecimal("testFile.txt") != 0)
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "101010101010010101");
    fclose(file);
    return binaryToDecimal("testFile.txt") == 174741;
}

int main()
{
    if (!programPassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    printf("decimal notation: %d", binaryToDecimal("data.txt"));
}