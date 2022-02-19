#include <stdio.h>
#include "lexer.h"

bool isDigit(int value)
{
    return value == '0' || value == '1' || value == '2'
        || value == '3' || value == '4' || value == '5'
        || value == '6' || value == '7' || value == '8'
        || value == '9';
}

bool isCorrect(char* fileName)
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
                state = 2;
                const char value = fgetc(file);
                if (value == EOF || !isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 2:
            {
                state = 3;
                const char value = fgetc(file);
                if (value == EOF || value != '.')
                {
                    state = -1;
                }
                break;
            }
            case 3:
            {
                state = 4;
                const char value = fgetc(file);
                if (value == EOF || (value != 'B' && value != 'M' && value != 'S'))
                {
                    state = -1;
                }
                break;
            }
            case 4:
            {
                state = 5;
                const char value = fgetc(file);
                if (value == EOF || !isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 5:
            {
                state = 6;
                const char value = fgetc(file);
                if (value == EOF || !isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 6:
            {
                state = 7;
                char value = fgetc(file);
                if (value == EOF || value != '-')
                {
                    state = -1;
                }
                value = fgetc(file);
                if (value == EOF || value != 'm')
                {
                    state = -1;
                }
                value = fgetc(file);
                if (value == EOF || value != 'm')
                {
                    state = -1;
                }
                break;
            }
            case 7:
            {
                const char value = fgetc(file);
                if (value == EOF)
                {
                    fclose(file);
                    state = 99;
                }
                break;
            }
            case -1:
            {
                fclose(file);
                return false;
            }
            default:
            {
                fclose(file);
                return true;
            }
        }
    }
}