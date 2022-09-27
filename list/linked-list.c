#include <stdio.h>
#include <stdlib.h>

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
void liset_insert_by_index(list *, int, data_type);
int list_empty(list *);
int list_size(list *);

// todos...
void list_reverse(list *);

int main()
{
    list *my_list = list_create();

    for (int i = 0; i < 10; i++)
    {
        list_insert_front(my_list, i + 1);
    }

    list_traverse(my_list);

    printf("\n");

    list_reverse(my_list);

    printf("\n");

    list_traverse(my_list);

    list_destory(my_list);

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

    l->tail->next = new_node;
    l->tail = new_node;
}

data_type list_pop_front(list *l)
{
    struct node *p = l->head;
    data_type r = p->data;

    l->head = p->next;
    free(p);

    return r;
}

data_type list_pop_back(list *l)
{
    struct node **p = &l->head;
    data_type r = l->tail->data;

    while ((*p)->next != l->tail)
    {
        p = &(*p)->next;
    }

    (*p)->next = NULL;
    free(l->tail);
    l->tail = *p;

    return r;
}

void liset_insert_by_index(list *l, int index, data_type value)
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

    // printf("prev %d\n", p->data);
    // printf("curr %d\n", (*c)->data);
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
    l->tail = l->head;
    struct node *prev = NULL, *curr = l->head, *next;
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
