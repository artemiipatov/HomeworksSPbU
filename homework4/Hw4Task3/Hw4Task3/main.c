#define _CRT_SECURE_NO_WARNINGS
#include "phonebookFunctions.h"
#include "tests.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    if (!uniteTestingFuctions())
    {
        printf("Test failed");
        return -1;
    }
    if (argc > 1)
    {
        printf("Tests passed");
        return 0;
    }
    printf("0 - exit\n");
    printf("1 - add note\n"); 
    printf("2 - print all notes\n");
    printf("3 - find telephone number using name\n");
    printf("4 - find name using telephone number\n");
    printf("5 - save data to file\n");

    int userInput = 1;
    PhoneBookEntry notesArray[100] = { '\0' };
    int currentIndex = readDataFromFile(notesArray, 0, "data.txt");
    if (currentIndex == -1)
    {
        return -1;
    }
    while (userInput != 0)
    {
        printf("\nType any number: ");
        scanf("%d", &userInput);
        getchar(); // used for reading extra newline after scanf
        switch (userInput)
        {
            case 0:
            {
                return 0;
            }
            case 1: //add note
            {
                char name[30] = { '\0' };
                printf("\nName: ");
                fgets(name, 30, stdin);
                char phone[30] = { '\0' };
                printf("Phone number: ");
                fgets(phone, 30, stdin);
                addNote(notesArray, name, phone, currentIndex);
                currentIndex += 1;
                break;
            }
            case 2: //print all notes
            {
                printf("\n-----\n");
                printAllNotes(notesArray, currentIndex);
                break;
            }
            case 3: //find telephone number using name
            {
                char toSearchName[30] = { '\0' };
                printf("\nName: ");
                fgets(toSearchName, 30, stdin);
                const int indexWithWantedNote = findPhoneNumberUsingName(notesArray, toSearchName, currentIndex);
                if (indexWithWantedNote == -1)
                {
                    printf("There is no person with this name\n");
                }
                else
                {
                    printf("Phone number: %s", notesArray[indexWithWantedNote].phone);
                }
                break;
            }
            case 4: //find name using telephone number
            {
                char toSearchPhoneNumber[30] = { '\0' };
                printf("\nPhone number: ");
                fgets(toSearchPhoneNumber, 30, stdin);
                const int indexWithWantedNote = findNameUsingPhoneNumber(notesArray, toSearchPhoneNumber, currentIndex);
                if (indexWithWantedNote == -1)
                {
                    printf("There is no person with this phone number\n");
                }
                else
                {
                    printf("Name: %s", notesArray[indexWithWantedNote].name);
                }
                break;
            }
            case 5: //save data to file
            {
                saveData(notesArray, currentIndex, "data.txt");
                break;
            }
            default:
            {
                printf("You've typed wrong number. Choose 0 to 5.");
                break;
            }
        };
    }
    return 0;
}

/*
0 - exit
1 - add note
2 - print all notes
3 - find telephone number using name
4 - find name using telephone number
5 - save data to file
*/