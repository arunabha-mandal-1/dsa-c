#include <stdio.h>

// display
void display(int arr[], int size){
    // traversal
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// deletion
int indexDeletion(int arr[], int capacity, int *size, int index){
    int n = *(size);
    if(index>=n){
        return -1; // failure status
    }
    for(int i=index; i<*(size)-1; i++){
        arr[i]=arr[i+1];
    }
    *(size) = n - 1;
    return 1; // success status
}

// main func
int main(){
    int arr[50]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size=10, capacity=sizeof(arr)/sizeof(arr[0]), index=9;
    printf("Original array!\n");
    display(arr, size);

    int deletionFlag = indexDeletion(arr, capacity, &size, index);
    if(deletionFlag==1){
        printf("Deletion successful! Modified array > \n");
        display(arr, size);
    }else if(deletionFlag==-1){
        printf("Deletion failed!");
    }
    // printf("%d\n", size); // just checking
    return 0;
}