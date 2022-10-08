#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H
#define INIT_CAPACITY 16
#define INIT_ARRAY_SIZE 0
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define VECTOR_TRUE 1
#define VECTOR_FALSE 0

typedef int data_type;

struct _vector
{
    data_type *array; // a pointer of type data_type;
    int size;
    int capacity;
};

typedef struct _vector *vector;

vector vector_create();
void vector_destory(vector);
void vector_extend_capacity(vector);        // private
void vector_shrink_capacity(vector);        // private
void vector_push(vector, data_type);        // add element to the end
data_type vector_pop(vector);               // remove the last element
data_type vector_at(vector, int);           // return element given index
int vector_is_empty(vector);                // if vector is empty
int vector_find(vector, data_type);         // return the first index of the given value
int vector_size(vector);                    // number of elements
int vector_capacity(vector);                // capacity
void vector_insert(vector, data_type, int); // insert at given index and shift trailing elements to the right
void vector_delete(vector, int);            // delete element at given index and shift trailing elements to the left
void vector_remove(vector, data_type);      // remove all elements matching given value

#endif