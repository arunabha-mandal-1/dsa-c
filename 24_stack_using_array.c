// stack using array
#include <stdio.h>
#include <stdlib.h>

// stack prototype
typedef struct Stack{
    int size;
    int top;
    int *arr;
}Stack;

// checkin' whether stack is empty
int isEmpty(Stack *ptr){
    return (ptr->top==-1);
}

// checkin' whether stack is full
int isFull(Stack *ptr){
    return (ptr->top==ptr->size-1);
}

// main function
int main(){
    // Stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int*)malloc(s.size*sizeof(int));

    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->size=6;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));

    // pushing elements
    s->arr[++(s->top)]=7;
    s->arr[++(s->top)]=8;
    s->arr[++(s->top)]=12;
    s->arr[++(s->top)]=45;
    s->arr[++(s->top)]=78;
    s->arr[++(s->top)]=96;

    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty.\n");
    }
    // Check if stack is full
    if(isFull(s)){
        printf("Stack is full.\n");
    }
    return 0;
}