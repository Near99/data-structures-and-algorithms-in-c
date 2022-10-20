/**
 * Priority Queue Implementation using Binary Heap.
 */
#include <stdio.h>
#include <stdlib.h>

#define P_QUEUE_TRUE 1
#define P_QUEUE_FALSE 0

typedef struct priority_queue
{
    int *queue;
    int size; // size n
    int capacity;
} Priority_Queue;

Priority_Queue *p_queue_create(int size);
void p_queue_insert(Priority_Queue *Q, int x);
int p_queue_find_min(Priority_Queue *Q);
void p_queue_delete_min(Priority_Queue *Q);
int p_queue_size(Priority_Queue *Q);
int p_queue_is_empty(Priority_Queue *Q);
int p_queue_is_full(Priority_Queue *Q);
int p_queue_parent(int index);
int p_queue_young_child(int index);
void p_queue_bubble_up(Priority_Queue *Q, int index);
/**
 * heapsort is nothing but an implementation of selection sort using the right data structre. 
 */
void heap_sort();

void pq_print(Priority_Queue *Q);

int main()
{
    Priority_Queue *q = p_queue_create(10);
    p_queue_insert(q, 10);
    p_queue_insert(q, 20);
    p_queue_insert(q, 25);
    p_queue_insert(q, 35);
    p_queue_insert(q, 13);
    p_queue_insert(q, 15);
    p_queue_insert(q, 18);
    p_queue_insert(q, 9);
    pq_print(q);
    return 0;
}

Priority_Queue *p_queue_create(int size)
{
    Priority_Queue *new_queue = malloc(sizeof(Priority_Queue));
    new_queue->queue = malloc(sizeof(int) * size);
    new_queue->size = 0;
    new_queue->capacity = size;
    for (int i = 0; i < size; i++)
    {
        new_queue->queue[i] = -1;
    }
    return new_queue;
}

int p_queue_find_min(Priority_Queue *Q)
{
    if (p_queue_is_empty(Q))
    {
        exit(EXIT_FAILURE);
    }
    return Q->queue[0];
}

void p_queue_insert(Priority_Queue *Q, int x)
{
    if (p_queue_is_full(Q))
    {
        printf("Queue is full!\n");
        exit(EXIT_FAILURE);
    }
    Q->queue[Q->size++] = x;
    p_queue_bubble_up(Q, Q->size - 1);
}

int p_queue_size(Priority_Queue *Q) { return Q->size; }

int p_queue_is_empty(Priority_Queue *Q) { return Q->size == 0 ? P_QUEUE_TRUE : P_QUEUE_FALSE; }

int p_queue_is_full(Priority_Queue *Q) { return Q->capacity == Q->size ? P_QUEUE_TRUE : P_QUEUE_FALSE; }

int p_queue_young_child(int index) { return ((2 * index) + 1); }

int p_queue_parent(int index)
{
    if (index == 0)
    {
        return (-1);
    }
    else
    {
        return ((index - 1) / 2);
    }
}

void p_queue_bubble_up(Priority_Queue *Q, int index)
{
    if (p_queue_parent(index) == -1)
    {
        return;
    }
    if (Q->queue[p_queue_parent(index)] > Q->queue[index])
    {
        int temp = Q->queue[p_queue_parent(index)];
        Q->queue[p_queue_parent(index)] = Q->queue[index];
        Q->queue[index] = temp;
        p_queue_bubble_up(Q, p_queue_parent(index));
    }
}

void pq_print(Priority_Queue *Q)
{
    for (int i = 0; i < Q->capacity; i++)
    {
        printf("%d\n", Q->queue[i]);
    }
}
