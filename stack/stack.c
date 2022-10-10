#include "stack.h"

Stack stack_create()
{
    Stack new_stack = NULL;
    return new_stack;
}

void stack_push(Stack *stack, int data)
{
    struct stack_node *new_node = malloc(sizeof(struct stack_node));
    new_node->data = data;
    if ((*stack) == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
        return;
    }
    new_node->next = *stack;
    *stack = new_node;
}

int stack_pop(Stack *stack)
{
    if (*stack == NULL)
    {
        printf("Empty stack!\n");
        exit(EXIT_FAILURE);
    }
    int data = (*stack)->data;
    Stack f = *stack;
    if ((*stack)->next == NULL)
    {
        *stack = NULL;
    }
    else
    {
        *stack = (*stack)->next;
    }
    free(f);
    return data;
}

int stack_top(Stack stack)
{
    if (stack == NULL)
    {
        printf("Empty stack!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data;
}

int stack_is_empty(Stack stack)
{
    return stack == NULL ? STACK_TRUE : STACK_FALSE;
}

int balanced_brackets(const char *string, int size)
{
    Stack s = stack_create();
    for (int i = 0; i < size; i++)
    {
        const char b = *(string + i);
        if (b == '(' || b == '{' || b == '[')
        {
            stack_push(&s, (int)b);
        }
        else if (b == ')' || b == '}' || b == ']')
        {
            if (stack_is_empty(s) || (b - stack_pop(&s)) > 2) // use ascii to check if the brackets are pairs.
            {
                return STACK_FALSE;
            }
        }
    }
    return stack_is_empty(s) ? STACK_TRUE : STACK_FALSE;
}

int *next_greater_element(int *arr, int size)
{
    if (size == 0)
    {
        return arr;
    }
    int *res = malloc(sizeof(int) * size);
    for (int j = 0; j < size; j++)
    {
        res[j] = -1;
    }
    Stack s = stack_create();
    stack_push(&s, *arr);
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > stack_top(s))
        {
            while (!stack_is_empty(s) && stack_top(s) < arr[i])
            {
                int idx;
                int k = stack_pop(&s);
                // couldn't come up a better way to get the index :(
                for (int j = 0; j < size; j++)
                {
                    if (arr[j] == k)
                    {
                        idx = (arr + j) - arr;
                    }
                }
                res[idx] = arr[i];
            }
            stack_push(&s, *(arr + i));
        }
        else
        {
            stack_push(&s, *(arr + i));
        }
    }
    return res;
}
