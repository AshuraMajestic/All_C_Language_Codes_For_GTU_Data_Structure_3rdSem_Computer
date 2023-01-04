#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
};


int isFull(struct queue *ptr)
{
    return ptr->rear == ptr->size - 1;
}
int isEmpty(struct queue *ptr)
{
    return ptr->front == ptr->rear;
}

void enqueue(struct queue *nice, int val)
{
    if (isFull(nice))
        printf("This Queue is full\n;");
    else
    {
        nice->arr[++nice->rear] = val;
    }
}
int dequeue(struct queue *nice)
{
    int a=-1;
    if (isEmpty(nice))
        printf("This queue is empty\n");
    else
    {
        a=nice->arr[++nice->front];
        
    }
    return a;
}

int main()
{

    /* GIVEN GRAPH
             0------1
             |  \  |
             |   \ |
             3-----2
              \   /
               \ /
                4
               / \
              /   \
             5     6 
    */
    struct queue explore;
    explore.front=explore.rear=0;
    explore.size=40;
    explore.arr=(int*)malloc(explore.size*sizeof(int));
    int node;
    int i=1;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    } ;
    printf("%d",i);
    visited[i]=1;
    enqueue(&explore,i);
    while(!isEmpty(&explore)){
        node=dequeue(&explore);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf(" %d",j);
                visited[j]=1;
                enqueue(&explore,j);
            }
        }    
            }
    return 0;
}