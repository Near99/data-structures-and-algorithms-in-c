#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define QUEUE_TRUE 1
#define QUEUE_FALSE 0

typedef struct queue
{
    int capacity;
    int size;
    int front;
    int rear;
    int *queue;
} Queue;

Queue *queue_create(int capacity);
void queue_enqueue(Queue *q, int value);
int queue_dequeue(Queue *q);
int queue_size(Queue *q);
int queue_empty(Queue *q);
int queue_full(Queue *q);
void queue_destory(Queue *q);

void queue_print_queue_status(Queue *q)
{
    printf("----------------\n");
    printf("Capacity: %d\n", q->capacity);
    printf("Size: %d\n", q->size);
    printf("Front: %d\n", q->front);
    printf("Rear: %d\n", q->rear);
    printf("----------------\n");
}

void queue_print_value(Queue *q)
{
    for (int i = 0; i < q->capacity; i++)
    {
        printf("%d\n", q->queue[i]);
    }
}

void test_all()
{
    clock_t begin = clock();
    printf("Running all the tests...\n");
    const int LENGTH = 10000000;
    Queue *q = queue_create(LENGTH);
    assert(q->capacity == LENGTH && q->size == 0 && q->front == 0 && q->rear == 0);
    assert(queue_empty(q) == QUEUE_TRUE);
    assert(queue_full(q) == QUEUE_FALSE);
    printf("Test Case: queue_create() - Passed.\n");
    for (int i = 0; i < LENGTH; i++)
    {
        queue_enqueue(q, i + 1);
    }
    assert(q->capacity == LENGTH && q->size == LENGTH && q->front == 0 && q->rear == 0);
    assert(queue_empty(q) == QUEUE_FALSE);
    assert(queue_full(q) == QUEUE_TRUE);
    for (int i = 0; i < LENGTH / 2; i++)
    {
        assert(queue_dequeue(q) == i + 1);
    }
    assert(q->capacity == LENGTH && q->size == (LENGTH / 2) && q->front == (LENGTH / 2) && q->rear == 0);
    for (int i = 0; i < LENGTH / 2; i++)
    {
        queue_enqueue(q, 899);
    }
    assert(queue_empty(q) == QUEUE_FALSE);
    assert(queue_full(q) == QUEUE_TRUE);
    printf("Test Case: queue_empty() - Passed.\n");
    printf("Test Case: queue_full() - Passed.\n");
    for (int i = LENGTH / 2; i < LENGTH; i++)
    {
        assert(queue_dequeue(q) == i + 1);
    }
    assert(q->capacity == LENGTH && q->size == (LENGTH / 2) && q->front == 0 && q->rear == (LENGTH / 2));
    for (int i = LENGTH / 2; i < LENGTH; i++)
    {
        assert(queue_dequeue(q) == 899);
    }
    assert(q->capacity == LENGTH && q->size == 0 && q->front == (LENGTH / 2) && q->rear == (LENGTH / 2));
    printf("Test Case: queue_dequeue() - Passed.\n");
    queue_destory(q);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
}

int main()
{
    test_all();

    return 0;
}

Queue *queue_create(int capacity)
{
    Queue *q = malloc(sizeof(Queue));
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    q->queue = malloc(sizeof(int) * capacity);
    return q;
}

void queue_enqueue(Queue *q, int value)
{
    if (queue_full(q))
    {
        printf("Full capacity!\n");
        exit(EXIT_FAILURE);
    }
    q->queue[q->rear++] = value;
    q->size++;
    if (q->rear == q->capacity)
    {
        q->rear = 0;
    }
}

int queue_dequeue(Queue *q)
{
    if (queue_empty(q))
    {
        printf("Empty queue!\n");
        exit(EXIT_FAILURE);
    }
    int value = q->queue[q->front++];
    q->size--;
    if (q->front == q->capacity)
    {
        q->front = 0;
    }
    return value;
}

int queue_size(Queue *q)
{
    return q->size;
}

int queue_empty(Queue *q)
{
    return q->size == 0 ? QUEUE_TRUE : QUEUE_FALSE;
}

int queue_full(Queue *q)
{
    return q->size == q->capacity ? QUEUE_TRUE : QUEUE_FALSE;
}

void queue_destory(Queue *q)
{
    free(q->queue);
    free(q);
}
