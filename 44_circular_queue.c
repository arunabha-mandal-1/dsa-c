// Circular queue

#include <stdio.h>
#include <stdlib.h>

// prototype of circular queue
typedef struct CircularQueue{
    int size;
    int front;
    int rear;
    int *arr;
}CircularQueue;

// Check if it's empty
int isEmpty(CircularQueue *q){
    return (q->rear==q->front);
}

// Check if it's full
int isFull(CircularQueue *q){
    return (((q->rear)+1)%(q->size)==q->front);
}

// enqueue
void enqueue(CircularQueue *q, int val){
    if(isFull(q)){
        printf("Queue overflow.\n");
    }else{
        q->rear=((q->rear)+1)%q->size;
        q->arr[q->rear]=val;
        printf("Enqued element : %d\n", val);
    }
}

// dequeue
int dequeue(CircularQueue *q){
    int val=INT_MIN;
    if(isEmpty(q)){
        printf("Queue underflow. ");
    }else{
        q->front=((q->front)+1)%q->size;
        val=q->arr[q->front];
    }
    printf("Dequed element : %d\n", val);
    return val;
}

// main function
int main(){
    CircularQueue q;
    q.size=4; // capacity = 3
    q.front=q.rear=0; // If we assign it to 0, it will never be full according to isFull condition
    q.arr=(int*)malloc(sizeof(int)*q.size);

    // enqueue few elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // Check if queue is full
    if(isFull(&q)){
        printf("Queue is full.\n");
    }

    //dequeue few elements
    int val1=dequeue(&q);
    int val2=dequeue(&q);
    int val3=dequeue(&q);
    // int val4=dequeue(&q);

    // Check if queue is empty
    if(isEmpty(&q)){
        printf("Queue is empty.\n");
    }

    // enquing again
    enqueue(&q, 1);
    enqueue(&q, 1);

    // Check if queue is full
    if(isFull(&q)){
        printf("Queue is full.\n");
    }
    return 0;
}