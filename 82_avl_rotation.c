// Insertion in a binary search tree and make it balanced, cwh approach
#include <stdio.h>
#include <stdlib.h>

// Prototype of node
typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height; // cuz we need |balance factor|
}Node;
// Height
int getHeight(Node* node){
    if(node==NULL){
        return -1;
    }
    return node->height;
}
// Create node
Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=0;
    return newNode;
}
// Balance factor
int getBF(Node* node){
    if(node==NULL){
        return -1;
    }
    return (getHeight(node->left)-getHeight(node->right));
}
// Max
int max(int a, int b){
    return (a>b?a:b);
}
// Left rotate
Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;
    // Rotating
    y->left=x;
    x->right=T2;
    x->height=max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height=max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
// Right rotate
Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* T2=x->right;
    // Rotating
    x->right=y;
    y->left=T2;
    x->height=max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height=max(getHeight(y->left), getHeight(y->right)) + 1;
    return x;
}
// Insertion
Node* insert(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->key){
        root->left=insert(root->left, data);
    }else if(data>root->key){
        root->right=insert(root->right, data);
    }else{
        printf("%d already exists in the BST.\n", data);
        return root;
    }
    root->height=max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf=getBF(root);
    // data inserted, now it's time to balance

    // LL
    if(bf>1 && data<root->left->key){
        return rightRotate(root);
    }
    // RR
    else if(bf<-1 && data>root->right->key){
        return leftRotate(root);
    }
    // LR
    else if(bf>1 && data>root->left->key){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    else if(bf<-1 && data<root->right->key){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// Preorder traversal
void preOrder(Node *root){
    if(root!=NULL){
        /*root->left->right*/
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
// Postorder traversal
void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}
// Inorder traversal
void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
// Main function
int main(){
    Node* root=NULL;
    root=insert(root, 1);
    root=insert(root, 3);
    root=insert(root, 4);
    root=insert(root, 10);
    root=insert(root, 2);
    root=insert(root, 5);

    inOrder(root);
    printf("\n");
    preOrder(root);
    return 0;
}