// Queue using linked list
#include <stdio.h>
#include <stdlib.h>

// Prototype for node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// Front and rear pointer so that we can access from anywhere in the program
Node *front=NULL;
Node *rear=NULL;

// Enqueue
void enqueue(int value){
    Node *n=(Node*)malloc(sizeof(Node));
    if(n==NULL){
        printf("Queue overflow.\n");
        return;
    }else{
        n->data=value;
        n->next=NULL;
        if(front==NULL){
            front=rear=n;
        }else{
            rear->next=n;
            rear=n;
        }
        printf("Enqueued element : %d\n", value);
    }
}

// Dequeue
int dequeue(){
    int value=INT_MIN;
    Node *ptr=front;
    if(ptr==NULL){
        printf("Queue underflow. ");
    }else{
        front=front->next;
        value=ptr->data;
        free(ptr);
    }
    printf("Dequeued element : %d\n", value);
    return value;
}

// Display all the elements
void display(){
    if(front==NULL){
        printf("Empty queue.\n");
    }else{
        Node *temp=front;
        printf("Elements are : ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

// Main function
int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();
    dequeue();

    display();

    dequeue();

    display();

    dequeue();

    return 0;
}