// Coding infix(without bracket) to postfix in C using stack
// Author : Arunabha Mandal
// Date : 16.10.2022

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// prototype for nodes
typedef struct Node{
    char character;
    struct Node *next;
}Node;

Node *top=NULL; // creating top pointer and making it global so that we can use it from anywhere from the program

// Check if the stack is empty
bool isEmpty(){
    return (top==NULL);
}

// push a new character
void push(char sym){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error.\n");
        return;
    }
    newNode->character=sym;
    newNode->next=top;
    top=newNode;
}

// pop a character
char pop(){
    if(!isEmpty()){
        Node *temp=top;
        char value=temp->character;
        top=top->next;
        free(temp);
        temp=NULL;
        return value;
    }else{
        return '!';
    }
}

// top character of stack
char stackTop(){
    if(top==NULL){
        return '=';
    }
    return (top->character);
}

// precedence of operator
int precedence(char ch){
    if(ch=='*' || ch=='/'){
        return 3;
    }else if(ch=='+' || ch=='-'){
        return 2;
    }else{
        return 0;
    }
}

// check if the character is an operator
bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return true;
    }else{
        return false;
    }
}

// infix to postfix
char *infixToPostfix(char *infix){
    char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;// tracking infix
    int j=0;// tracking postfix
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }else{
            if(precedence(infix[i])>precedence(stackTop())){
                push(infix[i]);
                i++;
            }else{
                postfix[j]=pop();
                j++;
            }
        }
    }
    while(!isEmpty()){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

// main function
int main(){
    char infix[100];
    printf("Enter the string : ");
    scanf("%[^\n]s", infix);
    // printf("%s=>%d\n", str, strlen(str));
    char *postfix=infixToPostfix(infix);
    printf("Postfix is %s\n", postfix);

    
    return 0;
}

// working