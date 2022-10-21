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
int p_queue_extract_min(Priority_Queue *Q);
int p_queue_size(Priority_Queue *Q);
int p_queue_is_empty(Priority_Queue *Q);
int p_queue_is_full(Priority_Queue *Q);
int p_queue_parent(int index);
int p_queue_young_child(int index);
void p_queue_bubble_up(Priority_Queue *Q, int index);
void p_queue_bubble_down(Priority_Queue *Q, int index); // percolate down operation also called heapify
/**
 * heapsort is nothing but an implementation of selection sort using the right data structre. 
 */
void heap_sort(int s[], int n);
void make_heap(Priority_Queue *Q, int s[], int n);
void pq_print(Priority_Queue *Q);

int main()
{
    Priority_Queue *q = p_queue_create(10);
    int arr[] = {200, 2, 19, 55, 70, 34, 28, 25, 66, 44};
    int heapsort[10];
    make_heap(q, arr, 10);
    for (int i = 0; i < 10; i++)
    {
        heapsort[i] = p_queue_extract_min(q);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", heapsort[i]);
    }
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

int p_queue_extract_min(Priority_Queue *Q)
{
    if (p_queue_is_empty(Q))
    {
        printf("Empty queue!\n");
        exit(EXIT_FAILURE);
    }
    int min = Q->queue[0];
    Q->queue[0] = Q->queue[--Q->size];
    p_queue_bubble_down(Q, 0);
    return min;
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

void p_queue_bubble_down(Priority_Queue *Q, int p)
{
    // min
    int m = p;
    // child
    int c = p_queue_young_child(m);
    // loop twich to find which child is smaller.
    for (int i = 0; i <= 1; i++)
    {
        if ((c + i) < Q->size) // boundary check.
        {
            if (Q->queue[m] > Q->queue[c + i])
            {
                m = c + i;
            }
        }
    }
    if (m != p)
    {
        int temp = Q->queue[m];
        Q->queue[m] = Q->queue[p];
        Q->queue[p] = temp;
        p_queue_bubble_down(Q, m);
    }
}

void pq_print(Priority_Queue *Q)
{
    for (int i = 0; i < Q->capacity; i++)
    {
        printf("%d\n", Q->queue[i]);
    }
}

void make_heap(Priority_Queue *Q, int s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p_queue_insert(Q, s[i]);
    }
}
