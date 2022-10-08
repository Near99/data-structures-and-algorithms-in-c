#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H
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

#endif