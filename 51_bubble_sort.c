// Bubble sort
#include <stdio.h>

// Printing all the elements of an array
void printArray(int* A, int size){
    printf("Elements are : ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Bubble sort function
void bubbleSort(int* A, int size){
    printf("Sorting..............\n");
    for(int i=0; i<size-1; i++){ // for number of pass
        printf("Working on pass no %d\n", i+1);
        for(int j=0; j<size-i-1; j++){ // for comparison in each pass
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

// Adaptive Bubble sort function
void bubbleSortAdaptive(int* A, int size){
    printf("Sorting..............\n");
    int isSorted=0; // to make it adaptive
    for(int i=0; i<size-1; i++){ // for number of pass
        printf("Working on pass no %d\n", i+1);
        isSorted=1; // assume it is sorted
        for(int j=0; j<size-i-1; j++){ // for comparison in each pass
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0; // if swapping happens, array is not sorted
            }
        }
        if(isSorted==1){
            return;
        }
    }
}

// Main function
int main(){
    int A1[]={12, 54, 652, 72, 655, 9};
    int A2[]={1, 2, 3, 4, 5};
    int n1=sizeof(A1)/sizeof(A1[0]);
    int n2=sizeof(A2)/sizeof(A2[0]);

    printf("A1 - \n");
    printArray(A1,n1); // printing the array before sorting
    // printf("%d %d\n", A, &A); // Same
    // bubbleSort(A1,n1); // printing the array after sorting
    bubbleSortAdaptive(A1,n1); // printing the array after sorting
    printArray(A1,n1); // printing the array after sorting

    // Bubble sort is not adaptive by default but we can make it default.
    // In case of sorted array, only one pass is required.
    // No swap => Array sorted

    printf("A2 - \n");
    printArray(A2,n2); // printing the array before sorting
    // bubbleSort(A2,n2); // printing the array after sorting
    bubbleSortAdaptive(A2,n2); // printing the array after sorting
    printArray(A2,n2); // printing the array after sorting

    return 0;
}