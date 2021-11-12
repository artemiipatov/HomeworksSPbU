#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "countingOut.h"
#include "countingOutTests.h"
#include "../../cyclicList/cyclicList/cyclicListTests.h"

int main()
{
    if (!(cyclicListPassedTests() && rhymePassedTests()))
    {
        printf("Tests failed");
        return -1;
    }
    int numberOfWarriors = 0;
    printf("Number of warriors: ");
    scanf("%d", &numberOfWarriors);
    int period = 0;
    printf("Period: ");
    scanf("%d", &period);
    printf("%d", countPosition(numberOfWarriors, period));
}