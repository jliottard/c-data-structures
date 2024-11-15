#include <stdio.h>

#include "src/vector.h"
#include "src/heap.h"

/*
 * Sort by insection
 * Complexity: O(n^2)
 */
void insertion_sort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int index = i;
        while (array[index - 1] > array[index]) {
            int tmp = array[index];
            array[index] = array[index - 1];
            array[index - 1] = tmp;
            index--;
        }
    }
}

void sort(struct Vector* vector) {
    // introsort is composed of insertion, heapsort and quicksort.
    insertion_sort(vector_array(vector), vector_size(vector));
}

int main(int argc, const char *argv[]) {
    // Vector usage
    unsigned int size = 10;
    struct Vector* vector = vector_create(size);
    // printf("vector new");
    for (int i = 0; i < size; i++) {
        vector_append(vector, size - i);
    }
    for (int i = 0; i < vector_size(vector); i++) {
        printf("vector[%d] = %d\n", i, vector_read(vector, i));
    }
    sort(vector);
    for (int i = 0; i < vector_size(vector); i++) {
        printf("sorted vector[%d] = %d\n", i, vector_read(vector, i));
    }
    int value;
    while (vector_pop(vector, &value) != -1) {
        printf("vector.pop = %d\n", value);
    }
    return 0;
}