#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char name[30];
    char phone[30];
} PhoneBookEntry;

// function for reading data from file at the beginning of the program; testOrNot = true => opens test.txt, else opens data.txt
int readDataFromFile(PhoneBookEntry* notesArray, int currentIndex, bool testOrNot)
{
    FILE* notes;
    if (testOrNot)
    {
        notes = fopen("test.txt", "r");
    }
    else
    {
        notes = fopen("data.txt", "r");
    }
    if (notes == NULL)
    {
        printf("File not found");
        return;
    }
    char* data[200] = { 0 };
    int linesRead = 0;

    while (!feof(notes))
    {
        char* buffer = malloc(sizeof(char) * 100);
        const int readBytes = fgets(buffer, 30, notes);
        if (readBytes < 0)
        {
            free(buffer);
            break;
        }
        data[linesRead] = buffer;
        ++linesRead;
    }
    for (int index = 0; index < linesRead - 1; index += 2)
    {
        strcpy(notesArray[currentIndex].name, data[index]);
        strcpy(notesArray[currentIndex].phone, data[index + 1]);
        ++currentIndex;
    }
    fclose(notes);
    return currentIndex;
}

// function for adding note (name and phone number) to an array with all notes
void addNote(PhoneBookEntry* notesArray, char* name, char* phone, int currentIndex)
{
    strcpy(notesArray[currentIndex].name, name);
    strcpy(notesArray[currentIndex].phone, phone);
    return;
}

// function for printing all notes in console
void printAllNotes(PhoneBookEntry* notesArray, int currentIndex)
{
    for (int index = 0; index < currentIndex; index++)
    {
        printf("Name: %sPhone Number: %s", notesArray[index].name, notesArray[index].phone);
        printf("-----\n");
    }
    return;
}

// function for searching phone number using name
int findPhoneNumberUsingName(PhoneBookEntry* notesArray, char* toSearchName, int currentIndex)
{
    int indexWithWantedNote = -1;
    for (int index = 0; index < currentIndex; index++)
    {
        if (!strcmp(notesArray[index].name, toSearchName))
        {
            indexWithWantedNote = index;
            return indexWithWantedNote;
        }
    }
    return indexWithWantedNote;
}

// function for searching name using phone number
int findNameUsingPhoneNumber(PhoneBookEntry* notesArray, char* toSearchPhoneNumber, int currentIndex)
{
    int indexWithWantedNote = -1 ;
    for (int index = 0; index < currentIndex; index++)
    {
        if (!strcmp(notesArray[index].phone, toSearchPhoneNumber))
        {
            indexWithWantedNote = index;
            return indexWithWantedNote;
        }
    }
    return indexWithWantedNote;
}

// assistant function for two searching functions; works this way: when variable nameOrPhone is true it prints name, when false -- phone
void printNameOrPhoneNumber(PhoneBookEntry* notesArray, int indexWithWantedNote, bool nameOrPhone)
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

// function for saving data to file
void saveData(PhoneBookEntry* notesArray, int currentIndex, bool testOrNot)
{
    FILE* notes;
    if (testOrNot)
    {
        notes = fopen("test.txt", "w");
    }
    else
    {
        notes = fopen("data.txt", "w");
    }
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
    return;
}

bool compareTwoArraysOfStruct(PhoneBookEntry* firstArray, PhoneBookEntry* secondArray, int currentIndex)
{
    for (int index = 0; index < currentIndex; index++)
    {
        if (strcmp(firstArray[index].name, secondArray[index].name) != 0)
        {
            return false;
        }
    }
    for (int index = 0; index < currentIndex; index++)
    {
        if (strcmp(firstArray[index].phone, secondArray[index].phone) != 0)
        {
            return false;
        }
    }
    return true;
}

bool testReadDataFromFile(PhoneBookEntry* testArray)
{
    readDataFromFile(testArray, 0, true);
    char* arrayWithTestValues[4] = { "isaac newton\n", "051-6320-123\n", "rene descartes\n", "03240-1234-534\n" };
    for (int index = 0; index < 3; index += 2)
    {
        if (strcmp(testArray[index/2].name, arrayWithTestValues[index]) != 0)
        {
            return false;
        }
    }
    for (int index = 1; index < 4; index += 2)
    {
        if (strcmp(testArray[index/2].phone, arrayWithTestValues[index]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool testAddNote(PhoneBookEntry* testArray)
{
    const char* name = "Adam Smith\n";
    const char* phone = "7(911)-123-45-67\n";
    addNote(testArray, name, phone, 2);
    return (!strcmp(testArray[2].name, "Adam Smith\n") && !strcmp(testArray[2].phone, "7(911)-123-45-67\n"));
}

bool testSearchFunctions(PhoneBookEntry* testArray)
{
    const char* name = "Adam Smith\n";
    return (findPhoneNumberUsingName(testArray, "Adam Smith\n", 3) == 2 && findNameUsingPhoneNumber(testArray, "03240-1234-534\n", 3) == 1);
}

bool testSaveDataToFile(PhoneBookEntry* testArray)
{
    saveData(testArray, 3, true);
    readDataFromFile(testArray, 3, true);
    char* assistantArray[6] = { "isaac newton\n", "051-6320-123\n", "rene descartes\n", "03240-1234-534\n", "Adam Smith\n", "7(911)-123-45-67\n" };
    for (int index = 0; index < 5; index += 2)
    {
        if (strcmp(testArray[index / 2].name, assistantArray[index]) != 0)
        {
            return false;
        }
    }
    for (int index = 1; index < 6; index += 2)
    {
        if (strcmp(testArray[index / 2].phone, assistantArray[index]) != 0)
        {
            return false;
        }
    }
    return true;
}

bool connectionOfTestingFuctions()
{
    FILE* file = fopen("test.txt", "w");
    if (file == NULL)
    {
        printf("File not found");
        return;
    }

    fprintf(file, "%s", "isaac newton\n");
    fprintf(file, "%s", "051-6320-123\n");
    fprintf(file, "%s", "rene descartes\n");
    fprintf(file, "%s", "03240-1234-534\n");
    fclose(file);

    PhoneBookEntry testArray[6];
    return testReadDataFromFile(testArray) && testAddNote(testArray) && testSearchFunctions(testArray) && testSaveDataToFile(testArray);
}

int main()
{
    if (!connectionOfTestingFuctions())
    {
        printf("Test failed");
        return -1;
    }
    printf("0 - exit\n1 - add note\n2 - print all notes\n3 - find telephone number using name\n4 - find name using telephone number\n5 - save data to file\n");
    int userInput = 1;
    PhoneBookEntry* notesArray[100];
    int currentIndex = 0;
    currentIndex = readDataFromFile(notesArray, currentIndex, false);
    while (userInput != 0)
    {
        printf("\nType any number: ");
        scanf("%d", &userInput);
        getchar(); // used for reading extra newline after scanf
        if (userInput == 1) //add note
        {
            char* name[30];
            printf("\nName: ");
            fgets(name, 30, stdin);
            char* phone[30];
            printf("Phone number: ");
            fgets(phone, 30, stdin);
            addNote(notesArray, name, phone, currentIndex);
            currentIndex += 1;
        }
        if (userInput == 2) //print all notes
        {
            printf("\n-----\n");
            printAllNotes(notesArray, currentIndex);
        }
        if (userInput == 3) //find telephone number using name
        {
            char* toSearchName[30];
            printf("\nName: ");
            fgets(toSearchName, 30, stdin);
            const int indexWithWantedNote = findPhoneNumberUsingName(notesArray, toSearchName, currentIndex);
            if (indexWithWantedNote == -1)
            {
                printf("There is no person with this name\n");
            }
            else
            {
                printNameOrPhoneNumber(notesArray, indexWithWantedNote, false);
            }
        }
        if (userInput == 4) //find name using telephone number
        {
            char* toSearchPhoneNumber[30];
            printf("\nPhone number: ");
            fgets(toSearchPhoneNumber, 30, stdin);
            const int indexWithWantedNote = findNameUsingPhoneNumber(notesArray, toSearchPhoneNumber, currentIndex);
            if (indexWithWantedNote == -1)
            {
                printf("There is no person with this phone number\n");
            }
            else
            {
                printNameOrPhoneNumber(notesArray, indexWithWantedNote, true);
            }
        }
        if (userInput == 5) //save data to file
        {
            saveData(notesArray, currentIndex, false);
        }
    }
}

/*
0 - exit
1 - add note
2 - print all notes
3 - find telephone number using name 
4 - find name using telephone number 
5 - save data to file
*/