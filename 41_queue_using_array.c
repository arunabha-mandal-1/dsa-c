// Queue implementation using array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototype for queue
typedef struct Queue{
    int size;
    int f;
    int r;
    int *arr;
}Queue;

// check if queue is full
bool isFull(Queue *q){
    return (q->r==q->size-1);
}

// check if it is empty
bool isEmpty(Queue *q){
    return (q->f==q->r);
}

// enqueue
void enqueue(Queue *q, int val){
    // if the r and f are pointing to the same index and the queue is empty, we are going back to the -1
    if(q->f!=-1 && q->r==q->f){
        q->f=q->r=-1;
    }

    if(isFull(q)){
        printf("This queue is full.\n");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}

// dequeue
int dequeue(Queue *q){
    int val=INT_MIN;
    if(isEmpty(q)){
        printf("Queue is empty.\n");
    }else{
        q->f++;
        val=q->arr[q->f];
    }
    return val;
}

// main function
int main(){
    Queue q;
    q.size=3;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    // Check if queue is empty
    // if(isEmpty(&q)){
        // printf("Queue is empty.\n");
    // }

    // Enqueue few elements
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);

    // Dequeuing few elements
    int val1=dequeue(&q);
    printf("First dequeued element : %d\n", val1);

    int val2=dequeue(&q);
    printf("Second dequeued element : %d\n", val2);

    int val3=dequeue(&q);
    printf("Third dequeued element : %d\n", val3);

    // Check if queue is empty
    if(isEmpty(&q)){
        printf("Queue is empty.\n"); // here it's empty
    }

    // Checking an edge case
    enqueue(&q,40);

    // Check if queue is full
    if(isFull(&q)){
        printf("Queue is full.\n"); // not full here
    }

    printf("r=%d\n", q.r);
    printf("f=%d\n", q.f);
    return 0;
}