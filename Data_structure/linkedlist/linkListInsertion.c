#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node * next;
};

//Inserting at first
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=head;
    return ptr;

}

//Inserting at End
struct Node* insertAtLast(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node* p=head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
};

//Case 3: Inserting between two node 
struct Node* insertatindex(struct Node* head,int index,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//Case 4: Inserting after NOde 
struct Node* insertAfterNode(struct Node* head,struct Node* address,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=address->next;
    address->next=ptr;
    
    return head;
}


void transverseLinkList(struct Node *ptr){
 while(ptr != NULL){
    printf("%d  ",ptr->data);
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
last=(struct Node*)malloc(sizeof(struct Node));

//Head element
head->data=33;
head->next=first;
//First Element
first->data=5;
first->next=second;
//Second Element
second->data=39;
second->next=last;
//Last Element
last->data=12;
last->next=NULL;
printf("\nLinkList before inertion: ");
transverseLinkList(head);
//head = insertAtFirst(head, 3);
//head = insertAtLast(head, 87);
//head = insertatindex(head,4, 100);
head = insertAfterNode(head,second, 99);
printf("\nLinkList after inertion: ");
transverseLinkList(head);
return 0;
}