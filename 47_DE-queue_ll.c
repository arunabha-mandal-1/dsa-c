// DE-queue using linked list
// There are two types of DE-queue :
/*
    1. Restricted input DE-queue where insertion from front is not allowed
    2. Restricted output DE-queue where deletion from rear is not allowed
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Protype of node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// Global rear and front pointer to node
Node *front=NULL;
Node *rear=NULL;

// Check if queue is empty
bool isEmpty(){
    return (front==NULL);
}

// Adding element at front of the queue
void enqueueFront(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Queue overflow.\n");
    }else{
        newNode->data=value;
        if(front==NULL){
            front=newNode;
            rear=newNode;
        }else{
            newNode->next=front;
            front=newNode;
        }
        printf("Equeued at front : %d\n", value);
    }
}

// Adding element at rear of the queue
void enqueueRear(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Queue overflow.\n");
    }else{
        newNode->data=value;
        newNode->next=NULL;
        if(front==NULL){
            front=newNode;
            rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
        printf("Equeued at rear : %d\n", value);
    }
}

// Removing element from front
int dequeueFront(){
    int value=INT_MIN;
    if(front==NULL){
        printf("Queue underflow. ");
    }else{
        Node *ptr=front;
        if(front==rear){ // In case there is only one element
            rear=rear->next;
        }
        front=front->next;
        Node *temp1=rear; // just for debug
        Node *temp2=front; // just for debug
        value=ptr->data;
        free(ptr);
        ptr=NULL;
        printf("Dequeued from front : %d\n", value);
    }
    return value;
}

// Removing element from front
int dequeueRear(){
    int value=INT_MIN;
    if(front==NULL){
        printf("Queue underflow. ");
    }else{
        Node *ptr=rear;
        value=ptr->data;
        if(front->next==NULL){ // Cuz rear->next is always NULL
            front=front->next;
            rear=rear->next;
            free(ptr);
            ptr=NULL;
        }else{
            Node *temp=front;
            while((temp->next)->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
            rear=temp;
            free(ptr);
            ptr=NULL;
        }
        printf("Dequeued from rear : %d\n", value);
    }
    return value;
}

// Traverse queue from front to rear
void printQueue(){
    Node *temp=front;
    if(temp==NULL){
        printf("Empty queue.\n");
        return;
    }
    printf("Elements are : ");
    while(temp!=NULL){
        int value=temp->data;
        printf("%d ", value);
        temp=temp->next;
    }
    printf("\n");
}

// Main function
int main(){
    if(isEmpty()){
        printf("Queue is empty.\n");
    }

    enqueueRear(1);
    enqueueRear(2);
    enqueueRear(3);
    enqueueRear(4);
    enqueueRear(5);

    if(isEmpty()){
        printf("Queue is empty.\n");
    }

    enqueueFront(6);
    enqueueFront(7);
    enqueueFront(8);

    printQueue();

    dequeueFront();
    dequeueFront();

    printQueue();

    dequeueRear();
    dequeueRear();

    printQueue();

    // Experimenting with only one element
    // enqueueRear(10);
    // dequeueFront();
    // printQueue();
    return 0;
}