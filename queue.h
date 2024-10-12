/*
==========================================
              Queue Implementation
==========================================
 * queue.h
 * 
 * A simple implementation of a circular buffer FIFO queue.
 *
 * Author: Mohamed Abdelmoneim
 * Date: 09/26/2024
 *
 * This header defines the interface for a FIFO queue
 * with enqueue and dequeue operations.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct 
{
    uint8_t* buffer;    // Pointer to the buffer 
    size_t head;        // Index of the head
    size_t tail;        // Index of the tail
    bool isFull;        // Flag indicating if the queue is full
    size_t capacity;    // Capacity of the queue
} fifo_queue_t;

/**
 * Checks if the queue is full, if so return true.
 */
bool isQueueFull(fifo_queue_t* queue);

/**
 * Checks if the queue is empty, if so return true.
 */
bool isQueueEmpty(fifo_queue_t* queue);

/**
 * Adds a data element to the queue.
 * Returns true if successful, false if the queue is full.
 */
bool enqueue(fifo_queue_t* queue, uint8_t data);

/**
 * Removes a data element from the queue.
 * Returns true if successful, false if the queue is empty.
 */
bool dequeue(fifo_queue_t* queue, uint8_t* data);

#endif
