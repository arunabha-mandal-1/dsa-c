// Tree traversal practice
#include <stdio.h>
#include <stdlib.h>

// Prototype of nodes
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
// Create node
Node* createNode(int dataItem){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=dataItem;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// Preorder traversal
void preOrder(Node* root){
    if(root!=NULL){
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
// Main function
int main(){
    /*
                                7
                        1               2
                    4       5       1       5
                  6   7   2   3               1

    */
   // Depth = 0
   Node *p=createNode(7);

    // Depth = 1
   Node *p1=createNode(1);
   Node *p2=createNode(2);

    // Depth = 2
   Node *p11=createNode(4);
   Node *p12=createNode(5);
   Node *p21=createNode(1);
   Node *p22=createNode(5);

    // Depth = 3
   Node *p111=createNode(6);
   Node *p112=createNode(7);
   Node *p121=createNode(2);
   Node *p122=createNode(3);
   Node *p222=createNode(1);

   // Linking 
   // depth 0 -> depth 1
   p->left=p1;
   p->right=p2;

   // depth 1 -> depth 2
   p1->left=p11;
   p1->right=p12;
   p2->left=p21;
   p2->right=p22;

   // depth 2 -> depth 3
   p11->left=p111;
   p11->right=p112;
   p12->left=p121;
   p12->right=p122;
   p22->right=p222;

   preOrder(p);
   printf("\n");
   postOrder(p);
   printf("\n");
   inOrder(p);


    return 0;
}