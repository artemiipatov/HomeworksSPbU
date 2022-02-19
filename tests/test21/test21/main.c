#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "tests.h"
//#include "../../list/list/listTests.h"

/*
0 – exit
1 – add value to sorted list
2 – remove value from the list
3 – print list
*/

int main()
{
    if (!programPassedTests())
    {
        return -1;
    }
    List* list = readFile("data.txt");
    if (list == NULL)
    {
        printf("Unexpected error occured while reading data");
        return -1;
    }
    printf("Input list: ");
    printList(list);
    printf("\nReversed list: ");
    reverse(list);
    printList(list);
    deleteList(&list);
}