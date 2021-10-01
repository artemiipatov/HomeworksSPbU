/*Массив*/

#include <stdio.h>

void swap(int m, int n, int x[100])
{
    const int mediumValue = (m + n) / 2;
    for (int index = m; index <= mediumValue; index++)
    {
        int temp = x[index];
        x[index] = x[n - index + m];
        x[n - index + m] = temp;
    }
}

int main()
{
    int m = 0;
    int n = 0;
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);

    int x[100] = { 0 };
    printf("Elements:\n");
    for (int i = 0; i <= m + n; i++)
    {
        scanf("%d", &x[i]);
    }

    swap(0, m, x);
    swap(m + 1, m + n, x);
    swap(0, m + n, x);

    printf("Swapped array: ");
    for (int j = 0; j <= m + n; j++)
    {
        printf("%d, ", x[j]);
    }
}