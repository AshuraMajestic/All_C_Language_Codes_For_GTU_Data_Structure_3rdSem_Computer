#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int front;
    int rear;
    int size;
    int *arr;
};

struct circularQueue *createQueue(int size)
{
    struct circularQueue *p = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    p->size = size;
    p->front = -1;
    p->rear = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));
    return p;
}

int isFull(struct circularQueue *ptr)
{
    return (ptr->rear + 1) % ptr->size == ptr->front;
}
int isEmpty(struct circularQueue *ptr)
{
    return ptr->rear == ptr->front;
}

struct circularQueue *encircularQueue(struct circularQueue *nice, int val)
{
    if (isFull(nice))
        return 0;
    else
    {
        nice->rear = (nice->rear + 1) % nice->size;
        nice->arr[nice->rear] = val;
        return nice;
    }
}
struct circularQueue *decircularQueue(struct circularQueue *nice)
{
    if (isEmpty(nice))
        return 0;
    else
    {
        nice->front = (nice->front + 1) % nice->size;
        return nice;
    }
}
void printQueue(struct circularQueue *line)
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
    struct circularQueue *line = createQueue(10);
    encircularQueue(line, 12);
    encircularQueue(line, 14);
    encircularQueue(line, 16);
    encircularQueue(line, 18);
    encircularQueue(line, 20);
    printQueue(line);
    decircularQueue(line);
    decircularQueue(line);
    decircularQueue(line);
    decircularQueue(line);
    decircularQueue(line);
    decircularQueue(line);
    printQueue(line);
    return 0;
}