#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int printArray(int *A, int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("%d ", A[i]);
    }
}
int maximum(int *A, int k)
{
    int max = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void countSort(int *A, int k)
{
    int i,j;
    int max = maximum(A, k);
    int *count = (int *)calloc(max+1,sizeof(int));
    for(i=0;i<k;i++){
        count[A[i]]++;
    }
    i=0;
    j=0;
    while(i<=max){
        if(count[i]>0){
            A[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
    free(count);
}
int main()
{
    int A[30];
    int k;
    printf("Enter the size of array:");
    scanf("%d", &k);
    printf("\n\nEnter the elemensts of array:");
    for (int i = 0; i < k; i++)
    {
        printf("\n[%d]:", i + 1);
        scanf("%d", &A[i]);
    }
    printf("\nArray before sorting:");
    printArray(A, k);
    countSort(A, k);
    printf("\n\nArray after sorting:");
    printArray(A, k);
    return 0;
}