#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void transverseLinkList(struct Node *ptr){
 while(ptr != NULL){
    printf("Element:%d \n",ptr->data);
    ptr=ptr->next;
 }   
}
int isEmpty(struct Node* top){
    return top==NULL;
}
int isFull(struct Node* top){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    return p==NULL;
}
struct Node* push(struct Node* top,int val){
    if(isFull(top)){
        printf("Stack Overflown!!!");
    }
    else{
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=val;
    p->next=top;
    top=p;
    return top;
    }
    }
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow!!!");
    }
    else{
    struct Node* p=*top;
    *top=(*top)->next;
    int k=p->data;
    free(p);
    return k;
    }

}

int main(){
    struct Node* top=NULL;
    top=push(top,12);
    top=push(top,33);
    top=push(top,46);
    top=push(top,57);
    top=push(top,87);
    top=push(top,98);
    top=push(top,100);
    printf("popped item %d\n",pop(&top));
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    transverseLinkList(top);
    return 0;
}