#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    char* arr;
};
struct Stack* createStack(unsigned capacity){
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->capacity = capacity;
    sp->top = -1;
    sp->arr=(char*)malloc(sp->capacity * sizeof(char));
    return sp;
}
int isFull(struct Stack* sp){
    return sp->top == sp->capacity;
}
int isEmpty(struct Stack* sp){
    return sp->top == -1;
}
void push(struct Stack* sp,char val){
    if(isFull(sp))
        printf("Stack Overflow!Cannot push item");
    else
        sp->arr[++sp->top] = val;
}
char pop(struct Stack* sp){
    if(isEmpty(sp))
        printf("Stack Underflow!Cannot pop item");
    else
        return sp->arr[sp->top--];
}
void reverse(char* str)
{
int n=strlen(str);
struct Stack* sp = createStack(n);
for (int i = 0; i < n; i++)
    push(sp,str[i]);

for(int i=0;i<n;i++)
    str[i] = pop(sp);
}
int main(){
    char str[30];
    printf("Enter string to reverse:");
    gets(str);
    reverse(str);
    printf("Reversed String: %s",str);
    return 0;
}