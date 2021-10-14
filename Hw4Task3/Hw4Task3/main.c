#include "phonebookFunctions.h"
#include "tests.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    if (!uniteTestingFuctions())
    {
        printf("Test failed");
        return -1;
    }
    printf("0 - exit\n");
    printf("1 - add note\n"); 
    printf("2 - print all notes\n");
    printf("3 - find telephone number using name\n");
    printf("4 - find name using telephone number\n");
    printf("5 - save data to file\n");
    int userInput = 1;
    PhoneBookEntry* notesArray[100] = { "\0" };
    int currentIndex = 0;
    currentIndex = readDataFromFile(notesArray, currentIndex, "data.txt");
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
                char name[30];
                printf("\nName: ");
                fgets(name, 30, stdin);
                char phone[30];
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
                break;
            }
            case 4: //find name using telephone number
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