#include <stdlib.h>
#include <string.h>

// Vector declaration
struct Vector {
    int _capacity;  // the allocated memory capacity of the array, private to the user
    int size;       // the used size of the array, public to the user
    int* array;
};

// Vector implementations
struct Vector * new_vector(unsigned int initial_capacity) {
    struct Vector* vector = (struct Vector*) malloc(sizeof(struct Vector));
    vector->_capacity = initial_capacity;
    vector->size = 0;
    vector->array = (int *) malloc(sizeof(int) * vector->_capacity);
    return vector;
}

/*
 * Append the value to the end of the vector
 */
void append(struct Vector* vector, int value) {
    if (vector->size == vector->_capacity) {
        int new_capacity = (vector->_capacity * 2);
        int *new_array = (int *) malloc(sizeof(int) * new_capacity);
        memcpy(new_array, vector->array, vector->_capacity);
        vector->_capacity = new_capacity;
        free(vector->array);
        vector->array = new_array;
    }
    vector->array[vector->size] = value;
    vector->size++;
}

/*
 * Remove the last value of the vector and return it by value.
 * Return -1 if there is no value to pop, 0 in nominal case.
 */
int pop(struct Vector* vector, int *value) {
    if (vector->size == 0) {
        return -1;
    }
    *value = vector->array[vector->size - 1];
    vector->size--;
    return 0;
}

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
    insertion_sort(vector->array, vector->size);
}

#include <stdio.h>
int main(int argc, const char *argv[]) {
    // Vector usage
    unsigned int size = 10;
    struct Vector* vector = new_vector(size);
    // printf("vector new");
    for (int i = 0; i < size; i++) {
        append(vector, size - i);
    }
    for (int i = 0; i < vector->size; i++) {
        printf("vector[%d] = %d\n", i, vector->array[i]);
    }
    sort(vector);
    for (int i = 0; i < vector->size; i++) {
        printf("sorted vector[%d] = %d\n", i, vector->array[i]);
    }
    int value;
    while (pop(vector, &value) != -1) {
        printf("vector.pop = %d\n", value);
    }
    return 0;
}