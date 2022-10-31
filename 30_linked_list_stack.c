#include <stdio.h>
#include <stdlib.h>

// prototype of node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// check if it's empty
int isEmpty(Node *top){
    return (top==NULL);
}

// check if it's full
int isFull(Node *top){ // 'top' seems redundant
    Node *p=(Node*)malloc(sizeof(Node));
    return (p==NULL);
} // this function seems illogical

// push
Node *push(Node *top, int value){
    // here i'm not using isFull but using kinda same approach
    Node *n=(Node*)malloc(sizeof(Node));
    if(!n){
        printf("Stack overflow.\n");
        return top;
    }else{
        n->data=value;
        n->next=top;
        top=n;
        return top;
    }
}

// pop
int pop(Node **top){
    if(isEmpty(*top)){
        printf("Stack underflow.\n");
        return INT_MIN;
    }else{
        Node *temp=*top;
        int value=temp->data;
        *top=(*top)->next;
        free(temp);
        return value;
    }
}

// traverse
void traverseStack(Node *top){
    if(!top){
        printf("No elements in the stack.\n");
        return;
    }
    Node *temp=top;
    printf("Elements are(top to bottom) : ");
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

// main function
int main(){
    Node *top=NULL;
    top=push(top, 78);
    top=push(top, 10);
    top=push(top, 11);
    traverseStack(top);

    int popped1=pop(&top);
    printf("Popped 1 = %d\n", popped1);
    traverseStack(top);
    return 0;
}
// another approach in the next program using global variable