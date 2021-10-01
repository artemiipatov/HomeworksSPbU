/*Баланс скобок*/

#include <stdio.h>
#include <string.h>

int main()
{
    int counter = 0;
    char string[20] = { 0 };
    printf("Expression: ");
    fgets(string, sizeof(string), stdin);
    const int length = strlen(string);

    for (int symbol = 0; symbol < length; ++symbol)
    {
        if (string[symbol] == '(')
        {
            ++counter;
        }
        else if (string[symbol] == ')')
        {
            --counter;
        }
        else
        {
            continue;
        }
        if (counter < 0)
        {
            printf("False");
            return 1;
        }
    }
    printf(counter == 0 ? "True" : "False");
}