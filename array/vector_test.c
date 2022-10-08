#include "vector_test.h"
#include "vector.h"

void test_vector()
{
    vector my_vector = vector_create();

    const int LOOP_T = 1000000;
    const int LOOP_T_HF = 500000;

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

    for (int i = 0; i < LOOP_T; i++)
    {
        vector_push(my_vector, i);
        assert(vector_size(my_vector) == i + 1);
        assert(vector_at(my_vector, i) == i);
    }
    assert(vector_size(my_vector) == LOOP_T);
    assert(vector_is_empty(my_vector) == VECTOR_FALSE);
    printf("Test Case: vector_capacity() - Passed.\n");
    printf("Test Case: vector_push() - Passed.\n");
    printf("Test Case: vector_at() - Passed.\n");
    printf("Test Case: vector_size() - Passed.\n");

    for (int i = 0; i < LOOP_T; i++)
    {
        if (i % 2 == 0)
        {
            *(my_vector->array + i) = -23;
        }
    }

    vector_remove(my_vector, -23);
    assert(vector_size(my_vector) == LOOP_T_HF);

    for (int i = 0; i < LOOP_T_HF; i++)
    {
        assert((*(my_vector->array + i)) != -23);
    }
    printf("Test Case: vector_remove() - Passed.\n");

    for (int i = 0; i < LOOP_T_HF; i++)
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

    const int LOOP_I = 100000;
    const int ASSERT_SIZE = LOOP_I + 1;
    const int INSERT_INDEX = 50000;
    const int AT_LOOP_T = INSERT_INDEX + 1;

    for (int i = 0; i < LOOP_I; i++)
    {
        vector_push(my_vector, i);
    }
    vector_insert(my_vector, -1996, INSERT_INDEX);
    assert(vector_size(my_vector) == ASSERT_SIZE);
    assert(vector_at(my_vector, INSERT_INDEX) == -1996);
    for (int i = LOOP_I; i >= AT_LOOP_T; i--)
    {
        assert(vector_at(my_vector, i) == i - 1);
    }
    printf("Test Case: vector_insert() - Passed.\n");

    assert((vector_find(my_vector, -1996)) == INSERT_INDEX);
    printf("Test Case: vector_find() - Passed.\n");

    vector_delete(my_vector, INSERT_INDEX);
    assert(vector_size(my_vector) == LOOP_I);
    for (int i = 0; i < LOOP_I; i++)
    {
        assert(vector_at(my_vector, i) == i);
    }
    printf("Test Case: vector_delete() - Passed.\n");

    vector_destory(my_vector);
};