#include "stack_test.h"

void test_all()
{
    printf("Running all the tests...\n");
    Stack s = stack_create();
    const int LOOP_F = 10000000;
    assert(stack_is_empty(s) == STACK_TRUE);
    for (int i = 0; i < LOOP_F; i++)
    {
        stack_push(&s, i + 1);
        assert(stack_top(s) == i + 1);
    }
    printf("Test Case: stack_push() - Passed.\n");
    printf("Test Case: stack_top() - Passed.\n");
    assert(stack_is_empty(s) == STACK_FALSE);
    for (int i = LOOP_F; i > 0; i--)
    {
        assert(stack_pop(&s) == i);
    }
    printf("Test Case: stack_pop() - Passed.\n");
    assert(stack_is_empty(s) == STACK_TRUE);
    printf("Test Case: stack_is_empty() - Passed.\n\n");
}

void test_balanced_brackets()
{
    printf("Start running test cases for balanced_brackets().\n");

    /**
     * @brief Test Case 1.
     */
    const char *string_1 = "([])(){}(())()()";
    size_t size_1 = strlen(string_1);
    assert(balanced_brackets(string_1, size_1) == STACK_TRUE);
    printf("Test Case 1 Passed.\n");

    /**
     * @brief Test Case 2.
     */
    const char *string_2 = "()[]{}{";
    size_t size_2 = strlen(string_2);
    assert(balanced_brackets(string_2, size_2) == STACK_FALSE);
    printf("Test Case 2 Passed.\n");

    /**
     * @brief Test Case 3.
     */
    const char *string_3 = "(((((({{{{{[[[[[([)])]]]]]}}}}}))))))";
    size_t size_3 = strlen(string_3);
    assert(balanced_brackets(string_3, size_3) == STACK_FALSE);
    printf("Test Case 3 Passed.\n");

    /**
     * @brief Test Case 4.
     */
    const char *string_4 = "()()[{()})]";
    size_t size_4 = strlen(string_4);
    assert(balanced_brackets(string_4, size_4) == STACK_FALSE);
    printf("Test Case 4 Passed.\n");

    /**
     * @brief Test Case 5.
     */
    const char *string_5 = "(()())((()()()))";
    size_t size_5 = strlen(string_5);
    assert(balanced_brackets(string_5, size_5) == STACK_TRUE);
    printf("Test Case 5 Passed.\n");

    /**
     * @brief Test Case 6.
     */
    const char *string_6 = "{}()";
    size_t size_6 = strlen(string_6);
    assert(balanced_brackets(string_6, size_6) == STACK_TRUE);
    printf("Test Case 6 Passed.\n");

    // --

    /**
     * @brief Test Case 7.
     */
    const char *string_7 = "()([])";
    size_t size_7 = strlen(string_7);
    assert(balanced_brackets(string_7, size_7) == STACK_TRUE);
    printf("Test Case 7 Passed.\n");

    /**
     * @brief Test Case 8.
     */
    const char *string_8 = "((){{{{[]}}}})";
    size_t size_8 = strlen(string_8);
    assert(balanced_brackets(string_8, size_8) == STACK_TRUE);
    printf("Test Case 8 Passed.\n");

    /**
     * @brief Test Case 9.
     */
    const char *string_9 = "((({})()))";
    size_t size_9 = strlen(string_9);
    assert(balanced_brackets(string_9, size_9) == STACK_TRUE);
    printf("Test Case 9 Passed.\n");

    /**
     * @brief Test Case 10.
     */
    const char *string_10 = "(([]()()){})";
    size_t size_10 = strlen(string_10);
    assert(balanced_brackets(string_10, size_10) == STACK_TRUE);
    printf("Test Case 10 Passed.\n");

    /**
     * @brief Test Case 11.
     */
    const char *string_11 = "(((((([[[[[[{{{{{{{{{{{{()}}}}}}}}}}}}]]]]]]))))))((([])({})[])[])[]([]){}(())";
    size_t size_11 = strlen(string_11);
    assert(balanced_brackets(string_11, size_11) == STACK_TRUE);
    printf("Test Case 11 Passed.\n");

    /**
     * @brief Test Case 12.
     */
    const char *string_12 = "{[[[[({(}))]]]]}";
    size_t size_12 = strlen(string_12);
    assert(balanced_brackets(string_12, size_12) == STACK_FALSE);
    printf("Test Case 12 Passed.\n");

    /**
     * @brief Test Case 13.
     */
    const char *string_13 = "[((([])([]){}){}){}([])[]((())";
    size_t size_13 = strlen(string_13);
    assert(balanced_brackets(string_13, size_13) == STACK_FALSE);
    printf("Test Case 13 Passed.\n");

    /**
     * @brief Test Case 14.
     */
    const char *string_14 = ")[]}";
    size_t size_14 = strlen(string_14);
    assert(balanced_brackets(string_14, size_14) == STACK_FALSE);
    printf("Test Case 14 Passed.\n");

    /**
     * @brief Test Case 15.
     */
    const char *string_15 = "(a)";
    size_t size_15 = strlen(string_15);
    assert(balanced_brackets(string_15, size_15) == STACK_TRUE);
    printf("Test Case 15 Passed.\n");

    /**
     * @brief Test Case 16.
     */
    const char *string_16 = "(a(";
    size_t size_16 = strlen(string_16);
    assert(balanced_brackets(string_16, size_16) == STACK_FALSE);
    printf("Test Case 16 Passed.\n");

    /**
     * @brief Test Case 17.
     */
    const char *string_17 = "(141[])(){waga}((51afaw))()hh()";
    size_t size_17 = strlen(string_17);
    assert(balanced_brackets(string_17, size_17) == STACK_TRUE);
    printf("Test Case 17 Passed.\n");

    /**
     * @brief Test Case 18.
     */
    const char *string_18 = "aafwgaga()[]a{}{gggg";
    size_t size_18 = strlen(string_18);
    assert(balanced_brackets(string_18, size_18) == STACK_FALSE);
    printf("Test Case 18 Passed.\n");

    /**
     * @brief Test Case 19.
     */
    const char *string_19 = "(((((({{{{{safaf[[[[[([)]safsafsa)]]]]]}}}gawga}}))))))";
    size_t size_19 = strlen(string_19);
    assert(balanced_brackets(string_19, size_19) == STACK_FALSE);
    printf("Test Case 19 Passed.\n");

    /**
     * @brief Test Case 20.
     */
    const char *string_20 = "()(agawg)[{()gawggaw})]";
    size_t size_20 = strlen(string_20);
    assert(balanced_brackets(string_20, size_20) == STACK_FALSE);
    printf("Test Case 20 Passed.\n");

    /**
     * @brief Test Case 21.
     */
    const char *string_21 = "(()agwg())((()agwga()())gawgwgag)";
    size_t size_21 = strlen(string_21);
    assert(balanced_brackets(string_21, size_21) == STACK_TRUE);
    printf("Test Case 21 Passed.\n");

    /**
     * @brief Test Case 22.
     */
    const char *string_22 = "{}gawgw()";
    size_t size_22 = strlen(string_22);
    assert(balanced_brackets(string_22, size_22) == STACK_TRUE);
    printf("Test Case 22 Passed.\n");

    /**
     * @brief Test Case 23.
     */
    const char *string_23 = "(agwgg)([ghhheah%&@Q])";
    size_t size_23 = strlen(string_23);
    assert(balanced_brackets(string_23, size_23) == STACK_TRUE);
    printf("Test Case 23 Passed.\n");
    printf("Passed all the test cases.\n\n");
}

void test_next_greater_element()
{
    printf("Start running test cases for next_greater_element().\n");
    /**
     * @brief Test Case 1.
     */
    int arr_1[] = {4, 5, 2, 25};
    int arr_output_1[] = {5, 25, 25, -1};
    size_t size_1 = sizeof(arr_1) / sizeof(int);
    int *res_1 = next_greater_element(arr_1, size_1);
    for (int i = 0; i < size_1; i++)
    {
        assert(res_1[i] == arr_output_1[i]);
    }
    printf("Test Case 1 Passed.\n");

    /**
     * @brief Test Case 2.
     */
    int arr_2[] = {13, 7, 6, 12};
    int arr_output_2[] = {-1, 12, 12, -1};
    size_t size_2 = sizeof(arr_2) / sizeof(int);
    int *res_2 = next_greater_element(arr_2, size_2);
    for (int i = 0; i < size_2; i++)
    {
        assert(res_2[i] == arr_output_2[i]);
    }
    printf("Test Case 2 Passed.\n");
    printf("Passed all the test cases.\n");
}
