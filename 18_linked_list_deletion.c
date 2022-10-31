// Linked list deletion

#include <stdio.h>
#include <stdlib.h>

// prototype of nodes
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// traversal
void linkedListTraversal(Node* ptr){
    printf("Elements are : ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// case 1: delete the first node
Node *deleteFirst(Node *head){
    Node *ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    return head;
}

// case 2: delete a node from a given index
Node *deleteAtIndex(Node *head, int index){
    Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    Node *q=p->next; // node to be deleted
    p->next=q->next;
    free(q);
    q=NULL;
    return head;
    // did not handle edge cases
}

// case 3: delete the last node
Node *deleteLast(Node *head){
    Node *ptr1=head;
    Node *ptr2=head->next;
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=ptr2->next;
    free(ptr2);
    ptr2=NULL;
    return head;
}

// case 4 : delete first node with the given value
Node *deleteGivenValue(Node *head, int value){
    Node *ptr1=head;
    Node *ptr2=head->next; // node to be deleted except the first node
    if(ptr1->data==value){ // for the first node
        head=head->next;
        free(ptr1);
        ptr1=NULL;
        return head;
    }

    // putting 'ptr2!=NULL' condition otherwise the second condition will throw seg fault if the element is not found
    while(ptr2!=NULL && ptr2->data!=value){ // for other nodes
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if(ptr2==NULL){
        return head;
    }
    ptr1->next=ptr2->next;
    free(ptr2);
    ptr2=NULL;
    return head;
}

// main function
int main(){
    Node* head;
    Node* second;
    Node* third;
    Node* forth;

    // Allocate memory for nodes in the linked list in heap
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    forth = (Node*)malloc(sizeof(Node));

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

    printf("Linked list before deletion............\n");
    linkedListTraversal(head);

    // deletion
    // head=deleteFirst(head); // case 1: delete the first node
    // head=deleteAtIndex(head, 1); // case 2: delete a node from a given index
    // head=deleteLast(head); // case 3: delete the last node
    head=deleteGivenValue(head, 123); // case 4: delete first node with the given value
    printf("Linked list after deletion............\n");
    linkedListTraversal(head);

    return 0;
}