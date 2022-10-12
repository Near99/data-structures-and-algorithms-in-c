#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define QUEUE_TRUE 1
#define QUEUE_FALSE 0

struct queue_node
{
    int item;
    struct queue_node *next;
};

typedef struct Queue
{
    struct queue_node *head;
    struct queue_node *tail;
} Queue;

Queue *queue_create();
void queue_enqueue(Queue *q, int value);
int queue_dequeue(Queue *q);
int queue_empty(Queue *q);
void queue_destory(Queue *q);
void _queue_iterate(struct queue_node *node);

int main()
{
    clock_t begin = clock();
    printf("Running all the tests...\n");
    Queue *q = queue_create();
    const int LOOP_F = 10000000;
    assert(queue_empty(q) == QUEUE_TRUE);
    for (int i = 0; i < LOOP_F; i++)
    {
        queue_enqueue(q, i + 1);
    }
    printf("Test Case: queue_enqueue() - Passed.\n");
    assert(queue_empty(q) == QUEUE_FALSE);
    for (int i = 0; i < LOOP_F; i++)
    {
        assert(queue_dequeue(q) == i + 1);
    }
    printf("Test Case: queue_dequeue() - Passed.\n");
    assert(queue_empty(q) == QUEUE_TRUE);
    printf("Test Case: queue_empty() - Passed.\n");
    queue_destory(q);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    return 0;
}

Queue *queue_create()
{
    Queue *q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue *q, int value)
{
    struct queue_node *new_node = malloc(sizeof(struct queue_node));
    new_node->item = value;
    new_node->next = NULL;
    if (q->head == NULL)
    {
        q->head = new_node;
    }
    if (q->tail != NULL)
    {
        q->tail->next = new_node;
    }
    q->tail = new_node;
}

int queue_dequeue(Queue *q)
{
    if (q->head == NULL)
    {
        printf("Empty queue!\n");
        exit(EXIT_FAILURE);
    }
    int data = q->head->item;
    struct queue_node *head = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(head);
    return data;
}

int queue_empty(Queue *q)
{
    return q->head == NULL ? QUEUE_TRUE : QUEUE_FALSE;
}

void queue_destory(Queue *q)
{
    struct queue_node *p = NULL, *c = q->head;
    while (c != NULL)
    {
        p = c;
        c = c->next;
        free(p);
    }
    free(q);
}

void _queue_iterate(struct queue_node *node)
{
    if (node == NULL)
        return;
    printf("%d\n", node->item);
    _queue_iterate(node->next);
}
