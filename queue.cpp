#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue* q, unsigned int size)
{
    q->arr = (int*)calloc(size, sizeof(int));
    q->posible_size = size;
    q->size = 0;
    q->first_i = 0;
}

void cleanQueue(Queue* q)
{
    free(q->arr);
    q->arr = NULL;
    q->posible_size = 0;
    q->size = 0;
    q->first_i = 0;
}

void enqueue(Queue* q, unsigned int newValue)
{
    if (!isFull(q))
    {
        q->arr[(q->first_i + q->size) % q->posible_size] = newValue;
        q->size++;
    }
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    int value = q->arr[q->first_i];
    q->first_i = (q->first_i + 1) % q->posible_size;
    q->size--;
    return value;
}

bool isEmpty(Queue* s)
{
    if (s->size == 0)
    {
        return true;
    }
    return false;
}

bool isFull(Queue* s)
{
    if (s->size == s->posible_size)
    {
        return true;
    }
    return false;
}