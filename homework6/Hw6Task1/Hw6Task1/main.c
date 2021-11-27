#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "../../list/list/list.h"
#include "../../list/list/listTests.h"
#include "sortedListFunctions.h"
#include "sortedListTests.h"

/*
0 – exit
1 – add value to sorted list
2 – remove value from the list
3 – print list
*/

int main(int argc, char argv[])
{
    if (!listTestsPassed() || !sortedListTestsPassed())
    {
        printf("Tests failed");
        return -1;
    }
    if (argc > 1)
    {
        return 0;
    }
    List* list = NULL;
    if (!createList(&list))
    {
        printf("Allocation failure");
        return -1;
    }
    Position* currentPosition = NULL;
    if (!createPosition(&currentPosition))
    {
        deleteList(&list);
        printf("Allocation failure");
        return -1;
    }
    first(list, currentPosition);
    printf("0 - exit\n");
    printf("1 - add value to the sorted list\n");
    printf("2 - delete value from the list\n");
    printf("3 - print the list");
    
    int userInput = 9;
    while (userInput != 0)
    {
        printf("\nType any number: ");
        scanf("%d*ñ", &userInput);
        switch (userInput)
        {
            case 0:
            {
                deleteList(&list);
                deletePosition(&currentPosition);
                return 0;
            }
            case 1:
            {
                int value = 0;
                printf("value: ");
                scanf("%d", &value);
                addItemToSortedList(list, value);
                break;
            }
            case 2:
            {
                int currentLength = getLength(list);
                int itemIndex = 0;
                printf("index of item to delete (choose 0 to %d): ", currentLength - 1);
                scanf("%d", &itemIndex);
                if (itemIndex >= currentLength)
                {
                    printf("There is no item with such index.\n");
                    break;
                }
                deleteItemByIndex(list, itemIndex);
                break;
            }
            case 3:
            {
                printList(list);
                printf("\n");
                break;
            }
        }
    }
}