#include <stdlib.h>
#include "rhyme.h"
#include "../../cyclicList/cyclicList/cyclicListFunctions.h"

int countPosition(int numberOfWarriors, int period)
{
    // creating list and position
    List* list = createList();
    if (list == NULL)
    {
        return -1;
    }
    Position* position = createPosition();
    if (position == NULL)
    {
        deleteList(&list);
        return -1;
    }

    // filling the list with positions of warriors
    if (!add(list, position, 1))
    {
        deleteList(&list);
        deletePosition(&position);
        return -1;
    }
    first(list, position);
    for (int index = 2; index <= numberOfWarriors; index++)
    {
        if (!add(list, position, index))
        {
            deleteList(&list);
            deletePosition(&position);
            return -1;
        }
        next(position);
    }

    // killing warriors and counting result
    int counter = 1;
    first(list, position);
    while (numberOfWarriors > 1 && period > 0)
    {
        if (counter % period == 0)
        {
            deleteItem(list, position);
        }
        else
        {
            next(position);
        }
        if (getLength(list) == 1)
        {
            break;
        }
        ++counter;
    }
    int result = get(list, position);
    deletePosition(&position);
    deleteList(&list);
    return result;
}