// Inorder traversal code
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

// Inorder traversal
void inOrderTraversal(Node *root){
    if(root!=NULL){
        /*left->root->right*/
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function
int main(){
    /*

        4
       / \
      1   6
     / \
    5   2

    */
   Node *p=createNode(4);

   Node *p1=createNode(1);
   Node *p2=createNode(6);

   Node *p3=createNode(5);
   Node *p4=createNode(2);

   // Linking
   p->left=p1;
   p->right=p2;

   p1->left=p3;
   p1->right=p4;

   inOrderTraversal(p);
   /*5 1 2 4 6*/
   
    return 0;
}