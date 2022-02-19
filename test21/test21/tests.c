#include <stdbool.h>
#include <stdlib.h>
#include "tests.h"
#include "list.h"

bool programPassedTests()
{
	List* list = readFile("testData.txt");
	Position* position = createPosition();
	if (position == NULL)
	{
		return false;
	}
	first(list, position);
	int length = getLength(list);
	int correctArray1[14] = { 10, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < getLength(list); i++)
	{
		if (getPositionValue(position) != correctArray1[i])
		{
			return false;
		}
		next(position);
	}
	reverse(list);
	first(list, position);
	int correctArray2[14] = {10, 9, 8, 7, 6, 5, 4, 4, 4, 3, 2, 2, 1, 10};
	for (int i = 0; i < getLength(list); i++)
	{
		if (getPositionValue(position) != correctArray2[i])
		{
			return false;
		}
		next(position);
	}
	deleteList(&list);
	return true;
}