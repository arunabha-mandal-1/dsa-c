// linked list insertions

#include <stdio.h>
#include <stdlib.h>

// prototype of nodes
typedef struct Node{
    int data;
    struct Node *next;
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

// insert at the beginning, case 1
Node *insertAtTheBeginning(Node *head, int data){
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}

// insert at index, case 2
Node *insertAtIndex(Node *head, int data, int index){
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
    // did not handle edge caeses here
    // working for 'insert at the end'
}

// insert at the end, case 3
Node *insertAtTheEnd(Node *head, int data){
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

// insert after a node, case 4
Node *insertAfterNode(Node *head, Node *prev, int data){
    Node *ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;

    // linking
    ptr->next=prev->next;
    prev->next=ptr;

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

    printf("Linked list before insertion.............\n");
    linkedListTraversal(head);

    // all four insertion
    // head=insertAtTheBeginning(head, 10); // case 1
    // head=insertAtIndex(head, 500, 5); // case 2
    // head=insertAtTheEnd(head, 500); // case 3
    head=insertAfterNode(head, forth, 500); // case 4
    printf("Linked list after insertion.............\n");
    linkedListTraversal(head);

    return 0;
}