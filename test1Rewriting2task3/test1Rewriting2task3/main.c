#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#define NUMBER_OF_ASCII_SYMBOLS 256

// counts frequency of every symbol in text file
bool countFrequency(char* fileName, int counters[NUMBER_OF_ASCII_SYMBOLS])
{
    //int counters[NUMBER_OF_ASCII_SYMBOLS] = { 0 };
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        return false;
    }
    while (true)
    {
        char symbol = getc(file);
        if (symbol == EOF)
        {
            break;
        }
        ++counters[((int)symbol + NUMBER_OF_ASCII_SYMBOLS) % NUMBER_OF_ASCII_SYMBOLS];
    }
    fclose(file);
    return true;
}

// prints frequency of every symbol
bool printCounters(char* fileName)
{
    int counters[NUMBER_OF_ASCII_SYMBOLS] = { 0 };
    if (!countFrequency(fileName, counters))
    {
        return false;
    }
    for (int index = 0; index < NUMBER_OF_ASCII_SYMBOLS; index++)
    {
        if (counters[index] != 0)
        {
            printf("%c %d\n", (char)index, counters[index]);
        }
    }
    return true;
}

// tests for countFrequency function
bool programPassedTests()
{
    int counters[NUMBER_OF_ASCII_SYMBOLS] = { 0 };
    if (!countFrequency("testFile.txt", counters))
    {
        return false;
    }
    if (counters[(int)'<'] != 4
        || counters[(int)'>'] != 4
        || counters[(int)'/'] != 5
        || counters[(int)'A'] != 3
        || counters[(int)'B'] != 3
        || counters[(int)'C'] != 3
        || counters[(int)'g'] != 2
        || counters[(int)'h'] != 5
        || counters[(int)'&'] != 2
        || counters[(int)'%'] != 2
        || counters[(int)'@'] != 1
        || counters[(int)'#'] != 1)
    {
        return false;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "");
    if (!programPassedTests())
    {
        printf("Tests failed.");
        return false;
    }
    if (!printCounters("data.txt"))
    {
        printf("Error occured");
    }
    return 0;
}