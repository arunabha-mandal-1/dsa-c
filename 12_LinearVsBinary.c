#include <stdio.h>

// linear search : sorted. unsorted
int linearSearch(int arr[], int size, int element){
    for(int i=0; i<size; i++){
        if(arr[i]==element){
            return i; // returns that indxe
        }
    }
    return -1; // if not found
}

// binary search : only sorted
int binarySearch(int arr[], int size, int element){
    int low=0, high=size-1, mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==element){
            return mid; // returns that index
        }else if(arr[mid]<element){
            low=mid+1;
        }else if(arr[mid]>element){
            high=mid-1;
        }
    }
    return -1;
}

// main func
int main(){

    printf("-----------------Linear Search-------------------\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 90}; // sorted array
    int size = sizeof(arr)/sizeof(arr[0]); // size of array
    int element = 90; // element we want to find

    int searchIndex = linearSearch(arr, size, element); // returns from linear search
    if(searchIndex==-1){
        printf("%d not found.\n", element);
    }else{
        printf("%d found at index %d\n", element, searchIndex);
    }

    printf("-----------------Binary Search-------------------\n");
    int searchIndexBinary = binarySearch(arr, size, element); // returns from binary search
    if(searchIndexBinary==-1){
        printf("%d not found.\n", element);
    }else{
        printf("%d found at index %d\n", element, searchIndex);
    }
    return 0;
}