#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// traversal
void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // link third and forth nodes
    third->data = 108;
    third->next = forth;

    // terminate the node at the third node
    forth->data = 66;
    forth->next = NULL;

    linkedListTraversal(head);

    return 0;
}