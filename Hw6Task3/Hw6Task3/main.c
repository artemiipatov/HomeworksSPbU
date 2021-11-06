#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include "tests.h"
#define NAME_SIZE 20

int main()
{
    if (!programPassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    FILE* file = fopen("data.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    List* list = createList();
    if (list == NULL)
    {
        printf("Allocation failure");
        fclose(file);
        return -1;
    }
    while (!feof(file))
    {
        char name[NAME_SIZE] = { '\0' };
        int number = 0;
        fscanf(file, "%[^ -]%*c%*c", &name);
        fscanf(file, "%d%*c", &number);
        if (!addAtTail(list, name, number))
        {
            deleteList(&list);
            fclose(file);
            return -1;
        }
    }
    fclose(file);

    int flag = -1;
    printf("names or numbers: ");
    scanf("%d", &flag);
    if (flag == 0)
    {
        if (mergeSort(list, names) == NULL)
        {
            printf("An error occurred while sorting");
            deleteList(&list);
            return -1;
        }
    }
    else
    {
        if (mergeSort(list, numbers) == NULL)
        {
            printf("An error occurred while sorting");
            deleteList(&list);
            return -1;
        }
    }
    
    int length = getLength(list);
    for (int index = 0; index < length; index++)
    {
        char name[NAME_SIZE] = { '\0' };
        int number = 0;
        popHead(list, &name , &number);
        printf("%s -- %d\n", name, number);
        //free(name);
    }
    deleteList(&list);
    return 0;
}