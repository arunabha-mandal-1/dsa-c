// Circular linked list
#include <stdio.h>
#include <stdlib.h>

// prototype of node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// traverse
void circularLLtraversal(Node *head){
    Node *ptr=head;
    printf("Elements are : ");
    do{
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}

// insert at the beginning
Node *insertAtFirst(Node *head, int data){
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;

    Node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    // At this point p points to the last node of the circular linked list.
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

// main function
int main(){

    // allocating spaces for nodes
    Node *head=(Node*)malloc(sizeof(Node));
    Node *second=(Node*)malloc(sizeof(Node));
    Node *third=(Node*)malloc(sizeof(Node));
    Node *forth=(Node*)malloc(sizeof(Node));

    // linking head and second
    head->data=4;
    head->next=second;

    // linking second and third
    second->data=3;
    second->next=third;

    // linking third and forth
    third->data=6;
    third->next=forth;

    // linking forth and head
    forth->data=1;
    forth->next=head;

    printf("Circular linked list before insertion...\n");
    circularLLtraversal(head);
    head=insertAtFirst(head, 50);
    printf("Circular linked list after insertion...\n");
    circularLLtraversal(head);
    
    return 0;
}