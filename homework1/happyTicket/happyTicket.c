#include <stdio.h>

int main()
{
	int counter = 0;
	int intArray[28] = { 0 };

	for (int first = 0; first <= 9; ++first)
	{
		for (int second = 0; second <= 9; ++second)
		{
			for (int third = 0; third <= 9; ++third)
			{
				int index = first + second + third;
				++intArray[index];
			}
		}
	}

	int total = 0;
	for (int i = 0; i <= 27; i++)
	{
		total += intArray[i] * intArray[i];
	}

	printf("%d", total);

	return 0;
}