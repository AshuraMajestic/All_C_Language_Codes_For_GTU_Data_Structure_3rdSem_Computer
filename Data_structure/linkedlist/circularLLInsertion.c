#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int transverseCircularLinkList(struct Node *head){
    struct Node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }  while(ptr != head); 
}
//Inserting at first
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    ptr->data=data;
    p=head;
    do{
        p=p->next;
    }while(p->next!=head);
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

//Inserting at End
struct Node* insertAtLast(struct Node* head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    p=head;
    do{
        p=p->next;
    }while(p->next!=head);
    p->next=ptr;
    ptr->next=head;
    return head;
};

//Case 3: Inserting between two node 
struct Node* insertatindex(struct Node* head,int index,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=1;
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



int main(){
struct Node* head;
struct Node* second
;
struct Node* third
;
struct Node* fourth
;
struct Node* last;

head=(struct Node*)malloc(sizeof(struct Node));
second
=(struct Node*)malloc(sizeof(struct Node));
third
=(struct Node*)malloc(sizeof(struct Node));
fourth
=(struct Node*)malloc(sizeof(struct Node));
last=(struct Node*)malloc(sizeof(struct Node));

//Head element
head->data=33;
head->next=second;
//First Element
second->data=5;
second->next=third;
//Second Element
third->data=39;
third->next=fourth;
//Third Element
fourth->data=21;
fourth->next=last;
//Last Element
last->data=12;
last->next=head;
printf("\nCicular link list before insertion:\n");
transverseCircularLinkList(head);
//head=insertAtFirst(head,0);
head = insertAtLast(head,99);
//head = insertatindex(head, 3 ,30);
//head = insertAfterNode(head,third,40);
printf("\nCicular link list after insertion:\n");
transverseCircularLinkList(head);
return 0;
}