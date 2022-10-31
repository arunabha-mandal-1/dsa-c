#include <stdio.h>
// display array elements
void display(int arr[], int size){
    // traversal
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 01. insertion at a particular index
int indexInsertion(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity){
        return -1; // failure status
    }
    // shifting elements
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element; // inserting
    return 1; // success status
}

// 02. insertion in an sorted(ascending) array
int sortedInsertion(int arr[], int size, int element, int capacity){
    if(size>=capacity){
        return -1; // failure status
    }
    // shifting elements
    int i=size-1;
    for(i; (i>=0 && arr[i]>element); i--){
        arr[i+1]=arr[i];
    }
    // inserting
    arr[i+1]=element;
    return 1;
}

// program starts here
int main(){
    // 01
    int arr[100] = {7, 8, 12, 27, 88, 102, 125, 226};
    // printf("%d\n", sizeof(arr)); // 400
    int size=8, element=45, index=3, capacity=sizeof(arr)/sizeof(arr[0]);
    display(arr, size); // before inserting
    int flag = indexInsertion(arr, size, element, capacity, index);
    if(flag==1){
        printf("Insertion successful! Modified array > \n");
        size=size+1;
        display(arr, size); // after inserting
    }else if(flag==-1){
        printf("Insertion failed\n");
    }
    
    // 02
    printf("---------------------------------------------------\n");
    int arrSorted[50] = {1, 2, 4, 5, 6, 7};
    size=6; element=3; capacity=sizeof(arrSorted)/sizeof(arrSorted[0]);
    display(arrSorted, size);
    int flagSorted=sortedInsertion(arrSorted, size, element, capacity);
    if(flagSorted==1){
        printf("Sorted Insertion successful! Modified array > \n");
        size=size+1;
        display(arrSorted, size); // after inserting
    }else if(flagSorted==-1){
        printf("Sorted Insertion failed\n");
    }

    return 0;
}