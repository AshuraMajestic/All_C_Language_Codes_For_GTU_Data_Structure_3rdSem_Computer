#include<stdio.h>

int printArray( int* A, int k){
    for(int i=0;i<k;i++){
        printf("%d ",A[i]);
    }
}

int partition(int* A,int low ,int high)
{
    int temp;
    int pivot = A[low];
    int i = low+1;
    int j = high;
do{
    while(A[i]<=pivot){
        i++;
    }
    while(A[j]>pivot){
        j--;
    }
    if(i<j){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
}while(i<j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSort(int* A, int low, int high){
    int partitionIndex;
    if(low<high){
    partitionIndex=partition(A, low, high);
    quickSort(A, low, partitionIndex-1);
    quickSort(A, partitionIndex+1, high);
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
   quickSort(A,0,k-1);
 printf("\n\nArray after sorting:");

   printArray(A,k);
    return 0;
}