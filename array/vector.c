#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

// prototypes
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

// ut
void test_vector();

int main()
{

    test_vector();

    return 0;
}

vector vector_create()
{
    /**
     * Ask for memory on the heap.
     * first mistake here is to write such code:
     *  struct _vector _v;
     *  vector v = &_v;
     * As learned in the pointer lessons, memory allocation apart 
     * from malloc will be on the stack, and the stack memory will 
     * be relased once the function get popped from  the stack, 
     * then all the information and data will get lost.
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
        vector_extend_capacity(v);
    }
    v->array[v->size++] = value;
}

data_type vector_pop(vector v)
{
    if (v->size == 0)
    {
        printf("Vector is empty!\n");
        exit(-1);
    }
    data_type value = v->array[v->size - 1];
    v->size--;

    if (v->size * 4 < v->capacity)
    {
        // shrink the capacity to half its size, when only a quarter of the capacity is used.
        vector_shrink_capacity(v);
    }

    return value;
}

data_type vector_at(vector v, int index)
{
    if (index < 0 || index > v->size - 1)
    {
        printf("Out of boundary!\n");
        exit(-1);
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

    free(v->array);
    v->array = new_capacity;
    v->capacity = v->capacity * 2;
}

void vector_shrink_capacity(vector v)
{
    if (v->capacity <= INIT_CAPACITY)
    {
        return;
    }

    int new_capacity = v->capacity / 2;

    data_type *new_array = (data_type *)malloc(sizeof(data_type) * new_capacity);

    /**
     * Well, I don't see anything reasonable checking if current size of the array 
     * is less than new capacity as only four times of current size less than current 
     * capacity will triger shrinking the current size will always be less than half 
     * of the current capacity.
     * 
     * But I'll just leave it there for now.
     */
    for (int i = 0; i < MIN(v->size, new_capacity); i++)
    {
        new_array[i] = v->array[i];
    }

    free(v->array);
    v->array = new_array;
    v->capacity = new_capacity;
    v->size = MIN(v->size, new_capacity); // again I don't think it's necessary.
}

/**
 * Return true if array is empty.
 */
int vector_is_empty(vector v)
{
    return v->size == 0 ? VECTOR_TRUE : VECTOR_FALSE;
}

int vector_find(vector v, data_type value)
{
    for (int index = 0; index < v->size; index++)
    {
        if (value == v->array[index])
        {
            return index;
        }
    }

    return -1;
}

int vector_size(vector v)
{
    return v->size;
}

int vector_capacity(vector v)
{
    return v->capacity;
}

void vector_insert(vector v, data_type value, int index)
{
    if (index < 0 || index > v->size - 1)
    {
        printf("Out of boundary.\n");
        exit(-1);
    }

    // make sure there is enough space.
    if (v->size + 1 >= v->capacity)
    {
        vector_extend_capacity(v);
    }

    // shifting
    int i = v->size - index;
    for (int j = 0; j < i; j++)
    {
        *((v->array + (v->size - 1)) + 1 - j) = *(v->array + (v->size - 1) - j);
    }

    *(v->array + index) = value;
    v->size++;
}

void vector_delete(vector v, int index)
{
    if (index < 0 || index > v->size - 1)
    {
        printf("Out of boundary\n");
        exit(-1);
    }

    int i = v->size - index - 1; // number of elemenets to shift
    int j = index + 1;           // starting point to shift to the left
    for (int k = 0; k < i; k++)
    {
        *(v->array + k + j - 1) = *(v->array + k + j);
    }

    v->size--;
}

void vector_remove(vector v, data_type value)
{
    for (int i = 0; i < v->size; i++)
    {
        if (*(v->array + i) == value)
        {
            vector_delete(v, i);
        }
    }
}

void test_vector()
{
    vector my_vector = vector_create();

    /**
     * my_vector->array is a pointer of data_type type, currently pointing 
     * to the size of 16 INIT_CAPACITY of type data_type space on the heap.
     * 
     * These two values should be equal and it is ;).
     */
    for (int i = 0; i < INIT_CAPACITY; i++)
    {
        assert(((my_vector->array) + i) == (&(my_vector->array)[i]));
    }
    assert(vector_is_empty(my_vector) == VECTOR_TRUE);
    printf("Test Case: vector_create() - Passed.\n");

    int counter = 0;
    for (int i = 0; i < 10000; i++)
    {
        vector_push(my_vector, i);
        assert(vector_size(my_vector) == i + 1);
        assert(vector_at(my_vector, i) == i);
    }
    assert(vector_size(my_vector) == 10000);
    assert(vector_is_empty(my_vector) == VECTOR_FALSE);
    printf("Test Case: vector_capacity() - Passed.\n");
    printf("Test Case: vector_push() - Passed.\n");
    printf("Test Case: vector_at() - Passed.\n");
    printf("Test Case: vector_size() - Passed.\n");

    for (int i = 0; i < 10000; i++)
    {
        if (i % 2 == 0)
        {
            *(my_vector->array + i) = -23;
        }
    }

    for (int i = 0; i < 10000; i++)
    {
        vector_remove(my_vector, -23);
    }
    assert(vector_size(my_vector) == 5000);

    for (int i = 0; i < 5000; i++)
    {
        assert((*(my_vector->array + i)) != -23);
    }
    printf("Test Case: vector_remove() - Passed.\n");

    for (int i = 0; i < 5000; i++)
    {
        vector_pop(my_vector);
    }
    assert(vector_size(my_vector) == 0);
    assert(vector_capacity(my_vector) == INIT_CAPACITY);
    assert(vector_is_empty(my_vector) == VECTOR_TRUE);
    printf("Test Case: vector_pop() - Passed.\n");
    printf("Test Case: vector_is_empty() - Passed.\n");
    printf("Test Case: vector_extend_capacity() - Passed.\n");
    printf("Test Case: vector_shrink_capacity() - Passed.\n");

    for (int i = 0; i < 10; i++)
    {
        vector_push(my_vector, i);
    }
    vector_insert(my_vector, -1996, 5);
    assert(vector_size(my_vector) == 11);
    assert(vector_at(my_vector, 5) == -1996);
    for (int i = 10; i >= 6; i--)
    {
        assert(vector_at(my_vector, i) == i - 1);
    }
    printf("Test Case: vector_insert() - Passed.\n");

    assert((vector_find(my_vector, -1996)) == 5);
    printf("Test Case: vector_find() - Passed.\n");

    vector_delete(my_vector, 5);
    assert(vector_size(my_vector) == 10);
    for (int i = 0; i < 10; i++)
    {
        assert(vector_at(my_vector, i) == i);
    }
    printf("Test Case: vector_delete() - Passed.\n");

    vector_destory(my_vector);
};
