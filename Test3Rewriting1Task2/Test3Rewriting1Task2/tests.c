#include <stdlib.h>
#include "tests.h"
#include "queue.h"

bool queuePassedTests()
{
    // testing queue with equal priorities
    Queue* queue = createQueue();
    enqueue(queue, 1, 1);
    enqueue(queue, 2, 1);
    enqueue(queue, 3, 1);
    enqueue(queue, 4, 2);
    enqueue(queue, 5, 1);
    if (dequeue(queue) != 4)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 1)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 2)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 3)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 5)
    {
        deleteQueue(&queue);
        return false;
    }

    // testing queue with common priorities
    enqueue(queue, 1, 6);
    enqueue(queue, 2, 54);
    enqueue(queue, 3, -45);
    enqueue(queue, 4, 20);
    enqueue(queue, 5, 200);
    enqueue(queue, 6, 8);
    if (dequeue(queue) != 5)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 2)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 4)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 6)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 1)
    {
        deleteQueue(&queue);
        return false;
    }
    if (dequeue(queue) != 3)
    {
        deleteQueue(&queue);
        return false;
    }
    deleteQueue(&queue);
    return queue == NULL;
}