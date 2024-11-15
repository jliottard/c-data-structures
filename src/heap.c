#include <stdlib.h>
#include <string.h>
#include "heap.h"

int _binary_heap_left_child(int i) {
    return 2*i + 1;
}

int _binary_heap_right_child(int i) {
    return 2*i + 2;
}

int _binary_heap_parent(int i) {
    return (int)((i - 1) /2);
}

void _swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

/*
 * Rise the end indexed element in the heap
 * Time complexity: O(log n)
 */
void _sift_up(int *array, int end) {
    while (end > 0) {
        int parent = _binary_heap_parent(end);
        if (array[parent] < array[end]) {
            _swap(array, parent, end);
            end = parent;
        } else {
            return;
        }
    }
}

void _sift_down(int *array, int array_size, int start) {
    while (start < array_size - 1) {
        int left_child = _binary_heap_left_child(start);
        int right_child = _binary_heap_right_child(start);
        if (array[start] < array[left_child] || array[start] < array[right_child]) {
            // swap with the max of the children
            if (array[left_child] > array[right_child]) {
                _swap(array, left_child, start);
                start = left_child;
            } else {
                _swap(array, right_child, start);
                start = right_child;
            }
        } else {
            return;
        }
    }
}

/*
 * Sort the array in place to be a max heap
 * Time complexity: O(n)
 */
void _heapify(int* array, int size) {
    int end = 1;
    while (end < size) {
        _sift_up(array, end);
        end++;
    }
}

struct Heap {
    struct Vector *vector;
};

struct Heap* new_heap() {
    struct Heap *heap = malloc(sizeof(struct Heap));
    struct Vector *vector = vector_create(1);
    heap->vector = vector;
    return heap;
}

struct Heap* heapify_from_array(int* array, int size) {
    struct Heap *heap = malloc(sizeof(struct Heap));
    struct Vector *vector = vector_create(size);
    memcpy(array, vector_array(vector), size);
    _heapify(vector_array(vector), vector_size(vector));
    heap->vector = vector;
    return heap;
}

struct Heap* heapify_from_vector(struct Vector *vector) {
    return heapify_from_array(vector_array(vector), vector_size(vector));
}

int heap_find_max(struct Heap *heap, int* max) {
    if (heap_size(heap) == 0) {
        return -1;
    }
    *max = vector_read(heap->vector, 0);
    return 0;
}

int heap_delete_max(struct Heap *heap) {
    if (vector_size(heap->vector) == 0) {
        return -1;
    }
    int value;
    int error = vector_pop(heap->vector, &value);
    if (error) {
        return error;
    }
    _sift_down(vector_array(heap->vector), vector_size(heap->vector), 0);
    return 0;
}

void heap_insert(struct Heap *heap, int value) {
    vector_append(heap->vector, value);
    _sift_up(vector_array(heap->vector), vector_size(heap->vector));
}

int heap_size(struct Heap *heap) {
    return vector_size(heap->vector);
}