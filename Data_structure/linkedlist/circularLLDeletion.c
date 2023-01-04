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
//Delete at first
struct Node * deleteAtFirst(struct Node *head){
    struct Node * ptr=head;
    struct Node* p=head;
    do{
        p=p->next;
    }while(p->next!=head);
    p->next=head->next;
    head=p->next;
    free(ptr);
    return head;
}

//Delete at End
struct Node* deleteAtLast(struct Node* head)
{
    struct Node* p=head;
    struct Node* ptr=head->next;
    do{
        ptr=ptr->next;
        p=p->next;
    }while(ptr->next!=head);
    p->next=head;
    free(ptr);
    return head;
};

//Case 3: Deleting between two node 
struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* ptr=head;
    struct Node* p=head->next;
    int i=1;
    do{
        p=p->next;
        ptr=ptr->next;
        i++;
    }while(i!=index-1);
    ptr->next=p->next;
    free(p);
    return head;
}

//Case 4: Deleting after NOde 
struct Node* deleteAfterNode(struct Node* head,struct Node* address){
    struct Node* ptr=head;
    struct Node* p=head->next;
    while(p!=address->next){
        p=p->next;
        ptr=ptr->next;
    }
    ptr->next=p->next;
    free(p);
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
//head=deleteAtFirst(head);
//head = deleteAtLast(head);
//head = deleteAtIndex(head, 3);
head = deleteAfterNode(head,third);
printf("\nCicular link list after insertion:\n");
transverseCircularLinkList(head);
return 0;
}