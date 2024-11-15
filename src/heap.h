#ifndef HEAP_H
#define HEAP_H

#include "vector.h"

struct Heap;

struct Heap* new_heap();

// Do not consume the array
struct Heap* heapify_from_array(int* array, int size);

// Do not consume the vector
struct Heap* heapify_from_vector(struct Vector *vector);

/*
 * Find the maximum item of the max heap
 * Return -1 if the heap is empty, 0 otherwise
 */
int heap_find_max(struct Heap *heap, int* max);

/*
 * Remove the root node of the max heap
 * Return 0 on success, -1 on failure
 */
int heap_delete_max(struct Heap *heap);

// Add a new key to the heap
void heap_insert(struct Heap *heap, int value);

// Return the number of items in the heap
int heap_size(struct Heap *heap);

#endif
