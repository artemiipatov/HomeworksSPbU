#include "phonebookFunctions.h"
#include <stdio.h>

int readDataFromFile(PhoneBookEntry* notesArray, int currentIndex, const char fileName[])
{
    FILE* notes = fopen(fileName, "r");
    if (notes == NULL)
    {
        printf("File not found");
        return -1;
    }
    char* data[200] = { 0 };
    int linesRead = 0;

    while (!feof(notes))
    {
        char* buffer = malloc(sizeof(char) * 30);
        const int readBytes = fgets(buffer, 30, notes);
        if (readBytes < 0)
        {
            free(buffer);
            break;
        }
        data[linesRead] = buffer;
        ++linesRead;
    }
    fclose(notes);
    for (int index = 0; index < linesRead - 1; index += 2)
    {
        strcpy(notesArray[currentIndex].name, data[index]);
        strcpy(notesArray[currentIndex].phone, data[index + 1]);
        ++currentIndex;
    }
    return currentIndex;
}

void addNote(PhoneBookEntry* notesArray, const char* name, const char* phone, const int currentIndex)
{
    strcpy(notesArray[currentIndex].name, name);
    strcpy(notesArray[currentIndex].phone, phone);
}

void printAllNotes(const PhoneBookEntry* notesArray, int currentIndex)
{
    for (int index = 0; index < currentIndex; index++)
    {
        printf("Name: %sPhone Number: %s", notesArray[index].name, notesArray[index].phone);
        printf("-----\n");
    }
}

int findPhoneNumberUsingName(const PhoneBookEntry* notesArray, const char* toSearchName, const int currentIndex)
{
    for (int index = 0; index < currentIndex; index++)
    {
        if (strcmp(notesArray[index].name, toSearchName) == 0)
        {
            return index;
        }
    }
    return -1;
}

int findNameUsingPhoneNumber(const PhoneBookEntry* notesArray, const char* toSearchPhoneNumber, const int currentIndex)
{
    for (int index = 0; index < currentIndex; index++)
    {
        if (strcmp(notesArray[index].phone, toSearchPhoneNumber) == 0)
        {
            return index;
        }
    }
    return -1;
}

void printNameOrPhoneNumber(const PhoneBookEntry* notesArray, const int indexWithWantedNote, const bool nameOrPhone)
{
    if (nameOrPhone)
    {
        printf("Name: %s", notesArray[indexWithWantedNote].name);
    }
    else
    {
        printf("Phone number: %s", notesArray[indexWithWantedNote].phone);
    }
}

void saveData(const PhoneBookEntry* notesArray, const int currentIndex, const char fileName[])
{
    FILE* notes = fopen(fileName, "w");
    if (notes == NULL)
    {
        printf("File not found");
        return;
    }
    for (int index = 0; index < currentIndex; index++)
    {
        fprintf(notes, "%s%s", notesArray[index].name, notesArray[index].phone);
    }
    fclose(notes);
}