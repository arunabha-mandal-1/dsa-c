// Linked representation of binary tree
#include <stdio.h>
#include <stdlib.h>

// Prototype of node
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Create node
Node *createNode(int data){
    Node *newNode=(Node*)malloc(sizeof(Node)); // creating a node pointer and allocating memory in heap
    newNode->data=data; // setting the data
    newNode->left=NULL; // setting left pointer to null
    newNode->right=NULL; // setting right pointer to null
    return newNode; // returning the created node
}

// Main function
int main(){
/*
    Node *p; // constructing the root node
    p=(Node*)malloc(sizeof(Node));
    p->data=2;
    p->left=NULL;
    p->right=NULL;

    Node *p1; // constructing the second node
    p1=(Node*)malloc(sizeof(Node));
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;

    Node *p2; // constructing the third node
    p2=(Node*)malloc(sizeof(Node));
    p2->data=4;
    p2->left=NULL;
    p2->right=NULL;

    // linking the root node with left and right children
    p->left=p1;
    p->right=p2;
*/

    // repeating multiple lines to create a node 
    // better we can write a function
    
    Node *p=createNode(2); // constructing the root node using function

    Node *p1=createNode(1); // constructing the second node using function
    Node *p2=createNode(4); // constructing the third node using function 

    // linking the root node with left and right children
    p->left=p1;
    p->right=p2;

    return 0;
}