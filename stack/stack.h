#include <stdio.h>
#include <stdlib.h>

#ifndef __PROJECT__STACK_LINKED_LIST_H__
#define __PROJECT__STACK_LINKED_LIST_H__
#define STACK_TRUE 1
#define STACK_FALSE 0

struct stack_node
{
    int data;
    struct stack_node *next;
};

typedef struct stack_node *Stack;

Stack stack_create();
void stack_push(Stack *stack, int data);
int stack_pop(Stack *stack);
int stack_top(Stack stack);
int stack_is_empty(Stack stack);
int balanced_brackets(const char *string, int size);

#endif