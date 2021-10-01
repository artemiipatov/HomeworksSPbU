#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

long double logTimeAlgorithm(int number, const int exponent)
{
    if (exponent == 0 || number == 1)
    {
        return 1;
    }
    int result = 1;
    int absExponent = abs(exponent);
    if (exponent % 2 == 0)
    {
        const int halfExponent = logTimeAlgorithm(number, absExponent / 2);
        result = halfExponent * halfExponent;
    }
    else
    {
        result = logTimeAlgorithm(number, absExponent - 1) * number;
    }
    if (exponent > 0)
    {
        return result;
    }
    else
    {
        if (number == 0)
        {
            return 0;
        }
        return (double)1 / result;
    }
}

long double linearTimeAlgorithm(const int number, int exponent)
{
    int AbsExponent = abs(exponent);
    int result = 1;
    if (exponent == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        while (AbsExponent > 0)
        {
            result *= number;
            --AbsExponent;
        }
    }
    if (exponent > 0)
    {
        return result;
    }
    else
    {
        if (number == 0)
        {
            return 0;
        }
        return (double)1 / result;
    }
}

bool testPositiveNumbers()
{
    return (logTimeAlgorithm(2, 10) == 1024) && (linearTimeAlgorithm(2, 10) == 1024);
}

bool testNegativeNumbers()
{
    return ((logTimeAlgorithm(-2, 9) == -512) && (logTimeAlgorithm(2, -3) == 0.125))
        && ((linearTimeAlgorithm(-2, 9) == -512) && (linearTimeAlgorithm(2, -3) == 0.125));
}

bool testDivisionByZero()
{
    return (logTimeAlgorithm(0, -2) == 0 && linearTimeAlgorithm(0, -2) == 0);
}

void main()
{
    if (!(testPositiveNumbers() && testNegativeNumbers() && testDivisionByZero()))
    {
        printf("Test failed");
        return -1;
    }
    int number = 0;
    printf("Number: ");
    scanf("%d", &number);
    int exponent = 1;
    printf("Exponent: ");
    scanf("%d", &exponent);
    if (number == 0 && exponent < 0)
    {
        printf("Divided by zero");
        return -1;
    }

    time_t start = clock();
    printf("Linear time complexity algorithm: %f", linearTimeAlgorithm(number, exponent));
    time_t end = clock();
    printf(", running time: %f", difftime(end, start));

    start = clock();
    printf("\nLog n time complexity algorithm: %f", logTimeAlgorithm(number, exponent));
    end = clock();
    printf(", running time: %f", difftime(end, start));
}