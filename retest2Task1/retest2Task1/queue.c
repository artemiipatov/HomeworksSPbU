#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "queue.h"

typedef struct QueueElement
{
    int value;
    struct QueueElement* next;
} QueueElement;

typedef struct Queue
{
    QueueElement* tail;
    QueueElement* head;
} Queue;

Queue* createQueue(void)
{
    return calloc(1, sizeof(Queue));
}

bool isEmpty(Queue* queue)
{
    return queue == NULL || queue->head == NULL;
}

void deleteQueue(Queue** queue)
{
    QueueElement* position = (*queue)->head;
    while (position != NULL)
    {
        (*queue)->head = (*queue)->head->next;
        free(position);
        position = (*queue)->head;
    }
    free(*queue);
    *queue = NULL;
}

bool enqueue(Queue* queue, const int value)
{
    QueueElement* newElement = calloc(1, sizeof(QueueElement));
    if (newElement == NULL)
    {
        return false;
    }
    newElement->value = value;
    if (queue->head == NULL)
    {
        queue->head = newElement;
        queue->tail = queue->head;
        return true;
    }
    queue->tail->next = newElement;
    queue->tail = newElement;
    return true;
}

int dequeue(Queue* queue)
{
    if (queue == NULL || queue->head == NULL)
    {
        return -1;
    }
    const int result = queue->head->value;
    QueueElement* temp = queue->head->next;
    free(queue->head);
    queue->head = temp;
    return result;
}

int processQuery(Queue* queue, const int query)
{
    if (query == -1)
    {
        return dequeue(queue);
    }
    return enqueue(queue, query);
}