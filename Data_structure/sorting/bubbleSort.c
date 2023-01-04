#include<stdio.h>

int printArray( int* A, int k){
    for(int i=0;i<k;i++){
        printf("%d ",A[i]);
    }
}
void bubbleSort(int* A, int k){
    int temp;
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
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
   bubbleSort(A,k);
 printf("\n\nArray after sorting:");

   printArray(A,k);

}