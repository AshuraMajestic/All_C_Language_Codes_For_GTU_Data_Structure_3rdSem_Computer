#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node * next;
};

//Delete at first
struct Node * deleteAtFirst(struct Node *head){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr=head;
    head=head->next;
    free(ptr);
    return head;

}

//Delete at End
struct Node* deleteAtLast(struct Node* head)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    p=head->next;
    while(p->next!=NULL){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=NULL;
    free(p);
    return head;
};

//Case 3: Deleting between two node 
struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    p=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        ptr=ptr->next;
        i++;
    }
    ptr->next=p->next;
    free(p);
    return head;
}

//Case 4: Deleting after NOde 
struct Node* deleteAfterNode(struct Node* head,struct Node* address){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    p=head->next;
    while(p!=address->next){
        p=p->next;
        ptr=ptr->next;
    }
    ptr->next=p->next;
    free(p);
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
printf("\nLinkList before deletion: ");
transverseLinkList(head);
//head = deleteAtFirst(head);
//head = deleteAtLast(head);
//head = deleteAtIndex(head,2);
//head = deleteAfterNode(head,first);
printf("\nLinkList after deletion: ");
transverseLinkList(head);
return 0;
}