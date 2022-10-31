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

// Count sort
void countSort(int* A, int size){
    int max=A[0];
    for(int i=1; i<size; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    int *auxArray=(int*)calloc(max+1, sizeof(int));
    for(int i=0; i<size; i++){
        auxArray[A[i]]=auxArray[A[i]] + 1;
    }
    // printArray(auxArray,max+1);
    int j=0;
    for(int i=0; i<max+1; i++){
        while(auxArray[i]!=0){
            A[j]=i;
            auxArray[i]--;
            j++;
        }
    }
}

// Main function
int main(){
    int A[]={4};
    int size=sizeof(A)/sizeof(A[0]);

    printArray(A,size);
    countSort(A,size);
    printArray(A,size);
    return 0;
}