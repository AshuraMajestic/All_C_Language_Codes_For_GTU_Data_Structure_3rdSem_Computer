#include<stdio.h>
int linearSearch(int *arr, int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            printf("Element found at index: %d",i);
            return 1;
        }
    }
    printf("Element not found");
    return 0;
    
}
int binarySearch(int *arr, int size, int element){
    int low,high,mid;
    low=0;
    high=size-1;
    while(low<=high){
    mid= (low + high) / 2;
    if(arr[mid]==element){
        return mid;
    }
    if(arr[mid]<element){
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
    }
    return -1;
}

int main(){
    //int unSortedarr[]={1,45,65,3,2,66};
    int arr[]={1,22,34,57,66,89,200,289};
    //int size=sizeof(unSortedarr)/sizeof(int),element=3;
    int size=sizeof(arr)/sizeof(int),element=200;
    int searchIndex = binarySearch(arr,size,element);
    //linearSearch(unSortedarr,size,element);
    printf("\nThe element %d was found at index %d", element,searchIndex);
    return 0;
}