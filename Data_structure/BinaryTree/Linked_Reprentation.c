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
void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    /*
                 4
                / \
               1   6
              / \
             5   2
    */
    struct Node *p=createNode(4);
    struct Node *p1=createNode(1);
    struct Node *p2=createNode(6);
    struct Node *p3=createNode(5);
    struct Node *p4=createNode(2);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("\nPreOrder transversal:(root->left->right)\n");
    preorder(p);
    printf("\n\nPostOrder transversal:(left->right->root)\n");
    postorder(p);
    printf("\n\nInOrder transversal:(left->root->right)\n");
    inorder(p);
    return 0;
}