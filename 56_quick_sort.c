// Quick sort
#include <stdio.h>

// Printing all the elements of an array
void printArray(int* A, int size){
    printf("Elements are : ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Making partition for quick sort
int partition(int* A, int low, int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;

    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            int temp1=A[i];
            A[i]=A[j];
            A[j]=temp1;
        }
    }while(i<j);
    
    // Swap A[low] and A[j]
    int temp2=A[low];
    A[low]=A[j];
    A[j]=temp2;
    return j;
}

// Quick sort
void quickSort(int* A, int low, int high){
    int partionIndex; // Index of pivot after partition

    if(low<high){
        partionIndex=partition(A,low,high);
        quickSort(A,low,partionIndex-1); // sort left subarray
        quickSort(A,partionIndex+1,high); // sort right subarray
    }
}

// Main function
int main(){
    int A1[]={12, 54, 54, 652, 72, 655, 9, 12};
    // int A2[]={3, 3, 1, 2, 5, 7};
    int A2[]={2,1};
    int n1=sizeof(A1)/sizeof(A1[0]);
    int n2=sizeof(A2)/sizeof(A2[0]);

    printArray(A1,n1);
    quickSort(A1,0,n1-1);
    printArray(A1,n1);

    printArray(A2,n2);
    quickSort(A2,0,n2-1);
    printArray(A2,n2);

    return 0;
}