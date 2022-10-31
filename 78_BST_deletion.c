// Deletion in binary tree
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
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Deletion
Node* inorderPredecessor(Node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
Node* deleteNode(Node* root, int value){
    Node* iPre=NULL;
    if(root==NULL){
        return NULL;
    }
    // base case
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    // search for the node to be deleted
    if(value<root->data){
        root->left=deleteNode(root->left, value);
    }else if(value>root->data){
        root->right=deleteNode(root->right, value);
    }
    // deletion strategy when the node is found
    else{
        iPre=inorderPredecessor(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left, iPre->data);
    }
    return root;
}
// Main function
int main(){
    /*

        5
       / \
      3   6
     / \
    1   4

    */
    Node* p=createNode(5);

    Node* p1=createNode(3);
    Node* p2=createNode(6);

    Node* p3=createNode(1);
    Node* p4=createNode(4);

    // Linking
    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    // Traversal
    inOrder(p);
    printf("\n");
    Node* ptr=deleteNode(p,2); // error
    printf("Data : %d\n", ptr->data);
    inOrder(p);

    return 0;
}