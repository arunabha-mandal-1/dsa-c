// my approach using global variable
 
#include <stdio.h>
#include <stdlib.h>

// prototype of node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *top=NULL; // using global variable so that we don't have to use double pointer


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
Node *push(int value){ // i don't need to pass top cuz it's global
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
int pop(){ // i don't even need to pass anything
    if(isEmpty(top)){
        printf("Stack underflow.\n");
        return INT_MIN;
    }else{
        Node *temp=top;
        int value=temp->data;
        top=(top)->next;
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
    top=push(78);
    top=push(10);
    top=push(11);
    traverseStack(top);

    int popped1=pop();
    printf("Popped 1 = %d\n", popped1);

    int popped2=pop();
    printf("Popped 2 = %d\n", popped2);

    int popped3=pop();
    printf("Popped 3 = %d\n", popped3);

    traverseStack(top);
    return 0;
}