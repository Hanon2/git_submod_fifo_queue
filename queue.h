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
 * This header defines the interface for a fixed-capacity FIFO queue
 * with enqueue and dequeue operations.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdint.h>

// Define a fixed maximum capacity for the queue
#define QUEUE_CAPACITY 5

typedef struct 
{
    uint8_t buffer[QUEUE_CAPACITY];  // store the elements
    uint8_t elementToBePopped;        // stores the element to be popped from the queue
    uint8_t tail;                     // Points to the next empty slot to write
    bool isFull;                      // checks if the queue is full
} fifo_queue_t;

/**
 * Initializes the queue, setting it to empty.
 */
void initQueue(fifo_queue_t* queue);

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
