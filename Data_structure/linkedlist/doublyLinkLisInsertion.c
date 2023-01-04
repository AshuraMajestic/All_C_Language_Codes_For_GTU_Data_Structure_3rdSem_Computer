#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};


void transverseLinkListForward(struct Node *ptr){
 while(ptr != NULL){
    printf("%d  ",ptr->data);
    ptr=ptr->next;
 }   
}
void transverseLinkListBackward(struct Node *ptr){
 while(ptr != NULL){
    printf("%d  ",ptr->data);
    ptr=ptr->prev;
 }   
}
void transverseLinkListBoth(struct Node *ptr){
    struct Node* last;
 while(ptr!= NULL){
    printf("%d  ",ptr->data);
    last=ptr;
    ptr=ptr->next;
 }   
 while(last!=NULL){
    printf("%d  ",last->data);
    last=last->prev;
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
last=(struct Node*)malloc(sizeof(struct Node));

//Head element
head->prev = NULL;
head->data=33;
head->next=first;
//First Element
first->prev=head;
first->data=5;
first->next=second;
//Second Element
second->prev=first;
second->data=39;
second->next=last;
//Last Element
last->prev=second;
last->data=12;
last->next = NULL;
printf("\nLinkList Forward: ");
transverseLinkListForward(head);
printf("\nLinkList Backward: ");
transverseLinkListBackward(last);
printf("\nLinkList Both sides: ");
transverseLinkListBoth(head);
return 0;
}