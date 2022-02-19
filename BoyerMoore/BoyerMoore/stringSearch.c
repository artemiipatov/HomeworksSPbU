#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stringSearch.h"

int findFirstOccurence(char* fileName, char* string)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return -1;
    }
    int table[256] = { 0 };
    const int stringLength = (int)strlen(string);
    int counter = stringLength;

    for (int index = stringLength - 2; index >= 0; index--)
    {
        if (table[(int)string[index]] == 0)
        {
            table[(int)string[index]] = stringLength - 1 - index;
        }
    }
    table[(int)string[stringLength - 1]] = table[(int)string[stringLength - 1]] == 0 ? stringLength : table[(int)string[stringLength - 1]];
    fseek(file, stringLength * sizeof(char) - 1, SEEK_CUR);
    while (true)
    {
        for (int i = stringLength - 1; i >= 0; i--)
        {
            const char symbol = fgetc(file);
            if (symbol == EOF)
            {
                fclose(file);
                return -1;
            }
            if (symbol != string[i])
            {
                if (i == stringLength - 1)
                {
                    if (table[(int)symbol] == 0)
                    {
                        fseek(file, stringLength - 1, SEEK_CUR);
                        counter += stringLength;
                    }
                    else
                    {
                        fseek(file, table[(int)symbol] - 1, SEEK_CUR);
                        counter += table[(int)symbol];
                    }
                    break;
                }
                fseek(file, stringLength - i - 1, SEEK_CUR);
                fseek(file, table[(int)string[stringLength - 1]] - 1, SEEK_CUR);
                counter += stringLength - i - 1 + table[(int)string[stringLength - 1]];
                break;
            }
            if (i == 0)
            {
                fclose(file);
                return counter;
            }
            fseek(file, -2, SEEK_CUR);
            --counter;
        }
    }
    fclose(file);
    return -1;
}