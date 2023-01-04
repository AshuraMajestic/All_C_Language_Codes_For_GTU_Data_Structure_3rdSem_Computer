#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node * createNode(int data){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->left=NULL;
    p->right=NULL;
    p->data=data;
    return p;
}
int isBST(struct Node* root){
    static struct Node * prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left))
            return 0;
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev =root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct Node* searchIter(struct Node* root,int key){
    while(root!=NULL){
    if(root->data==key)
        return root;
    else if(root->data>key)
        root=root->left;
    else
        root=root->right;
    }
    return NULL;
}
int main(){
    /*
                 5
                / \
               3   6
              / \
             1   4
    */
    struct Node *p=createNode(5);
    struct Node *p1=createNode(3);
    struct Node *p2=createNode(6);
    struct Node *p3=createNode(1);
    struct Node *p4=createNode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    int key;
    printf("\n\nEnter the element you want to find in binary search tree:");
    scanf("%d",&key);
    if(isBST(p)){
        struct Node * n=searchIter(p,key);
        if(n==NULL){
            printf("\nKey Not found");
        }
        else
        printf("\nThe %d is present in the tree",n->data);       
    }
    else
        printf("\nThis is not a Binary serach tree");
    return 0;
}