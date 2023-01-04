#include<stdio.h>
void display(int arr[],int n){
    //Traversal: Visiting every element of array
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
//code for insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return size+1;
}
int indDeletion(int arr[], int size, int index){
//code for Deletion
    if(size<0){
        return -1;
    }
    for (int i = index; i <= size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return size-1;
}

int main(){
    int arr[100]={1, 2, 6, 46,65,43};
    int size=6,element=26,index=3;
    display(arr,size);
    size=indInsertion(arr, size, element, 100, index);   
    display(arr,size);
    size=indDeletion(arr,size,4);
    display(arr,size);
    return 0;
}