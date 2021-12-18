#include <stdio.h>
#include <stdbool.h>
#include "AVLtree.h"
#include "AVLtreeTests.h"

int main()
{
    if (!AvlTreePassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    Dict* dict = createDictionary();
    if (dict == NULL)
    {
        printf("Allocation failure");
        return -1;
    }
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
                char key[50] = { '\0' };
                char value[50] = { '\0' };
                printf("Enter key: ");
                gets_s(key, 50);
                printf("Enter value (it should be less than 50 symbols): ");
                gets_s(value, 50);
                if (!insert(dict, key, value))
                {
                    printf("An error occured while inserting.");
                    return -1;
                }
                break;
            }
            case 2:
            {
                char key[50] = { '\0' };
                printf("Enter key: ");
                gets_s(key, 50);
                const char* value = getValue(dict, key);
                printf("Value: %s\n", value == "" ? NULL : value);
                break;
            }
            case 3:
            {
                char key[50] = { '\0' };
                printf("Enter key: ");
                gets_s(key, 50);
                inDictionary(dict, key) ? printf("This key is in the dictionary.\n") : printf("This key is NOT in the dictionary.\n");
                break;
            }
            case 4:
            {
                char key[50] = { '\0' };
                printf("Enter key: ");
                gets_s(key, 50);
                deleteNode(&dict, key);
                break;
            }
            default:
            {
                printf("You've chosen wrong number. Choose 0 to 4.\n");
            }
        }
    }
    return 0;
}