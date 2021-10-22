#include "mostFrequentElementSearch.h"
#include <stdlib.h>

int findMostFrequent(int sequence[], int length)
{
    int counter = 1;
    int maxNumber = INT_MIN;
    int mostFrequentElement = sequence[0];
    for (int index = 1; index < length; index++)
    {
        if (sequence[index] == sequence[index - 1])
        {
            counter++;
        }
        if (counter > maxNumber)
        {
            maxNumber = counter;
            mostFrequentElement = sequence[index - 1];
        }
        if (sequence[index] != sequence[index - 1])
        {
            counter = 1;
        }
    }
    return mostFrequentElement;
}