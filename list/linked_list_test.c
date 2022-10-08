#include "linked_list.h"
#include "linked_list_test.h"

void test_all()
{
    printf("Running all the tests...\n");
    list *my_list = list_create();

    assert(list_size(my_list) == 0 && list_empty(my_list) == LIST_TRUE && my_list->head == NULL && my_list->tail == NULL);
    printf("Test Case: list_create() - Passed.\n");

    const int LOOP_F = 10000000;
    for (int i = 0; i < LOOP_F; i++)
    {
        list_insert_front(my_list, i + 1);
        assert(my_list->head->data == i + 1);
    }
    assert(list_size(my_list) == LOOP_F && list_empty(my_list) == LIST_FALSE && my_list->tail->data == 1);
    printf("Test Case: list_size() - Passed.\n");
    printf("Test Case: list_empty() - Passed.\n");
    printf("Test Case: list_insert_front() - Passed.\n");

    for (int i = LOOP_F; i > 0; i--)
    {
        if (my_list->head != NULL)
        {
            assert(my_list->head->data == i);
        }
        if (my_list->tail != NULL)
        {
            assert(my_list->tail->data == 1);
        }
        assert(list_pop_front(my_list) == i);
    }
    assert(my_list->head == NULL && my_list->tail == NULL);
    printf("Test Case: list_pop_front() - Passed.\n");

    const int LOOP_B = 10000;
    for (int i = 0; i < LOOP_B; i++)
    {
        list_insert_front(my_list, i + 1);
    }

    for (int i = LOOP_B - 1; i >= 0; i--)
    {
        assert(list_search_by_index(my_list, i) == list_pop_back(my_list));
    }
    printf("Test Case: list_search_by_index() - Passed.\n");

    for (int i = 0; i < LOOP_B; i++)
    {
        list_insert_front(my_list, i + 1);
    }
    for (int i = 0; i < LOOP_B; i++)
    {
        if (my_list->tail != NULL)
        {
            assert(my_list->tail->data == i + 1);
        }
        assert(list_pop_back(my_list) == i + 1);
    }
    assert(my_list->tail == NULL && my_list->head == NULL && list_size(my_list) == 0);
    printf("Test Case: list_pop_back() - Passed.\n");

    for (int i = 0; i < LOOP_F; i++)
    {
        list_insert_back(my_list, i + 1);
        assert(my_list->head->data == 1 && my_list->tail->data == i + 1);
    }
    assert(list_size(my_list) == LOOP_F);
    printf("Test Case: list_insert_back() - Passed.\n");

    for (int i = 0; i < LOOP_F; i++)
    {
        list_remove(my_list, i + 1);
    }
    assert(list_size(my_list) == 0 && my_list->tail == NULL && my_list->head == NULL);
    printf("Test Case: list_remove() - Passed.\n");

    for (int i = 0; i < 10000; i++)
    {
        list_insert_back(my_list, -1);
    }
    for (int i = 0; i < 10000; i++)
    {
        list_insert_by_index(my_list, i, i);
        assert(list_search_by_index(my_list, i) == i);
    }
    for (int i = 19; i >= 10; i--)
    {
        list_insert_by_index(my_list, i, i);
        assert(list_search_by_index(my_list, i) == i);
    }
    printf("Test Case: list_search_by_index() - Passed.\n");

    list_destory(my_list);
}

void test_remove_duplicates_from_linked_list()
{
    printf("Start running test cases for remove_duplicates_from_linked_list().\n");
    list *l = list_create();

    /**
     * @brief Test Case 1.
     */
    data_type test_case_1[] = {1, 1, 1, 3, 4, 4, 4, 5, 6, 6};
    data_type test_case_1_output[] = {1, 3, 4, 5, 6};
    for (int i = 0; i < sizeof(test_case_1) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_1[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == 1 && l->tail->data == 6 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_1_output) / sizeof(data_type); i++)
    {
        assert(test_case_1_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 1 Passed.\n");

    /**
     * @brief Test Case 2.
     */
    data_type test_case_2[] = {1, 1, 1, 1, 1, 4, 4, 5, 6, 6};
    data_type test_case_2_output[] = {1, 4, 5, 6};
    for (int i = 0; i < sizeof(test_case_2) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_2[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == 1 && l->tail->data == 6 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_2_output) / sizeof(data_type); i++)
    {
        assert(test_case_2_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 2 Passed.\n");

    /**
     * @brief Test Case 3.
     */
    data_type test_case_3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    data_type test_case_3_output[] = {1};
    for (int i = 0; i < sizeof(test_case_3) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_3[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == 1 && l->tail->data == 1 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_3_output) / sizeof(data_type); i++)
    {
        assert(test_case_3_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 3 Passed.\n");

    /**
     * @brief Test Case 4.
     */
    data_type test_case_4[] = {1, 9, 11, 15, 15, 16, 17};
    data_type test_case_4_output[] = {1, 9, 11, 15, 16, 17};
    for (int i = 0; i < sizeof(test_case_4) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_4[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == 1 && l->tail->data == 17 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_4_output) / sizeof(data_type); i++)
    {
        assert(test_case_4_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 4 Passed.\n");

    /**
     * @brief Test Case 5.
     */
    data_type test_case_5[] = {1};
    data_type test_case_5_output[] = {1};
    for (int i = 0; i < sizeof(test_case_5) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_5[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == 1 && l->tail->data == 1 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_5_output) / sizeof(data_type); i++)
    {
        assert(test_case_5_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 5 Passed.\n");

    /**
     * @brief Test Case 6.
     */
    data_type test_case_6[] = {-5, -1, -1, -1, 5, 5, 5, 8, 8, 9, 10, 11, 11};
    data_type test_case_6_output[] = {-5, -1, 5, 8, 9, 10, 11};
    for (int i = 0; i < sizeof(test_case_6) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_6[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == -5 && l->tail->data == 11 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_6_output) / sizeof(data_type); i++)
    {
        assert(test_case_6_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 6 Passed.\n");

    /**
     * @brief Test Case 7.
     */
    data_type test_case_7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12};
    data_type test_case_7_output[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int i = 0; i < sizeof(test_case_7) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_7[i]);
    }
    remove_duplicates_from_linked_list(l);
    assert(l->head->data == 1 && l->tail->data == 12 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_7_output) / sizeof(data_type); i++)
    {
        assert(test_case_7_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);

    list_destory(l);

    printf("Test Case 7 Passed.\n");
    printf("Passed all the test cases.\n\n");
}

void test_remove_kth_node_from_end()
{
    printf("\nStart running test cases for remove_kth_node_fron_end().\n");
    list *l = list_create();
    int k;
    /**
     * @brief Test Case 1.
     */
    data_type test_case_1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_1_output[] = {0, 1, 2, 3, 4, 5, 7, 8, 9};
    k = 4;
    for (int i = 0; i < sizeof(test_case_1) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_1[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_1_output) / sizeof(data_type); i++)
    {
        assert(test_case_1_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 1 Passed.\n");

    /**
     * @brief Test Case 2.
     */
    data_type test_case_2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_2_output[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    k = 1;
    for (int i = 0; i < sizeof(test_case_2) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_2[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 8 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_2_output) / sizeof(data_type); i++)
    {
        assert(test_case_2_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 2 Passed.\n");

    /**
     * @brief Test Case 3.
     */
    data_type test_case_3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_3_output[] = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    k = 2;
    for (int i = 0; i < sizeof(test_case_3) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_3[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_3_output) / sizeof(data_type); i++)
    {
        assert(test_case_3_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 3 Passed.\n");

    /**
     * @brief Test Case 4.
     */
    data_type test_case_4[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_4_output[] = {0, 1, 2, 3, 4, 5, 6, 8, 9};
    k = 3;
    for (int i = 0; i < sizeof(test_case_4) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_4[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_4_output) / sizeof(data_type); i++)
    {
        assert(test_case_4_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 4 Passed.\n");

    /**
     * @brief Test Case 5.
     */
    data_type test_case_5[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_5_output[] = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    k = 5;
    for (int i = 0; i < sizeof(test_case_5) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_5[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_5_output) / sizeof(data_type); i++)
    {
        assert(test_case_5_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 5 Passed.\n");

    /**
     * @brief Test Case 6.
     */
    data_type test_case_6[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_6_output[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    k = 6;
    for (int i = 0; i < sizeof(test_case_6) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_6[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_6_output) / sizeof(data_type); i++)
    {
        assert(test_case_6_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 6 Passed.\n");

    /**
     * @brief Test Case 7.
     */
    data_type test_case_7[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_7_output[] = {0, 1, 2, 4, 5, 6, 7, 8, 9};
    k = 7;
    for (int i = 0; i < sizeof(test_case_7) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_7[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_7_output) / sizeof(data_type); i++)
    {
        assert(test_case_7_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 7 Passed.\n");

    /**
     * @brief Test Case 8.
     */
    data_type test_case_8[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_8_output[] = {0, 1, 3, 4, 5, 6, 7, 8, 9};
    k = 8;
    for (int i = 0; i < sizeof(test_case_8) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_8[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_8_output) / sizeof(data_type); i++)
    {
        assert(test_case_8_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 8 Passed.\n");

    /**
     * @brief Test Case 9.
     */
    data_type test_case_9[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_9_output[] = {0, 2, 3, 4, 5, 6, 7, 8, 9};
    k = 9;
    for (int i = 0; i < sizeof(test_case_9) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_9[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 0 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_9_output) / sizeof(data_type); i++)
    {
        assert(test_case_9_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    printf("Test Case 9 Passed.\n");

    /**
     * @brief Test Case 10.
     */
    data_type test_case_10[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_type test_case_10_output[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    k = 10;
    for (int i = 0; i < sizeof(test_case_10) / sizeof(data_type); i++)
    {
        list_insert_back(l, test_case_10[i]);
    }
    remove_kth_node_from_end(l, k);
    assert(l->head->data == 1 && l->tail->data == 9 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_10_output) / sizeof(data_type); i++)
    {
        assert(test_case_10_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);

    list_destory(l);

    printf("Test Case 10 Passed.\n");
    printf("Passed all the test cases.\n\n");
}

void test_sum_of_linked_lists()
{
    printf("Start running test cases for sum_of_linked_lists().\n");
    list *l1 = list_create();
    list *l2 = list_create();
    list *l;

    /**
     * @brief Test Case 1.
     */
    data_type test_case_1_1[] = {2, 4, 7, 1};
    data_type test_case_1_2[] = {9, 4, 5};
    data_type test_case_1_output[] = {1, 9, 2, 2};
    for (int i = 0; i < sizeof(test_case_1_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_1_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_1_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_1_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 1 && l->tail->data == 2 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_1_output) / sizeof(data_type); i++)
    {
        assert(test_case_1_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 1 Passed\n");

    /**
     * @brief Test Case 2.
     */
    data_type test_case_2_1[] = {2};
    data_type test_case_2_2[] = {9};
    data_type test_case_2_output[] = {1, 1};
    for (int i = 0; i < sizeof(test_case_2_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_2_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_2_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_2_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 1 && l->tail->data == 1 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_2_output) / sizeof(data_type); i++)
    {
        assert(test_case_2_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 2 Passed\n");

    /**
     * @brief Test Case 3.
     */
    data_type test_case_3_1[] = {0, 0, 0, 5};
    data_type test_case_3_2[] = {9};
    data_type test_case_3_output[] = {9, 0, 0, 5};
    for (int i = 0; i < sizeof(test_case_3_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_3_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_3_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_3_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 9 && l->tail->data == 5 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_3_output) / sizeof(data_type); i++)
    {
        assert(test_case_3_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 3 Passed\n");

    /**
     * @brief Test Case 4.
     */
    data_type test_case_4_1[] = {1, 1, 1};
    data_type test_case_4_2[] = {9, 9, 9};
    data_type test_case_4_output[] = {0, 1, 1, 1};
    for (int i = 0; i < sizeof(test_case_4_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_4_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_4_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_4_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 0 && l->tail->data == 1 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_4_output) / sizeof(data_type); i++)
    {
        assert(test_case_4_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 4 Passed\n");

    /**
     * @brief Test Case 5.
     */
    data_type test_case_5_1[] = {1, 2, 3};
    data_type test_case_5_2[] = {6, 7, 9, 1, 8};
    data_type test_case_5_output[] = {7, 9, 2, 2, 8};
    for (int i = 0; i < sizeof(test_case_5_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_5_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_5_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_5_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 7 && l->tail->data == 8 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_5_output) / sizeof(data_type); i++)
    {
        assert(test_case_5_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 5 Passed\n");

    /**
     * @brief Test Case 6.
     */
    data_type test_case_6_1[] = {0};
    data_type test_case_6_2[] = {0};
    data_type test_case_6_output[] = {0};
    for (int i = 0; i < sizeof(test_case_6_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_6_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_6_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_6_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 0 && l->tail->data == 0 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_6_output) / sizeof(data_type); i++)
    {
        assert(test_case_6_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 6 Passed\n");

    /**
     * @brief Test Case 7.
     */
    data_type test_case_7_1[] = {0};
    data_type test_case_7_2[] = {0, 0, 0, 0, 0, 8};
    data_type test_case_7_output[] = {0, 0, 0, 0, 0, 8};
    for (int i = 0; i < sizeof(test_case_7_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_7_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_7_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_7_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 0 && l->tail->data == 8 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_7_output) / sizeof(data_type); i++)
    {
        assert(test_case_7_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 7 Passed\n");

    /**
     * @brief Test Case 8.
     */
    data_type test_case_8_1[] = {4, 6, 9, 3, 1};
    data_type test_case_8_2[] = {0, 0, 0, 0, 2, 7};
    data_type test_case_8_output[] = {4, 6, 9, 3, 3, 7};
    for (int i = 0; i < sizeof(test_case_8_1) / sizeof(data_type); i++)
    {
        list_insert_back(l1, test_case_8_1[i]);
    }
    for (int i = 0; i < sizeof(test_case_8_2) / sizeof(data_type); i++)
    {
        list_insert_back(l2, test_case_8_2[i]);
    }
    l = sum_of_linked_lists(l1, l2);
    assert(l->head->data == 4 && l->tail->data == 7 && l->tail->next == NULL);
    for (int i = 0; i < sizeof(test_case_8_output) / sizeof(data_type); i++)
    {
        assert(test_case_8_output[i] == list_pop_front(l));
    }
    assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    list_destory(l1);
    list_destory(l2);
    l1 = list_create();
    l2 = list_create();
    assert(list_empty(l1) && list_empty(l2));
    printf("Test Case 8 Passed\n");
    printf("Passed all the test cases.\n");
}