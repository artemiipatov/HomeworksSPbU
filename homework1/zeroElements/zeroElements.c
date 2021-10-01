#include <stdio.h>

int main()
{
    int inputArray[20] = { 0 };
    short int length = 0;

    printf("Number of elements: ");
    scanf("%hi", &length);

    short int counter = 0;
    for (short int i = 0; i < length; ++i)
    {
        printf("Enter the element: ");
        scanf("%d", &inputArray[i]);

        if (inputArray[i] == 0)
        {
            ++counter;
        }
    }
    printf("answer: %d\n", counter);

    return 0;
}