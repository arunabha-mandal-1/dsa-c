// Count sort
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

// Maximum element of array elements
int maximum(int* A, int size){
    int max=INT_MIN;
    for(int i=0; i<size; i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    return max;
}

// Count sort
void countSort(int* A, int size){
    // Find the max element in A
    int max=maximum(A,size);

    // Creating the count array
    int* count=(int*)malloc((max+1)*sizeof(int));

    // Initialize the array elements to 0
    for(int i=0; i<max+1; i++){
        count[i]=0;
    }

    // Increment the corresponding index in the count array
    for(int i=0; i<size; i++){
        count[A[i]]++;
    }

    int m=0; // counter for count array
    int n=0; // counter for given array A

    while(m<max+1){
        if(count[m]>0){
            A[n]=m;
            count[m]--;
            n++;
        }else{
            m++;
        }
    }
}

// Main function
int main(){
    // int A[]={9, 1, 4, 14, 4, 0, 15, 6, 0};
    int A[]={4,1};
    int size=sizeof(A)/sizeof(A[0]);

    printArray(A,size);
    printf("Sorting...\n");
    countSort(A,size);
    printArray(A,size);

    return 0;
}