#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node* next;
};

int transverseLinkList(struct Node *ptr){
 while(ptr != NULL){
    printf("Element:%d \n",ptr->data);
    ptr=ptr->next;
 }   
}

int main(){
struct Node* head;
struct Node* first;
struct Node* second;
struct Node* third;
struct Node* last;

head=(struct Node*)malloc(sizeof(struct Node));
first=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));
last=(struct Node*)malloc(sizeof(struct Node));

//Head element
head->data=33;
head->next=first;
//First Element
first->data=5;
first->next=second;
//Second Element
second->data=39;
second->next=third;
//Third Element
third->data=21;
third->next=last;
//Last Element
last->data=12;
last->next=NULL;
transverseLinkList(head);
return 0;
}