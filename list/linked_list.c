#include "linked_list.h"

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
    struct node *prev = NULL, *curr = l->head, *next = NULL;
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
    int i = 0, j = 0;
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
    if (p == NULL) // hanlde if the head is to be deleted.
    {
        l->head = d->next;
        free(d);
        return;
    }
    if (d->next == NULL) // handle if the tail is to be deleted.
    {
        l->tail = p;
    }
    p->next = d->next;
    free(d);
}

list *sum_of_linked_lists(list *l1, list *l2)
{
    list *l = list_create();
    struct node *pp = l->head, *p1 = l1->head, *p2 = l2->head;
    int c = 0;
    while (p1 != NULL || p2 != NULL)
    {
        int p1d = p1 != NULL ? p1->data : 0;
        int p2d = p2 != NULL ? p2->data : 0;
        int i = p1d + p2d + c;
        c = i / 10;
        int d = i % 10;

        struct node *n = malloc(sizeof(struct node));
        n->data = d;
        n->next = NULL;

        if (l->head == NULL)
        {
            l->head = n;
        }
        else
        {
            pp->next = n;
        }
        l->tail = n;
        pp = n;
        if (p1 != NULL)
        {
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            p2 = p2->next;
        }
    }
    if (c > 0)
    {
        struct node *n = malloc(sizeof(struct node));
        n->data = c;
        n->next = NULL;
        pp->next = n;
        l->tail = n;
    }

    return l;
}
