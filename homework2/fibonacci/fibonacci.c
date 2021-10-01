#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int recursiveFibonacciAlgorithm(int number)
{
    if (number <= 0)
    {
        return 0;
    }
    if (number == 1 || number == 2)
    {
        return 1;
    }
    return recursiveFibonacciAlgorithm(number - 1) + recursiveFibonacciAlgorithm(number - 2);
}

int iterativeFibonacciAlgorithm(int number)
{
    if (number <= 0)
    {
        return 0;
    }
    if (number == 1 || number == 2)
    {
        return 1;
    }

    int start = 1;
    int stack[2] = { 0, 1 };
    while (start < number)
    {
        int newNumber = stack[0] + stack[1];
        stack[0] = stack[1];
        stack[1] = newNumber;
        ++start;
    }
    return stack[1];
}

bool testCorrectInput()
{
    const int fibonacciCorrectSequence[9] = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };
    for (int number = 0; number <= 8; number++)
    {
        if ((fibonacciCorrectSequence[number] != iterativeFibonacciAlgorithm(number))
            || (fibonacciCorrectSequence[number] != recursiveFibonacciAlgorithm(number)))
        {
            return false;
        }
    }
    return true;
}

bool testIncorrectInput()
{
    return !(recursiveFibonacciAlgorithm(-10) || iterativeFibonacciAlgorithm(-10));
}

int runProgram();

void main()
{
    if (testCorrectInput() && testIncorrectInput())
    {
        runProgram();
    }
    else
    {
        printf("Test failed");
    }
}

int runProgram()
{
    int number = 2;
    while (true)
    {
        clock_t start = clock();
        recursiveFibonacciAlgorithm(number);
        clock_t end = clock();
        const double recursiveTime = difftime(end, start);

        start = clock();
        iterativeFibonacciAlgorithm(number);
        end = clock();
        const double iterativeTime = difftime(end, start);

        if (recursiveTime - iterativeTime > 50)
        {
            printf("Recursive algorithm becomes much slower than iterative on %d step", number);
            return 0;
        }
        ++number;
    }
}