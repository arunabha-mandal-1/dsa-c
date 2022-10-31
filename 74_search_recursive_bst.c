// Searching in a binary tree(recursive)
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
// Preorder traversal
void preOrder(Node *root){
    if(root!=NULL){
        /*root->left->right*/
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Postorder traversal
void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
// Inorder traversal
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
// Check whether a tree is a binary search tree
int isBST(Node* root){ // similar to inorder traversal
    static Node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){ // checking for left
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){ // checking for the current one
            return 0;
        }
        prev=root;
        return isBST(root->right); // repeating process for left
        // if(!isBST(root->right)){
        //     return 0;
        // }
    }else{
        return 1;// considering empty tree a bst
    }
}
// Searching a node in a binary tree
Node* search(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }else if(key<root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
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

    // preOrder(p);
    // printf("\n");
    inOrder(p);
    printf("\n");
    // postOrder(p);
    // printf("\n");

    int isBst=isBST(p);
    if(isBst){
        printf("It's a BST.\n");
    }else{
        printf("It's not a BST.\n");
    }

    if(isBST){ // If the tree is not BST, there's no reason to find an element using 'search' function
        Node* myNode=search(p,4);
        if(myNode!=NULL){
            printf("Found : %d\n", myNode->data);
        }else{
            printf("Element not found.\n");
        }
    }

    return 0;
}