#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashTable.h"
#include "list.h"

bool programPassedTests()
{
    FILE* file = fopen("testFile.txt", "w");
    if (file == NULL)
    {
        return false;
    }
    fprintf(file, "oer qjiwe ksd wek wek oer oer ksd zxc asd qwe qwe qwe ewq");
    fclose(file);
    List* list = deleteDuplicates("testData.txt");
    if (list == NULL)
    {
        return false;
    }
    Position* position = createPosition();
    if (position == NULL)
    {
        deleteList(&list);
        return false;
    }
    first(list, &position);
    char* correctValues[] = {"qwe", "oer", "qjiwe", "wek", "zxc", "ksd", "asd", "ewq"};
    int index = 0;
    while (!isNull(position))
    {
        if (strcmp(correctValues[index], getValue(position)) != 0)
        {
            return false;
        }
        next(&position);
        ++index;
    }
    return true;
}