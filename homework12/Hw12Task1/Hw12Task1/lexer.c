#include <stdio.h>
#include "lexer.h"

typedef enum stateName
{

} stateName;

bool isDigit(int value)
{
    return '0' <= value && value <= '9';
}

bool isReal(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return false;
    }
    int state = 0;
    while (true)
    {
        const char value = fgetc(file);
        switch (state)
        {
            case 0:
            {
                state = 1;
                if (value == EOF || !isDigit(value))
                {
                    state = -1;
                }
                break;
            }
            case 1:
            {
                if (value == EOF)
                {
                    state = 6;
                }
                else if (value == 'E')
                {
                    state = 4;
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
                if (value == EOF)
                {
                    state = 6;
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