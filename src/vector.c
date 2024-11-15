#include <string.h>
#include <stdlib.h>

#include "vector.h"

struct Vector {
    int _capacity;  // the allocated memory capacity of the array, private to the user
    int size;       // the used size of the array, public to the user
    int* array;
};

struct Vector * vector_create(unsigned int initial_capacity) {
    struct Vector* vector = (struct Vector*) malloc(sizeof(struct Vector));
    vector->_capacity = initial_capacity;
    vector->size = 0;
    vector->array = (int *) malloc(sizeof(int) * vector->_capacity);
    return vector;
}

void vector_delete(struct Vector* vector) {
    free(vector->array);
    free(vector);
}

int* vector_array(struct Vector* vector) {
    return vector->array;
}

int vector_size(struct Vector* vector) {
    return vector->size;
}

int vector_read(struct Vector* vector, int index) {
    return vector->array[index];
}

void vector_write(struct Vector* vector, int index, int value) {
    if (0 < index && index < vector_size(vector)) {
        vector->array[index] = value;
    }
}

void vector_append(struct Vector* vector, int value) {
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

int vector_pop(struct Vector* vector, int *value) {
    if (vector->size == 0) {
        return -1;
    }
    *value = vector->array[vector->size - 1];
    vector->size--;
    return 0;
}
