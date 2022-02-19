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
    int priority;
    struct QueueElement* next;
} QueueElement;

typedef struct Queue
{
    QueueElement* tail;
    QueueElement* head;
} Queue;

Queue* createQueue()
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

bool enqueue(Queue* queue, int value, int priority)
{
    QueueElement* newElement = calloc(1, sizeof(QueueElement));
    if (newElement == NULL)
    {
        return false;
    }
    newElement->value = value;
    newElement->priority = priority;
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
    if (queue->head == NULL)
    {
        return -1;
    }
    QueueElement* currentElement = queue->head->next;
    QueueElement* elementBeforeMaximum = queue->head;
    QueueElement* assistantElement = queue->head;
    int maximumPriority = INT_MIN;
    while (currentElement != NULL)
    {
        if (currentElement->priority > maximumPriority)
        {
            maximumPriority = currentElement->priority;
            elementBeforeMaximum = assistantElement;
        }
        assistantElement = assistantElement->next;
        currentElement = currentElement->next;
    }
    int result = 0;
    if (maximumPriority <= queue->head->priority)
    {
        result = queue->head->value;
        QueueElement* temp = queue->head->next;
        free(queue->head);
        queue->head = temp;
        queue->tail = queue->head == NULL ? NULL : queue->tail;
    }
    else if (queue->head->next == NULL)
    {
        result = queue->head->value;
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        result = elementBeforeMaximum->next->value;
        QueueElement* temp = elementBeforeMaximum->next->next;
        free(elementBeforeMaximum->next);
        elementBeforeMaximum->next = temp;
    }
    return result;
}