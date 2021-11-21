#include <stdio.h>

int main()
{
    FILE* notes = fopen("data.txt", "r");
    if (notes == NULL)
    {
        printf("File not found");
        return;
    }

    char* data[100] = { 0 };
    int linesRead = 0;
    while (!feof(notes))
    {
        char* buffer = malloc(sizeof(char) * 100);
        //const int readBytes = fscanf(notes, "%20c%n", buffer);
        const int readBytes = fgets(buffer, 15, notes);
        if (readBytes < 0)
        {
            break;
        }
        data[linesRead] = buffer;
        ++linesRead;
    }
    for (int index = 0; index < linesRead; index++)
    {
        printf("%s", data[index]);
    }
}