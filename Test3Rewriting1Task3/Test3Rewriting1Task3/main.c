#include <stdio.h>
#include <stdbool.h>

// checks if string is correct
bool isAccepted(char* fileName)
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
                const char value = getc(file);
                if (('A' <= value && value <= 'Z') || ('0' <= value && value <= '9')
                    || value == '.' || value == '_' || value == '%' || value == '+' || value == '-')
                {
                    state = 1;
                }
                else
                {
                    state = -1;
                }
                break;
            }
            case 1:
            {
                const char value = getc(file);
                if (value == EOF)
                {
                    fclose(file);
                    return true;
                }
                if (('A' <= value && value <= 'Z') || ('0' <= value && value <= '9')
                    || value == '.' || value == '_' || value == '%' || value == '+' || value == '-')
                {
                    state = 1;
                }
                else if (value == '@')
                {
                    state = 2;
                }
                else
                {
                    state = -1;
                }
                break;
            }
            case 2:
            {
                const char value = getc(file);
                if(value == EOF)
                {
                    fclose(file);
                    return true;
                }
                if (('A' <= value && value <= 'Z') || ('0' <= value && value <= '9') || value == '-')
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
                const char value = getc(file);
                if (value == EOF)
                {
                    fclose(file);
                    return true;
                }
                if (('A' <= value && value <= 'Z') || ('0' <= value && value <= '9') || value == '-')
                {
                    state = 3;
                }
                else if (value == '.')
                {
                    state = 4;
                }
                else
                {
                    state = -1;
                }
                break;
            }
            case 4:
            {
                const char value = getc(file);
                if (value == EOF)
                {
                    fclose(file);
                    return true;
                }
                else if (('A' <= value && value <= 'Z') || ('0' <= value && value <= '9') || value == '-')
                {
                    state = 3;
                }
                else if (value == '.')
                {
                    state = 4;
                }
                else if ('A' <= value && value <= 'Z')
                {
                    return true;
                }
                else
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
}

// tests function above
bool programPassedTests()
{
    FILE* file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "ABZMN954._134%4-VC+D@ZXC09.CD09R");
    fclose(file);
    if (!isAccepted("testFile.txt"))
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "CD09R");
    fclose(file);
    if (isAccepted("testFile.txt"))
    {
        return false;
    }

    file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, ".");
    fclose(file);
    return !isAccepted("testFile.txt");
}

int main()
{
    if (!programPassedTests())
    {
        return -1;
    }
    return 0;
}