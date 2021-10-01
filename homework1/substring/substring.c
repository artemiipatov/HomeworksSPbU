/*Подстрока*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s[100] = { 0 };
    char s1[10] = { 0 };
    printf("String: ");
    gets(s);
    printf("Substring: ");
    gets(s1);

    const int stringLength = strlen(s);
    const int substringLength = strlen(s1);
    int answer = 0;
    for (int index = 0; index < (stringLength - substringLength + 1); index++)
    {
        if (s[index] == s1[0])
        {
            bool flag = true;
            for (int iter = index; iter < index + substringLength; iter++)
            {
                if (s1[iter - index] != s[iter])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ++answer;
            }
        }
    }
    printf("Substring was found %d times.", answer);
}