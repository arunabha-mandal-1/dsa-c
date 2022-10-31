// Stacks can be used for checking balancing of symbols
// Algorithm : 
 /*
    a. Create a stack.
    b. while(end of input is not reached){
        1) If the character read is not a symbol to be balanced, ignore it.
        2) If the character is an opening symbol like (,{,[, push it onto the stack
        3) If it is a closing symbol like ),},], then if the stack is empty report an error. Otherwise pop up the stack.
        4) If the symbol popped is not the corresponding opening symbol, report an error.
    }
    c. At end of input, if the stack is not empty report an error.
 */

// Author : Arunabha Mandal
// Date : 15.10.2022

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// prototype for nodes
typedef struct Node{
    char symbol;
    struct Node *next;
}Node;

Node *top=NULL; // creating top pointer and making it global so that we can use it from anywhere from the program

// Check if the stack is empty
int isEmpty(){
    return (top==NULL);
}

// push a new symbol
void push(char sym){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error.\n");
        return;
    }
    newNode->symbol=sym;
    newNode->next=top;
    top=newNode;
}

// pop a symbol
char pop(){
    if(!isEmpty()){
        Node *temp=top;
        char value=temp->symbol;
        top=top->next;
        free(temp);
        temp=NULL;
        return value;
    }else{
        return '!';
    }
}

// Checking if it is balanced
bool isBalanced(char *symStr){
    int len=strlen(symStr);
    int i=0;
    while(i<len){
        if(symStr[i]=='(' || symStr[i]=='{' || symStr[i]=='['){
            push(symStr[i]);
        }else if(symStr[i]==')' || symStr[i]=='}' || symStr[i]==']'){
            if(isEmpty()){ // we are checking in pop function tho
                return false;
            }else{
                char temp=pop();
                if(temp=='!'){
                    printf("Something went wrong.\n");
                    return false;
                }
                if(temp=='('){
                    if(symStr[i]!=')'){
                        return false;
                    }
                }
                else if(temp=='{'){
                    if(symStr[i]!='}'){
                        return false;
                    }
                }
                else if(temp=='['){
                    if(symStr[i]!=']'){
                        return false;
                    }
                }
            }
        }
        i++;
    }
    if(isEmpty()){
        return true;
    }else{
        return false;
    }
}

// main function
int main(){
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]s", str);
    printf("%s=>%d\n", str, strlen(str));
    bool flag=isBalanced(str);
    if(flag==true){
        printf("Balanced.\n");
    }else{
        printf("Not balanced.\n");
    }
    
    return 0;
}

// working