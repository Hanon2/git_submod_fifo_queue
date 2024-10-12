#include "queue.h"

bool isQueueFull(fifo_queue_t* queue)
{
    return queue->isFull;
}

bool isQueueEmpty(fifo_queue_t* queue)
{
    return (!queue->isFull && (queue->head == queue->tail));
}

bool enqueue(fifo_queue_t* queue, uint8_t data)
{
    if (isQueueFull(queue))    
        return false;
    
    queue->buffer[queue->tail] = data;
    
    // Increment tail and wrap around with modulo
    queue->tail = (queue->tail + 1) % queue->capacity;

    if (queue->tail == queue->head)
        queue->isFull = true;
    
    return true;
}

bool dequeue(fifo_queue_t* queue, uint8_t* data)
{
    if (isQueueEmpty(queue))
        return false;

    *data = queue->buffer[queue->head];
    
    // Increment head and wrap around with modulo
    queue->head = (queue->head + 1) % queue->capacity;

    // After dequeuing, the queue cannot be full anymore
    queue->isFull = false;
    
    return true;
}
