/*Простые числа*/

#include <stdio.h>
#include <stdbool.h>

int sieve(int n)
{
    bool boolArray[10001] = { false };
    for (int i = 2; i <= n; i++)
    {
        boolArray[i] = true;
    }

    for (int i = 2; i < (n / 2); i++)
    {
        for (int j = 2; j < (n / i) + 1; j++)
        {
            int index = i * j;
            boolArray[index] = false;
        }
    }
    printf("Prime numbers:\n");
    for (int index = 2; index < n; index++)
    {
        if (boolArray[index] == true)
        {
            printf("%d\n", index);
        }
    }
}

int main()
{
    int n = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    sieve(n);
}