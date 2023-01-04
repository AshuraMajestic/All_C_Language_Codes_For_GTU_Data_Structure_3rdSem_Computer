//Implementing stack by array
#include<stdio.h>
#include<stdlib.h>
//intiallizing stack
struct stack{
    int top;
    int size;
    int *arr;
};
//peek or stack top
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int peek(){}

int isEmpty(struct stack* p){
    return p->top==-1;
}
int isFull(struct stack* p){
    return p->top==p->size-1; 
}
void push(struct stack* p,int value){
    if(isFull(p))
        printf("Stack Overflow!!");
    else
        p->arr[++p->top]=value;
} 
int pop(struct stack* p){
    return isEmpty(p)?printf("Stack Underflow"):p->arr[p->top--];
}


int main(){
    struct stack * p = (struct stack*)malloc(sizeof(struct stack));
    p->size=10;
    p->top=-1;
    p->arr=(int*)malloc(p->size*sizeof(int));
    push(p,12);
    push(p,33);
    push(p,45);
    push(p,99);
    pop(p);
    printf("Element is found at: %d",stackTop(p));
    for(int i=p->top;i>-1;i--){
        printf("\n Element:%d",p->arr[i]);
    }
    return 0;
}