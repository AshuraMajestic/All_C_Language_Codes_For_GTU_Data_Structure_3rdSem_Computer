#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Queue{
    struct Node *front,*rear;
};
struct Queue* createQueue(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(struct Queue* q,int val){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
        printf("Queue is Full!!!");
    else{
        temp->data=val;
        temp->next=NULL;
        if(q->front==NULL)
            q->front=q->rear=temp;
        else{
        q->rear->next=temp;
        q->rear=temp;
        }
    }
}
int dequeue(struct Queue* q){
    int val=0;
    struct Node* f=q->front;
    if(q->front==NULL)
        return -1;
    else{
        q->front=q->front->next;
        val=f->data;
        free(f);
    }
    return val;
}

void printQueue(struct Queue *ptr){
struct Node* n=ptr->front;
if(n==NULL){
    printf("\nQueue is Empty!!!");
}
else{
printf("\nQueue:");
 while(n != NULL){
    printf("%d ",n->data);
    n=n->next;
 }   
}
}

int main()
{
    struct Queue* q=createQueue();
    enqueue(q, 12);
    enqueue(q, 60);
    enqueue(q, 40);
    enqueue(q, 16);
    enqueue(q, 99);
    printQueue(q);
   dequeue(q);
   dequeue(q);
   dequeue(q);
   dequeue(q);
    printQueue(q);


}
