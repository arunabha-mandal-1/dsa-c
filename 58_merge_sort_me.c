// Merge sort
#include <stdio.h>
#include <stdlib.h>

// Printing all the elements of an array
void printArray(int* A, int size){
    printf("Elements are : ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Merging two sorted arrays
void merge(int* A, int low, int mid, int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int *B=(int*)malloc((high-low+1)*sizeof(int)); // Auxiliary array to store sorted data

    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){ // Copying remaining elements from left half(low-mid) to B
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<=high){ // Copying remaining elements from right half(mid+1-high) to B
        B[k]=A[j];
        j++;
        k++;
    }
    for(int l=low, m=0; l<=high, m<k; l++, m++){ // Copying elements from auxiliary array to original array
        A[l]=B[m];
    }
}

// Merge sort
void mergeSort(int* A, int low, int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

// Main function
int main(){
    // int A1[]={-85, 52, 1, 745, 56, 85, 43, 85, 585639, 5, 1, 96, -100, 1236, 8549, 96354};
    // int A1[]={1, 2, 3, 4, 5};
    int A1[]={2,1};
    int n1=sizeof(A1)/sizeof(A1[0]);

    printArray(A1,n1);
    mergeSort(A1,0,n1-1);
    printf("Sorting...................\n");
    printArray(A1,n1);

    return 0;
}