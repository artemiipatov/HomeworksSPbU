#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "dictionaryFunctions.h"
#include "dictTests.h"

int main()
{
    if (!programPassedTests())
    {
        printf("Tests failed.");
        return -1;
    }
    Node* dict = createDictionary();
    printf("This is a dictionary implementation.\n");
    printf("Dictionary functions: \n");
    printf("0 - Quit\n");
    printf("1 - Add value with input key to the dictionary\n");
    printf("2 - Get value from the dictionary by input key\n");
    printf("3 - Check if key is in the dictionary\n");
    printf("4 - Remove key and value with such key\n");

    int userInput = 9;
    while (userInput != 0)
    {
        printf("\nChoose number: ");
        scanf_s("%d%*c", &userInput);
        switch (userInput)
        {
            case 0:
            {
                printf("Exiting...");
                deleteDictionary(&dict);
                return 0;
            }
            case 1:
            {
                int key = 0;
                char value[50] = { '\0' };
                printf("Enter key: ");
                scanf_s("%d%*c", &key);
                printf("Enter value (it should be less than 50 symbols): ");
                gets(value);
                dict = addNode(dict, key, value);
                break;
            }
            case 2:
            {
                int key = 0;
                printf("Enter key: ");
                scanf_s("%d%*c", &key);
                printf("Value: %s\n", getValue(&dict, key));
                break;
            }
            case 3:
            {
                int key = 0;
                printf("Enter key: ");
                scanf_s("%d%*c", &key);
                inDictionary(&dict, key) ? printf("This key is in the dictionary.\n") : printf("This key is not in the dictionary.\n");
                break;
            }
            case 4:
            {
                int key = 0;
                printf("Enter key: ");
                scanf_s("%d%*c", &key);
                dict = deleteNode(dict, key);
                break;
            }
            default:
            {
                printf("You've chosen the wrong number. Choose 0 to 4.\n");
            }
        }
    }
    deleteDictionary(&dict);
    return 0;
}