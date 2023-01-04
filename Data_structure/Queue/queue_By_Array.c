#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
};
struct queue *createQueue(int size)
{
    struct queue *p = (struct queue *)malloc(sizeof(struct queue));
    p->size = size;
    p->front = -1;
    p->rear = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));
    return p;
}

int isFull(struct queue *ptr)
{
    return ptr->rear == ptr->size - 1;
}
int isEmpty(struct queue *ptr)
{
    return ptr->front == ptr->rear;
}

struct queue *enqueue(struct queue *nice, int val)
{
    if (isFull(nice))
        return 0;
    else
    {
        nice->arr[++nice->rear] = val;
        return nice;
    }
}
struct queue *dequeue(struct queue *nice)
{
    if (isEmpty(nice))
        return 0;
    else
    {
        nice->arr[nice->front++];
        return nice;
    }
}
void printQueue(struct queue *line)
{
    if (isEmpty(line))
    {
        printf("\nQueue is Empty");
    }
    else if (isFull(line))
    {
        printf("Stack is Full");
    }
    else
    {
        printf("\nQueue: ");
        for (int i = line->front + 1; i <= line->rear; i++)
        {
            printf("%d ", line->arr[i]);
        }
    }
}

int main()
{
    struct queue *line = createQueue(10);
    enqueue(line, 12);
    enqueue(line, 14);
    printQueue(line);
    enqueue(line, 16);
    enqueue(line, 18);
    enqueue(line, 20);
    printQueue(line);
    dequeue(line);
    dequeue(line);
    dequeue(line);
    printQueue(line);
    dequeue(line);
    dequeue(line);
    dequeue(line);
    printQueue(line);
    return 0;
}