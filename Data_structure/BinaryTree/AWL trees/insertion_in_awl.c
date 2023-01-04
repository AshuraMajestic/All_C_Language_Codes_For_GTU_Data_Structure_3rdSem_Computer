#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *left,*right;
    int height;
};
int max(int a, int b){
    return a>b?a:b;
}
int getHeight(struct Node * root){
    if(root==NULL)
        return 0;
    return root->height;
}
struct Node * createNode(int key){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->height=1;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int getBalanceFactor(struct Node* root ){
    if(root==NULL)
        return 0;
    return (getHeight(root->left))-(getHeight(root->right));
}
struct Node* leftRotate(struct Node* x){
    struct Node* y=x->right;
    struct Node* T2=y->left;

    y->left=x;
    x->right=T2;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    return y;
}
struct Node* rightRotate(struct Node* y){
    struct Node* x=y->left;
    struct Node* T2=x->right;

    x->right=y;
    y->left=T2;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    return x;
}
struct Node* insert(struct Node* root,int key){
    if (root == NULL)
        return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        printf("Duplicate key cannot be inserted");
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    int BF=getBalanceFactor(root);
        //LL rotation
        if(BF>1 && key<root->left->data)
            return rightRotate(root);
        //RR rotation
        if(BF<-1 && key>root->right->data)
            return leftRotate(root);
        //LR rotation
        if(BF>1 && key>root->left->data){
            root->left=leftRotate(root->left);
            return rightRotate(root);
            }
        //RL rotation
        if(BF<-1 && key<root->right->data){
            root->right=rightRotate(root->right);
            return leftRotate(root);
            }
    return root;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root=NULL;
    root=insert(root,1);
    root=insert(root,12);
    root=insert(root,34);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,8);
    root=insert(root,0);
    inorder(root);
    /*
    Insert 1
                1
    Insert 12
                1
                 \
                 12
    Insert 34 and RR rotation
                 1                                   12
                  \                                 /  \
                  12     <-Left rotation->         1   34
                    \
                    34
    Insert 2
                    12      
                   /  \                             
                  1   34     
                   \                                 
                    2                           
     
    Insert 6 and RR Roation
                    12                                  12
                   /  \                                /  \
                  1   34  <- left rotation->          2   34
                   \                                 / \
                    2                               1   6
                     \
                      6        
    Insert 8  no rotationon
            12
           /  \
          2   34
         / \
        1   6
             \
              8
    Insert 0
            12
           /  \
          2   34
         / \
        1   6
       /     \
      0       8
      

    */
    return 0;
}