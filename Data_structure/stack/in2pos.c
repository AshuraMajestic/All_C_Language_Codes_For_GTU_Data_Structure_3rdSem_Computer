#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr){
    if (ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr,char val){
    if(isFull(ptr)){
        printf("Stack Overflow! cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!Cannot pop fromn the stack\n");
    }
    else{
        char val =ptr->arr[ptr->top];
        ptr->top--;
         return val;
    }
}

int precedence(char ch){
    if(ch=='('){
        return 5;
    }
    else if(ch==')'){
        return 4;
    }
    else if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-' ){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

char* infix2Postfix(char* infix){
    struct stack * sp =(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr= (char *)malloc(sp->size*sizeof(char));
    char * postfix= (char *)malloc((strlen(infix)+1)* sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char infix[30];
    printf("Please Enter the infix expression:");
    gets(infix);
    printf("postfix is %s",infix2Postfix(infix));
    return 0;
}
