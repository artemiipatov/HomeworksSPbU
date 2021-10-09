#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

int binaryToDecimal(int binaryNumber[])
{
    int decimalNumber = 0;
    int powerOfTwo = 1;
    for (int index = 0; index < sizeof(int) * 8; index++)
    {
        decimalNumber += binaryNumber[index] * powerOfTwo;
        powerOfTwo *= 2;
    }
    return decimalNumber;
}

void decimalToBinary(int binaryNumber[], int decimalNumber)
{
    for (int index = 0; index < sizeof(int) * 8; index++)
    {
        binaryNumber[index] = abs(decimalNumber % 2);
        decimalNumber >>= 1;
    }
}

void binaryAddition(int firstBinaryNumber[], int secondBinaryNumber[], int sum[])
{
    int transition = 0;
    for (int index = 0; index < sizeof(int) * 8; index++)
    {
        const int sumOfTwoDigits = firstBinaryNumber[index] + secondBinaryNumber[index] + transition;
        sum[index] = sumOfTwoDigits % 2;
        if (sumOfTwoDigits > 1)
        {
            transition = 1;
        }
        else
        {
            transition = 0;
        }
    }
}

bool compareArrays(int firstArray[], int secondArray[])
{
    const sizeInt = sizeof(int) * 8;
    for (int index = 0; index < sizeInt; index++)
    {
        if (firstArray[index] != secondArray[sizeInt - index - 1])
        {
            return false;
        }
    }
    return true;
}

bool testCorrectExecutionOfAllFunctions()
{
    // positive numbers
    const int firstDecimalNumber1 = 756;
    int firstBinaryNumber1[sizeof(int) * 8] = { 0 };
    int correctFirstBinaryNumber1[sizeof(int) * 8] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 };
    decimalToBinary(firstBinaryNumber1, firstDecimalNumber1);
    if (!compareArrays(firstBinaryNumber1, correctFirstBinaryNumber1))
    {
        return false;
    }

    const int secondDecimalNumber1 = 13985;
    int secondBinaryNumber1[sizeof(int) * 8] = { 0 };
    int correctSecondBinaryNumber1[sizeof(int) * 8] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 };
    decimalToBinary(secondBinaryNumber1, secondDecimalNumber1);
    if (!compareArrays(secondBinaryNumber1, correctSecondBinaryNumber1))
    {
        return false;
    }

    int binarySum1[sizeof(int) * 8] = { 0 };
    int correctBinarySum1[sizeof(int) * 8] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1 };
    binaryAddition(firstBinaryNumber1, secondBinaryNumber1, binarySum1);
    if (!compareArrays(binarySum1, correctBinarySum1))
    {
        return false;
    }
    if (binaryToDecimal(binarySum1) != 14741)
    {
        return false;
    }


    // positive and negative numbers
    const int firstDecimalNumber2 = -1243;
    int firstBinaryNumber2[sizeof(int) * 8] = { 0 };
    decimalToBinary(firstBinaryNumber2, firstDecimalNumber2);
    
    const int secondDecimalNumber2 = 1982;
    int secondBinaryNumber2[sizeof(int) * 8] = { 0 };
    decimalToBinary(secondBinaryNumber2, secondDecimalNumber2);

    int binarySum2[sizeof(int) * 8] = { 0 };
    int correctBinarySum2[sizeof(int) * 8] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1 };
    binaryAddition(firstBinaryNumber2, secondBinaryNumber2, binarySum2);
    if (!compareArrays(binarySum2, correctBinarySum2))
    {
        return false;
    }
    if (binaryToDecimal(binarySum2) != 739)
    {
        return false;
    }


    // negative nubmers
    const int firstDecimalNumber3 = -9432;
    int firstBinaryNumber3[sizeof(int) * 8] = { 0 };
    int correctFirstBinaryNumber3[sizeof(int) * 8] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0 };
    decimalToBinary(firstBinaryNumber3, firstDecimalNumber3);
    if (!compareArrays(firstBinaryNumber3, correctFirstBinaryNumber3))
    {
        return false;
    }

    const int secondDecimalNumber3 = -10000;
    int secondBinaryNumber3[sizeof(int) * 8] = { 0 };
    int correctSecondBinaryNumber3[sizeof(int) * 8] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 };
    decimalToBinary(secondBinaryNumber3, secondDecimalNumber3);
    if (!compareArrays(secondBinaryNumber3, correctSecondBinaryNumber3))
    {
        return false;
    }

    int binarySum3[sizeof(int) * 8] = { 0 };
    int correctBinarySum3[sizeof(int) * 8] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 };
    binaryAddition(firstBinaryNumber3, secondBinaryNumber3, binarySum3);
    if (!compareArrays(binarySum3, correctBinarySum3))
    {
        return false;
    }
    if (binaryToDecimal(binarySum3) != -19432)
    {
        return false;
    }

    return true;
}

int main()
{
    // Russian symbols
    setlocale(0, "Russian");

    if (!testCorrectExecutionOfAllFunctions())
    {
        printf("Программа не прошла тесты.");
        return -1;
    }

    // Two decimal numbers
    printf("Введите числа:\n");
    int firstDecimalNumber = 0;
    scanf("%d", &firstDecimalNumber);
    int secondDecimalNumber = 0;
    scanf("%d", &secondDecimalNumber);

    // Two decimal numbers to binary
    int firstBinaryNumber[sizeof(int) * 8] = { 0 };
    decimalToBinary(firstBinaryNumber, firstDecimalNumber);
    printf("\nПервое число в двоичной системе счисления: ");
    for (int index = sizeof(int) * 8 - 1; index >= 0; index--)
    {
        printf("%d", firstBinaryNumber[index]);
    }
    
    int secondBinaryNumber[sizeof(int) * 8] = { 0 };
    decimalToBinary(secondBinaryNumber, secondDecimalNumber);
    printf("\nВторое число в двоичной системе счисления: ");
    for (int index = sizeof(int) * 8 - 1; index >= 0; index--)
    {
        printf("%d", secondBinaryNumber[index]);
    }

    // Sum of two binary numbers
    int binarySum[sizeof(int) * 8] = { 0 };
    printf("\nСумма двоичных чисел: ");
    binaryAddition(firstBinaryNumber, secondBinaryNumber, binarySum);
    for (int index = sizeof(int) * 8 - 1; index >= 0; index--)
    {
        printf("%d", binarySum[index]);
    }

    // Decimal sum
    printf("\nСумма в десятичной системе счисления: %d", binaryToDecimal(binarySum));
}