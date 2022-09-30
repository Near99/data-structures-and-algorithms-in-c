#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LIST_TRUE 1
#define LIST_FALSE 0

typedef int data_type;

struct node
{
    data_type data;
    struct node *next;
};

typedef struct list
{
    struct node *head;
    struct node *tail;
} list;

// prototypes
list *list_create();
void list_insert_front(list *, data_type);
void list_insert_back(list *, data_type);
data_type list_search_by_index(list *, int);
data_type list_pop_front(list *);
data_type list_pop_back(list *);
void list_traverse(list *);
void list_recursive(struct node *);
void list_destory(list *);
void list_remove(list *, data_type);
void list_insert_by_index(list *, int, data_type);
int list_empty(list *);
int list_size(list *);
void list_reverse(list *);
void remove_kth_node_from_end(list *, int);
void remove_duplicates_from_linked_list(list *);
list *sum_of_linked_lists(list *, list *);

// unit test
void test_all();
void test_remove_kth_node_from_end();
void test_remove_duplicates_from_linked_list();
void test_sum_of_linked_lists();

list *sum_of_linked_lists(list *l1, list *l2)
{
    list *l = list_create();
    int ls1 = list_size(l1);
    int ls2 = list_size(l2);
    struct node *lp = ls1 > ls2 ? l1->head : l2->head;
    struct node *lp2 = ls1 <= ls2 ? l1->head : l2->head;
    struct node **pp = &l->head;
    int k = 0;
    // printf("%d\n", lp->data);
    // printf("%d\n", lp2->data);
    while (lp != NULL || k != 0)
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->next = NULL;
        if (lp2 != NULL)
        {
            int i = lp->data + lp2->data;
            if ((i < 10) && (k == 0))
            {
                new_node->data = i;
            }
            else if ((i < 10) && (k != 0))
            {
                new_node->data = i + k;
                k--;
            }
            else if ((i >= 10) && (k == 0))
            {
                int j = i % 10;
                new_node->data = j;
                k++;
            }
            else if ((i >= 10) && (k != 0))
            {
                int r = i % 10;
                new_node->data = r + k;
            }
            lp2 = lp2->next;
        }
        else
        {
            if (k == 0)
            {
                new_node->data = lp->data;
            }
            else
            {
                new_node->data = lp->data + k;
                k--;
            }
        }
        if (l->head == NULL)
        {
            l->head = new_node;
            l->tail = new_node;
            // printf("%d\n", new_node->data);
        }
        else
        {
            printf("called\n");
            (*pp)->next = new_node;
            pp = &(*pp)->next;
            // printf("%d\n", new_node->data);
        }
        if (lp->next == NULL)
        {
            l->tail = new_node;
            // printf("%d\n", l->tail->data);
            // printf("called changing tail\n");
        }
        lp = lp->next;
        // lp2 = lp2->next;
        // printf("called\n");
    }
    return l;
}

void test_sum_of_linked_lists()
{
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
    list_traverse(l);
    // assert(l->head->data == 1 && l->tail->data == 1 && l->tail->next == NULL);
    // for (int i = 0; i < sizeof(test_case_2_output) / sizeof(data_type); i++)
    // {
    //     assert(test_case_2_output[i] == list_pop_front(l));
    // }
    // assert(list_empty(l) == LIST_TRUE && list_size(l) == 0 && l->head == NULL && l->tail == NULL);
    // printf("Test Case 2 Passed\n");
}

int main()
{
    // test_all();

    // test_remove_kth_node_from_end();

    // test_remove_duplicates_from_linked_list();

    test_sum_of_linked_lists();

    return 0;
}

list *list_create()
{

    list *new_list = malloc(sizeof(list));

    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

void list_insert_front(list *l, data_type data)
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;

    if (l->tail == NULL)
    {
        l->tail = new_node;
    }
}

void list_insert_back(list *l, data_type data)
{
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    if (l->head == NULL)
    {
        l->head = new_node;
    }

    if (l->tail == NULL)
    {
        l->tail = new_node;
        return;
    }

    l->tail->next = new_node;
    l->tail = new_node;
}

data_type list_pop_front(list *l)
{
    struct node *p = l->head;
    data_type r = p->data;

    if (l->head == l->tail)
    {
        l->tail = NULL;
    }

    l->head = p->next;
    free(p);

    return r;
}

data_type list_pop_back(list *l)
{
    if (l->head == NULL)
    {
        printf("Empty list!\n");
        exit(EXIT_FAILURE);
    }
    struct node **p = &l->head;
    data_type r = l->tail->data;

    if ((*p) == l->tail)
    {
        free(l->tail);
        l->tail = NULL;
        l->head = NULL;
        return r;
    }

    while ((*p)->next != l->tail)
    {
        p = &(*p)->next;
    }

    (*p)->next = NULL;
    free(l->tail);
    l->tail = *p;

    return r;
}

void list_insert_by_index(list *l, int index, data_type value)
{
    if (index < 0 || index >= list_size(l))
    {
        printf("Out of boundary!\n");
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;

    if (index == 0)
    {
        list_insert_front(l, value);
        return;
    }

    struct node **c = &l->head, *p = NULL;
    while (index != 0)
    {
        p = *c;
        c = &(*c)->next;
        index--;
    }

    new_node->next = *c;
    p->next = new_node;
}

data_type list_search_by_index(list *l, int index)
{
    if (index < 0 || index >= list_size(l))
    {
        printf("Out of boundary!\n");
        exit(EXIT_FAILURE);
    }

    struct node *n = l->head;

    while (index != 0)
    {
        n = n->next;
        index--;
    }

    return n->data;
}

void list_remove(list *l, data_type target)
{
    struct node **c = &l->head, *p = NULL, *d = NULL;
    while ((*c)->data != target && (*c)->next != NULL) // would crash if not make null checking.
    {
        p = *c;
        c = &(*c)->next;
    }
    if ((*c)->data != target)
    {
        printf("Target not found!\n");
        return;
    }
    // Change tail if the last node is to be removed.
    if ((*c)->data == target && (*c)->next == NULL)
    {
        l->tail = p;
    }
    d = *c;
    *c = d->next;
    free(d);
}

void list_reverse(list *l)
{
    struct node *prev = NULL, *curr = l->head, *next;
    l->tail = l->head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l->head = prev;
}

void list_destory(list *l)
{
    struct node *p = NULL, *c = l->head;
    while (c != NULL)
    {
        p = c;
        c = c->next;
        free(p);
    }
    free(l);
}

int list_size(list *l)
{
    int c = 0;
    struct node *n = l->head;
    while (n != NULL)
    {
        c++;
        n = n->next;
    }
    return c;
}

int list_empty(list *l)
{
    return l->head == NULL ? LIST_TRUE : LIST_FALSE;
}

void list_traverse(list *l)
{
    list_recursive(l->head);
}

void list_recursive(struct node *l)
{
    if (l == NULL)
    {
        return;
    }
    printf("%d\n", l->data);
    list_recursive(l->next);
}

void remove_duplicates_from_linked_list(list *l)
{
    struct node *c = l->head, *n = c->next;
    while (n != NULL)
    {
        if (c->data == n->data)
        {
            if (l->tail == n) // handle if the last node is to be removed.
            {
                l->tail = c;
            }
            c->next = n->next;
            free(n);
            n = c->next;
        }
        else
        {
            c = c->next;
            n = n->next;
        }
    }
}

void remove_kth_node_from_end(list *l, int k)
{
    int i, j = 0;
    struct node *c = l->head;
    while (c != NULL)
    {
        i++;
        c = c->next;
    }
    j = i - k;

    struct node *d = l->head, *p = NULL;
    while (j > 0)
    {
        p = d;
        d = d->next;
        j--;
    }
    if (p == NULL) // hanlde if the head is to be delete.
    {
        l->head = d->next;
        free(d);
        return;
    }
    if (d->next == NULL) // handle if the tail is to be delete.
    {
        l->tail = p;
    }
    p->next = d->next;
    free(d);
}

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
    printf("Test Case 7 Passed.\n");
    printf("Passed all the test cases.\n");
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
    printf("Test Case 10 Passed.\n");
    printf("Passed all the test cases.\n\n");
}
