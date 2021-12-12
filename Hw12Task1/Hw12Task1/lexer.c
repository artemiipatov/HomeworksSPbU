#include <stdio.h>
#include "lexer.h"

bool isDigit(int value)
{
    return value == '0' || value == '1' || value == '2'
        || value == '3' || value == '4' || value == '5'
        || value == '6' || value == '7'|| value == '8'
        || value == '9';
}

bool isReal(char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return false;
    }
    int state = 0;
    while (true)
    {
        switch (state)
        {
            case 0:
            {
                state = 1;
                const char value = fgetc(file);
                if (value == EOF || !isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 1:
            {
                const char value = fgetc(file);
                if (value == EOF)
                {
                    state = -1;
                }
                else if (value == '.')
                {
                    state = 2;
                }
                else if (!isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 2:
            {
                const char value = fgetc(file);
                if (isDigit(value))
                {
                    state = 3;
                }
                else
                {
                    state = -1;
                }
                break;
            }
            case 3:
            {
                const char value = fgetc(file);
                if (value == EOF)
                {
                    state = -1;
                }
                else if (value == 'E')
                {
                    state = 4;
                }
                else if (!isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 4:
            {
                const char value = fgetc(file);
                if (value == '+' || value == '-')
                {
                    state = 5;
                }
                else if (isDigit(value))
                {
                    state = 6;
                }
                else
                {
                    state = -1;
                }
                break;
            }
            case 5:
            {
                const char value = fgetc(file);
                if (isDigit(value))
                {
                    state = 6;
                }
                else
                {
                    state = -1;
                }
                break;
            }
            case 6:
            {
                const char value = fgetc(file);
                if (value == EOF)
                {
                    fclose(file);
                    return true;
                }
                else if (!isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            default:
            {
                fclose(file);
                return false;
            }
        }
    }
    fclose(file);
    return true;
}