#pragma once
#include <stdbool.h>

// queue structure
typedef struct Queue Queue;

// creates queue
Queue* createQueue(void);

// deletes queue
void deleteQueue(Queue** queue);

// adds element with given key and priority at the tail of the queue
bool enqueue(Queue* queue, int value);

// delete element with maximum priority and returns its value
int dequeue(Queue* queue);

// processes query
int processQuery(Queue* queue, const int query);