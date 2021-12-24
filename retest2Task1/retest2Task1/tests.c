#include "queue.h"
#include "tests.h"
#include <stdlib.h>

bool queuePassedTests(void)
{
    Queue* queue = createQueue();
    if (queue == NULL)
    {
        return false;
    }
    if (processQuery(queue, -1) != -1
        || processQuery(queue, 1) != 1
        || processQuery(queue, 2) != 1
        || processQuery(queue, 3) != 1
        || processQuery(queue, 4) != 1)
    {
        return false;
    }
    if (processQuery(queue, -1) != 1
        || processQuery(queue, -1) != 2
        || processQuery(queue, -1) != 3
        || processQuery(queue, -1) != 4
        || processQuery(queue, -1) != -1)
    {
        return false;
    }
    deleteQueue(&queue);
    return queue == NULL;
}