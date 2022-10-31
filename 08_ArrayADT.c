#include <stdio.h>
#include <stdlib.h>

// our ADT
struct myArray{
    int total_size; // total size we want to allocate
    int used_size; // total size we want to use for a particular task, it's good to have some extra memory as we don't run out of memory
    int *ptr; // base address
};

// creating an array using myArray ADT
void createArray(struct myArray *a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize*sizeof(int)); // allocating memory in heap ...
    // otherwise the memory will be gone after the function terminates
} 

// showing elements of the array
void show(struct myArray *a){
    printf("Showing values : ");
    for(int i=0; i<(a->used_size); i++){
        printf("%d ", (a->ptr)[i]);  
    }
}

// setting value of the array
void setVal(struct myArray *a){
    for(int i=0; i<a->used_size; i++){
        printf("Enter element %d : ", i+1);
        scanf("%d", &((a->ptr)[i]));  
    }
}
int main(){
    struct myArray marks;
    createArray(&marks, 10, 2);
    setVal(&marks);
    show(&marks);
    free(marks.ptr);
    return 0;
}