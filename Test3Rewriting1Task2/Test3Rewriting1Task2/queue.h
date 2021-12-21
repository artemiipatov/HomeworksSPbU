#pragma once

// queue structure
typedef struct Queue Queue;

// creates queue
Queue* createQueue();

// deletes queue
void deleteQueue(Queue** queue);

// adds element with given key and priority at the tail of the queue
bool enqueue(Queue* queue, int value, int priority);

// delete element with maximum priority and returns its value
int dequeue(Queue* queue);