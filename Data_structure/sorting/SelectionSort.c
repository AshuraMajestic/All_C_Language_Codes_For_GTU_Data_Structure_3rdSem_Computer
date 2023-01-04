#include<stdio.h>

int printArray( int* A, int k){
    for(int i=0;i<k;i++){
        printf("%d ",A[i]);
    }
}
int selectionSort(int* A, int k){
    int temp,lowestIndex;
    for(int i=0; i<k; i++){
        lowestIndex=i;
        for(int j=i+1; j<k;j++){
            if(A[j]<A[lowestIndex]){
                lowestIndex=j;
            }
            temp=A[lowestIndex];
            A[lowestIndex]=A[i];
            A[i]=temp;
        }
    }
}


int main(){
   int A[30];
   int k;
   printf("Enter the size of array:");
   scanf("%d",&k);
   printf("\n\nEnter the elemensts of array:");
   for(int i=0;i<k;i++){
    printf("\n[%d]:",i+1);
    scanf("%d",&A[i]);
   }
    printf("\nArray before sorting:");
   printArray(A,k);
   selectionSort(A,k);
    printf("\n\nArray after sorting:");
   printArray(A,k);
    return 0;
}