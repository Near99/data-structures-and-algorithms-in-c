#include "vector.h"

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
    vector v = malloc(sizeof(struct _vector));

    v->size = INIT_ARRAY_SIZE;
    v->capacity = INIT_CAPACITY;
    v->array = malloc(sizeof(data_type) * (v->capacity));

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
    *(v->array + v->size++) = value;
}

data_type vector_pop(vector v)
{
    if (v->size == 0)
    {
        printf("Vector is empty!\n");
        exit(EXIT_FAILURE);
    }
    data_type value = *(v->array + v->size - 1);
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
        exit(EXIT_FAILURE);
    }

    return *(v->array + index);
}

void vector_extend_capacity(vector v)
{
    data_type *new_capacity = malloc(sizeof(data_type) * (v->capacity * 2));

    for (int i = 0; i < v->size; i++)
    {
        *(new_capacity + i) = *(v->array + i);
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

    data_type *new_array = malloc(sizeof(data_type) * new_capacity);

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
        *(new_array + i) = *(v->array + i);
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
        if (value == *(v->array + index))
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
        exit(EXIT_FAILURE);
    }

    // make sure there is enough space.
    if (v->size + 1 >= v->capacity)
    {
        vector_extend_capacity(v);
    }

    for (int i = v->size - 1; i >= index; i--)
    {
        *(v->array + i + 1) = *(v->array + i);
    }

    *(v->array + index) = value;
    v->size++;
}

void vector_delete(vector v, int index)
{
    if (index < 0 || index > v->size - 1)
    {
        printf("Out of boundary\n");
        exit(EXIT_FAILURE);
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
    data_type *new_array = malloc(sizeof(data_type) * v->capacity);
    int c = 0;

    for (int i = 0; i < v->size; i++)
    {
        if (*(v->array + i) != value)
        {
            *(new_array + c++) = *(v->array + i);
        }
    }

    free(v->array);
    v->array = new_array;
    v->size = c;
}