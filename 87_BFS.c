// Breadth First Search(BFS)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        // printf("Enqueued element : %d\n", value);
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
    // printf("Dequeued element : %d\n", value);
    return value;
}

// Checking if the queue is empty
bool isEmpty(){
    return (front==NULL);
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
    // BFS implementation
    int node;
    int i=1;
    int visitedMarker[7]={0,0,0,0,0,0,0}; // it's indexes are node elements
    // using adjancy matrix approach here
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ", i);
    visitedMarker[i]=1;
    enqueue(i); // for exploration
    while(!isEmpty()){
        int node=dequeue();
        for(int j=0; j<7; j++){
            if(a[node][j]==1 && visitedMarker[j]==0){
                printf("%d ", j);
                visitedMarker[j]=1;
                enqueue(j);
            }
        }
    }
    printf("\n");
    return 0;
}