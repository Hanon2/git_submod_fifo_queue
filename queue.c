#include "queue.h"


void initQueue(fifo_queue_t* queue)
{
    queue->elementToBePopped = 0;
    queue->isFull = false;
    queue->tail = QUEUE_CAPACITY;
}

bool isQueueFull(fifo_queue_t* queue)
{
    return queue->isFull;
}

bool isQueueEmpty(fifo_queue_t* queue)
{
    return (queue->tail == QUEUE_CAPACITY);
}

bool enqueue(fifo_queue_t* queue, uint8_t data)
{
    if (isQueueFull(queue))    
        return false;
        
    queue->buffer[queue->tail] = data;
    queue->tail -= 1;
    if(queue->tail == 0)
        queue->isFull = true;
        
    return true;
}


bool dequeue(fifo_queue_t* queue, uint8_t* data)
{
    if (isQueueEmpty(queue))
        return false;
    queue->elementToBePopped = queue->buffer[QUEUE_CAPACITY - queue->tail];
    *data = queue->elementToBePopped;
    queue->tail++;
    return true;
}
