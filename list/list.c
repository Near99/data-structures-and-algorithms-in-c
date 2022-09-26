/**
 * The list is simplest linked structure. The three basic operations supported 
 * by lists are searching, insertion, and deletion.
 * 
 * Can be used to implement other data structures: stacks, queues, hash tables.
 */

#include <stdio.h>
#include <stdlib.h>

typedef int data_type;

typedef struct list
{
    data_type item;
    struct list *next;
} list;

list *list_create(data_type value)
{
    list *l = (list *)malloc(sizeof(list));

    l->item = value;
    l->next = NULL;

    return l;
}

void list_insert(list **l, data_type x)
{
    list *new_list = (list *)malloc(sizeof(list));
    new_list->item = x;

    // Change head.
    new_list->next = *l;
    *l = new_list;
};

list *list_search(list *l, data_type x)
{
    if (l->next == NULL)
    {
        return (NULL);
    }

    if (l->item == x)
    {
        return l;
    }

    list_search(l->next, x);
}

void list_recursive(list *l)
{
    if (l == NULL)
    {
        return;
    }
    printf("%d\n", l->item);
    list_recursive(l->next);
}

void list_iterative(list *l)
{
    list *p = l;
    while (p != NULL)
    {
        printf("%d\n", p->item);
        p = p->next;
    }
}

data_type list_pop_front(list **l)
{
    if (*l == NULL)
    {
        exit(-1);
    }

    list *p = *l;
    data_type r = (*l)->item;
    p = (*l)->next;
    free(*l);
    *l = p;

    return r;
}

void list_delete(list **l, data_type x)
{
    // if ((*l)->next == NULL)
    // {
    //     free(*l);
    //     *l = NULL;
    //     return;
    // }

    list *p = *l; // pred
    list *d = *l; // node to be delete

    // 1225 -> 225 -> 23 -> 10 -> null
    while (p != NULL)
    {
        // why does the programm get terminated when p-> is NULL and make a comparation?
        if (p->next != NULL && p->next->item == x)
        {
            break;
        }
        p = p->next;
    }

    while (d != NULL)
    {
        if (d->item == x)
        {
            break;
        }
        else
        {
            d = d->next;
        }
    }

    if (p == NULL)
    {
        *l = d->next;
    }
    else
    {
        p->next = d->next;
    }

    free(d);
}

int main()
{
    list *l = list_create(10);

    list_insert(&l, 23);
    list_insert(&l, 225);
    list_insert(&l, 1225);

    // list_delete(&l, 225);
    // list_delete(&l, 23);
    list_delete(&l, 10);
    // list_delete(&l, 1225);

    list_iterative(l);

    // printf("%p\n", l);

    return 0;
}