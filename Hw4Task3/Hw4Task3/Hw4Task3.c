#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char name[30];
    char phone[30];
} PhoneBookEntry;

// function for reading data from file at the beginning of the program
int readDataFromFile(PhoneBookEntry* notesArray, int currentIndex)
{
    FILE* notes = fopen("data.txt", "r");
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
void addNote(PhoneBookEntry* notesArray, int currentIndex)
{
    char* name[30];
    printf("\nName: ");
    fgets(name, 30, stdin);
    strcpy(notesArray[currentIndex].name, name);

    char* phone[30];
    printf("Phone number: ");
    fgets(phone, 30, stdin);
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
void findPhoneNumberUsingName(PhoneBookEntry* notesArray, int currentIndex)
{
    char* toSearchName[30];
    printf("\nName: ");
    fgets(toSearchName, 30, stdin);
    for (int index = 0; index < currentIndex; index++)
    {
        if (!strcmp(notesArray[index].name, toSearchName))
        {
            printf("Phone number: %s", notesArray[index].phone);
            return;
        }
    }
    printf("There is no person with this name\n");
    return;
}

// function for searching name using phone number
void findNameUsingPhoneNumber(PhoneBookEntry* notesArray, int currentIndex)
{
    char* toSearchPhoneNumber[30];
    printf("\nPhone number: ");
    fgets(toSearchPhoneNumber, 30, stdin);
    for (int index = 0; index < currentIndex; index++)
    {
        if (!strcmp(notesArray[index].phone, toSearchPhoneNumber))
        {
            printf("Name: %s", notesArray[index].name);
            return;
        }
    }
    printf("There is no person with this phone number\n");
    return;
}

// function for saving data to file
void saveData(PhoneBookEntry* notesArray, int currentIndex)
{
    FILE* notes= fopen("data.txt", "w");
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

void main()
{
    printf("0 - exit\n1 - add note\n2 - print all notes\n3 - find telephone number using name\n4 - find name using telephone number\n5 - save data to file\n");
    int userInput = 1;
    PhoneBookEntry* notesArray[100];
    int currentIndex = 0;
    currentIndex = readDataFromFile(notesArray, currentIndex);
    while (userInput != 0)
    {
        printf("\nType any number: ");
        scanf("%d", &userInput);
        getchar(); // used for reading extra newline after scanf
        if (userInput == 1)
        {
            addNote(notesArray, currentIndex);
            currentIndex += 1;
        }
        if (userInput == 2)
        {
            printf("\n-----\n");
            printAllNotes(notesArray, currentIndex);
        }
        if (userInput == 3)
        {
            findPhoneNumberUsingName(notesArray, currentIndex);
        }
        if (userInput == 4)
        {
            findNameUsingPhoneNumber(notesArray, currentIndex);
        }
        if (userInput == 5)
        {
            saveData(notesArray, currentIndex);
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