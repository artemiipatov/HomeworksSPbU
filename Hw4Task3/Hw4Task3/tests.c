#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include "phonebookFunctions.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool testReadDataFromFile(PhoneBookEntry* testArray)
{
    readDataFromFile(testArray, 0, "test.txt");
    char* arrayWithTestValues[4] = { "isaac newton\n", "051-6320-123\n", "rene descartes\n", "03240-1234-534\n" };
    for (int index = 0; index < 3; index += 2)
    {
        if (strcmp(testArray[index / 2].name, arrayWithTestValues[index]) != 0)
        {
            return false;
        }
    }
    for (int index = 1; index < 4; index += 2)
    {
        if (strcmp(testArray[index / 2].phone, arrayWithTestValues[index]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool testAddNote(PhoneBookEntry* testArray)
{
    addNote(testArray, "Adam Smith\n", "7(911)-123-45-67\n", 2);
    return (strcmp(testArray[2].name, "Adam Smith\n") == 0 && strcmp(testArray[2].phone, "7(911)-123-45-67\n") == 0);
}

bool testSearchFunctions(PhoneBookEntry* testArray)
{
    return (findPhoneNumberUsingName(testArray, "Adam Smith\n", 3) == 2 && findNameUsingPhoneNumber(testArray, "03240-1234-534\n", 3) == 1);
}

bool testSaveDataToFile(PhoneBookEntry* testArray)
{
    saveData(testArray, 3, "test.txt");
    PhoneBookEntry dataFromFile[3] = { '\0' };
    readDataFromFile(dataFromFile, 0, "test.txt");
    char* assistantArray[6] = { "isaac newton\n", "051-6320-123\n", "rene descartes\n", "03240-1234-534\n", "Adam Smith\n", "7(911)-123-45-67\n" };
    for (int index = 0; index < 5; index += 2)
    {
        if (strcmp(dataFromFile[index / 2].name, assistantArray[index]) != 0)
        {
            return false;
        }
    }
    for (int index = 1; index < 6; index += 2)
    {
        if (strcmp(dataFromFile[index / 2].phone, assistantArray[index]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool uniteTestingFuctions()
{
    FILE* file = fopen("test.txt", "w");
    if (file == NULL)
    {
        printf("File not found");
        return false;
    }

    fprintf(file, "%s", "isaac newton\n");
    fprintf(file, "%s", "051-6320-123\n");
    fprintf(file, "%s", "rene descartes\n");
    fprintf(file, "%s", "03240-1234-534\n");
    fclose(file);

    PhoneBookEntry testArray[3] = { '\0' };
    return testReadDataFromFile(testArray) && testAddNote(testArray) && testSearchFunctions(testArray) && testSaveDataToFile(testArray);
}