// Insertion in a binary tree
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
// Insertion
void insert(Node* root, int key){ // cwh approach, might be wrong imo
    Node* prev=NULL;
    while(root!=NULL){
        prev=root; // hold the root before getting updated
        if(key==root->data){
            printf("%d already exists in the BST.\n", key);
            return;
        }else if(key<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    Node* newNode=createNode(key);
    if(key<prev->data){
        prev->left=newNode;
    }else{
        prev->right=newNode;
    }
}
Node* _insert(Node* root, int key){ // my approach
    if(root==NULL){
        // if the BST is empty
        Node* newNode=createNode(key);
        root=newNode;
    }else{
        Node* prev=NULL;
        Node* temp=root;
        while(temp!=NULL){
            prev=temp;
            if(key==temp->data){
                printf("%d already exists in the BST.\n", key);
                break;
            }else if(key<temp->data){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        Node* newNode=createNode(key);
        if(key<prev->data){
            prev->left=newNode;
        }else if(key>prev->data){
            prev->right=newNode;
        }
    }
    return root; // one return statement to cover it all
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

    p=_insert(p,4);
    p=_insert(p,10);
    p=_insert(p,7);
    p=_insert(p,6);
    p=_insert(p,8);
    // printf("right of 6 : %d\n", p2->right->data); // Checking
    // insert(p,10);
    // insert(p,8);
    // insert(p,5);
    inOrder(p);


    return 0;
}