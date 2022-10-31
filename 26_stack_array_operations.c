// Coding Push(), Pop(), isEmpty() and isFull() Operations in Stack Using an Array
#include <stdio.h>
#include <stdlib.h>

// prototype of stack
typedef struct Stack{
    int size;
    int top;
    int *array;
}Stack;

// Check if stack is full
int isFull(Stack *s){
    return (s->top==s->size-1);
}

// check if stack is empty
int isEmpty(Stack *s){
    return (s->top==-1);
}

// push
void push(Stack *s, int value){
    if(isFull(s)){
        printf("Stack overflow. You cannot push %d in the stack.\n", value);
    }else{
        s->array[++(s->top)]=value; // incrementing and pushing value in one line
    }
}

// pop
int pop(Stack *s){
    if(s->top==-1){
        printf("Stack underflow.\n");
        return INT_MIN;
    }else{
        return s->array[(s->top)--];
    }
}

// main function
int main(){
    Stack *sp=(Stack*)malloc(sizeof(Stack));
    sp->size=10;
    sp->top=-1;
    sp->array=(int*)malloc(sp->size*sizeof(int));
    if(sp){
        printf("Stack has been created successfully.\n");
        if(sp->array){
            printf("Integer array for the stack has been created.\n");
        }else{
            printf("Integer array for the stack has not been created.\n");
        }
    }

    /*-------------------------*/
    if(isEmpty(sp)){
        printf("Stack is empty.\n");
    }
    if(isFull(sp)){
        printf("Stack is full.\n");
    }
    /*---------------------------*/

    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);

     /*-------------------------*/
    if(isEmpty(sp)){
        printf("Stack is empty.\n");
    }
    if(isFull(sp)){
        printf("Stack is full.\n");
    }
    /*---------------------------*/

    push(sp,7);
    push(sp,8);
    push(sp,9);
    push(sp,10);

     /*-------------------------*/
    if(isEmpty(sp)){
        printf("Stack is empty.\n");
    }
    if(isFull(sp)){
        printf("Stack is full.\n");
    }
    /*---------------------------*/

    push(sp,11);

    int popped1=pop(sp);
    printf("Popped 1 = %d\n", popped1);

    int popped2=pop(sp);
    printf("Popped 2 = %d\n", popped2);

    int popped3=pop(sp);
    printf("Popped 3 = %d\n", popped3);

    int popped4=pop(sp);
    printf("Popped 4 = %d\n", popped4);

    int popped5=pop(sp);
    printf("Popped 5 = %d\n", popped5);

    int popped6=pop(sp);
    printf("Popped 6 = %d\n", popped6);

    int popped7=pop(sp);
    printf("Popped 7 = %d\n", popped7);

    int popped8=pop(sp);
    printf("Popped 8 = %d\n", popped8);

    int popped9=pop(sp);
    printf("Popped 9 = %d\n", popped9);

    int popped10=pop(sp);
    printf("Popped 10 = %d\n", popped10);

    int popped11=pop(sp);
    printf("Popped 11 = %d\n", popped11);
    
    return 0;
}