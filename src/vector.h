#ifndef VECTOR_H
#define VECTOR_H

struct Vector;

// Return a newly allocated vector
struct Vector * vector_create(unsigned int initial_capacity);

void vector_delete(struct Vector* vector);

int* vector_array(struct Vector* vector);

int vector_size(struct Vector* vector);

// Return the vector's value at the index if the index is in vector's bounds
int vector_read(struct Vector* vector, int index);

// Insert the value at the index in the vector if the index is in vector's bounds
void vector_write(struct Vector* vector, int index, int value);

// Append the value to the end of the vector
void vector_append(struct Vector* vector, int value);

/*
 * Remove the last value of the vector and return it by value.
 * Return -1 if there is no value to pop, 0 in nominal case.
 */
int vector_pop(struct Vector* vector, int *value);

#endif
