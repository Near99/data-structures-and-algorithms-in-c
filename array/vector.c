#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 16
#define INIT_ARRAY_SIZE 0

typedef int data_type;

struct _vector
{
    data_type *array; // a pointer of type data_type;
    int size;
    int capacity;
};

typedef struct _vector *vector;

// prototypes
vector vector_create();
void vector_destory(vector);
void vector_push(vector, data_type);
data_type vector_pop(vector);
data_type vector_at(vector, int);
void vector_extend_capacity(vector);
void vector_shrink_capacity(vector);

int main()
{
    vector my_vector = vector_create();

    /**
     * my_vector->array is a pointer of data_type type,
     * currently pointing to the size of 16 INIT_CAPACITY
     * of type data_type space on the heap.
     * 
     * These two values should be equal and it is ;).
     */
    for (int i = 0; i < INIT_CAPACITY; i++)
    {
        // printf("%p\n", (my_vector->array) + i);
        // printf("%p\n", &(my_vector->array)[i]);
    }

    for (int i = 0; i < 80; i++)
    {
        vector_push(my_vector, 1990 + i);
    }

    for (int i = 0; i < my_vector->size; i++)
    {
        // printf("%d\n", my_vector->array[i]);
    }

    printf("capacity: %d\n", my_vector->capacity);
    printf("size: %d\n", my_vector->size);

    data_type f = vector_pop(my_vector);
    data_type r = vector_at(my_vector, 79);

    printf("%d\n", r);
    printf("%d\n", f);

    return 0;
}

vector vector_create()
{
    /**
     * Ask for memory on the heap.
     * first mistake here is to write such code:
     *  struct _vector _v;
     *  vector v = &_v;
     * As learned in the pointer lessons, memory allocation 
     * apart from malloc will be on the stack, and the stack
     * memory will be relased once the function get popped from 
     * the stack, then all the information and data will get lost.
     */
    vector v = (vector)malloc(sizeof(struct _vector));

    v->size = INIT_ARRAY_SIZE;
    v->capacity = INIT_CAPACITY;
    v->array = (data_type *)malloc(sizeof(data_type) * (v->capacity));

    return v;
}

void vector_destory(vector v)
{
    free(v->array);
    free(v);
}

void vector_push(vector v, data_type value)
{
    if (v->size >= v->capacity)
    {
        printf("Out of capacity!!\n");
        vector_extend_capacity(v);
    }
    v->array[v->size++] = value;
}

data_type vector_pop(vector v)
{
    data_type value = v->array[v->size - 1];
    v->size--;

    if (v->size < v->capacity / 2)
    {
        // todos..
        // shrink the capacity to half its size;
        printf("Shrink needed!\n");
    }

    return value;
}

data_type vector_at(vector v, int index)
{
    if (index < 0 || index > v->size - 1) // less than current size - 1 cause index starting from 0; second mistake.
    {
        printf("Out of boundary!\n");
        return -1;
    }

    return v->array[index];
}

void vector_extend_capacity(vector v)
{
    data_type *new_capacity = (data_type *)malloc(sizeof(data_type) * (v->capacity * 2));

    for (int i = 0; i < v->size; i++)
    {
        new_capacity[i] = v->array[i];
    }

    v->capacity = v->capacity * 2;
    free(v->array);
    v->array = new_capacity;
}

void vector_shrink_capacity(vector v)
{
    if (v->capacity <= INIT_CAPACITY)
    {
        return;
    }

    data_type *new_capacity = (data_type *)malloc(sizeof(data_type) * (v->capacity / 2));

    for (int i = 0; i < v->size; i++)
    {
        new_capacity[i] = v->array[i];
    }

    v->capacity = v->capacity / 2;
    free(v->array);
    v->array = new_capacity;
}
