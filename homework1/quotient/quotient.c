#include <stdio.h>

int main()
{
    int dividend = 0;
    int divisor = 1;

    printf("Dividend: ");
    scanf("%d", &dividend);
    printf("Divisor: ");
    scanf("%d", &divisor);

    int counter = 0;
    int quotient = 0;
    if (divisor == 0)
    {
        printf("Error: division by zero\n");
        exit(1);
    }
    if (dividend > 0)
    {
        if (divisor > 0)
        {
            while (dividend - divisor >= 0)
            {
                dividend -= divisor;
                ++quotient;
            }
        }
        else
        {
            divisor = -divisor;
            while (dividend - divisor >= 0)
            {
                dividend -= divisor;
                --quotient;
            }
            dividend = -dividend;
        }
    }
    else if (dividend < 0)
    {
        if (divisor > 0)
        {
            while (dividend < 0)
            {
                dividend += divisor;
                --quotient;
            }
        }
        else
        {
            while (dividend < 0)
            {
                dividend -= divisor;
                ++quotient;
            }
        }
    }
    else
    {
        printf("quotient: 0");
        exit(1);
    }

    printf("Quotient: %d", quotient);

    return 0;
}