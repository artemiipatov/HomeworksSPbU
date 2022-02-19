#include <stdio.h>
#include "queue.h"
#include "tests.h"

int main()
{
    if (!queuePassedTests())
    {
        printf("Tests failed");
        return -1;
    }
    return 0;
}